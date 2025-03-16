#define Throttle 0
#define RC_switch 1
#define Headlight_switch 2

#include<BluetoothSerial.h>
#include<ESP32Servo.h>
#include<VescUart.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

Servo esc;
BluetoothSerial SerialBT;
VescUart UART;

int cmd = 0;
int pos = 1500;
int interval = 100;
int previousMillis = 0;
bool useRC = true;
int RC = 15;
int RC_pos = 1500;
int duration = 0;

int a = 0;
int b = 0;
int c = 0;
bool x = true;

void setup() {
  esc.attach(13);

  pinMode(RC, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(RC), RC_read, CHANGE);
  
  Serial.begin(115200);
  Serial2.begin(115200);
  while (!Serial) {;}
  UART.setSerialPort(&Serial2);

  SerialBT.begin();
  Serial.setTimeout(10);
  Serial2.setTimeout(10);
  SerialBT.setTimeout(10);
}

void loop() {
  SerialBT.register_callback(callback);
  
  if(useRC){
    interrupts();
    Serial.print("RC: ");
    Serial.println(RC_pos);
    esc.writeMicroseconds(RC_pos);
  }

  
  if(SerialBT.available() > 0){ 
    cmd = SerialBT.readStringUntil('#').toInt();
    if(cmd == Throttle){
        pos = SerialBT.readStringUntil('#').toInt();
        if(!useRC){
          noInterrupts();
          Serial.print("BT: ");
          Serial.println(pos);
          esc.writeMicroseconds(pos);
        }
    }
    if(cmd == RC_switch){
        useRC = !useRC;
        Serial.println("RC Switch");
    }
    SerialBT.flush();
  }

  if (millis() - previousMillis >= interval) {
    duration += 100;
    
    if( UART.getVescValues() ){
      Serial.println("Working"); 
      SerialBT.println(UART.data.rpm);
      SerialBT.println(UART.data.inpVoltage);
      SerialBT.println(UART.data.ampHours);
      SerialBT.println(UART.data.tachometerAbs);
      SerialBT.println(UART.data.ampHoursCharged);
      SerialBT.println(duration);
    }
    else{
      Serial.println("Failed to get data!");
    }
    previousMillis = millis();
  }
}

void RC_read(){
    if(digitalRead(RC) == HIGH) a = micros();
    else b = micros();
    if(b > a) RC_pos = constrain(map(b - a, 1180, 1920, 1000, 2000), 1000, 2000);
}

void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param){
  if(event == ESP_SPP_CLOSE_EVT ){
    useRC = true;
  }
}
