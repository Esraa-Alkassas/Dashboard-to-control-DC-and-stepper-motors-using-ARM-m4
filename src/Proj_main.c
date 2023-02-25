/*
 * Proj_main.c
 *
 *  Created on: Jan 27, 2023
 *      Author: Lenovo
 */
// what is remained for me in this code is only the 7 seg//////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************************/
/*                                           STD_TYPES_LIB_INCLUDE                                           */
/************************************************************************************************************/

//if you try this project and doesn't behave well, check any line you contains theses functions
//void MGPIO_voidSetPortValue (MGPIOx_t Copy_uddtPortNum, u8 Copy_u8PortValue);
//void MGPIO_voidSetFirstHalfPortValue (MGPIOx_t Copy_uddtPortNum, u8 Copy_u8PortValue);
//because i have changed the names of them but i'm not sure if i have changed every line contiains them...



#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"


/***************************************************************************************/
/*                          MCAL Lower Layer interface files                           */
/***************************************************************************************/
#include "MRCC_interface.h"     // Rcc included to enable GPIO Peripheral clock & to init system clock
#include "MGPIO_interface.h"
#include "SYS_interface.h"


/***************************************************************************************/
/*                          HAL Lower Layer interface files                            */
/***************************************************************************************/
//#include "SYS_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "KPD_interface.h"



// application : writing my name on the LCD
int main ()
{
	//u8 u8_KeyPressed;

	u8 keyyyy;
	u8 keyyy;
	u8 keyy;
	u8 key;
	u8 pass[3];
	u8 count =0;
	u8 R_pass [3] = {'2','4','5'} ;
	u8 flag=1;
	u8 flagg=1;
	u8 flaggg =1;
	u8 z =0;


	MRCC_voidInitSystemCloak ();
	MRCC_voidEnablePeripheralCloak(AHB1, MRCC_PERIPHERIAL_EN_GPIOA);
	MRCC_voidEnablePeripheralCloak(AHB1, MRCC_PERIPHERIAL_EN_GPIOB);
	MRCC_voidEnablePeripheralCloak(AHB1, MRCC_PERIPHERIAL_EN_GPIOC);

	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN0,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN1,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN2,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN3,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN4,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN5,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN6,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN7,  MGPIO_PIN_OUTPUT);



	MGPIO_voidSetPinMode (MGPIO_PORTA, LCD_RS_PIN,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTA, LCD_RW_PIN,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTA,LCD_E_PIN ,  MGPIO_PIN_OUTPUT);



	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN0 ,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN1 ,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN2 ,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN3 ,  MGPIO_PIN_OUTPUT);


	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN4 ,  MGPIO_PIN_INPUT);
	MGPIO_voidSetPinPullType (MGPIO_PORTA, PIN4, MGPIO_PIN_PULL_UP);


	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN5 ,  MGPIO_PIN_INPUT);
	MGPIO_voidSetPinPullType (MGPIO_PORTA, PIN5, MGPIO_PIN_PULL_UP);


	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN6 ,  MGPIO_PIN_INPUT);
	MGPIO_voidSetPinPullType (MGPIO_PORTA, PIN6, MGPIO_PIN_PULL_UP);

	MGPIO_voidSetPinMode (MGPIO_PORTA,PIN7 ,  MGPIO_PIN_INPUT);
	MGPIO_voidSetPinPullType (MGPIO_PORTA, PIN7, MGPIO_PIN_PULL_UP);

	/* buzzer for 7rami!!*/
	MGPIO_voidSetPinMode (MGPIO_PORTC, PIN15,  MGPIO_PIN_OUTPUT);
	// blinking leds for 7ramii
//	MGPIO_voidSetPinMode (MGPIO_PORTC, PIN14,  MGPIO_PIN_OUTPUT);
//	MGPIO_voidSetPinMode (MGPIO_PORTC, PIN13,  MGPIO_PIN_OUTPUT);


	/* motor pin output  */
	MGPIO_voidSetPinMode (MGPIO_PORTA, PIN11,  MGPIO_PIN_OUTPUT);
	//MGPIO_voidSetPinMode (MGPIO_PORTB, PIN8,  MGPIO_PIN_OUTPUT);
	//MGPIO_voidSetPinOutputType (MGPIO_PORTA, PIN11, MGPIO_OPEN_DDRAIN);


	/* Buzzer output */
	MGPIO_voidSetPinMode (MGPIO_PORTA, PIN12,  MGPIO_PIN_OUTPUT);

	/* led output */
	MGPIO_voidSetPinMode (MGPIO_PORTA, PIN15,  MGPIO_PIN_OUTPUT);

	/* 7 seg pins output */
	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN8,  MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN9,  MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN10,  MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN12,  MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN13,  MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN14,  MGPIO_PIN_OUTPUT);
	MGPIO_voidSetPinMode (MGPIO_PORTB, PIN15,  MGPIO_PIN_OUTPUT);


#define zero    0b0111111                          //0x3f      // number will differ here because i will put bit11 in the register with 0 because there is no pin11 in portb
#define one     0b0000110                          //0x06
#define two     0b10110011                          //0x5B
#define three   0b10010111                          // 0x4F

	u8 arr[4] ={zero, one, two, three};



	/* Init LCD */
	HLCD_vidInit();
	MSTK_voidDelay_ms(1);
	HLCD_vidGoToXY (0,0);
	HLCD_vidWriteStr ("Welcome to");
	HLCD_vidGoToXY (0,1);
	HLCD_vidWriteStr ("our Dashboard!");

	MSTK_voidDelay_ms(10000);
	HLCD_vidsendCMD (0x01);
	HLCD_vidGoToXY (0,0);
	HLCD_vidWriteStr ("Enter Password");
	HLCD_vidGoToXY (0,1);
	MSTK_voidDelay_ms(1);


	while(1)
	{
		//MGPIO_voidSetSecHalfValuePort (MGPIO_PORTB, zero);
		key = KPD_u8GetPressedKey ();

		if (key!= NOT_PRESSED)
		{

				if (key != '=' && count <=2)
					{
						HLCD_vidsendChar ('*');
						pass [count] = key;
						count++;
					}

				else if (key == '=' && pass [0] != '2' && pass [1] != '4' && pass [2] != '5')
				{
						z +=1;
						MGPIO_voidSetSecHalfValuePort (MGPIO_PORTB, arr[z]);
						count =0;
						HLCD_vidsendCMD (0x01);
						HLCD_vidGoToXY (0,0);
						HLCD_vidWriteStr ("Wrong Password");
						HLCD_vidGoToXY (0,1);
						HLCD_vidWriteStr ("Try again..");
						MSTK_voidDelay_ms(10000);
						HLCD_vidsendCMD (0x01);

						//MGPIO_voidSetSecHalfValuePort (MGPIO_PORTB, arr[z]);
				}

				if (z == 3)
				{
					HLCD_vidsendCMD (0x01);
					HLCD_vidGoToXY (0,0);
					HLCD_vidWriteStr ("You have 0 attempts left!");
					HLCD_vidGoToXY (0,1);
					HLCD_vidWriteStr ("7Ramii!!!!!");
					// buzzer on here
					MGPIO_voidSetPinValue (MGPIO_PORTC, PIN15, MGPIO_PIN_HIGH);
				}

				if(key == '=' && pass [0] == '2' && pass [1] == '4' && pass [2] == '5')
				{
//					count =0;
//					HLCD_vidsendCMD (0x01);
//					MSTK_voidDelay_ms(10);
//					HLCD_vidGoToXY (0,0);
//					HLCD_vidWriteStr ("1-DCM");
//					HLCD_vidGoToXY (9,0);
//					HLCD_vidWriteStr ("2-stepper");
//					HLCD_vidGoToXY (9,1);
//					HLCD_vidWriteStr ("3-Led");
//					HLCD_vidGoToXY (5,1);
//					HLCD_vidWriteStr ("4-BUZZER");
//					flag =1;

					count =0;
					HLCD_vidsendCMD (0x01);
					MSTK_voidDelay_ms(10);
					HLCD_vidGoToXY (0,0);
					HLCD_vidWriteStr ("1-DCM");
					HLCD_vidGoToXY (8,0);
					HLCD_vidWriteStr ("2-Buzzer");
					HLCD_vidGoToXY (0,1);
					HLCD_vidWriteStr ("3-Led");
					flag =1;


					//switch ()
					while (flag !=0)
					{
						keyy = KPD_u8GetPressedKey ();

					if (keyy!= NOT_PRESSED)
					{

					if (keyy == '1')
					{
						HLCD_vidsendCMD (0x01);
						MSTK_voidDelay_ms(10);
						HLCD_vidGoToXY (0,0);
						HLCD_vidWriteStr ("1-ON");
						HLCD_vidGoToXY (9,0);
						HLCD_vidWriteStr ("2-OFF");
						HLCD_vidGoToXY (0,1);
						HLCD_vidWriteStr ("3-Back..");
						flagg =1;
						while (flagg !=0)
						{
							keyyy = KPD_u8GetPressedKey ();

							if (keyyy!= NOT_PRESSED)
							{

							if (keyyy == '1')
							{
								HLCD_vidsendCMD (0x01);
								MSTK_voidDelay_ms(10);
								HLCD_vidGoToXY (0,0);
								HLCD_vidWriteStr ("Motor on");
								MGPIO_voidSetPinValue (MGPIO_PORTA, PIN11, MGPIO_PIN_HIGH);

							}

							else if (keyyy=='2')
							{
								HLCD_vidsendCMD (0x01);
								MSTK_voidDelay_ms(10);
								HLCD_vidGoToXY (0,0);
								HLCD_vidWriteStr ("Motor off");
								MGPIO_voidSetPinValue (MGPIO_PORTA, PIN11, MGPIO_PIN_LOW);


							}
							else if (keyyy =='3')
							{
//								HLCD_vidsendCMD (0x01);
//								MSTK_voidDelay_ms(10);
//								HLCD_vidGoToXY (0,0);
//								HLCD_vidWriteStr ("1-DCM");
//								HLCD_vidGoToXY (9,0);
//								HLCD_vidWriteStr ("2-stepper");
//								HLCD_vidGoToXY (9,1);
//								HLCD_vidWriteStr ("3-Led");
//								HLCD_vidGoToXY (5,1);
//								HLCD_vidWriteStr ("4-BUZZER");
//								flagg =0;


								HLCD_vidsendCMD (0x01);
								MSTK_voidDelay_ms(10);
								HLCD_vidGoToXY (0,0);
								HLCD_vidWriteStr ("1-DCM");
								HLCD_vidGoToXY (8,0);
								HLCD_vidWriteStr ("2-Buzzer");
								HLCD_vidGoToXY (0,1);
								HLCD_vidWriteStr ("3-Led");
								flagg =0;


							}
							else
							{
								//do nothing
							}

						}
						}

					}


					  else if (keyy =='2')
					  {
					  	HLCD_vidsendCMD (0x01);
						MSTK_voidDelay_ms(10);
						HLCD_vidGoToXY (0,0);
						HLCD_vidWriteStr ("1-ON");
						HLCD_vidGoToXY (9,0);
						HLCD_vidWriteStr ("2-OFF");
						HLCD_vidGoToXY (0,1);
						HLCD_vidWriteStr ("3-Back..");
						flagg=1;
						while (flagg !=0)
						{
							keyyy = KPD_u8GetPressedKey ();

							if (keyyy!= NOT_PRESSED)
							{

							if (keyyy == '1')
							{
								HLCD_vidsendCMD (0x01);
								MSTK_voidDelay_ms(10);
								HLCD_vidGoToXY (0,0);
								HLCD_vidWriteStr ("Buzzer on");
								MGPIO_voidSetPinValue (MGPIO_PORTA, PIN12, MGPIO_PIN_HIGH);
							}

							else if (keyyy=='2')
							{
								HLCD_vidsendCMD (0x01);
								MSTK_voidDelay_ms(10);
								HLCD_vidGoToXY (0,0);
								HLCD_vidWriteStr ("Buzzer off");
								MGPIO_voidSetPinValue (MGPIO_PORTA, PIN12, MGPIO_PIN_LOW);

							}
							else if (keyyy =='3')
						{
//								HLCD_vidsendCMD (0x01);
//								MSTK_voidDelay_ms(10);
//								HLCD_vidGoToXY (0,0);
//								HLCD_vidWriteStr ("1-DCM");
//								HLCD_vidGoToXY (9,0);
//								HLCD_vidWriteStr ("2-stepper");
//								HLCD_vidGoToXY (9,1);
//								HLCD_vidWriteStr ("3-Led");
//								HLCD_vidGoToXY (5,1);
//								HLCD_vidWriteStr ("4-BUZZER");
//								flagg =0;


								HLCD_vidsendCMD (0x01);
								MSTK_voidDelay_ms(10);
								HLCD_vidGoToXY (0,0);
								HLCD_vidWriteStr ("1-DCM");
								HLCD_vidGoToXY (8,0);
								HLCD_vidWriteStr ("2-Buzzer");
								HLCD_vidGoToXY (0,1);
								HLCD_vidWriteStr ("3-Led");
								flagg =0;

							}
							else
							{
								//do nothing
							}

						}
						}
					  }
					  else if (keyy =='3')
					  {
					  	HLCD_vidsendCMD (0x01);
						MSTK_voidDelay_ms(10);
						HLCD_vidGoToXY (0,0);
						HLCD_vidWriteStr ("1-ON");
						HLCD_vidGoToXY (9,0);
						HLCD_vidWriteStr ("2-OFF");
						HLCD_vidGoToXY (0,1);
						HLCD_vidWriteStr ("3-Back..");
						flagg=1;
						while (flagg !=0)
						{
							keyyy = KPD_u8GetPressedKey ();

							if (keyyy!= NOT_PRESSED)
							{

							if (keyyy == '1')
							{
								HLCD_vidsendCMD (0x01);
								MSTK_voidDelay_ms(10);
								HLCD_vidGoToXY (0,0);
								HLCD_vidWriteStr ("led on");
								MGPIO_voidSetPinValue (MGPIO_PORTA, PIN15, MGPIO_PIN_HIGH);
							}

							else if (keyyy=='2')
							{
								HLCD_vidsendCMD (0x01);
								MSTK_voidDelay_ms(10);
								HLCD_vidGoToXY (0,0);
								HLCD_vidWriteStr ("led off");
								MGPIO_voidSetPinValue (MGPIO_PORTA, PIN15, MGPIO_PIN_LOW);

							}
							else if (keyyy =='3')
							{
//								HLCD_vidsendCMD (0x01);
//								MSTK_voidDelay_ms(10);
//								HLCD_vidGoToXY (0,0);
//								HLCD_vidWriteStr ("1-DCM");
//								HLCD_vidGoToXY (9,0);
//								HLCD_vidWriteStr ("2-stepper");
//								HLCD_vidGoToXY (9,1);
//								HLCD_vidWriteStr ("3-Led");
//								HLCD_vidGoToXY (5,1);
//								HLCD_vidWriteStr ("4-BUZZER");
//								flagg =0;


								HLCD_vidsendCMD (0x01);
								MSTK_voidDelay_ms(10);
								HLCD_vidGoToXY (0,0);
								HLCD_vidWriteStr ("1-DCM");
								HLCD_vidGoToXY (8,0);
								HLCD_vidWriteStr ("2-Buzzer");
								HLCD_vidGoToXY (0,1);
								HLCD_vidWriteStr ("3-Led");
								flagg =0;

							}
							else
							{
								//do nothing
							}

						}
						}
					  }

					  else if (keyy =='4')
					  {
							HLCD_vidsendCMD (0x01);
							flag =0;
							HLCD_vidWriteStr ("Welcome to");
							HLCD_vidGoToXY (0,1);
							HLCD_vidWriteStr ("our Dashboard!");

							MSTK_voidDelay_ms(10000);
							HLCD_vidsendCMD (0x01);
							HLCD_vidGoToXY (0,0);
							HLCD_vidWriteStr ("Enter Password");
							HLCD_vidGoToXY (0,1);
							MSTK_voidDelay_ms(1);
					  }

					}
					}





//					while (flaggg !=0)
//					{
//						keyyy = KPD_u8GetPressedKey ();
//
//						if (keyyyy!= NOT_PRESSED)
//						{
//
//						if (keyyyy == '2')
//						{
//							HLCD_vidsendCMD (0x01);
//							MSTK_voidDelay_ms(10);
//							HLCD_vidGoToXY (0,0);
//							HLCD_vidWriteStr ("Buzzer on");
//							MGPIO_voidSetPinValue (MGPIO_PORTA, PIN12, MGPIO_PIN_HIGH);
//						}
//
//						else if (keyyyy=='2')
//						{
//							HLCD_vidsendCMD (0x01);
//							MSTK_voidDelay_ms(10);
//							HLCD_vidGoToXY (0,0);
//							HLCD_vidWriteStr ("Buzzer off");
//							MGPIO_voidSetPinValue (MGPIO_PORTA, PIN12, MGPIO_PIN_LOW);
//
//						}
//						else if (keyyy =='3')
//						{
//							flaggg =0;
//
//						}
//						else
//						{
//							//do nothing
//						}
//
//					}
//					}


				//	}
				//	else if (keyy == '2')
				//	{

						//MGPIO_voidSetPinValue (MGPIO_PORTA, PIN12, MGPIO_PIN_HIGH);
//						DIO_vidSetPinVal (DIO_PORTA, DIO_PIN0, DIO_LOW);
//						DIO_vidSetPinVal (DIO_PORTA, DIO_PIN2, DIO_HIGH);
//						HLCD_vidGoToXY (0,1);
//						HLCD_vidsendChar (' ');
//
//
//						HLCD_vidGoToXY (8,1);
//						HLCD_vidsendChar (0);
//						HLCD_vidSaveInCGRAM ();




				//	else if (keyy == '3')
				//	{
				//		DIO_vidSetPinVal (DIO_PORTA, DIO_PIN0, DIO_LOW);
				//		DIO_vidSetPinVal (DIO_PORTA, DIO_PIN2, DIO_LOW);
				//		flag=0;
				//		HLCD_vidsendCMD (0x01);
				//	}






		}
			}

	}
}


















//while (1)
//{


//		u8_KeyPressed = KPD_u8GetPressedKey ();
//		if(u8_KeyPressed != NOT_PRESSED)
//		{
//			HLCD_vidsendChar (u8_KeyPressed);
//		}


//		while (KPD_u8GetPressedKey ()==NOT_PRESSED);
//		HLCD_vidsendChar (KPD_u8GetPressedKey ());
//}
