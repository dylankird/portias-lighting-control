#include <TeensyDMX.h>

namespace teensydmx = ::qindesign::teensydmx;

teensydmx::Sender dmxTx{Serial1};

// Channels:
// 1 - Burnt out or not connected
// 2 - Backdrop lighting
// 3 - Burnt out or not connected
// 4 - Spotlight pointing at stage-left
// 5 - Another spotlight point at stage-left (but from further away)
// 6 - A spotlight pointing at the pillar all the way stage-left
// 7 - A spotlight pointing at the center of the stage from the very back of the room stage-right
// 8 - A spotlight that shines at the center of the audience seating from stage-right. Also another spotlight pointing center stage
// 9 - A spotlight that points at stage-right from stage-right
// 10 - Burnt out or not connected
// 11 - A spotlight pointing at the piller all the way stage-right
// 12 - Burnt out or not connected

elapsedMillis timeout;

void setup() {

	for(int i = 14; i < 24; i++) {
		pinMode(i, INPUT_PULLUP);
	}
	pinMode(13, OUTPUT);
	dmxTx.begin();
}

void loop() {
	//light_test(2);
  
	if(digitalRead(23) == LOW) { //Button 1
		dmxTx.set(2, 255);
    timeout = 0;
	}
	if(digitalRead(22) == LOW) { //Button 2
		dmxTx.set(4, 255);
    timeout = 0;
	}
	if(digitalRead(21) == LOW) { //Button 3
		dmxTx.set(5, 255);
    timeout = 0;
	}
	if(digitalRead(20) == LOW) { //Button 4
		dmxTx.set(6, 255);
    timeout = 0;
	}
	if(digitalRead(19) == LOW) { //Button 5
		dmxTx.set(7, 255);
    timeout = 0;
	}
	if(digitalRead(18) == LOW) { //Button 6
		dmxTx.set(8, 255);
    timeout = 0;
	}
	if(digitalRead(17) == LOW) { //Button 7
		dmxTx.set(9, 255);
    timeout = 0;
	}
	if(digitalRead(16) == LOW) { //Button 8
		dmxTx.set(11, 255);
    timeout = 0;
	}
	if(digitalRead(15) == LOW) { //Button 9
		for(int i = 1; i < 13; i++) {
			dmxTx.set(i, 255);
		}
    timeout = 0;
	}
	if(digitalRead(14) == LOW) { //Off Button
		for(int i = 1; i < 13; i++) {
			dmxTx.set(i, 0);
		}
    timeout = 0;
	}

  if(timeout > 1800000)    //1800000 = 30 min
  {
    for(int i = 1; i < 13; i++) {
      dmxTx.set(i, 0);
    }
    timeout = 0;
  }
}



void light_test(int channel) {
	digitalWrite(13, HIGH);
	dmxTx.set(channel, 255);
	delay(1000);
	digitalWrite(13, LOW);
	dmxTx.set(channel, 0);
	delay(1000);
}
