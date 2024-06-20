
#include <avr/sleep.h>
#include <avr/power.h>
// disable ADC to save power during sleep 
//#define adc_disable() (ADCSRA &= ~(1<<ADEN)) 


int pinLeds1 = 4; //physical pin 3, ADC2
int pinLeds2 = 1; //pin 6 main eyes?
int pinLeds3 = 0; //pin 5 
int pinLed4 = 3; //pin 2, adc3
int buttonPin = 2; //pin 7 interrupt/wake up pin
int buttonState;
int prevbuttonstate = 1;
//long ran; //variable for the random number
int time = 15;


void setup (){
  pinMode (pinLeds1, OUTPUT);
  pinMode (pinLeds2, OUTPUT);
  pinMode (pinLeds3, OUTPUT);
  pinMode (pinLed4, OUTPUT);
  pinMode (buttonPin, INPUT);
  randomSeed(analogRead(0)); //open pin for random seed

  //sleep mode settings
  //adc_disable(); // ADC uses ~320uA while asleep
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
    digitalWrite(pinLeds2,LOW);
  enterSleep(); //sleep immediately if button not pressed
  //prevbuttonstate = HIGH;
  }

//if sleep does not happen, or wakeup is triggered, roll the die!

//if ((buttonState == LOW) && (prevbuttonstate == HIGH)){ //debounce
 


  // 
  for (int i = 0; i <= 255; i++){
    analogWrite(pinLeds2,i);
  delay(1);
  }
 //delay(10);

   for (int i = 255; i >= 0; i--){
    analogWrite(pinLeds2,i);
  delay(1);
   }
delay(30);

 // prevbuttonstate = LOW;
//}

}