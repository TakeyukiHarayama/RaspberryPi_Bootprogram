#include<stdio.h>
#include<wiringPi.h>

#define LED_PORT 17

int main(int argc, char *argv[]){
	int i, time;

	if(wiringPiSetupGpio() == -1) return 1;
	pinMode(LED_PORT, OUTPUT);

	if(argc == 1) time = 500;
	if(argc == 2) time = 1000;

	digitalWrite(LED_PORT, 1);
	delay(time);

	digitalWrite(LED_PORT, 0);

	for(i=0; i < 10; i++){
		digitalWrite(4, 1);
		delay(time);
		digitalWrite(4, 0);
		delay(time);
	}
	return 0;
}
