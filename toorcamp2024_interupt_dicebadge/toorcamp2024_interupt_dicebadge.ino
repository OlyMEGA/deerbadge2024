
#include <avr/sleep.h>
#include <avr/power.h>
// disable ADC to save power during sleep 
#define adc_disable() (ADCSRA &= ~(1<<ADEN)) 


int pinLeds1 = 4;
int pinLeds2 = 1;
int pinLeds3 = 0;
int pinLed4 = 3;
int buttonPin = 2; //interrupt/wake up pin
int buttonState;
int prevbuttonstate = 1;
long ran; //variable for the random number
int time = 15;


void setup (){
  pinMode (pinLeds1, OUTPUT);
  pinMode (pinLeds2, OUTPUT);
  pinMode (pinLeds3, OUTPUT);
  pinMode (pinLed4, OUTPUT);
  pinMode (buttonPin, INPUT);
  randomSeed(analogRead(0)); //open pin for random seed

  //sleep mode settings
  adc_disable(); // ADC uses ~320uA while asleep
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); //sleep level setting

}

void pin2Interrupt(void){
  for (int i = 1; i <= 7; i++){
  //clear prev roll for the next one
    digitalWrite (pinLeds1, LOW);
    digitalWrite (pinLeds2, LOW);
    digitalWrite (pinLeds3, LOW);
    digitalWrite (pinLed4, LOW);
    delay(time);

      ran = random(1, 7);
      if (ran == 1){
        digitalWrite (pinLed4, HIGH);
        delay (time);
      }
      if (ran == 2){
        digitalWrite (pinLeds1, HIGH);
        delay (time);
      }
      if (ran == 3){
        digitalWrite (pinLeds3, HIGH);
        digitalWrite (pinLed4, HIGH);
        delay (time);
      }
      if (ran == 4){
        digitalWrite (pinLeds1, HIGH);
        digitalWrite (pinLeds3, HIGH);
        delay (time);

      }
      if (ran == 5){
        digitalWrite (pinLeds1, HIGH);
        digitalWrite (pinLeds3, HIGH);
        digitalWrite (pinLed4, HIGH);
        delay (time);
    }
    if (ran == 6){
        digitalWrite (pinLeds1, HIGH);
        digitalWrite (pinLeds2, HIGH);
        digitalWrite (pinLeds3, HIGH);
        delay (time);
    }
    delay(i * 100);
  }
  delay(5000); //hold final die roll 
  digitalWrite (pinLeds1, LOW);
  digitalWrite (pinLeds2, LOW);
  digitalWrite (pinLeds3, LOW);
  digitalWrite (pinLed4, LOW); 


}


void loop()
{
  delay(500); // needed, otherwise gets stuck in sleep mode? 
  attachInterrupt(0,pin2Interrupt,LOW);
  sleep_enable();
  sleep_mode(); 
}