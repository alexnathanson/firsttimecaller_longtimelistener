const int transistorPin1 = 3;    // connected to the base of the transistor
const int transistorPin2 = 5;    // connected to the base of the transistor
const int transistorPin3 = 6;    // connected to the base of the transistor
const int button1 = 7;    // connected to the button
const int button2 = 8;    // connected to the button
const int button3 = 12;    // connected to the button
int butt_val1 = 0; // used to store the state of the button
int butt_val2 = 0; // used to store the state of the button
int butt_val3 = 0; // used to store the state of the button
int old_butt1 = 0;
int old_butt2 = 0;
int old_butt3 = 0;

 void setup() {
   Serial.begin(9600);
   // set  the transistor pin as output:
   pinMode(transistorPin1, OUTPUT);
   pinMode(transistorPin2, OUTPUT);
   pinMode(transistorPin3, OUTPUT);
   pinMode(button1, INPUT);
   pinMode(button2, INPUT);
   pinMode(button3, INPUT);

 }
 
 void loop() {
   // read the potentiometers:
   int sensorValue1 = analogRead(A0);
   int sensorValue2 = analogRead(A1);
   int sensorValue3 = analogRead(A2);

// read the buttons;
    butt_val1 = digitalRead(button1);
    butt_val2 = digitalRead(button2);
    butt_val3 = digitalRead(button3);

// send button data
 
  if (butt_val1 != old_butt1) {
      Serial.print("4 ");
      Serial.println(butt_val1);
      old_butt1 = butt_val1;
      delay(5);
  }
  
   if (butt_val2 != old_butt2) {
      Serial.print("5 ");
      Serial.println(butt_val2);
      old_butt2 = butt_val2;
      delay(5);
  }
  
   if (butt_val3 != old_butt3) {
      Serial.print("6 ");
      Serial.println(butt_val3);
      old_butt3 = butt_val3;
      delay(5);
  }
  
   // map the sensor value to a range from 0 - 255: (adjusted because the pot would only go down to 150)
   int outputValue1 = map(sensorValue1, 0, 1023, 0, 255);
   int outputValue2 = map(sensorValue2, 0, 1023, 0, 255);
   int outputValue3 = map(sensorValue3, 0, 1023, 0, 255);
   
   // use that to control the transistor:
   if (outputValue1 >= 0){
      analogWrite(transistorPin1, outputValue1);
      analogWrite(transistorPin2, outputValue2);
      analogWrite(transistorPin3, outputValue3);
     
   }
   Serial.print("1 ");
   Serial.println(outputValue1);
   Serial.print("2 ");
   Serial.println(outputValue2);
   Serial.print("3 ");
   Serial.println(outputValue3);
 }
 
