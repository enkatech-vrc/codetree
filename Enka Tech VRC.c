#pragma config(Sensor, in4,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Sensor, in5,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Sensor, in6,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, dgtl1,  mainswitch,     sensorTouch)
#pragma config(Sensor, dgtl4,  range,          sensorSONAR_cm)
#pragma config(Sensor, dgtl11, but1,           sensorTouch)
#pragma config(Motor,  port1,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port6,           clawM,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           gripperM,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           wristM,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           mainarmM,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int state = 1;
int up = 127;
int non = 0;
int dw = -127;
// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{



	AutonomousCodePlaceholderForTesting();
}


task usercontrol()
{
	while(true){

	//Ultrasonic Sensor for autonomous
		while(SensorValue(range)> 50 )
		{
			motor[rightMotor] = dw;
			motor[leftMotor] = dw;
		}
		while (state == 1)
		{

		//Emergency button state
			if(SensorValue(but1) == 1)
			{
				state = !state;
			}
			motor[leftMotor]  = -(vexRT[Ch3]);
			motor[rightMotor] = -(vexRT[Ch2]);
			UserControlCodePlaceholderForTesting();

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


			//Main Arm
			if(SensorValue(mainswitch) == 1)
			{
				motor[mainarmM] = dw;
				delay(500);
				motor[mainarmM] = non;
			}
			else{
				if (vexRT[Btn8U] == 1)
				{
					motor[mainarmM] = up;
				}
				else if (vexRT[Btn8D] ==1)
				{
					motor[mainarmM] = dw;
				}
				else
				{
					motor[mainarmM] = non;
				}
			}


			// Wrist Motion
			if (vexRT[Btn8R] == 1)
			{
				motor[wristM] = up;
			}
			else if (vexRT[Btn8L] == 1)
			{
				motor[wristM] = dw;
			}
			else
			{
				motor[wristM] = non;
			}

			// Gripper Motion
			if (vexRT[Btn5D] == 1)
			{
				motor[gripperM] = up;
			}
			else if (vexRT[Btn5U] ==1)
			{
				motor[gripperM] = dw;
			}
			else
			{
				motor[gripperM] = non;
			}



			// Super Spin
			if (vexRT[Btn7L] == 1)
			{
				motor[rightMotor] = up;
				motor[leftMotor] = dw;

				delay(1100);
			}
			else if(vexRT[Btn7R] == 1)
			{
				motor[leftMotor] = up;
				motor[rightMotor] = dw;
				delay(1100);
			}
			else
			{
				motor[rightMotor] = non;
				motor[leftMotor] = non;
			}

		}

while(vexRT(Btn7D) == 1)
{
  wait1Msec(2000);          // The program waits for 2000 milliseconds before continuing.

  int threshold = 505;      /* found by taking a reading on both DARK and LIGHT    */
                            /* surfaces, adding them together, then dividing by 2. */
  while(true)
  {


    // RIGHT sensor sees dark:
    if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      // counter-steer right:
      motor[leftMotor]  = 30;
      motor[rightMotor] = -30;
    }
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // go straight
      motor[leftMotor]  = 30;
      motor[rightMotor] = 30;
    }
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = -30;
      motor[rightMotor] = 30;
    }
  }
}
		// Emergency button auto motor down
		motor[leftMotor]  = 0;
		motor[rightMotor] = 0;
		motor[gripperM]  = 0;
		motor[mainarmM] = 0;
		motor[clawM]  = 0;
}}
