/*  ESP8266模块在Nodemcu开发板上的程序实操  */
/*  12个WS2812B模块组成的灯环实现模拟警灯的各种显示效果  */
/*  实现用智能手机（或者其他终端）对ESP8266进行配网 */

/* 包含Ardinou标准头文件 Adafruit灯珠控制头文件和WifiManager配网头文件 */
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <WiFiManager.h>

/* 定义数据针脚为 D5，定义灯珠数量为 12 */
#define PIN D5
#define NUMPIXELS 12

/* 帮助微控制器与NeoPixel进行通信 */
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

/* 定义标准短延时和标准长延时 */
#define DELAYVAL 100
#define DELAYFOO 400

/*  初始化LED,只执行一次  */
void setup()
{
//建立WiFiManager对象 ，下列为链接到ESP8266时的WiFi名称
  WiFiManager wifiManager;
  wifiManager.autoConnect("ESP8266 配网助手");
//如果连接成功，则启动预设的LED灯显示作为指示
  pixels.begin();
}

/* 定义各功能函数 (必须定义在loop函数前否则无法调用并执行）*/

// 红灯/蓝灯三连闪并交替
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
    delay(75);
    for (int j = 0; j < 3; j++)
    {
      pixels.setPixelColor(j, pixels.Color(0, 0, 0));
    }
    pixels.show();
    delay(DELAYVAL);
  }
  pixels.clear();
  delay(75);
  for (int i = 0; i < 3; i++)
  {
    for (int j = 6; j < 9; j++)
    {
      pixels.setPixelColor(j, pixels.Color(0, 0, 150));
    }
    pixels.show();
    delay(75);
    for (int j = 6; j < 9; j++)
    {
      pixels.setPixelColor(j, pixels.Color(0, 0, 0));
    }
    pixels.show();
    delay(75);
  }
  pixels.clear();
  delay(DELAYFOO);
}

// 红灯蓝灯交替闪烁
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

// 红灯蓝灯流水
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

// 模拟真实警灯闪烁
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

// 红色呼吸灯启动和熄灭
void Breath()
{
  int j = 0;
  int i = 0;
  while (j <= 150)
  {
    for (i = 0; i < 12; i++)
    {
      pixels.setPixelColor(i, pixels.Color(j, 0, 0));
    }
    pixels.show();
    j++;
    pixels.setPixelColor(i, pixels.Color(j, 0, 0));
    pixels.show();
    delay(20);
  }
  delay(200);
  j = 150;
  while (j >= 0)
  {
    for (i = 0; i < 12; i++)
    {
      pixels.setPixelColor(i, pixels.Color(j, 0, 0));
    }
    pixels.show();
    j--;
    pixels.setPixelColor(i, pixels.Color(j, 0, 0));
    pixels.show();
    delay(40);
  }
}

/* 主功能函数，循环执行 */
void loop()
{
  for (int x = 0; x < 3; x++)
  {
    Breath();
    delay(DELAYVAL);
  }
  delay(DELAYFOO);
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