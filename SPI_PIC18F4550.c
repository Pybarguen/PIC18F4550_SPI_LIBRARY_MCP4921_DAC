
// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 2       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes from the 96 MHz PLL divided by 2)

// CONFIG1H
#pragma config FOSC = XT_XT     // Oscillator Selection bits (XT oscillator (XT))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 1        // Watchdog Timer Postscale Select bits (1:1)

// CONFIG3H
#pragma config CCP2MX = OFF     // CCP2 MUX bit (CCP2 input/output is multiplexed with RB3)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = OFF     // Stack Full/Underflow Reset Enable bit (Stack full/underflow will not cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#define CCS PORTBbits.RB2
#define Led LATBbits.LATB3
#define _XTAL_FREQ 4000000
#include <xc.h>
#include "Pic18f4550_SPI_master_library.h"


//Senoidal signal array in program memory
int *const p[322] = {
    127, 129, 132, 134, 137, 139, 142, 144, 
147, 149, 152, 154, 157, 159, 161, 164, 
166, 169, 171, 173, 176, 178, 180, 182, 
185, 187, 189, 191, 193, 196, 198, 200, 
202, 204, 206, 208, 210, 211, 213, 215, 
217, 219, 220, 222, 224, 225, 227, 228, 
230, 231, 233, 234, 235, 237, 238, 239, 
240, 242, 243, 244, 245, 246, 246, 247, 
248, 249, 250, 250, 251, 251, 252, 252, 
253, 253, 254, 254, 254, 254, 254, 254, 
254, 254, 254, 254, 254, 254, 254, 253, 
253, 253, 252, 252, 251, 251, 250, 249, 
249, 248, 247, 246, 245, 244, 243, 242, 
241, 240, 239, 237, 236, 235, 234, 232, 
231, 229, 228, 226, 225, 223, 221, 220, 
218, 216, 214, 212, 211, 209, 207, 205, 
203, 201, 199, 197, 195, 192, 190, 188, 
186, 184, 181, 179, 177, 175, 172, 170, 
168, 165, 163, 160, 158, 156, 153, 151, 
148, 146, 143, 141, 138, 136, 133, 131, 
128, 126, 123, 121, 118, 116, 113, 111, 
108, 106, 104, 101, 99, 96, 94, 91, 
89,  87, 84, 82, 80, 77, 75, 73, 
70,  68, 66, 64, 62, 60, 57, 55, 
53,  51, 49, 47, 45, 44, 42, 40, 
38, 36, 35, 33, 31, 30, 28, 26, 
25, 23, 22, 21, 19, 18, 17, 15, 14, 
13, 12, 11, 10, 9, 8, 7, 6, 6, 5, 4, 
3, 3, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 
3, 3, 4, 4, 5, 6, 7, 7, 8, 9, 10, 11, 
12, 14, 15, 16, 17, 18, 20, 21, 23, 24, 
25, 27, 29, 30, 32, 33, 35, 37, 39, 41, 
42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 
63, 65, 67, 69, 71, 74, 76, 78, 81, 83, 
85, 88, 90, 92, 95, 97, 100, 102, 104, 
107, 109, 112, 114, 117, 119, 122, 124, 127
};

int i = 0;


void __interrupt(high_priority) tcInt(void)
{
    if (TMR0IE && TMR0IF) {  // any timer 0 interrupts?
        
        write_byte_spi(p[i]);
        TMR0L = 0;
         TMR0IF=0;       
         i += 1;
         if(i>=322)
         {
             i = 0;
         }
        

       
    }
    /*
   if (TMR1IE && TMR1IF) {  // any timer 1 interrupts?
        TMR1IF=0;
        tick_count += 100;
    }
     * */
    // process other interrupt sources here, if required
    return;
}

void main(void) {

    
  //TMR0
    //Activacion de interrupcion TMR0
    INTCON = 0b10100000;
    T0CON =  0b11001000; 
    RCONbits.IPEN = 0;//Desactivado los niveles de interrupcion
    TMR0L = 0;
    
  //SPI
   Spi_init();//start spi interface
   Spi_mode(CPOL_0_CPHA_0);//SPI mode 0 0 
   Spi_clock_mode(SPI_MASTER_CLOCK_DIV_4);//SPI clock = FOSC/4 
   TRISBbits.RB2 = 0;//SLAVE control PIN
   TRISBbits.RB3 = 0;//output for TMR0 control
   CCS = 1;//Slave control PIN
 
 
 
 while(1)
 {
     ;;
 }
 
 
}
