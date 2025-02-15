#include "defines.h"
void delay_ms(int);
void delay_s(int);
void delay_us(int);
void cmdlcd(int);
void CharLCD(char );
void initlcd(void);
void strlcd(char *);
void numlcd(int a);

void init_rtc(void);

	int st=0;
	int hour;
	int min;
	int sec;
	int dom;
	int month;
	int year;
	int alaram=0;
	int time_i=0;
	int al_1=0;
	int rep=0;
	char al[2][3]={"OFF","ON "};
	char repeat[2][5]={"ONCE ","DAILY"};

int alaram_symbol[]={0x04,0x0e,0x0e,0x0e,0x0e,0x1f,0x04,0x00};
	
char arr[7][20]={"SUN","MON","TUES","WED","THURS","FRI","SAT"};
int time[ROW][COL];
