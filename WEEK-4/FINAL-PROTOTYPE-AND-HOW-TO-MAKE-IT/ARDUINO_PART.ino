/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

//CODE AND CIRCUIT TAKEN FROM "HELLO WORLD EXAMPLE" AND ADAPTED TO PROCESS BBC RRS FEED
//USE IN CONJUCTION WITH PROCESSING FILE
//UPLOAD ARDUINO SKETCH FULLY FIRST, THEN RUN PROCESSING (BECAUSE I KEEP FORGETTING THAT) 
//IF ERROR CODE APPEARS REGARDING COM3, IT'S BECAUSE PROCESSING NEEDS TO BE STOPPED BEFORE ARDUINO CAN BE UPDATED.


// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char val; // Data received from the serial port
int count =0;

  int i=0;
  int j=0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("                                ");
   Serial.begin(9600); // Start serial communication at 9600 bps
  lcd.setCursor(i, j);

}

void loop() {
  
  if (Serial.available()){
   val = Serial.read(); // read it and store it in val
 

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):

  // print the number of seconds since reset:
  lcd.print(val);
  i++;
if (i>15){
  j++;
  i=0;
}
if (j>1){
  j=0;
}
 lcd.setCursor(i, j);
  delay(50);
   }}  
  


