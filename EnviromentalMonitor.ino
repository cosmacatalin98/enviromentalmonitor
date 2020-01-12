#include "DHT.h"
#include <SoftwareSerial.h>
#include <LedControl.h>

//Comunicarea seriala
SoftwareSerial EEBlue(2, 3); // RX | TX

//Senzorul de temperatura si umiditate
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//Matricea de LED-uri 8x8
int DIN = 4;
int CS =  7;
int CLK = 5;
LedControl lc = LedControl(DIN, CLK, CS, 0); //DIN CLK CS

//Modelul cifrelor si a mesajului HELLO
byte zeroDigitDec[8] = {0xFE, 0x82, 0xFE, 0x00, 0x00, 0xFE, 0x82, 0xFE};
byte oneDigitDec[8] = {0x08, 0x04, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,};
byte twoDigitDec[8] = {0xF2, 0x92, 0x9E, 0x00, 0x00, 0x00, 0x00, 0x00,};
byte threeDigitDec[8] = {0x92, 0x92, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,};
byte fourDigitDec[8] = {0x1E, 0x10, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,};
byte fiveDigitDec[8] = {0x9E, 0x92, 0xF2, 0x00, 0x00, 0x00, 0x00, 0x00,};
byte sixDigitDec[8] = {0xFE, 0x92, 0xF2, 0x00, 0x00, 0x00, 0x00, 0x00,};
byte sevenDigitDec[8] = {0x02, 0x02, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,};
byte eightDigitDec[8] = {0xFE, 0x92, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,};
byte nineDigitDec[8] = {0x9E, 0x92, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,};

byte zeroDigitUnit[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x82, 0xFE,};
byte oneDigitUnit[8] = {0x08, 0x04, 0xFE, 0x00, 0x00, 0x08, 0x04, 0xFE};
byte twoDigitUnit[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xF2, 0x92, 0x9E,};
byte threeDigitUnit[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x92, 0x92, 0xFE,};
byte fourDigitUnit[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x10, 0xFE,};
byte fiveDigitUnit[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x9E, 0x92, 0xF2,};
byte sixDigitUnit[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x92, 0xF2,};
byte sevenDigitUnit[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0xFE,};
byte eightDigitUnit[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x92, 0xFE,};
byte nineDigitUnit[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x9E, 0x92, 0xFE,};

byte HelloSH0[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,};
byte HelloSH1[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x18,};
byte HelloSH2[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x18, 0x18,};
byte HelloSH3[8] = {0x00, 0x00, 0x00, 0x00, 0xFF, 0x18, 0x18, 0xFF,};
byte HelloSH4[8] = {0x00, 0x00, 0x00, 0xFF, 0x18, 0x18, 0xFF, 0x00,};
byte HelloSH5[8] = {0x00, 0x00, 0xFF, 0x18, 0x18, 0xFF, 0x00, 0xFF,};
byte HelloSH6[8] = {0x00, 0xFF, 0x18, 0x18, 0xFF, 0x00, 0xFF, 0x99,};
byte HelloSH7[8] = {0xFF, 0x18, 0x18, 0xFF, 0x00, 0xFF, 0x99, 0x99,};
byte HelloSH8[8] = {0x18, 0x18, 0xFF, 0x00, 0xFF, 0x99, 0x99, 0x00,};
byte HelloSH9[8] = {0x18, 0xFF, 0x00, 0xFF, 0x99, 0x99, 0x00, 0xFF,};
byte HelloSH10[8] = {0xFF, 0x00, 0xFF, 0x99, 0x99, 0x00, 0xFF, 0x80,};
byte HelloSH11[8] = {0x00, 0xFF, 0x99, 0x99, 0x00, 0xFF, 0x80, 0x80,};
byte HelloSH12[8] = {0xFF, 0x99, 0x99, 0x00, 0xFF, 0x80, 0x80, 0x00,};
byte HelloSH13[8] = {0x99, 0x99, 0x00, 0xFF, 0x80, 0x80, 0x00, 0xFF,};
byte HelloSH14[8] = {0x99, 0x00, 0xFF, 0x80, 0x80, 0x00, 0xFF, 0x80,};
byte HelloSH15[8] = {0x00, 0xFF, 0x80, 0x80, 0x00, 0xFF, 0x80, 0x80,};
byte HelloSH16[8] = {0xFF, 0x80, 0x80, 0x00, 0xFF, 0x80, 0x80, 0x00,};
byte HelloSH17[8] = {0x80, 0x80, 0x00, 0xFF, 0x80, 0x80, 0x00, 0xFF,};
byte HelloSH18[8] = {0x80, 0x00, 0xFF, 0x80, 0x80, 0x00, 0xFF, 0x81,};
byte HelloSH19[8] = {0x00, 0xFF, 0x80, 0x80, 0x00, 0xFF, 0x81, 0x81,};
byte HelloSH20[8] = {0xFF, 0x80, 0x80, 0x00, 0xFF, 0x81, 0x81, 0xFF,};
byte HelloSH21[8] = {0x80, 0x80, 0x00, 0xFF, 0x81, 0x81, 0xFF, 0x00,};
byte HelloSH22[8] = {0x80, 0x00, 0xFF, 0x81, 0x81, 0xFF, 0x00, 0x00,};
byte HelloSH23[8] = {0x00, 0xFF, 0x81, 0x81, 0xFF, 0x00, 0x00, 0x00,};
byte HelloSH24[8] = {0xFF, 0x81, 0x81, 0xFF, 0x00, 0x00, 0x00, 0x00,};
byte HelloSH25[8] = {0x81, 0x81, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,};
byte HelloSH26[8] = {0x81, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,};
byte HelloSH27[8] = {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,};
byte HelloSH28[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,};

//Valorile senzorilor
int umd;
int tmp;
int lum;
int sun;

//Flag-uri folosite pentru identificarea comenzilor primite de la smartphone
char tmpFlag = '0';
char ctr = '0';

void setup()
{
  //Initializarea matricii de LED-uri
  lc.shutdown(0, false);      //MAX72XX este in modul power-saving la inceput
  lc.setIntensity(0, 15);     //Setam luminozitatea la valoarea maxima
  lc.clearDisplay(0);        
  //Inceperea comuniarii seriale
  Serial.begin(9600);
  //Inceperea comunicarii modulului bluetooth
  EEBlue.begin(9600);  
  //Inceperea citirii a temperaturii si a umiditatii
  dht.begin();

}

void loop()
{
//Daca se transmit date de la modulul bluetooth le preluam
// si in functie de flag-ul primit afisam una dintre valorile
// senzorilor
  if (EEBlue.available()) {
    tmpFlag = EEBlue.read();
  }

  if (tmpFlag == '0') {
    ctr = '0';
  }
  if (tmpFlag == '1') {
    ctr = '1';
  }
  if (tmpFlag == '2') {
    ctr = '2';
  }

  if (tmpFlag == '3') {
    ctr = '3';
  }

  if (tmpFlag == '4') {
    ctr = '4';
  }

  controlLedMatrix();

}

//Functie de control a matricii de LED-uri
void controlLedMatrix() {
  if (ctr == '0') {
    printHello();
  }
  if (ctr == '1') {
    readDHT11();
    printNumber(tmp);
  }

  if (ctr == '2') {
    readDHT11();
    printNumber(umd);
  }

  if (ctr == '3') {
    readLDR();
    printNumber(lum);
  }

  if (ctr == '4') {
    readSM();
    printNumber(sun);
  }
}

//Citirea datelor de la senzorul de temperatura si umiditate
void readDHT11() {
  delay(2000);
  umd = dht.readHumidity();
  tmp = dht.readTemperature();
}

//Citirea datelor de la senzorul de lumina
void readLDR() {
  delay(2000);
  int av = analogRead(A0);
  double Vout = av * 0.0048828125;
  lum = (2500 / Vout - 500) / 250;
  if (lum > 99) {
    lum = 99;
  }
}

//Citirea datelor de la senzorul de sunet
void readSM() {
  delay(1000);
  sun = analogRead(A1);
  if (sun > 99) {
    sun = 99;
  }
}

//Functie utilizata pentru afisarea unui caracter pe matricea de LED-uri
void printEntire(byte character [])
{
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    lc.setRow(0, i, character[i]);
  }
}

//Functie utilizata pentru afisarea unui caracter pe prima jumatate a matricii de LED-uri
void printFirstHalf(byte character [])
{
  int i = 0;
  for (i = 0; i < 4; i++)
  {
    lc.setRow(0, i, character[i]);
  }
}

//Functie utilizata pentru afisarea unui caracter pe cea dea doua jumatate a matricii de LED-uri
void printSecondHalf(byte character [])
{
  int i = 0;
  for (i = 4; i < 8; i++)
  {
    lc.setRow(0, i, character[i]);
  }
}

//Afiseaza un numar de la 0 la 99 pe matricea de LED-uri
void printNumber(int x) {
  int d = x / 10;
  int u = x % 10;

  switch (u) {
    case 0:
      printSecondHalf(zeroDigitUnit);
      break;
    case 1:
      printSecondHalf(oneDigitUnit);
      break;
    case 2:
      printSecondHalf(twoDigitUnit);
      break;
    case 3:
      printSecondHalf(threeDigitUnit);
      break;
    case 4:
      printSecondHalf(fourDigitUnit);
      break;
    case 5:
      printSecondHalf(fiveDigitUnit);
      break;
    case 6:
      printSecondHalf(sixDigitUnit);
      break;
    case 7:
      printSecondHalf(sevenDigitUnit);
      break;
    case 8:
      printSecondHalf(eightDigitUnit);
      break;
    case 9:
      printSecondHalf(nineDigitUnit);
      break;
    default:
      printSecondHalf(zeroDigitUnit);
      break;
  }
  switch (d) {
    case 0:
      printFirstHalf(zeroDigitDec);
      break;
    case 1:
      printFirstHalf(oneDigitDec);
      break;
    case 2:
      printFirstHalf(twoDigitDec);
      break;
    case 3:
      printFirstHalf(threeDigitDec);
      break;
    case 4:
      printFirstHalf(fourDigitDec);
      break;
    case 5:
      printFirstHalf(fiveDigitDec);
      break;
    case 6:
      printFirstHalf(sixDigitDec);
      break;
    case 7:
      printFirstHalf(sevenDigitDec);
      break;
    case 8:
      printFirstHalf(eightDigitDec);
      break;
    case 9:
      printFirstHalf(nineDigitDec);
      break;
    default:
      printFirstHalf(zeroDigitDec);
      break;
  }
}

//Afiseaza mesajul HELLO pe matricea de LED-uri
void printHello() {
  int hd = 150;
  printEntire(HelloSH0);
  delay(hd);
  printEntire(HelloSH1);
  delay(hd);
  printEntire(HelloSH2);
  delay(hd);
  printEntire(HelloSH3);
  delay(hd);
  printEntire(HelloSH4);
  delay(hd);
  printEntire(HelloSH5);
  delay(hd);
  printEntire(HelloSH6);
  delay(hd);
  printEntire(HelloSH7);
  delay(hd);
  printEntire(HelloSH8);
  delay(hd);
  printEntire(HelloSH9);
  delay(hd);
  printEntire(HelloSH10);
  delay(hd);
  printEntire(HelloSH11);
  delay(hd);
  printEntire(HelloSH12);
  delay(hd);
  printEntire(HelloSH13);
  delay(hd);
  printEntire(HelloSH14);
  delay(hd);
  printEntire(HelloSH15);
  delay(hd);
  printEntire(HelloSH16);
  delay(hd);
  printEntire(HelloSH17);
  delay(hd);
  printEntire(HelloSH18);
  delay(hd);
  printEntire(HelloSH19);
  delay(hd);
  printEntire(HelloSH20);
  delay(hd);
  printEntire(HelloSH21);
  delay(hd);
  printEntire(HelloSH22);
  delay(hd);
  printEntire(HelloSH23);
  delay(hd);
  printEntire(HelloSH24);
  delay(hd);
  printEntire(HelloSH25);
  delay(hd);
  printEntire(HelloSH26);
  delay(hd);
  printEntire(HelloSH27);
  delay(hd);
  printEntire(HelloSH28);
  delay(hd);
}
