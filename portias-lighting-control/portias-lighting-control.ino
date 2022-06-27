#include <TeensyDMX.h>

namespace teensydmx = ::qindesign::teensydmx;

teensydmx::Sender dmxTx{Serial1};

void setup() {

	for(int i = 14; i < 24; i++) {
		pinMode(i, INPUT_PULLUP);
	}
	pinMode(13, OUTPUT);
	dmxTx.begin();
}

void loop() {
	digitalWrite(13, HIGH);
	dmxTx.set(2, 255);
	delay(1000);
	digitalWrite(13, LOW);
	dmxTx.set(2, 0);
	delay(1000);
}
