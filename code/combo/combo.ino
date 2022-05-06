
// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPLw8mKIMCy"
#define BLYNK_DEVICE_NAME "Solar Panel Data"
#define BLYNK_AUTH_TOKEN "-_vlcjMXEiEdW8NrMt9-Wo-7zYum7s9l"
#define mV_per_amp 200

#define LED_pin 8  //not sure if this works as output pin
#define voltage_pin A2
#define current_pin A3
#define east_pin A0
#define west_pin A1
#define motor_red_pin 12   //wire with green tape
#define motor_black_pin 13\



#define BLYNK_PRINT Serial
#define ESP8266_BAUD 9600


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

//Software Serial for Uno
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(4, 5); // TX from chip goes in 6 (RX pin), Green wire(aka RX) goes in 7 (TX pin) TX(chip)->RX(mcu), RX(chip)->TX(mcu)


char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Daniel's Laptop";
char pass[] = "solarpanel";
int pos=0;
int doTrack;
int manualControl;
int manualEast;
int manualWest;

ESP8266 wifi(&EspSerial);

//LED test to test if Blynk and wifi chip are working
// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V6
BLYNK_WRITE(V6)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V5 to a variable

  // process received value
  digitalWrite(LED_pin,pinValue);
}

BLYNK_WRITE(V7)
{
  doTrack = param.asInt(); // assigning incoming value from pin V7 to a variable
  //Serial.print(doTrack);
}

BLYNK_WRITE(V8)
{
  manualControl = param.asInt(); // assigning incoming value from pin V7 to a variable
  //Serial.print(doTrack);
}
BLYNK_WRITE(V9)
{
  manualEast = param.asInt(); // assigning incoming value from pin V7 to a variable
  //Serial.print(doTrack);
}
BLYNK_WRITE(V10)
{
  manualWest = param.asInt(); // assigning incoming value from pin V7 to a variable
  //Serial.print(doTrack);
}



BlynkTimer power_data_timer;
void voltage_event()
{
  double temp_voltage = 0;
  double temp_current = 0;

  double volttest = analogRead(voltage_pin);
  Serial.println(volttest);
  for (int i = 0; i < 100; i++)
  {
    temp_voltage = temp_voltage + analogRead(voltage_pin);
    temp_current = temp_current + analogRead(current_pin);
  }
  //Serial.print(temp_voltage);
  double volt_configured = temp_voltage/100;
  double volt_configured2 = volt_configured*5/1024;
  //Serial.println(volt_configured);
  double panel_voltage = volt_configured2 * ((10+2)/2);

  //Serial.print("Voltage:    ");
  //Serial.println(panel_voltage);  //voltage divider
  Blynk.virtualWrite(V0, panel_voltage);  //write voltage

  int current_offset = 500 ; // .1 * vcc (mV) (ideally, we should measure to see)

  double panel_current_voltage = (temp_current/100) * (5000/1024);
  double current_scale = (1+2)/2;
  double panel_current = (panel_current_voltage*current_scale - current_offset)/mV_per_amp;
  //Serial.print("Current:    ");
  //Serial.println(panel_current);  //voltage divider
  Blynk.virtualWrite(V1, panel_current);  //write current to Blynk

  double panel_power = panel_voltage * panel_current / 1000;
  Blynk.virtualWrite(V2, panel_power);  //write power to Blynk
  
  double EAST, WEST;
  double diffh, temph;
  EAST = analogRead(east_pin);
  WEST = analogRead(west_pin);
  //Serial.println(west_pin);

  diffh = abs(EAST-WEST);
  temph = (EAST+WEST)/2;
  diffh = 100*(diffh/temph);

  String str1 = "";
  String str2 = "";
  String str3 = "";

  power_data_timer.setTimeout(3000L, ActionOFF);  // Run ActionOFF function in 3 seconds
  //Serial.print(pos);
  if (diffh >= .00001){
      if(EAST<WEST && (pos<30)){ //if east voltage is lower(aka resistance is higher), move clockwise
        str3 = "Move east.";
        Serial.print("East: ");
        Serial.print(String(EAST));
        Serial.print(" West: ");
        Serial.print(String(WEST));
        if(doTrack == 1){
          setMotor(-1);
          pos+=1;
          delay(1000);
        } 
      }
      else if(pos>-30){         //else the west resistance is higher, move west 1 degree to balance
        str3 = "Move west.";
        Serial.print("East: ");
        Serial.print(String(EAST));
        Serial.print(" West: ");
        Serial.print(String(WEST));
        if(doTrack == 1){
          setMotor(1);
          pos-=1;
          delay(1000);
        }
      }
      setMotor(0);
      //delay(500);
  }
  if(manualControl == 1 && doTrack == 0){
          if (manualEast == 1){
            setMotor(-1);
            //delay(1000);
          }
          if (manualWest == 1){
            setMotor(1);
            //delay(1000);
          }
  }
  double east_voltage = EAST*5/1024;
  double west_voltage = WEST*5/1024;
  str1 = "East: " + String(east_voltage, 2);
  str2 = "West: " + String(west_voltage, 2);
  // Send it to the server
  Blynk.virtualWrite(V3, str1);
  Blynk.virtualWrite(V4, str2);
  Blynk.virtualWrite(V5, str3);

} 

//null function just to have timing
void ActionOFF(){

}


void setMotor(int dir) {

  if (dir == 1) { //clockwise
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  else if (dir == -1) {
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
}




void setup()
{
  // Debug console
  pinMode(LED_pin,OUTPUT);
  pinMode(east_pin, INPUT);  //east
  pinMode(west_pin, INPUT);   //west
  pinMode(voltage_pin, INPUT);
  pinMode(current_pin, INPUT);
  pinMode(motor_red_pin, OUTPUT);  //motor
  pinMode(motor_black_pin, OUTPUT);  //motor
  Serial.begin(115200);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);

  power_data_timer.setInterval(1000L, voltage_event);
}

void loop()
{
  Blynk.run();
  power_data_timer.run();
}
