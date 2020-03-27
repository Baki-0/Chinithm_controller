#include <Keyboard.h>
void setup() {
  pinMode(2, OUTPUT);	//汎用パルス出力
  pinMode(3, INPUT);	//1番入力
  pinMode(4, OUTPUT);	//1番LED
  pinMode(5, INPUT);	//2番入力
  pinMode(6, OUTPUT);	//2番LED
  pinMode(7, INPUT);	//3番入力
  pinMode(8, OUTPUT);	//3番LED
  pinMode(9, INPUT);	//4番入力
  pinMode(10, OUTPUT);	//4番LED
  Serial.begin(9600);
  Serial.println("Leady");
  Keyboard.begin();
}

void loop() {
  int t[4] = {0,0,0,0};
  int f[4] = {0,0,0,0};
  int l = 5;

  digitalWrite(2, HIGH);  //パルス

  while (digitalRead(3) != HIGH){
    t[0]++; //立ち上がり時間の計測
  }
  
  while (digitalRead(5) != HIGH){
    t[1]++; //立ち上がり時間の計測
  }

  while (digitalRead(7) != HIGH){
    t[2]++; //立ち上がり時間の計測
  }

  while (digitalRead(9) != HIGH){
    t[3]++; //立ち上がり時間の計測
  }
  //放電
  digitalWrite(2, LOW);
  delay (1);

  //フィルター
  f[0] += (t[0] - f[0]) / 2;
  f[1] += (t[1] - f[1]) / 2;
  f[2] += (t[2] - f[2]) / 2;
  f[3] += (t[3] - f[3]) / 2;


  if (f[0] > l ) {
    digitalWrite(4, HIGH);
    Keyboard.press(0x50);
    //delay(5);
  } else{
    Keyboard.releaseAll();
    digitalWrite(4, LOW);
  }
   
  if (f[1] > l) {
    digitalWrite(6, HIGH);
    Keyboard.press(0x51);
  }else{
    Keyboard.releaseAll();
    digitalWrite(6, LOW);
  }
  
  if(f[2] > l){
    digitalWrite(8, HIGH);
    Keyboard.press(0x52);
  }else{
    Keyboard.releaseAll();
    digitalWrite(8, LOW);
  }
   
  if (f[3] > l){
    digitalWrite(10, HIGH);
    Keyboard.press(0x53);
  }else{
    Keyboard.releaseAll();
    digitalWrite(10, LOW);
  }
}
