#include <SoftwareSerial.h> 



SoftwareSerial mySerial(9, 10);
 int k;
 int counter;
 int irsensor=8;
int isblack;
void setup()
{
  pinMode(irsensor,INPUT);
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}


void loop()
{
  isblack=digitalRead(irsensor);
  delay(5000);
  k+=5000;
  isblack=digitalRead(irsensor);
  if(isblack==LOW&&counter==0)
  {
    SendMessage();
    counter++;
   }
  RecieveMessage();
 if (mySerial.available()>0)
   Serial.write(mySerial.read());
   if(k>48)
   {
    Serial.println();
    SendMessage();
    }
}


 void SendMessage()
{

  mySerial.println("OK");
  mySerial.println("AT+CMGF=1");    
  delay(1000);  
  mySerial.println("AT+CMGS=\"+919686341457\"\r"); 
  delay(1000);
  mySerial.println("Dustbin is full\nID-590008\nRegion:-Udyambhag\nhttps://maps.google.com/?cid=14680814991694128018");
   delay(100);
  mySerial.println((char)26);
  delay(1000);


}
 void RecieveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
 }
