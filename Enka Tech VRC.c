#pragma config(Motor,  port1,           rightM,        tmotorNone, openLoop)
#pragma config(Motor,  port2,           leftM,         tmotorNone, openLoop)
#pragma config(Motor,  port3,           clawM,         tmotorNone, openLoop)
#pragma config(Motor,  port4,           gripperM,      tmotorNone, openLoop)
int up = 127;
int non = 0;
int dw = -127;

#pragma platform(VEX2)

#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"


void pre_auton()
{

	bStopTasksBetweenModes = true;
}


task autonomous()
{

	AutonomousCodePlaceholderForTesting(); // remove when your code done
}


task usercontrol()
{
	while (true)
	{
		// Tank Drive
		motor[rightM] = vexRT[Ch2]; // Sag motor joystick(CH2) ile baglandi.
		motor[leftM] = vexRT[Ch2]; //Sol motor joystick(CH3) ile baglandi.

		//Claw Motion
		if (vexRT[Btn6U] == 1)
		{
			motor[clawM] = up;
		}
		else if (vexRT[Btn6D] ==1)
		{
			motor[clawM] = dw;
		}
		else
		{
			motor[clawM] = non;
		}

		// Gripper Motion
		if (vexRT[Btn5U] == 1)
		{
			motor[gripperM] = up;
		}
		else if (vexRT[Btn5D] ==1)
		{
			motor[gripperM] = dw;
		}
		else
		{
			motor[gripperM] = non;
		}

		// Super Spin
		if (vexRT[Btn8D] == 1)
		{
			motor[rightM] = up;
			motor[leftM] = dw;
			delay(1000);
		}
		else
		{
			motor[rightM] = non;
			motor[leftM] = non;
		}

		UserControlCodePlaceholderForTesting(); // remove when your code done
	}
}
