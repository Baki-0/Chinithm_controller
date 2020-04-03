#include <Keyboard.h>
void setup() {
  pinMode(2, OUTPUT);	//左ドン用パルス出力
  pinMode(3, INPUT);	//左ドン入力
  pinMode(4, OUTPUT);	//右ドン用パルス出力
  pinMode(5, INPUT);	//右ドン入力
  pinMode(6, OUTPUT);	//左カッ用パルス出力
  pinMode(7, INPUT);	//左カッ入力
  pinMode(8, OUTPUT);	//右カッ用パルス出力
  pinMode(9, INPUT);	//右カッ入力
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
  
  //放電
  digitalWrite(2, LOW);
  delay (1);

  digitalWrite(4, HIGH);  //パルス

  while (digitalRead(5) != HIGH){
    t[1]++; //立ち上がり時間の計測
  }

  //放電
  digitalWrite(4, LOW);
  delay (1);

  digitalWrite(6, HIGH);  //パルス

  while (digitalRead(7) != HIGH){
    t[2]++; //立ち上がり時間の計測
  }
  
  //放電
  digitalWrite(6, LOW);
  delay (1);

  digitalWrite(8, HIGH);  //パルス

  while (digitalRead(9) != HIGH){
    t[3]++; //立ち上がり時間の計測
  }
  //放電
  digitalWrite(8, LOW);
  delay (1);

  //フィルター
  f[0] += (t[0] - f[0]) / 2;
  f[1] += (t[1] - f[1]) / 2;
  f[2] += (t[2] - f[2]) / 2;
  f[3] += (t[3] - f[3]) / 2;


  if (f[0] > l ) {
    Keyboard.press(0x46);
    //delay(5);
  } else{
    Keyboard.releaseAll();
  }
   
  if (f[1] > l) {
    Keyboard.press(0x4A);
  }else{
    Keyboard.releaseAll();
  }
  
  if(f[2] > l){
    Keyboard.press(0x44);
  }else{
    Keyboard.releaseAll();
  }
   
  if (f[3] > l){
    Keyboard.press(0x4B);
  }else{
    Keyboard.releaseAll();
  }
}
