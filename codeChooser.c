#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)

const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}

void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}

task main(){
	int count = 0;
	clearLCDLine(0);
	clearLCDLine(1);
	while(nLCDButtons != centerButton){
		switch(count){
		case 0:
			displayLCDCenteredString(0, "Autonomous 1");
			displayLCDCenteredString(1, "<<--Enter-->>");
			waitForPress();
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count = 3;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 1:
			displayLCDCenteredString(0, "Autonomous 2");
			displayLCDCenteredString(1, "<<--Enter-->>");
			waitForPress();
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 2:
			displayLCDCenteredString(0, "Autonomous 3");
			displayLCDCenteredString(1, "<<--Enter-->>");
			waitForPress();
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count++;
			}
			break;
		case 3:
			displayLCDCenteredString(0, "Autonomous 4");
			displayLCDCenteredString(1, "<<--Enter-->>");
			waitForPress();
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				count = 0;
			}
			break;
		default:
			count = 0;
			break;
		}
	}
}
