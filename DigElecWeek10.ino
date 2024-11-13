#include "BetterButton.h"

int button1Pin = 37;
int button2Pin = 36;
int button3Pin = 35;
int button4Pin = 34;
int button5Pin = 33;

int ledPin1 = 24;
int ledPin2 = 11;

BetterButton button1(button1Pin, 0);
BetterButton button2(button2Pin, 1);
BetterButton button3(button3Pin, 2);
BetterButton button4(button4Pin, 3);
BetterButton button5(button5Pin, 4);

void setup() {
  Serial.begin(9600);

  button1.pressHandler(onPress);
  button1.releaseHandler(onRelease);
  button2.pressHandler(onPress);
  button2.releaseHandler(onRelease);
  button3.pressHandler(onPress);
  button3.releaseHandler(onRelease);
  button4.pressHandler(onPress);
  button4.releaseHandler(onRelease);
  button5.pressHandler(onPress);
  button5.releaseHandler(onRelease);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  button1.process();
  button2.process();
  button3.process();
  button4.process();
  button5.process();
}

void onPress(int val) {
  Serial.print(val);
  Serial.println(" on");
  usbMIDI.sendNoteOn(val + 60, 90, 1);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
}

void onRelease(int val) {
  Serial.print(val);
  Serial.println(" off");
  usbMIDI.sendNoteOff(val + 60, 0, 1);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
}
