#include <LiquidCrystal.h>
#define CLICK 2
#define OUTPUT_A 3
#define OUTPUT_B 4

LiquidCrystal lcd(5, 6, 7, 8, 9, 10);

int counter = 0;
int aState;
int aLastState;
int clickState;
int clickLastState;
void setup() {
  // put your setup code here, to run once:
  pinMode(OUTPUT_A, INPUT);
  pinMode(OUTPUT_B, INPUT);
  Serial.begin(9600);

  aLastState = digitalRead(OUTPUT_A);
  clickLastState = digitalRead(CLICK);

  lcd.begin(16, 2);
  lcd.print(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  aState = digitalRead(OUTPUT_A);
  if (aState == HIGH && aLastState == LOW){
    if (digitalRead(OUTPUT_B) != aState){
      counter++; 
    }  
    else{
      counter--;  
    }
    lcd.clear();
    lcd.print(counter);
  }
  if (aState == LOW && aLastState == HIGH){
    delay(50);  
  }
  aLastState = aState;

  click();
}

void click() {
  clickState = digitalRead(CLICK);
  if (clickState == HIGH && clickLastState == LOW){
    lcd.clear();
    lcd.print("Click");  
  }
  if (clickState == LOW && clickLastState == HIGH){
    delay(100);  
  }

  clickLastState = clickState;
}
