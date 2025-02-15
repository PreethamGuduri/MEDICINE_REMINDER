#include<LPC21xx.h>




#define FOSC	12000000  // 12million
#define CCLK  (5*FOSC)   
#define PCLK  (CCLK/4)


#define PREINT_VAL  (int)((PCLK / 32768) - 1)
#define PREFRAC_VAL (PCLK-((PREINT + 1) * 32768))

#define RTC_ENABLE	0x01  
#define RTC_RESET   0x02  

void init_rtc(void)
{
	CCR = RTC_RESET; // 0x02	
	PREINT = PREINT_VAL;  
	PREFRAC = PREFRAC_VAL;
	CCR = RTC_ENABLE;
}
