#include <Keyboard.h>
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  Serial.println("Leady");
  Keyboard.begin();
}

void loop() {
  int t = 0;
  int l = 5;

  digitalWrite(2, HIGH);  //パルス
  while (digitalRead(3) != HIGH){
    t++; //立ち上がり時間の計測
  }

  //放電
  digitalWrite(2, LOW);
  delay (1);

  int f = 0;
  f += (t - f) / 2;
  Serial.println(f);

  if (f > l ) {
    digitalWrite(4, HIGH);
    Keyboard.press(0x50);
    //delay(5);
  } else {
    Keyboard.releaseAll();
    digitalWrite(4, LOW);
  }
}
