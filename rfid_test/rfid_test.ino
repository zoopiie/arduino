
#include <SPI.h>
#include <MFRC522.h>

MFRC522 rfid(10,9);

//String TAG_ID=String("8b")+" "+String("5b")+" "+String("24")+" "+String("a3"); // UID du badge ou de la carte acceptée.
#include <U8glib.h>
 U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_NO_ACK|U8G_I2C_OPT_FAST);
int incomingData;

String recep;

int led = 2;
int a = 4;

void setup() {

  pinMode(led, OUTPUT);
Serial.begin(9600);
  SPI.begin();
rfid.PCD_Init();
delay(30);
}

void loop() { 
  
 if (rfid.PICC_IsNewCardPresent()) {
    if (rfid.PICC_ReadCardSerial()) {
      String myKey=String( String (rfid.uid.uidByte[0],HEX) + String(rfid.uid.uidByte[1],HEX) + String(rfid.uid.uidByte[2],HEX)  + String(rfid.uid.uidByte[3],HEX));
      Serial.println(myKey);
      
      rfid.PICC_HaltA();
      rfid.PCD_StopCrypto1();
    }
  }
  if (Serial.available()>0) {  
    
    int donnee=Serial.read();
    
    if (donnee=='2') {
      Serial.println("Eteindre L");
      digitalWrite(2,0);
    }
 
   
    if (donnee=='1') {
      Serial.println("Allumer L");
      digitalWrite(2,1);
   }

  }
  
  }

     



     
