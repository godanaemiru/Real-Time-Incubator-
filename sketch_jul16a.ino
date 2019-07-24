#include <liquidcrystal.h>

LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

// initialization

int ldrpin = 9;

float temp;

int temppin= 0;

int ldrstate = 0;

void setup()

{

pinMode (fan, OUTPUT);

pinMode (bulb, OUTPUT);




pinMode (ldrpin, INPUT);

Serial.begin (9600); // Setting the Baud Rate

lcd.begin (16, 2); // Activating both Rows of LCD

lcd.print (“2019”);

delay (5000);

lcd.clear();

lcd.print (“Recess Project”);

delay (5000);

lcd.clear ();

lcd.print (“INCUBATOR”);

delay (5000);

lcd.clear ();

lcd.print (“Group Members”);

delay (5000);

lcd.clear ();

lcd.print (“Lukambuzi Fred”);

delay (5000);

lcd.clear ();

lcd.print (“Phiona Nagaza”);

delay (5000);

lcd.clear ();

lcd.print (“Benjamin Ssali”);

delay (5000);

lcd.clear ();

lcd.print (“Godana Emiru”);

delay (5000);

lcd.clear ();

lcd.print (“Nabunya Immaculate”);

delay (5000);

lcd.clear ();

lcd.print (“Initialization”);

delay (5000);

lcd.clear ();

lcd.print (“Temperature = ”);

}

void loop ()

{

ldrstate = digitalRead (ldrpin); // Reading the LDR State

temp = analogRead (tempPin); // Reading the Temperature

temp = temp*0.48828125; // Conversion Factor

delay (1000);

Serial.printIn (temp); // Printing in Serial Monitor

Serial.printIn (“Centigrade”);

lcd.serCursor (0, 1); // Selecting the LCD Cursor to 1st Line

lcd.print (temp);

lcd.print (“Centigrade”);

if (ldrstate == HIGH)

{

if (temp>36  && temp < 38) // Maintaining the Range 32 – 36.

{

digitalWrite (fan, HIGH);

digitalWrite (bulb, LOW);

}


else if (temp<32)

{

digitalWrite (fan, LOW);

digitalWrite (bulb, HIGH);

}

else

{

digitalWrite (fan, LOW);

digitalWrite (bulb, LOW);

}

}

else

{

if (temp>36 && temp <= 38)

{

digitalWrite (fan, HIGH);

delay (800);

digitalWrite (fan, LOW);

delay (200);

digitalWrite (bulb, LOW);

}

else if (temp<32 && temp > 30)

{

digitalWrite (fan, LOW);

digitalWrite (bulb, HIGH);

}

else 

{

digitalWrite (fan, LOW);

digitalWrite (bulb, LOW);

}

}

if (temp > 38) // if temperatures are above 38
{
    //message should be sent through gsm
    Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"+256779626969\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print("temperatures are high"); //text content
  updateSerial();
  mySerial.write(26);
}
else if(temp < 30)
{
  //message should be sent 
     Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"+256779626969\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print("temperatures are low"); //text content
  updateSerial();
  mySerial.write(26);
}
}
