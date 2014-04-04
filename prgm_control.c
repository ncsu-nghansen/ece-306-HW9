#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"


volatile int LeftMotorPower = 0;
volatile int RightMotorPower = 0;
int ProgramState = 0;
int OldState = -1;

char IsLight = 1;
char WasLight = 1;

void Control_Process(void)
{
	ProgramState = ADC_Thumb/511; //Three distinct states
                  //"0123456789abcdef"
	display_2 = "                ";
	
	switch(ProgramState)
	{
		case 0:
					//	"0123456789abcdef"
			display_1 = " Resistor Codes ";  
                        display_2 = "                ";
			break;
		case 1: 
					//	"0123456789abcdef"
			display_1 = "     Shapes     ";
                        display_2 = "                ";
			break;
		case 2:
					//	"0123456789abcdef"
			display_1 = "      Song      ";
                        display_2 = "                ";
			break;
		default:
					//	"0123456789abcdef"
			display_1 = "  OUT OF RANGE  ";
                        display_2 = "                ";
			break;
	}
}