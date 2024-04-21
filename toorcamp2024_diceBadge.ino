int pinLeds1 = 4;
int pinLeds2 = 1;
int pinLeds3 = 0;
int pinLed4 = 3;
int buttonPin = 2;
int buttonState;
long ran;
int time = 15;
int timeMultiplyer = 10;
int rollCounter = 1;

void setup ()
{
  pinMode (pinLeds1, OUTPUT);
  pinMode (pinLeds2, OUTPUT);
  pinMode (pinLeds3, OUTPUT);
  pinMode (pinLed4, OUTPUT);
  pinMode (buttonPin, INPUT);
  randomSeed(analogRead(0));
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW){
    for (int i = 0; i <= 6; i++){

   // time = (timeMultiplyer * rollCounter);

    digitalWrite (pinLeds1, LOW);
    digitalWrite (pinLeds2, LOW);
    digitalWrite (pinLeds3, LOW);
    digitalWrite (pinLed4, LOW);
    delay(15);

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


   
   rollCounter++;
   }
   delay(250);
   rollCounter = 1;
  }
  digitalWrite (pinLeds1, LOW);
  digitalWrite (pinLeds2, LOW);
  digitalWrite (pinLeds3, LOW);
  digitalWrite (pinLed4, LOW);
}