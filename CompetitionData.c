#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{

}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////



//============================================| TASK DRIVE |============================================
task Drive()
{
	while(true)
  {
		motor[RwheelL]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
		motor[FwheelL]  = (vexRT[Ch1] + vexRT[Ch2])/2;  // (y + x)/2
		motor[RwheelR] = (vexRT[Ch2] - vexRT[Ch1])/-2;  // (y - x)/2
		motor[FwheelR] = (vexRT[Ch1] - vexRT[Ch2])/2;   // (y - x)/2
	}
}
//====================================================================================================

//============================================| TASK LIFT |============================================
task Lift()
{
	while(true)
	{
    if(vexRT[Btn6UXmtr2] == 1)
    {
      motor[liftL] = 127;
      motor[liftR] = 127;
    }
    else
    {
      if(vexRT[Btn6DXmtr2] == 1)
     {
         motor[liftL] = -127;
         motor[liftR] = -127;
     }
    else
     {
      motor[liftL] = 0;
      motor[liftR] = 0;     }
	 }
	}
}
//====================================================================================================

//==========================================|Task Throw|==============================================
task throw()
{
	while(true)
  {
		if(vexRT[Btn7R] == 1)
		{
			SensorValue[solenoid1] = 1;
	  }
	  else
	  {
	  	SensorValue[solenoid1] = 0;
	  }
	}
}
//====================================================================================================
//==========================================|Task Bar|==============================================
task bar()
{
	while(true)
	{
		if(vexRT[Btn7UXmtr2] == 1)
		{
			SensorValue[solenoid2] = 1;
	  }
	  else
	  {
	  	SensorValue[solenoid2] = 0;
	  }
  }
}
//==========================================|Task Spin|==============================================
task spin()
{
	while(true)
  {
	 if(vexRT[Btn5UXmtr2] == 1)
		{
		  motor(whiskL) = 127;
		  motor(whiskR) = -127;
	  }
	 else
    {
    if(vexRT[Btn5DXmtr2] == 1)
     {
	  	motor(whiskL) = -127;
	  	motor(whiskR) = 127;
	   }
	  else if(vexRT[Btn8LXmtr2] == 1)
	   {
		  motor(whiskL) = 0;
		  motor(whiskR) = 0;
	   }
    }
	 }
}

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
	  StartTask(Drive);   /*driver 1*/
		StartTask(Lift);   /*driver 2*/
  	StartTask(throw);	/*driver 1*/
		StartTask(bar);		/*driver 2*/
		StartTask(spin);	/*driver 2*/
	}
}
