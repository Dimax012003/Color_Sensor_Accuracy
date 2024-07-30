#include <Wire.h>
int color[3]={11,10,6};
const int S3=4;
const int S2=5;
const int S1=12;
const int S0=13;

int output=8;
int red_recognition(int a,int b);
int green_recognition(int a,int b);
int bleu_recognition(int a,int b);
int red_recognition(int a,int b){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  
  // Reading the output frequency
  int redFrequency = pulseIn(output, LOW);
  return redFrequency;
}
int green_recognition(int a,int b){
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  
  // Reading the output frequency
  int greenFrequency = pulseIn(output, LOW);
  
  return greenFrequency;
}
int bleu_recognition(int a,int b){
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  
  // Reading the output frequency
  int bleuFrequency = pulseIn(output, LOW);

  return bleuFrequency;
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(output,INPUT);

  for(int i=0;i<3;i++){
    pinMode(color[i],OUTPUT);
  }
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int red_g;
  int green_g;
  int bleu_g;
  int red=random(100,255);

  int bleu=random(0,125);
  int green=random(0,120);
  analogWrite(color[0],red);
  analogWrite(color[1],green);
  analogWrite(color[2],bleu);
  delay(1000);
  Serial.print(red);
  Serial.print(" ");
  Serial.print(green);
  Serial.print(" ");
  Serial.print(bleu);
  Serial.print(" ");

  red_g=red_recognition(S2,S3);
  green_g=green_recognition(S2,S3);
  bleu_g=bleu_recognition(S2,S3);
  Serial.print(250-red_g);
  Serial.print(" ");
  Serial.print(250-green_g);
  Serial.print(" ");
  Serial.println(250-bleu_g);
  delay(500);

}
