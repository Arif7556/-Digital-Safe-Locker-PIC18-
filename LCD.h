void lcd_cmd(unsigned char);
void lcd_init(void);
void lcd_data(unsigned char);
void lcd_string(unsigned char *);
void delay(void);
#define RS PORTCbits.RC1
#define RW PORTCbits.RC0
#define EN PORTCbits.RC2
#define data_line PORTD
 
void lcd_init(void)
{
TRISC=0x00;
TRISD=0x00;
lcd_cmd(0x30);
lcd_cmd(0x38);
lcd_cmd(0x01);
lcd_cmd(0x80);
lcd_cmd(0x0F);
}
void lcd_string(unsigned char *P)
{
while(P!='\0')
{
lcd_data(*P);
P++;
}
}
void lcd_cmd(unsigned char c )
{
data_line=c;
RS=0;
RW=0;
EN=1;
delay();
EN=0;
}

void lcd_data(unsigned char c)
{
data_line=c;
RS=1;
RW=0;
EN=1;
delay();
EN=0;
}
void delay(void)
{
	int i,j;
	for (i=0;i<200;i++)
	for (j=0;j<200;j++);
}

