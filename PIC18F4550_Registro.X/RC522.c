#include "RC522.h"
#include "config.h"

unsigned char MFRC522_Rd(unsigned char Address) 
{
   unsigned int i, ucAddr;
   unsigned int ucResult = 0;
   
   //output_bit (MFRC522_SCK, 0);
   //output_bit (MFRC522_CS, 0);
   MFRC522_SCK = 0;
   MFRC522_CS = 0;
   ucAddr = ( (Address<<1)&0x7E)|0x80;

   for (i = 8; i > 0; i--)
   {
      //output_bit (MFRC522_SI, ((ucAddr&0x80) == 0x80));
      //output_bit (MFRC522_SCK, 1);
       if((ucAddr&0x80) == 0x80){
           MFRC522_SI = 1;
       }
       else{
           MFRC522_SI = 0;
       }
       MFRC522_SCK = 1;
       ucAddr <<= 1;
     //output_bit (MFRC522_SCK, 0);
       MFRC522_SCK = 0;
   }

   for (i = 8; i > 0; i--)
   {
      //output_bit (MFRC522_SCK, 1);
      MFRC522_SCK = 1;
      ucResult <<= 1;
      ucResult|= MFRC522_SO;
      //output_bit (MFRC522_SCK, 0);
      MFRC522_SCK = 0;
   }

  
   //output_bit (MFRC522_CS, 1);
   MFRC522_CS = 1;
   //output_bit (MFRC522_SCK, 1);
   MFRC522_SCK = 1;
   return (unsigned char)ucResult;
}
void MFRC522_Wr(unsigned char Address, unsigned char value)
{
  
   unsigned char i, ucAddr;
   //output_bit (MFRC522_SCK, 0);
   MFRC522_SCK = 0;
   //output_bit (MFRC522_CS, 0);
   MFRC522_CS = 0;
   ucAddr = ( (Address<<1)&0x7E);
   for(i = 8; i > 0; i--){
        //output_bit (MFRC522_SI, ( (ucAddr&0x80) == 0x80));
        if((ucAddr&0x80) == 0x80) MFRC522_SI = 1;
        else MFRC522_SI = 0;
        //output_bit (MFRC522_SCK, 1);
        MFRC522_SCK = 1;
        ucAddr <<= 1;
        //output_bit (MFRC522_SCK, 0);
        MFRC522_SCK = 0;
   }
   for(i = 8; i > 0; i--)
   {
       //output_bit (MFRC522_SI, ( (value&0x80) == 0x80));
       if((value&0x80) == 0x80) MFRC522_SI = 1;
       else MFRC522_SI = 0;
       //output_bit (MFRC522_SCK, 1);
       MFRC522_SCK = 1;
       value <<= 1;
       //output_bit (MFRC522_SCK, 0);
       MFRC522_SCK = 0;
   }
   //output_bit (MFRC522_CS, 1);
   MFRC522_CS = 1;
   //output_bit (MFRC522_SCK, 1);
   MFRC522_SCK = 1;
}
static void MFRC522_Clear_Bit( char addr, char mask )
{     unsigned char  tmp =0x0;
      tmp=MFRC522_Rd( addr ) ;
     MFRC522_Wr( addr,  tmp&~mask );   
}
static void MFRC522_Set_Bit( char addr, char mask )
{    unsigned char  tmp =0x0;
      tmp=MFRC522_Rd( addr ) ; 
     MFRC522_Wr( addr, tmp|mask );
}
void MFRC522_Reset(void)
{ 
    
   //output_bit (MFRC522_RST, 1) ;
   MFRC522_RST = 1;
   __delay_us(1);
   //output_bit (MFRC522_RST, 0) ;
   MFRC522_RST = 0;
   __delay_us(1);
   //output_bit (MFRC522_RST, 1) ;
   MFRC522_RST = 1;
   __delay_us(1);
   MFRC522_Wr( COMMANDREG, PCD_RESETPHASE );
   __delay_us(1);
      
}
void MFRC522_AntennaOn(void)
{                                              
unsigned char stt;
stt= MFRC522_Rd( TXCONTROLREG ) ;
MFRC522_Set_Bit( TXCONTROLREG, 0x03 );
}
void MFRC522_AntennaOff(void)
{
MFRC522_Clear_Bit( TXCONTROLREG, 0x03 );                                          
}
void MFRC522_Init(void)     
{   
    MFRC522_S_CS = 0;
    MFRC522_S_SCK = 0;
    MFRC522_S_SI = 0;
    MFRC522_S_SO = 1;
    MFRC522_S_RST = 0;
    
    //output_bit(MFRC522_CS , 1); 
    //output_bit( MFRC522_RST , 1);
     MFRC522_CS = 1;
     MFRC522_RST = 1;
     MFRC522_Reset();       
     MFRC522_Wr( TMODEREG, 0x8D );      //Tauto=1; f(Timer) = 6.78MHz/TPreScaler
     MFRC522_Wr( TPRESCALERREG, 0x3E ); //TModeReg[3..0] + TPrescalerReg
     MFRC522_Wr( TRELOADREGL, 30 );
     MFRC522_Wr( TRELOADREGH, 0 ); 
     MFRC522_Wr( TXAUTOREG, 0x40 );    //100%ASK
     MFRC522_Wr( MODEREG, 0x3D );      // CRC valor inicial de 0x6363
       
  
     MFRC522_AntennaOff() ;            
     MFRC522_AntennaOn();
}
char MFRC522_ToCard( char command, char *sendData, char sendLen, char *backData, unsigned *backLen )
{
  char _status = MI_ERR;
  char irqEn = 0x00;
  char waitIRq = 0x00;               
  char lastBits;
  char n;
  unsigned int i;
 
  switch (command)
  {
    case PCD_AUTHENT:       //Certification cards close
    {
      irqEn = 0x12;
      waitIRq = 0x10;
      break;
    }
    case PCD_TRANSCEIVE:    //Transmit FIFO data
    {
      irqEn = 0x77;
      waitIRq = 0x30;
      break;
    }
    default:
      break;
  }
  MFRC522_Wr( COMMIENREG, irqEn | 0x80 );  //Interrupt request
  MFRC522_Clear_Bit( COMMIRQREG, 0x80 );   //Clear all interrupt request bit
  MFRC522_Set_Bit( FIFOLEVELREG, 0x80 );   //FlushBuffer=1, FIFO Initialization
  MFRC522_Wr( COMMANDREG, PCD_IDLE );      //NO action; Cancel the current command???
 
  for ( i=0; i < sendLen; i++ )
  {
    MFRC522_Wr( FIFODATAREG, sendData[i] );
  }
 
  MFRC522_Wr( COMMANDREG, command );
  if (command == PCD_TRANSCEIVE )
  {
    MFRC522_Set_Bit( BITFRAMINGREG, 0x80 ); //StartSend=1,transmission of data starts 
  }
 
  i = 0xFFFF;  
  do
  {
 
    n = MFRC522_Rd( COMMIRQREG );
    i--;
  }
  while ( i && !(n & 0x01) && !( n & waitIRq ) );
  MFRC522_Clear_Bit( BITFRAMINGREG, 0x80 );   
  if (i != 0)
  {
    if( !( MFRC522_Rd( ERRORREG ) & 0x1B ) )
    {
      _status = MI_OK;
      if ( n & irqEn & 0x01 )
      {
        _status = MI_NOTAGERR;      
      }
      if ( command == PCD_TRANSCEIVE )
      {
        n = MFRC522_Rd( FIFOLEVELREG );
        lastBits = MFRC522_Rd( CONTROLREG ) & 0x07;
        if (lastBits)
        {
          *backLen = (n-1) * 8 + lastBits;
        }
        else
        {
          *backLen = n * 8;
        }
        if (n == 0)
        {
          n = 1;
        }
        if (n > 16)
        {
          n = 16;
        }
      
        for (i=0; i < n; i++)
        {
          backData[i] = MFRC522_Rd( FIFODATAREG );
        }
 
  backData[i] = 0;
      }
    }
    else
    {
      _status = MI_ERR;
    }
  }
 
  return _status;
}
char MFRC522_Request( char reqMode, char *TagType )
{
  char _status;
  unsigned backBits;           
  MFRC522_Wr( BITFRAMINGREG, 0x07 );
  TagType[0] = reqMode;
  _status = MFRC522_ToCard( PCD_TRANSCEIVE, TagType, 1, TagType, &backBits );
  if ( (_status != MI_OK) || (backBits != 0x10) )
  {
    _status = MI_ERR;
  }
  return _status;
}
void MFRC522_CRC( char *dataIn, char length, char *dataOut )
{
char i, n;
    MFRC522_Clear_Bit( DIVIRQREG, 0x04 );
    MFRC522_Set_Bit( FIFOLEVELREG, 0x80 );   
   
    
    for ( i = 0; i < length; i++ )
    {  
        MFRC522_Wr( FIFODATAREG, *dataIn++ );  
    }
   
    MFRC522_Wr( COMMANDREG, PCD_CALCCRC );
       
    i = 0xFF;
 
    do
    {
        n = MFRC522_Rd( DIVIRQREG );
        i--;
    }
    while( i && !(n & 0x04) );        //CRCIrq = 1
       
    dataOut[0] = MFRC522_Rd( CRCRESULTREGL );
    dataOut[1] = MFRC522_Rd( CRCRESULTREGM );       
}

//hibernation
void MFRC522_Halt(void)
{
  unsigned unLen;
  char buff[4];
 
  buff[0] = PICC_HALT;
  buff[1] = 0;
  MFRC522_CRC( buff, 2, &buff[2] );
  MFRC522_Clear_Bit( STATUS2REG, 0x80 );
  MFRC522_ToCard( PCD_TRANSCEIVE, buff, 4, buff, &unLen );
  MFRC522_Clear_Bit( STATUS2REG, 0x08 );
}
char MFRC522_AntiColl( char *serNum )
{
  char _status;
  char i;
  char serNumCheck = 0;
  unsigned int unLen;
  MFRC522_Wr( BITFRAMINGREG, 0x00 );                //TxLastBists = BitFramingReg[2..0]
  serNum[0] = PICC_ANTICOLL;
  serNum[1] = 0x20;
  MFRC522_Clear_Bit( STATUS2REG, 0x08 );
  _status = MFRC522_ToCard( PCD_TRANSCEIVE, serNum, 2, serNum, &unLen );
  if (_status == MI_OK)
  {
    for ( i=0; i < 4; i++ )
    {
      serNumCheck ^= serNum[i];
    }
   
    if ( serNumCheck != serNum[4] )
    {
      _status = MI_ERR;
    }
  }
  return _status;
}
char MFRC522_isCard( char *TagType )
{
    if (MFRC522_Request( PICC_REQIDL, TagType ) == MI_OK)
        return 1;
    else
        return 0;
}
char MFRC522_ReadCardSerial( char *str )
{
char _status;
_status = MFRC522_AntiColl( str );
str[5] = 0;
if (_status == MI_OK)
  return 1;
else
  return 0;
}

void MFRC522_Clear_UID(char* u_i)
{
  for(int j=0; j<10; j++)
  {
    u_i[j] = 0;
  }
}
