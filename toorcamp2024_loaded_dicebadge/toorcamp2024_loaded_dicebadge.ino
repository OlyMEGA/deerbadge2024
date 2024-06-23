
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
  detachInterrupt(0); //detach interrupt before anything else
  //dont put any delays or anything in here
}

void enterSleep(void){
  attachInterrupt(0,pin2Interrupt,LOW);
 // set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode(); //pauses here and goes to sleep
  //program continues from here once interrupt is detected
  sleep_disable();
}

void loop()
{
  //checks if button is held down, this keeps the program from locking up
  buttonState = digitalRead(buttonPin); 
  if (buttonState == HIGH){
  enterSleep(); //sleep immediately if button not pressed
  prevbuttonstate = HIGH;
  }

//if sleep does not happen, or wakeup is triggered, roll the die!
//roll 7 times and keep the last one
if ((buttonState == LOW) && (prevbuttonstate == HIGH)){
    for (int i = 0; i <= 6; i++){
//clear prev roll for the next one
  digitalWrite (pinLeds1, LOW);
  digitalWrite (pinLeds2, LOW);
  digitalWrite (pinLeds3, LOW);
  digitalWrite (pinLed4, LOW);
  delay(time);

    ran = random(0, 1000);
    if (ran <= 100){
      digitalWrite (pinLed4, HIGH);
      delay (time);
    }
    if (ran > 100 && ran <= 200){
      digitalWrite (pinLeds1, HIGH);
      delay (time);
    }
    if (ran > 200 && ran <= 300){
      digitalWrite (pinLeds3, HIGH);
      digitalWrite (pinLed4, HIGH);
      delay (time);
    }
    if (ran > 300 && ran <= 400){
      digitalWrite (pinLeds1, HIGH);
      digitalWrite (pinLeds3, HIGH);
      delay (time);
    }
    if (ran > 400 && ran <= 500){
      digitalWrite (pinLeds1, HIGH);
      digitalWrite (pinLeds3, HIGH);
      digitalWrite (pinLed4, HIGH);
      delay (time);
   }
   if (ran > 500){
      digitalWrite (pinLeds1, HIGH);
      digitalWrite (pinLeds2, HIGH);
      digitalWrite (pinLeds3, HIGH);
      delay (time);
   }
  }
  delay(250); //hold final die roll
  prevbuttonstate = LOW;
}
//clear all leds at loop end
  digitalWrite (pinLeds1, LOW);
  digitalWrite (pinLeds2, LOW);
  digitalWrite (pinLeds3, LOW);
  digitalWrite (pinLed4, LOW);
}