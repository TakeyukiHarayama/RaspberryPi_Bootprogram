#include<stdio.h>
#include<string.h>
#include<wiringPi.h>

#define RELAY_PORT 17

int main(int argc, char *argv[]){
	int time = 500;
	char *forced_shutdown = "--force";

	if(wiringPiSetupGpio() == -1){
		return 1;
	}
	pinMode(RELAY_PORT, OUTPUT);
	if(strcmp(argv[1], forced_shutdown) == 0){
		time = 1000;
	}

	digitalWrite(RELAY_PORT, 1);
	delay(time);
	digitalWrite(RELAY_PORT, 0);

	return 0;
}
