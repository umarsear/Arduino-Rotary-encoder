/*
  
****Copyright 2019 - MakerUSA LLC**** 

This example shows how to use the round rotary encoder and includes 
functionality for the push button incorporated in the encoder

Connect GND pin to Arduino ground
Connect 5v pin to Arduino 5V
Connect Key pin to Arduino Pin 8
Connect S1 pin to Arduino Pin 7
Connect S2 pin to Arduino Pin 6

*/  
 #define S2 6  
 #define S1 7
 #define B1 8
 int counter = 0; 
 int aState;
 int buttonState;
 int lastButtonState;
 int aLastState;  
 void setup() { 
   pinMode (S2,INPUT);
   pinMode (S1,INPUT);
   pinMode (B1,INPUT);
   
   Serial.begin (9600);
   aLastState = digitalRead(S2);   
   lastButtonState=digitalRead(B1);
 } 
 void loop() { 
   aState = digitalRead(S2); 
   buttonState = digitalRead(B1);
   if (aState != aLastState){     
     if (digitalRead(S1) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     if (buttonState == HIGH) {
       Serial.print("Position: ");
     } else {
       Serial.print("Button Pressed, Position: ");
     }
     Serial.println(counter);     
   } 
   else {
     if(buttonState!=lastButtonState) {
       if (buttonState == HIGH) {
          Serial.println("Button Released");
       } else {
        Serial.println("Button Pressed");
       }
       lastButtonState=buttonState;  
     }
   }
   aLastState = aState;
 }
