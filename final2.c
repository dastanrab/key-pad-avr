/*
 * final2.c
 *
 * Created: 6/26/2021 7:15:43 AM
 * Author: afarinesh pardaz
 */

#define  F_CPU 16000000UL
#include <io.h>
#include <alcd.h>
#include <delay.h>
char k[4][3]={{'1','2','3'},
								{'4','5','6'},
								{'7','8','9'},
								{'*','0','#'}};
                     

unsigned char c,r1;
char pass[]="1234";
int flag=1;
int i=0;

void main(void)

{
    lcd_init(16);
    DDRB=0xf0;
    PORTB=0xff;
     
    lcd_gotoxy(1, 0); 
    lcd_puts("salam");
    delay_ms(150);
    lcd_clear();  
    


while(1)
	{
		
		do
		{
			PORTB&=0x0f;
			r1=PINB&0x0f;
		} while(r1!=0x0f);
	

		do
		{
			delay_ms(20);
			r1=PINB&0x0f;
		}	  while(r1==0x0f);
		
		while(1)
		{
			PORTB=0xef;     //0b11101111
			r1=PINB&0x0f;
			if(r1!=0x0f)
			{
				c=0;
				break;
			}
			PORTB=0xdf;     //0b11011111
			r1=PINB&0x0f;
			if(r1!=0x0f)
			{
				c=1;
				break;
			}
			PORTB=0xbf;     //0b10111111
			r1=PINB&0x0f;
			if(r1!=0x0f)
			{
				c=2;
				break;
			}

		}
        
        if(i==4){ 
        if(flag==1){ 
        lcd_gotoxy(3, 0);
        lcd_puts("dorost");
         delay_ms(50);
         lcd_clear(); }
        else{
           lcd_gotoxy(3, 0);
           lcd_puts("na dorost");
            delay_ms(50);
            lcd_clear();  
        }
        i=0;
         
        
        }

		else if(r1==0x0e){
        lcd_putchar('*');
        delay_ms(10); 
        if(pass[i]!=k[0][c]){
           flag=0;
        }
        i++;
        }
		else if(r1==0x0d){
		
        lcd_putchar('*'); 
        delay_ms(10);
         if(pass[i]!=k[1][c]){
           flag=0;
        }
        i++;}
		else if(r1==0x0b){
		
        lcd_putchar('*');
        delay_ms(10);
         if(pass[i]!=k[2][c]){
           flag=0;
        }
        i++;}
		else{
        lcd_putchar('*');
        delay_ms(10);
         if(pass[i]!=k[3][c]){
           flag=0;
        }
        i++;}
	}  
  }
