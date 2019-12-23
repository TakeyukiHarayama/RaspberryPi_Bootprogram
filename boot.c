#include<stdio.h>
#include<string.h>
#include<wiringPi.h>

#define RELAY_PORT 17
#define HIGH 1
#define LOW 0

int main(int argc, char *argv[]){
	int time = 500;
	char *forced_shutdown = "--force";

	if(wiringPiSetupGpio() == -1){
		return 1;
	}
	pinMode(RELAY_PORT, OUTPUT);
	if(argc > 1 && strcmp(argv[1], forced_shutdown) == 0){
		time = 1000;
	}

	digitalWrite(RELAY_PORT, HIGH);
	delay(time);
	digitalWrite(RELAY_PORT, LOW);

	return 0;
}
