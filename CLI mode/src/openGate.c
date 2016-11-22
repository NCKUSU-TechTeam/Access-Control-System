#include <stdio.h>
#include <wiringPi.h>

// Check out the id by `gpio readall`, and using wPi as id.
#define LED 8

int main(void)
{
	printf("Access Control receive the signal!\n");

	wiringPiSetup();
	pinMode(LED,OUTPUT);

	printf("Prepare to open the gate!\n");
	// Turn oh the GPIO, open the gate.
	digitalWrite(LED,HIGH);
	delay(5000);
	printf("Now shut down the gate.\n");
	digitalWrite(LED,LOW);

	return 0;
}
