![Logo Raymaxime](./docs/Raymaxime_logo.png)

# Raymaxime-display
Raymaxime is a multifunction display dedicated to sailing more specifically for sailboats, it allows to display values ​​(ex: wind direction, wind speed, heading, GPS speed, etc).

The Raymaxime was created with an M5Stack so it has a LCD screen of 320x240 pixels, 4 buttons including a destiny to restart the device, a WiFi chip and Bluetooth, a 150 mAh battery that can be upgraded, a USB type-C port and an SD card reader.

The M5Stack is connected to a Wi-Fi Raspberry pi 3, which has the Openplotter operating system, the raaspberry also has a GPS and an ultrasonic wind vane.

## SignalK values ​​that can be retrieved

SignalK | Json
------------ | -------------
Heading | ap.heading
GPS speed | ap.gps_speed
Wind speed |ap.wind_speed
Wind direction |ap.wind_direction
Pilot mode |ap.mode
Pilot status |ap.mode


## Get started :
Step 1 : Go to **Raymaxime-display** folder and **src** folder and modify **WiFiParameters.h** file with your parameters.

Command for Linux :

> nano ~/Raymaxime-display/src/WiFiParameters.h

```c++
#define WIFI_SSID "Your_SSID"       //ex: Wifihome
#define WIFI_PASSWORD  "Your_Pass"  //ex: Mypassofmyhome22
#define TCP_HOST  "Your_TCP_Host"   //ex: 192.168.0.2
#define TCP_PORT Your_Port          //x: 11111
```

Step 2 :  Go to **Raymaxime-display** folder and **src** folder and modify **Setup.h** file and uncomment the default pilot mode that you wish and comment the active mode.

Mode | Value
------------ | ------------
Compass | compass
GPS | gps
Wind | wind
True wind | true wind


Command for Linux :

> nano ~/Raymaxime-display/src/setup.h

```c++
//Choose your default mode of Pypilot

const char* VALUE_PILOT_MODE = "compass";
//const char* VALUE_PILOT_MODE = "gps";
//const char* VALUE_PILOT_MODE = "wind";
//const char* VALUE_PILOT_MODE = "true wind";
```

Step 3 : In this same file choose the parameters of the display

:bangbang: : If you modify this file you must also modify the last 4 lines in the file **main.cpp** so that it matches.

```c++
const char* TEXT_ZONE_1 = "WIND DIR";
const char* TEXT_ZONE_2 = "WIND SPEED";
const char* TEXT_ZONE_3 = "HEADING";
const char* TEXT_ZONE_4 = "TARGET CAP";
```
> nano ~/Raymaxime-display/src/main.cpp

```c++
display_text(TEXT_ZONE_1, Wind_direction, 1);
display_text(TEXT_ZONE_2, Wind_speed, 2);
display_text(TEXT_ZONE_3, True_heading, 3);
display_text(TEXT_ZONE_4, Target_heading, 4);
}
```
Step 4 : In this same file choose the value of TACK .

:bangbang: : **The value of the TACK enter in this file is gale  : your_final_value - 10°.**
```c++
const int TACK = 90; // your number + 9 + 1 || here 90 + 9 + 1 = 100°.
```
*In my exemple my final TACK is 100°.*

## Controling autopilot :

The autopilot of pypilot will be **activated**/**desactivated** when **"button B"** was released.

**Button A** increases the target heading by +1°, +10° and +100°

Pressed For | Result
------------ | -------------
500 ms | + 1°
1500 ms | + 10°
5000 ms | + 100°

**Button C** increases the target heading by -1°, -10° and -100°

Pressed For | Result
------------ | -------------
500 ms | - 1°
1500 ms | - 10°
5000 ms | - 100°
