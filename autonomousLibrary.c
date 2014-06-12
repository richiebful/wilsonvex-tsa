#pragma config(Sensor, dgtl1,  solenoid1,       sensorDigitalOut)
#pragma config(Sensor, dgtl2, solenoid2, 				sensorDigitalOut)
#pragma config(Motor,  port9,           FwheelR,        tmotorVex269, openLoop)
#pragma config(Motor,  port4,           liftL,         tmotorVex269, openLoop)
#pragma config(Motor,  port5,           liftR,         tmotorVex269, openLoop)
#pragma config(Motor,  port8,           FwheelL,        tmotorVex269, openLoop)
#pragma config(Motor,  port6,           whiskL,        tmotorVex269, openLoop)
#pragma config(Motor,  port7,           whiskR,        tmotorVex269, openLoop)
#pragma config(Motor,  port2, 					RwheelL, 				tmotorVex296, openLoop)
#pragma config(Motor,  port3, 					RwheelR,			 tmotorVex296, openLoop)

int lift_speed = 50;
int lift_period = 2000;
int rightturn = 1000; //millis to execute right turn
int turnaround = -2000;
int leftturn = -1000;

void rotate(int check1){
	int wheel_setting = 20;
	if (check1 < 0){
		ClearTimer(T1);
		while (time1[T1] < check1){
			motor[RwheelL]=motor[FwheelL] = wheel_setting;
			motor[RwheelR] = motor[FwheelR] = -wheel_setting;
		}
		motor[RwheelR] = motor[FwheelR] = 0;
		motor[RwheelL] = motor[FwheelL] = 0;
  }
  else if(check1 > 0){
  	ClearTimer(T1);
  	while (time1[T1] < check1){
  		motor[RwheelL]= motor[FwheelL] = -wheel_setting;
  		motor[RwheelR] = motor[FwheelR] = wheel_setting;
  	}
  	motor[RwheelL] = motor[FwheelL] = 0;
  	motor[RwheelR] = motor[FwheelR] = 0;
	}
}

task deckUp(){
	motor[liftL] = lift_speed;
	motor[liftR] = -lift_speed;
	ClearTimer(T1);
	while(time1[T1] < lift_period){
		wait10Msec(10);
	}
	motor[liftL] = 0;
	motor[liftR] = 0;
}

void moveForward(int period){
	int wheel_setting = 50;
	motor[RwheelL] = motor[FwheelL] = -wheel_setting;
	motor[RwheelR] = motor[FwheelR] = wheel_setting;
	ClearTimer(T1);
	while(time1[T1] < period){
		wait10Msec(10);
	}
}

task deckDown(){
	motor[liftL] = -lift_speed;
	motor[liftR] = lift_speed;
	ClearTimer(T1);
	while(time1[T1] < lift_period){
		wait10Msec(10);
	}
	motor[liftL] = 0;
	motor[liftR] = 0;
}

void throw(void){
	SensorValue[solenoid2] = SensorValue[solenoid1] = 1;
	wait10Msec(50);
	SensorValue[solenoid2] = SensorValue[solenoid1] = 0;
}

void rotOut(int period){
	int rot_speed = 50;
	motor[whiskL] = -rot_speed;
	motor[whiskR] = rot_speed;
	ClearTimer(T1);
	while(time1[T1] < period){
		wait10Msec(10);
	}
	motor[whiskL] = motor[whiskR] = 0;
}

//rotates the whisks to bring balls in
void rotIn(int period){
	int rot_speed = 50;
	motor[whiskL] = rot_speed;
	motor[whiskR] = -rot_speed;
	ClearTimer(T1);
	while(time1[T1] < period){
		wait10Msec(10);
	}
	motor[whiskL] = motor[whiskR] = 0;
}


//all tasks are of form auto<autonomous-version><color><location>
//location is "A" for closest to bar, "B" for other position

task auto1blueA(){
	//setup: have it facing towards the blue hanging pole, parallel to the side
	//spin whisks inward left clockwise, right counter-c.
	int Ti1 = 2000;//time to get to gather bucky balls
	int Ti2 = 1000;//time tgt. alignment w/ back goal
	int Ti3 = 5000;//time tgt. back goals
	int Ti4 = 1000;//time to drop balls into goal
	rotIn(Ti1);
	moveForward(Ti1);
	rotate(rightturn);
	moveForward(Ti2);
	rotate(rightturn);
	moveForward(Ti3);
	StartTask(deckUp);
	rotOut(Ti4);
	rotate(turnaround);
	rotate(leftturn);
}

task auto1redA(){
	//setup: have it facing towards the blue hanging pole, parallel to the side
	//spin whisks inward left clockwise, right counter-c.
	int Ti1 = 2000;//time to get to gather bucky balls
	int Ti2 = 1000;//time tgt. alignment w/ back goal
	int Ti3 = 5000;//time tgt. back goals
	int Ti4 = 1000;//time to drop balls into goal
	rotIn(Ti1);
	moveForward(Ti1);
	rotate(rightturn);
	moveForward(Ti2);
	rotate(leftturn);
	moveForward(Ti3);
	StartTask(deckUp);
	rotOut(Ti4);
	rotate(turnaround);
	rotate(rightturn);
}

task auto2blueA(){
	int Ti1 = 1000;
	int Ti2 = 2000;//get Blue Ball
	int Ti3 = 3000;
	int Ti4 = 2400;
	int Ti5 = 2000;
	moveForward(Ti1);
	rotIn(Ti2);
	rotate(rightturn);
	moveForward(Ti3);
	StartTask(deckUp);
	throw();
	rotate(leftturn);
	moveForward(Ti4);
	rotate(turnaround);
	moveForward(Ti5);
}

task auto2redA(){
	int Ti1 = 1000;
	int Ti2 = 2000;//get Red Ball
	int Ti3 = 3000;
	int Ti4 = 2400;
	int Ti5 = 2000;
	moveForward(Ti1);
	rotIn(Ti2);
	rotate(leftturn);
	moveForward(Ti3);
	StartTask(deckUp);
	throw();
	rotate(rightturn);
	moveForward(Ti4);
	rotate(turnaround);
	moveForward(Ti5);
}

task main(){
	wait10Msec(100);
	StartTask(auto1blueA);
}
