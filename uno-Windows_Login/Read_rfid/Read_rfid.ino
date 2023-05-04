#include <SPI.h>
#include <MFRC522.h> // RFID library
#define SS_PIN 10 //RX slave select
#define RST_PIN 9
int gled = 7; // optional
int rled = 4;// optional
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.
String card_ID=""; // 
String password="" ; // Change It To Your Windows / fb / any Account's Password
String rfid="";// UID (unique Id Code Of Your Rfid Tag)
void setup() {
  Serial.begin(9600); // Initialize serial communications with the PC
  SPI.begin();  // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card
  pinMode(gled,OUTPUT);
  pinMode(rled,OUTPUT);
}
void loop() {
  //look for new card
   if ( ! mfrc522.PICC_IsNewCardPresent()) {
  return;
 }
 if ( ! mfrc522.PICC_ReadCardSerial()) {
  return;//if read card serial(0) returns 1, the uid struct contians the ID of the read card.
 }
 for (byte i = 0; i < mfrc522.uid.size; i++) {
   card_ID += mfrc522.uid.uidByte[i];
 }
// Serial.println(card_ID);
       Serial.print(card_ID);
delay(1000);
card_ID="";
}
