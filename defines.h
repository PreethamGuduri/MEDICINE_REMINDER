#define ROW 10
#define COL 8
#define pos(flag) \
        if (flag == 0) { \
            cmdlcd(0x80); \
            strlcd("  "); \
            /* numlcd(HOUR); */ \
            CharLCD(':'); \
            numlcd(MIN); \
            CharLCD(':'); \
            numlcd(SEC); \
			strlcd("   ");\
			strlcd(arr[DOW]);\
			cmdlcd(0xc0); \
			numlcd(DOM); \
			CharLCD('/'); \
			numlcd(MONTH); \
			CharLCD('/'); \
			num_year(YEAR); \
			delay_ms(90); \
        } else if (flag == 1) { \
            cmdlcd(0x80); \
            numlcd(HOUR); \
            CharLCD(':'); \
            strlcd("  "); \
            /* numlcd(MIN); */ \
            CharLCD(':'); \
            numlcd(SEC); \
			strlcd("   ");\
			strlcd(arr[DOW]);\
			cmdlcd(0xc0); \
			numlcd(DOM); \
			CharLCD('/'); \
			numlcd(MONTH); \
			CharLCD('/'); \
			num_year(YEAR); \
            delay_ms(90); \
        } else if (flag == 2) { \
            cmdlcd(0x80); \
            numlcd(HOUR); \
            CharLCD(':'); \
            numlcd(MIN); \
            CharLCD(':'); \
            strlcd("  "); \
            /* numlcd(SEC); */ \
			strlcd("   ");\
			strlcd(arr[DOW]);\
			cmdlcd(0xc0); \
			numlcd(DOM); \
			CharLCD('/'); \
			numlcd(MONTH); \
			CharLCD('/'); \
			num_year(YEAR); \
            delay_ms(90); \
        } else if(flag == 3){ \
			cmdlcd(0x80); \
            numlcd(HOUR); \
            CharLCD(':'); \
            numlcd(MIN); \
            CharLCD(':'); \
            numlcd(SEC);  \
			strlcd("   ");\
			strlcd("      "); \
		/*	strlcd(arr[DOW]);*/\
			cmdlcd(0xc0); \
			numlcd(DOM); \
			CharLCD('/'); \
			numlcd(MONTH); \
			CharLCD('/'); \
			num_year(YEAR); \
            delay_ms(90); \
			} else if(flag == 4)\
			{\
			cmdlcd(0x80); \
            numlcd(HOUR); \
            CharLCD(':'); \
            numlcd(MIN); \
            CharLCD(':'); \
            numlcd(SEC);  \
			strlcd("   ");\
			strlcd(arr[DOW]);\
			cmdlcd(0xc0); \
				strlcd("  ");\
	/*		numlcd(DOM);*/ \
			CharLCD('/'); \
			numlcd(MONTH); \
			CharLCD('/'); \
			num_year(YEAR); \
            delay_ms(90); \
			}else if(flag == 5)\
			{\
			cmdlcd(0x80); \
            numlcd(HOUR); \
            CharLCD(':'); \
            numlcd(MIN); \
            CharLCD(':'); \
            numlcd(SEC);  \
			strlcd("   ");\
			strlcd(arr[DOW]);\
			cmdlcd(0xc0); \
			numlcd(DOM); \
			CharLCD('/'); \
			strlcd("  ");\
		/*	numlcd(MONTH); */\
			CharLCD('/'); \
			num_year(YEAR); \
            delay_ms(90); \
			}else if(flag == 6)\
			{\
			cmdlcd(0x80); \
            numlcd(HOUR); \
            CharLCD(':'); \
            numlcd(MIN); \
            CharLCD(':'); \
            numlcd(SEC);  \
			strlcd("   ");\
			strlcd(arr[DOW]);\
			cmdlcd(0xc0); \
			numlcd(DOM); \
			CharLCD('/'); \
			numlcd(MONTH); \
			CharLCD('/'); \
			strlcd("     "); \
	/*		num_year(YEAR); */\
            delay_ms(90); \
			}\

					
#define am_pos(flag) \
        if (flag == 0) { \
            cmdlcd(0x80); \
            strlcd("  "); \
            /* numlcd(HOUR); */ \
            CharLCD(':'); \
            numlcd(min); \
            CharLCD(':'); \
            numlcd(sec); \
			strlcd("   ");\
			strlcd(repeat[rep]);\
			cmdlcd(0xc0); \
			numlcd(dom); \
			CharLCD('/'); \
			numlcd(month); \
			CharLCD('/'); \
			num_year(year); \
			strlcd("	  ");\
			strlcd(al[al_1]);\
          delay_ms(90); \
        } else if (flag == 1) { \
            cmdlcd(0x80); \
            numlcd(hour); \
            CharLCD(':'); \
            strlcd("  "); \
            /* numlcd(MIN); */ \
            CharLCD(':'); \
            numlcd(sec); \
			strlcd("   ");\
			strlcd(repeat[rep]);\
			cmdlcd(0xc0); \
			numlcd(dom); \
			CharLCD('/'); \
			numlcd(month); \
			CharLCD('/'); \
			num_year(year); \
			strlcd(" 	 ");\
	strlcd(al[al_1]);\
            delay_ms(90); \
        } else if (flag == 2) { \
            cmdlcd(0x80); \
            numlcd(hour); \
            CharLCD(':'); \
            numlcd(min); \
            CharLCD(':'); \
            strlcd("  "); \
            /* numlcd(SEC); */ \
			strlcd("   ");\
		strlcd(repeat[rep]);\
			cmdlcd(0xc0); \
			numlcd(dom); \
			CharLCD('/'); \
			numlcd(month); \
			CharLCD('/'); \
			num_year(year); \
			strlcd("	  ");\
			strlcd(al[al_1]);\
            delay_ms(90); \
			}else if(flag == 3){\
			cmdlcd(0x80); \
            numlcd(hour); \
            CharLCD(':'); \
            numlcd(min); \
            CharLCD(':'); \
            numlcd(sec);  \
			strlcd("   ");\
			strlcd("         ");\
			/*strlcd(repeat[rep]);*/\
			cmdlcd(0xc0); \
			numlcd(DOM);\
			CharLCD('/'); \
			numlcd(month); \
			CharLCD('/'); \
			num_year(year); \
			strlcd("	  ");\
			strlcd(al[al_1]);\
            delay_ms(90); \
			} else if(flag == 4)\
			{\
			cmdlcd(0x80); \
            numlcd(hour); \
            CharLCD(':'); \
            numlcd(min); \
            CharLCD(':'); \
            numlcd(sec);  \
			strlcd("   ");\
			strlcd(repeat[rep]);\
			cmdlcd(0xc0); \
			strlcd("  ");\
	/*		numlcd(DOM);*/ \
			CharLCD('/'); \
			numlcd(month); \
			CharLCD('/'); \
			num_year(year); \
			strlcd(" 	 ");\
			strlcd(al[al_1]);\
            delay_ms(90); \
			}else if(flag == 5)\
			{\
			cmdlcd(0x80); \
            numlcd(hour); \
            CharLCD(':'); \
            numlcd(min); \
            CharLCD(':'); \
            numlcd(sec);  \
			strlcd("   ");\
			strlcd(repeat[rep]);\
			cmdlcd(0xc0); \
			numlcd(dom); \
			CharLCD('/'); \
			strlcd("  ");\
		/*	numlcd(MONTH); */\
			CharLCD('/'); \
			num_year(year); \
			strlcd("	  ");\
			strlcd(al[al_1]);\
            delay_ms(90); \
			}else if(flag == 6)\
			{\
			cmdlcd(0x80); \
            numlcd(hour); \
            CharLCD(':'); \
            numlcd(min); \
            CharLCD(':'); \
            numlcd(sec);  \
			strlcd("   ");\
			strlcd(repeat[rep]);\
			cmdlcd(0xc0); \
			numlcd(dom); \
			CharLCD('/'); \
			numlcd(month); \
			CharLCD('/'); \
			strlcd("    "); \
			/*	num_year(YEAR); */\
			strlcd(" 	 ");\
			strlcd(al[al_1]);\
            delay_ms(90); \
			}else if(flag == 7){\
			cmdlcd(0x80); \
            numlcd(hour); \
            CharLCD(':'); \
            numlcd(min); \
            CharLCD(':'); \
            numlcd(sec);  \
			strlcd("   ");\
			strlcd(repeat[rep]);\
			cmdlcd(0xc0); \
			numlcd(dom); \
			CharLCD('/'); \
			numlcd(month); \
			CharLCD('/'); \
			num_year(year); \
			strlcd(" 	 ");\
			strlcd("     "); \
	/*	strlcd(al[al_1]);*/\
            delay_ms(90); \
			}\

					
#define dis_tm     \
				cmdlcd(0x80); \
				numlcd(HOUR); \
				CharLCD(':'); \
				numlcd(MIN); \
				CharLCD(':'); \
				numlcd(SEC); \
				strlcd("   ");\
				strlcd(arr[DOW]);\
				cmdlcd(0xc0); \
				numlcd(DOM); \
				CharLCD('/'); \
				numlcd(MONTH); \
				CharLCD('/'); \
				num_year(YEAR); \
				strlcd("  ");\
					
				
#define sw_1 16
#define sw_2 17
#define sw_3 18
#define sw_4 20
#define IsPress(sw) (((1 << sw)&IOPIN1)==0)
#define IsNotPress(sw) (((1 << sw)&IOPIN1))
#define SUPERLOOP while(1)
