#include <Arduino.h>
#include <wchar.h>
#include <locale.h>

// Librería de impresión - https://learn.adafruit.com/mini-thermal-receipt-printer
#include "Adafruit_Thermal.h"

// Pines para definir comunicación Serial
#define TX_PIN 3
#define RX_PIN 1

Adafruit_Thermal printer(&Serial);

// Tipos de Barcode - http://www.barcodeisland.com/symbolgy.phtml
/*
12 Dígitos → UPC_A
6 Dígitos → UPC_E
13 Dígitos → EAN13
8 Dígitos → EAN8
Variable 0-9,A-Z,space,$%+-./ → CODE39
2-254 variable múltiple de 2 Dígitos → ITF
Variable 0-9,A-D,%+-./ → CODABAR
2-255 characters (ASCII 0-127) → CODE128

Ejemplo:
printer.print(F("CODE128:"));
printer.printBarcode("Adafruit", CODE128);
*/

void setup()
{

  // Establezco locale
  //setlocale(LC_ALL, "");
  setlocale(LC_CTYPE, "Spanish");

  //pinMode(7, OUTPUT);
  //digitalWrite(7, LOW);

  Serial.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);
  printer.begin();

  printer.justify('C');
  printer.boldOn();
  printer.println("Impresión de prueba");
  printer.boldOff();
  printer.justify('L');

  printer.print(F("Texto a la izquierda:"));

  printer.feed(2);
  printer.setDefault(); // Restore printer to defaults
}

void loop()
{
}