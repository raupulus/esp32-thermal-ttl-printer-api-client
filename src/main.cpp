#include <Arduino.h>

// Librería de impresión - https://learn.adafruit.com/mini-thermal-receipt-printer
#include "Adafruit_Thermal.h"

// Defino comunicación Serial
#define TX_PIN 3
#define RX_PIN 1
#define BAUDRATE 9600

// Defino parámetros de impresora térmica
Adafruit_Thermal printer(&Serial);
#define DEFAULT_CHARSET CHARSET_SPAIN2
#define DEFAULT_CODEPAGE CODEPAGE_ISO_8859_15

// Wireless

//TODO

void setup()
{
  int CHARSET = DEFAULT_CHARSET;
  int CODEPAGE = DEFAULT_CODEPAGE;

  //pinMode(7, OUTPUT);
  //digitalWrite(7, LOW);

  Serial.begin(BAUDRATE, SERIAL_8N1, RX_PIN, TX_PIN);
  sleep(1);
  printer.begin();
  sleep(1);

  // Establezco locale
  printer.setCharset(CHARSET);
  printer.setCodePage(CODEPAGE);
  sleep(1);

  //printer.print(F("avión en € y @"));
  String text = "avión en € y @";

  int lineSize = text.length();

  uint8_t data[lineSize];

  for (int i = 0; i < lineSize; i++)
  {
    data[i] = text.charAt(i);

    printer.write(data[i]);
  }

  //printBitmap(*bitmap, width, height, scale = 1, center = true)
  /*
  printer.println("Iniciando");
  printer.justify('C');
  printer.boldOn();
  printer.println("Impresión de prueba");
  printer.boldOff();
  printer.justify('L');

  printer.println("Texto a la izquierda");
  */

  //printer.write();

  printer.feed(3);
  printer.setDefault(); // Restore printer to defaults
  printer.wake();       // Pone en modo bajo consumo la impresora
}

void loop()
{
}