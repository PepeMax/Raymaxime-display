# Raymaxime-display

![Logo Raymaxime](./docs/Raymaxime_logo.png)

## Get started :
Step 1 : Go to **Raymaxime-display** folder and **src** folder and modify **WiFiParameters.h** file.

Command for Linux :

> nano ~/Raymaxime-display/src/WiFiParameters.h

```c++
#define WIFI_SSID "Your_SSID"		*ex: Wifihome*
#define WIFI_PASSWORD  "Your_Pass"		*ex: Mypassofmyhome22*
#define TCP_HOST  "Your_TCP_Host"		*ex: 192.168.0.2*
#define TCP_PORT Your_Port		*ex: 11111*
```

## Controling autopilot :

The autopilot on the Raspberry will be **activated** when **"button A"** was released.

The autopilot on the Raspberry Pi will be **deactivated** when **"button C"** was released
