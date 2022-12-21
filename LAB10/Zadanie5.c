int main(void){
    PMC_PCER = 1 << 3 | 1 << 12;
    //konfiguracjaliniiwyjściowej (LAB1–spotkanie1oraz2)
    TC0_CCR =1<<1;//wyłączamy inkrementację licznika tak, bymożliwa była jegokonfiguracja 
    TC0_SR;//pustyodczyt wceluwyzerowania ewentualnieustawionych flag 

    // 48MHz / 128 = 375 000 Hz
    // czyli RC = 37500 aby interwał wynosił 100ms

    TC0_CMR= TIMER_CLOCK4 | 1 << 14;//wybór częstotliwościinkrementacji licznikaMCK/1024 orazbitCPCTRG 
    TC0_RC =37500;//wartośćRCobliczonapowyżej
    TC0_CCR = 1 | 1 << 2;//włączenie zegaratimeraorazreset programowy(rejestr TC_CCR)
    
    while (1){
        if((TC0_SR & (1 << 4)) !=0) { // sprawdzenieczynabiciezwiązanym 
                                                // zporównaniemwartościlicznikazrejestremRC
                                                // jest1–programowy odczytpowodujereset
                                                // wartościrejestru TC0_SR..........................
                                                //zmiana stanuliniiwyjściowej (poprzednie laboratoria)

            PIOB_ODSR ^= LCD_BACKLIGHT;
        } 
    } 
}
