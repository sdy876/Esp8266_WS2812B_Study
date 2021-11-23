#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN D5
#define NUMPIXELS 12

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 100
#define DELAYFOO 400

void setup()
{
  pixels.begin();
}

void Tripleflash()
{
  pixels.clear();
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      pixels.setPixelColor(j, pixels.Color(150, 0, 0));
    }
    pixels.show();
    delay(100);
    for (int j = 0; j < 3; j++)
    {
      pixels.setPixelColor(j, pixels.Color(0, 0, 0));
    }
    pixels.show();
    delay(100);
  }
  pixels.clear();
  delay(DELAYFOO);
  for (int i = 0; i < 3; i++)
  {
    for (int j = 6; j < 9; j++)
    {
      pixels.setPixelColor(j, pixels.Color(0, 0, 150));
    }
    pixels.show();
    delay(100);
    for (int j = 6; j < 9; j++)
    {
      pixels.setPixelColor(j, pixels.Color(0, 0, 0));
    }
    pixels.show();
    delay(100);
  }
  pixels.clear();
  delay(DELAYFOO);
}

void Flash()
{
  for (int i = 0; i < 3; i++)
  {
    pixels.setPixelColor(i, pixels.Color(150, 0, 0));
  }
  pixels.show();
  delay(DELAYVAL);
  delay(DELAYVAL);
  pixels.clear();
  for (int j = 6; j < 9; j++)
  {
    pixels.setPixelColor(j, pixels.Color(0, 0, 150));
  }
  pixels.show();
  delay(DELAYVAL);
  delay(DELAYVAL);
  pixels.clear();
}

void Chase_redblue()
{
  for (int k = 0; k < 9; k = k + 3)
  {
    pixels.setPixelColor(k, pixels.Color(0, 0, 0));
  }
  pixels.show();
  for (int m = 1; m < 8; m = m + 6)
  {
    pixels.setPixelColor(m, pixels.Color(150, 0, 0));
    pixels.setPixelColor(m + 1, pixels.Color(150, 0, 0));
  }
  pixels.show();
  for (int m1 = 4; m1 < 11; m1 = m1 + 6)
  {
    pixels.setPixelColor(m1, pixels.Color(0, 0, 150));
    pixels.setPixelColor(m1 + 1, pixels.Color(0, 0, 150));
  }
  pixels.show();
  delay(250);
  for (int m = 1; m < 8; m = m + 6)
  {
    pixels.setPixelColor(m, pixels.Color(0, 0, 150));
    pixels.setPixelColor(m + 1, pixels.Color(0, 0, 150));
  }
  pixels.show();
  for (int m1 = 4; m1 < 11; m1 = m1 + 6)
  {
    pixels.setPixelColor(m1, pixels.Color(150, 0, 0));
    pixels.setPixelColor(m1 + 1, pixels.Color(150, 0, 0));
  }
  pixels.show();
  pixels.clear();
  delay(250);
}

void Real_partol()
{
  int i = 0;
  pixels.setPixelColor(i, pixels.Color(120, 0, 0));
  pixels.setPixelColor(i + 1, pixels.Color(120, 0, 0));
  pixels.setPixelColor(i + 6, pixels.Color(0, 0, 255));
  pixels.setPixelColor(i + 7, pixels.Color(0, 0, 255));
  pixels.show();
  delay(250);
  pixels.clear();
  i = i + 3;
  pixels.setPixelColor(i, pixels.Color(120, 0, 0));
  pixels.setPixelColor(i + 1, pixels.Color(120, 0, 0));
  pixels.setPixelColor(i + 6, pixels.Color(0, 0, 255));
  pixels.setPixelColor(i + 7, pixels.Color(0, 0, 255));
  pixels.show();
  delay(250);
  pixels.clear();
}

void loop()
{
  for (int x = 0; x < 3; x++)
  {
    Real_partol();
    delay(DELAYVAL);
  }
  delay(DELAYFOO);
  for (int x = 0; x < 3; x++)
  {
    Chase_redblue();
    delay(DELAYVAL);
  }
  delay(DELAYFOO);
  for (int x = 0; x < 3; x++)
  {
    Flash();
    delay(DELAYVAL);
  }
  delay(DELAYFOO);
  for (int x = 0; x < 3; x++)
  {
    Tripleflash();
    delay(DELAYVAL);
  }
  delay(DELAYFOO);
}