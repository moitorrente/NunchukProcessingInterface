#include <Wire.h>
#include "nunchuck_funcs.h"

const int max_joyx = 223;
const int min_joyx = 27;
const int max_joyy = 229;
const int min_joyy = 38;

int loop_cnt=0;
long map_joyx, map_joyy, map_accx, map_accy;


String powerRight="0";
String powerLeft="0";
byte accx, accy, zbut, cbut, joyx, joyy;
String s_joyx, s_joyy, s_c, s_z, s_accx, s_accy;

void setup()
{
  Serial.begin(19200);
  nunchuck_setpowerpins();
  nunchuck_init(); // send the initilization handshake
}

void loop()
{
  if( loop_cnt > 100 ) { // every 100 msecs get new data
    loop_cnt = 0;

    nunchuck_get_data();

    accx = nunchuck_accelx(); // ranges from approx 70 - 182
    accy = nunchuck_accely(); // ranges from approx 65 - 173
    zbut = nunchuck_zbutton();
    cbut = nunchuck_cbutton(); 
    joyx = nunchuck_joyx();
    joyy = nunchuck_joyy();

//Mapeo del eje x del joystick
    map_joyx=map(joyx, min_joyx, max_joyx, -100, 100);
    if(map_joyx>100){
      map_joyx=100;
    }
    else if(map_joyx<-100){
      map_joyx=-100;
    }
    
//Mapeo del eje y del joystick    
    map_joyy=map(joyy, min_joyy, max_joyy, -100, 100);
    if(map_joyy>100){
      map_joyy=100;
    }
    else if(map_joyy<-100){
      map_joyy=-100;
    }

//Mapeo del eje x del acelerometro
    map_accx=map(accx, 75, 177, -100, 100);
    if(map_accx>100){
      map_accx=100;
    }
    else if(map_accx<-100){
      map_accx=-100;
    }
//Mapeo del eje y del acelerometro
    map_accy=map(accy, 75, 174, -100, 100);
    if(map_accy>100){
      map_accy=100;
    }
    else if(map_accy<-100){
      map_accy=-100;
    }

    s_joyx=(String)map_joyx;
    s_joyy=(String)map_joyy;
    s_c=(String)cbut;
    s_z=(String)zbut;
    s_accx=(String)map_accx;
    s_accy=(String)map_accy;
    
    Serial.print(s_joyx+" "+s_joyy+" "+s_accx+" "+s_accy+" "+s_c+" "+s_z+" "+"a");
  }
  loop_cnt++;
  delay(1);
}








