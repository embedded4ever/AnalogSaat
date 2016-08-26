#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
int saat_merkezx=42;
int saat_merkezy=24;
int saat_yaricapi=23;
const float dereceden_aciya=0.0174533;
int i,y,z;
void setup() {
  display.begin();
  display.setContrast(20);
  display.clearDisplay();
  display.display(); 
  delay(2000);
}
void ekran_ayarla()
{
   display.drawCircle(saat_merkezx,saat_merkezy,saat_yaricapi,BLACK);
  for(int i=0; i<12; i++)
  {
     saat_cubuklari(i);
  }
  for(int i=0; i<60; i++)
  {
    saat_ibreleri(i);
  }
}
void loop()
{
    display.clearDisplay();
    ekran_ayarla();
    saniye_ciz(i);
    dakika_ciz(y);
    saat_ciz(z);
    //display.setCursor(24,24);
   // display.print("volkan");
    display.display();
    delay(1000);
    i++;
    if(i>=60) { i=i%60; y++;}
    if(y>=60) { y=y%60; z++;}
}
void saniye_ciz(int saniye)
{  
  float saniye_x,saniye_y;
  saniye_x =23*cos((saniye*6+270)*dereceden_aciya);
  saniye_y =23*sin((saniye*6+270)*dereceden_aciya);
  display.drawLine(saat_merkezx,saat_merkezy,saniye_x+saat_merkezx,saniye_y+saat_merkezy,BLACK);
}
void saat_ciz(int saat)
{
  float saat_x,saat_y;
  saat_x=8*cos((saat*30+270)*dereceden_aciya);
  saat_y=8*sin((saat*30+270)*dereceden_aciya);
  display.drawLine(saat_merkezx,saat_merkezy,saat_x+saat_merkezx,saat_y+saat_merkezy,BLACK);
}
void dakika_ciz(int dakika)
{
  
  float dakika_x,dakika_y;
  dakika_x=13*cos((dakika*6+270)*dereceden_aciya);
  dakika_y=13*sin((dakika*6+270)*dereceden_aciya);
  display.drawLine(saat_merkezx,saat_merkezy,dakika_x+saat_merkezx,dakika_y+saat_merkezy,BLACK);
}
void saat_cubuklari(int saat_cubuklari)
{
  float x1, y1, x2, y2;
  saat_cubuklari=saat_cubuklari*30;
  saat_cubuklari=saat_cubuklari+270;
  x1=29*cos(saat_cubuklari*dereceden_aciya);
  y1=29*sin(saat_cubuklari*dereceden_aciya);
  x2=20*cos(saat_cubuklari*dereceden_aciya);
  y2=20*sin(saat_cubuklari*dereceden_aciya);
  display.drawLine(x1+saat_merkezx, y1+saat_merkezy, x2+saat_merkezx, y2+saat_merkezy,BLACK);
}
void saat_ibreleri(int ibre)
{
  float x1, y1, x2, y2;
  ibre=ibre*6;
  ibre=ibre+360;
  x1=23*cos(ibre*dereceden_aciya);
  y1=23*sin(ibre*dereceden_aciya);
  x2=20*cos(ibre*dereceden_aciya);
  y2=20*sin(ibre*dereceden_aciya);
  display.drawLine(x1+saat_merkezx, y1+saat_merkezy, x2+saat_merkezx, y2+saat_merkezy,BLACK);
}


