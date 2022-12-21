#include <targets/AT91SAM7.h>
#include <LCD.h>

#define LCD_BACKLIGHT PIOB_SODR_P20

int main(void){
    PMC_PCER=PMC_PCER_PIOB;
    PIT_MR=PIT_MR_PITTEN | 299999; // przy założeniu że MCK 48MHz przepłninie licznika CPIV co 100ms
    while (1){
        if(PIT_PIIR && 0b00000011001000000000000000000000) { // odczekanie na przpełnienie liczbika CPIV 50 razy czyli 5 sekund
            PIT_PIVR; // reset licznika
            PIOB_ODSR ^= LCD_BACKLIGHT; // zmiana podświetlenia do zaobserwowania interwału 5 sekundowego 
        } 
    } 
}
