#pragma config(Sensor, dgtl1,  Piston,         sensorDigitalOut)
#pragma config(Sensor, dgtl2,  Piston2,        sensorDigitalOut)
#pragma config(Motor,  port2,           BrightMotor,   tmotorVex393, openLoop)
#pragma config(Motor,  port3,           BleftMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port4,           lift1,         tmotorVex393, openLoop)
#pragma config(Motor,  port5,           lift2,         tmotorVex393, openLoop)
#pragma config(Motor,  port6,           Spin1,         tmotorVex393, openLoop)
#pragma config(Motor,  port7,           Spin2,         tmotorVex393, openLoop)
#pragma config(Motor,  port8,           L1,            tmotorVex393, openLoop)
#pragma config(Motor,  port9,           R2,            tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
Project Title:
Team Members:                                                                                                                                                                                                                                                                                                                                         chris is the best
Date:b
Section:


Task Description:


Pseudocode: Is for Squares.

*/



//============================================| TASK DRIVE |============================================
task Drive()
{
	while(true)
  {
		motor[BleftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
		motor[L1]  = (vexRT[Ch1] + vexRT[Ch2])/2;  // (y + x)/2
		motor[BrightMotor] = (vexRT[Ch2] - vexRT[Ch1])/-2;  // (y - x)/2
		motor[R2] = (vexRT[Ch1] - vexRT[Ch2])/2;   // (y - x)/2
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
      motor[lift1] = 127;
      motor[lift2] = 127;
    }
    else
    {
      if(vexRT[Btn6DXmtr2] == 1)
     {
         motor[lift1] = -127;
         motor[lift2] = -127;
     }
    else
     {
      motor[lift1] = 0;
      motor[lift2] = 0;
     }
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
			SensorValue[Piston] = 1;
	  }
	  else
	  {
	  	SensorValue[Piston] = 0;
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
			SensorValue[Piston2] = 1;
	  }
	  else
	  {
	  	SensorValue[Piston2] = 0;
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
		  motor(Spin1) = 127;
		  motor(Spin2) = -127;
	  }
	 else
    {
    if(vexRT[Btn5DXmtr2] == 1)
     {
	  	motor(Spin1) = -127;
	  	motor(Spin2) = 127;
	   }
	  else if(vexRT[Btn8LXmtr2] == 1)
	   {
		  motor(Spin1) = 0;
		  motor(Spin2) = 0;
	   }
    }
	 }
}
//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++

task main()
{
while(1==1)
 {
  StartTask(Drive);   /*driver 1*/
	StartTask(Lift);   /*driver 2*/
  StartTask(throw);	/*driver 1*/
	StartTask(bar);		/*driver 2*/
	StartTask(spin);	/*driver 2*/
 }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
