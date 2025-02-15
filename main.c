#include<LPC21xx.h>
#include<string.h>
#include "header.h"
#include "init_lcd.h"
#include "init_rtc.h"
#include "defines.h"




void num_year(int a)	// Function to Dipslay Year
{
	CharLCD((a/1000)+'0');
	CharLCD(((a/100)%10)+'0');
	CharLCD(((a/10)%10)+'0');
	CharLCD((a%10)+'0');
	
}

void am_fun()	//Function to display the alarm time
{
		cmdlcd(0x80);

	numlcd(hour);
	CharLCD(':');
	numlcd(min);
	CharLCD(':');
	numlcd(sec);
	strlcd("   ");
	strlcd(repeat[rep]);
	cmdlcd(0xc0);
	numlcd(dom);
	CharLCD('/');
	numlcd(month);
	CharLCD('/');
	num_year(year);
	strlcd("	  ");
	strlcd(al[al_1]);
}

int Edit_alarm(int pos)	// Function to Edit Alarm
{
	int flag=0,i;
	hour	=	time[pos][0];
	min	=	time[pos][1];
	sec = time[pos][2];
	dom=time[pos][3];
	month=time[pos][4];
	year=time[pos][5];
	rep=time[pos][6];
	al_1=time[pos][7];
		while(1)
		{
			if(((1 << sw_1)&IOPIN1)==0)
			{
							if(flag == 0)
							{
								hour++;
								(hour == 24)?(hour = 0):hour;
							}
							if(flag == 1)
							{
								min ++;
								(min == 60)?(min = 0):min;

							}
							if(flag == 2)
							{
								sec++;
								(sec == 60)?(sec = 0):sec;
							}
							if(flag == 3)
							{
								if(rep==0)
									rep=1;
								else
									rep=0;
							}
							if(flag == 4)
							{
								dom++;
								(dom == 31)?(dom = 0):dom;
							}
							if(flag == 5)
							{
								month ++;
								(month == 13)?(month = 0):month;
							}
							if(flag == 6)
							{
								year ++ ;
							}
							if(flag == 7)
							{
								if(al_1)
									al_1=0;
								else
									al_1=1;
							}
				for(i=200*12000;i>=0;i--)
						{
								if(((1 << sw_1)&IOPIN1))
									break;
						}
				while(((1 << sw_1)&IOPIN1)==0)
				{
						am_fun();
						for(i=1*12000;i>=0;i--)
						{
								if(((1 << sw_1)&IOPIN1))
									break;
						}
							if(flag == 0)
							{
								hour++;
								(hour == 24)?(hour = 0):hour;
							}
							if(flag == 1)
							{
								min ++;
								(min == 60)?(min = 0):min;

							}
							if(flag == 2)
							{
								sec++;
								(sec == 60)?(sec = 0):sec;
							}
							if(flag == 3)
							{
								if(rep==0)
									rep=1;
								else
									rep=0;
							}
							if(flag == 4)
							{
								dom++;
								(dom == 31)?(dom = 0):dom;
							}
							if(flag == 5)
							{
								month ++;
								(month == 13)?(month = 0):month;
							}
							if(flag == 6)
							{
								year ++ ;
							}
							if(flag == 7)
							{
								if(al_1)
									al_1=0;
								else
									al_1=1;
							}				}	//while sw_1
			
			}// if sw_1
			
			if(((1 << sw_2)&IOPIN1) == 0)
			{
					flag++;
					if(flag == 8)
					flag=0;
				while(((1 << sw_2)&IOPIN1) == 0)
				{
						
						if(((1 << sw_2)&IOPIN1))
								break;
						for(i=90*12000;i>=0;i--)
						{
							if(((1 << sw_2)&IOPIN1))
								break;
						}
						
						am_fun();
						for(i=50*12000;i>=0;i--)
						{
								if(((1 << sw_2)&IOPIN1))
								break;
						}
				} // while
			} // sw_2
			am_pos(flag);
			for(i=5*12000;i>=0;i--)
			{
					if((((1 << sw_2)&IOPIN1)==0)||(((1 << sw_1)&IOPIN1)==0)||(((1 << sw_4)&IOPIN1)==0))
					break;
			}
			am_fun();
			for(i=80*12000;i>=0;i--)
			{
					if((((1 << sw_2)&IOPIN1)==0)||(((1 << sw_1)&IOPIN1)==0)||(((1 << sw_4)&IOPIN1)==0))
					break;
			}
		if(((1 << sw_3)&IOPIN1)==0)
			return 1;
		if(((1 << sw_4)&IOPIN1)==0)
		{

			while(((1 << sw_4)&IOPIN1)==0);
			time[pos][0]=hour;
			time[pos][1]=min;
			time[pos][2]=sec;
			time[pos][3]=dom;
			time[pos][4]=month;
			time[pos][5]=year;
			time[pos][6]=rep;
			time[pos][7]=al_1;
			cmdlcd(0x01);
			strlcd("AlARAM UPDATED");
			cmdlcd(0xc0);
			strlcd("SUCCESSFULLY");
			delay_ms(400);
			cmdlcd(0x01);
			break;
		}
			
		
	}	//while
			return 1;
}

int am(void)			// Function to SET alarm
{
	int i,pos=0;
	int flag=0;
	cmdlcd(0x01);
	while(((1 << sw_3)&IOPIN1)==0);

SUPERLOOP{
	start:
	if(IsPress(sw_2))
	{
		while(IsPress(sw_2));
		Edit_alarm(pos);
	}
	if(IsPress(sw_4)&&pos<time_i)
	{
		cmdlcd(0x01);
		strlcd("WANT TO DELETE");
		delay_ms(500);
		cmdlcd(0x01);
		strlcd("PRESS AGAIN OR");
		cmdlcd(0xc0);
		strlcd("PRESS (M) TO EXIT");
		while(1)
		{
			
			if(IsPress(sw_3))	// exit form delete
			{
				while(IsPress(sw_3));	
				cmdlcd(0x01);
				break;
			}else if(IsPress(sw_4))	// Delete ALARM
				{
					while(IsPress(sw_4));
					memmove(time + pos, time + pos + 1, (ROW - pos - 1) * COL * sizeof(int));
					cmdlcd(0x01);
					strlcd("DELETED");
					cmdlcd(0xc0);
					strlcd("SUCCESSFULLY");
					delay_ms(500);
					time_i--;
					break;
				}
		}
	}
		if((time_i>0) && (pos!=time_i))
		{
					cmdlcd(0x80); 
					numlcd(pos+1);
					strlcd("| ");
					numlcd(time[pos][0]); 
					CharLCD(':'); 
					numlcd(time[pos][1]); 
					CharLCD(':'); 
					numlcd(time[pos][2]);
					strlcd("	");
					if(time[pos][6]==0)
					{
						strlcd("OC ");
					}else
					{
						strlcd("DLY");
					}
					cmdlcd(0xc0); 
					if(time[pos][7])
					{
						CharLCD(0);
						strlcd("  	");
					}
					else{
					strlcd("    ");}
					numlcd(time[pos][3]); 
					CharLCD('/'); 
					numlcd(time[pos][4]); 
					CharLCD('/'); 
					num_year(time[pos][5]); 
					strlcd("  ");
		}else if(time_i==0)
		{
			cmdlcd(0x80);
			//numlcd(time_i+1);
			//strlcd(". ADD");
		}
		if(pos == time_i && pos!=10)
		{
			cmdlcd(0x80);
			numlcd(time_i+1);
			strlcd(".ADD ALARAM              ");
			cmdlcd(0xc0);
			strlcd("																");
		}
		if(pos == 10)
		{
			cmdlcd(0x80);
			numlcd(time_i+1);
			strlcd(". ALARAM LIMIT           ");
			cmdlcd(0xc0);
			strlcd("EXCEED        						");

		}
	if(IsPress(sw_1)) // alaram slide
	{
			pos++;	// no.of alaram
		if(pos==(time_i+1))
			pos=0;

	
		while(IsPress(sw_1));
	}
	
	if(IsPress(sw_4)&&(pos == time_i))
	{
					hour = HOUR;
					min =  MIN;
					sec = SEC;
					dom = DOM;
					month = MONTH;
					year = YEAR;
					al_1=0;
					rep=0;
					cmdlcd(0x01);
					while(IsPress(sw_4))
					{
						cmdlcd(0x80);
						numlcd(time_i+1);
						strlcd(".ADD ALARAM              ");
						cmdlcd(0xc0);
						strlcd("																");
					}
					if(time_i == 10)
					{
						strlcd("ALARAM LIMIT");
						cmdlcd(0xc0);
						strlcd("EXCEED");
						delay_s(2);
						goto start;
					}
					while(1)
					{
						if(IsPress(sw_1))
						{
							if(flag == 0)
							{
								hour++;
								(hour == 24)?(hour = 0):hour;
							}
							if(flag == 1)
							{
								min ++;
								(min == 60)?(min = 0):min;

							}
							if(flag == 2)
							{
								sec++;
								(sec == 60)?(sec = 0):sec;
							}
							if(flag == 3)
							{
								if(rep==0)
									rep=1;
								else
									rep=0;
							}
							if(flag == 4)
							{
								dom++;
								(dom == 31)?(dom = 0):dom;
							}
							if(flag == 5)
							{
								month ++;
								(month == 13)?(month = 0):month;
							}
							if(flag == 6)
							{
								year ++ ;
							}
							if(flag == 7)
							{
								if(al_1)
									al_1=0;
								else
									al_1=1;
							}		
							for(i=200*12000;i>=0;i--)
								{
										if(IsNotPress(sw_1))
											break;
								}
							while(((1 << sw_1)&IOPIN1)==0)
							{
									am_fun();
									for(i=1*12000;i>=0;i--)
									{
											if(IsNotPress(sw_1))
												break;
									}
								if(flag == 0)
								{
									hour++;
									(hour == 24)?(hour = 0):hour;
								}
								if(flag == 1)
								{
									min ++;
									(min == 60)?(min = 0):min;

								}
								if(flag == 2)
								{
									sec++;
									(sec == 60)?(sec = 0):sec;
								}
								if(flag == 3)
								{
									if(rep==0)
										rep=1;
									else
										rep=0;
								}
								if(flag == 4)
								{
									dom++;
									(dom == 31)?(dom = 0):dom;
								}
								if(flag == 5)
								{
									month ++;
									(month == 13)?(month = 0):month;
								}
								if(flag == 6)
								{
									year ++ ;
								}
								if(flag == 7)
								{
									if(al_1)
										al_1=0;
									else
										al_1=1;
								}							}	//while sw_1
						
						}// if sw_1
						if(IsPress(sw_2))
						{
								flag++;
								if(flag == 8)
								flag=0;
							while(IsPress(sw_2))
							{
									
									if(IsNotPress(sw_2) ||IsPress(sw_3))
											break;
									for(i=90*12000;i>=0;i--)
									{
										if(IsNotPress(sw_2))
											break;
									}
									
									am_fun();
									for(i=50*12000;i>=0;i--)
									{
											if(IsNotPress(sw_2))
											break;
									}
							} // while
						} // sw_2
						am_pos(flag);
						for(i=5*12000;i>=0;i--)
						{
								if(IsPress(sw_2) || IsPress(sw_1) || IsPress(sw_3)|| IsPress(sw_4))
								break;
						}
						am_fun();
						for(i=80*12000;i>=0;i--)
						{
								if(IsPress(sw_2) || IsPress(sw_1) || IsPress(sw_3)|| IsPress(sw_4))
								break;
						}
						if(IsPress(sw_3))
							return 1;
						if(IsPress(sw_4))
						{

							while(IsPress(sw_4));
							time[time_i][0]=hour;
							time[time_i][1]=min;
							time[time_i][2]=sec;
							time[time_i][3]=dom;
							time[time_i][4]=month;
							time[time_i][5]=year;
							time[time_i][6]=rep;
							time[time_i][7]=al_1;
							time_i++;
							cmdlcd(0x01);
							strlcd("AlARAM SET");
							cmdlcd(0xc0);
							strlcd("SUCCESSFULLY");
							delay_ms(400);
							cmdlcd(0x01);
							break;

						
					}
			}	//while
}	//if
	if(IsPress(sw_3))
		return 1;
}}
	

int fun(void)			// TIme (RTC) EDIT
{
	int i;
	int flag=0;
	cmdlcd(0x01);
	cmdlcd(0x80);
	SUPERLOOP					//	while(1)
	{
		if(IsPress(sw_1))
		{
			if(flag == 0)	//	If position Match while sliding
			{
				HOUR++; // Incrementing HOUR 
				(HOUR == 24)?(HOUR = 0):HOUR;	// hour limitation while increment
		
			}
			if(flag == 1)	//	Checking position
			{
				MIN++;			//	Incrementing MIN
				(MIN == 60)?(MIN = 0):MIN; // Min limitation while increment

			}
			if(flag == 2)
			{
				SEC++;	//	Incrementing sec
				(SEC == 60)?(SEC = 0):SEC;	// Sec limitation 

			}
			if(flag == 3)
			{
				DOW++;	//	Incrementing Date
				(DOW == 7)?(DOW = 0):DOW;	// Week limitation

			}
			if(flag == 4)
			{
				DOM++;	//	Incrementing date
				(DOM == 31)?(DOM = 0):DOM;	// Date limitation

			}
			if(flag == 5)
			{
				MONTH ++; // Month Increment
				(MONTH == 13)?(MONTH = 0):MONTH; // Month Limitation

			}
			if(flag == 6)
			{
				YEAR ++ ; // Year Increment
			}
			for(i=200*12000;i>=0;i--)	//	delay when switch in hold
				{
						if(((1 << sw_1)&IOPIN1)) // break if switch released while in loop
							break;
				}
			while(IsPress(sw_1))	// If switch is not released
			{
				/** If switch  1 is not released then vlaues has to increment with some delay **/
					
					dis_tm; // Display Time
			if(flag == 0)	//	If position Match while sliding
			{
				HOUR++; // Incrementing HOUR 
				(HOUR == 24)?(HOUR = 0):HOUR;	// hour limitation while increment
		
			}
				if(flag == 1)	//	Checking position
				{
					MIN++;			//	Incrementing MIN
					(MIN == 60)?(MIN = 0):MIN; // Min limitation while increment

				}
				if(flag == 2)
				{
					SEC++;	//	Incrementing sec
					(SEC == 60)?(SEC = 0):SEC;	// Sec limitation 

				}
				if(flag == 3)
				{
					DOW++;	//	Incrementing Date
					(DOW == 7)?(DOW = 0):DOW;	// Week limitation

				}
				if(flag == 4)
				{
					DOM++;	//	Incrementing date
					(DOM == 30)?(DOM = 0):DOM;	// Date limitation

				}
				if(flag == 5)
				{
					MONTH ++; // Month Increment
					(MONTH == 13)?(MONTH = 0):MONTH; // Month Limitation

				}
				if(flag == 6)
				{
					YEAR ++ ; // Year Increment
				}
				for(i=1*12000;i>=0;i--)		// Delay between increments
				{
						if(((1 << sw_1)&IOPIN1))		//Break if switch is released
							break;
				}
			}	// while sw_1
		}	// Ispress SW_1
		
	/** If switch 2 is pressed then the currsor has to move from hour to min to sec **/
		if(IsPress(sw_2))	
		{
			flag++;
			(flag == 7)?(flag = 0):flag;
			while(IsPress(sw_2))
			{
					if(IsPress(sw_2))
							break;
					for(i=90*12000;i>=0;i--)
					{
						if(IsPress(sw_2))
							break;
					}
					dis_tm;
					for(i=50*12000;i>=0;i--)
					{
							if(IsPress(sw_2))
							break;
					}
			} // while
		} // if
		
					pos(flag)
					dis_tm
		
					for(i=50*12000;i>=0;i--)
					{
							if(IsPress(sw_1)|| IsPress(sw_2)  || IsPress(sw_3) )
								break;					
					}
/**** If switch 3 is pressed then current mode is jump to next mode ***/
		if(IsPress(sw_3) && st==0)
		{
			while(IsPress(sw_3))
			{
					pos(flag)
					dis_tm
			}
				if(am())
				return 1;
		}

	} // while
	
}

int main()
{
		int j,i;
		init_rtc();	//	INITIALISING RTC
		init_lcd();	//	INITIALISING LCD
		cmdlcd(0x40); // Switching to CGRAM to store user defined symbols
		for(j=0;j<8;j++)
		CharLCD(alaram_symbol[j]);
		IODIR1 |=1<<19; // Direction for alarm
	
	/*** Pre setting RTC time with some values ***/
		HOUR = 2;
		MIN = 24;
		SEC = 40;
		DOM = 4;
		MONTH = 2;
		YEAR = 2025;
		DOW = 2;
/*** Pres setting  Alarm with RTC values ***/
		hour = HOUR;
		min =MIN;
		sec = 0;
		dom = DOM;
		month = MONTH;
		year = YEAR;

		SUPERLOOP
		{	
						dis_tm;	// Displaying RTC 
						if(IsPress(sw_3))	// If switch is pressed it jumps to RTC edit mode
						{	
							while(IsPress(sw_3))
							{
								dis_tm;
							}
							if(st==0)
							fun();
							cmdlcd(0x01);
							while(IsPress(sw_3))
							{
								dis_tm;
							}
						}
						for(j=0;j<time_i;j++)	//	Checking for Alarms
						{	
							if(time[j][7])			//	Checking for wheather Alarm is on or off
							{
								if(time[j][6]==1) // Alarm happens daily until user delete
								{
									if(time[j][0]==HOUR)
										{
											if(time[j][1]==MIN)
												{
													if(time[j][2]==SEC)
													{
														cmdlcd(0x01);
														while(1)
														{
															cmdlcd(0x80);
															strlcd("TIME TO TAKE");
															cmdlcd(0xc0);
															strlcd("MEDICINE");
															IOSET1 = 1 <<19;
															if(IsPress(sw_3))
															{
																while(IsPress(sw_3));
																//alaram = 0;
																IOCLR1 = 1 << 19;
																break;
															}
														}	// while
													}
												}
											}
												
								}	// if (DAILY--);
							
								if(time[j][6]==0) // Alarm Ring once after set 
								{
									if(time[j][5]==YEAR)
									{
										if(time[j][4]==MONTH)
										{
											if(time[j][3]==DOM)
											{
												if(time[j][0]==HOUR)
												{
													if(time[j][1]==MIN)
														{
															if(time[j][2]==SEC)
															{
																	/** Automatically Deleted after succesfful alarm ring **/
																	memmove(time + j, time + j + 1, (ROW - j - 1) * COL * sizeof(int));
																	time_i--;
																	cmdlcd(0x01);
																	while(1)
																	{
																		cmdlcd(0x80);
																		strlcd("TIME TO TAKE");
																		cmdlcd(0xc0);
																		strlcd("MEDICINE");
																		IOSET1=1<<19;
																		for(i=90*12000;i>=0;i--)
																		{
																			if(IsPress(sw_3))
																				break;
																		}
																		IOCLR1=1<<19;
																		for(i=90*12000;i>=0;i--)
																		{
																			if(IsPress(sw_3))
																				break;
																		}
																		if(IsPress(sw_3))	//	Waiting for switch press to stop the alarm
																		{
																			while(IsPress(sw_3));
																			//alaram = 0;
																			if(((1 << 19)&IOPIN1))
																			IOCLR1 = 1 << 19;
																			break;
																		}
																	}	// while
																}	// SEC
															}// MIN
														}	//HOUR
													}	// DAY
												}	//	MONTH
											}	//YEAR
										} // once
									}	// ALARAM SET
								} //for
						
					
		}
}
