![Logo Raymaxime](./docs/Raymaxime_logo.png)

# Raymaxime-display

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

## Controling autopilot :

The autopilot on the Raspberry will be **activated** when **"button A"** was released.

The autopilot on the Raspberry Pi will be **deactivated** when **"button C"** was released


## SignalK values ​​that can be retrieved

SignalK | Json
------------ | -------------
Heading | ap.heading
GPS speed | ap.gps_speed
Wind speed |ap.wind_speed
Wind direction |ap.wind_direction
Pilot mode |ap.mode
Pilot status |ap.mode
