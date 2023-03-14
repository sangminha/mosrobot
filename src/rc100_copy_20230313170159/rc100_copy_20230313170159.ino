/*******************************************************************************
* Copyright 2016 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* Predefined RC-100 button key value
* Please refer to Remote Controller Code Map(http://emanual.robotis.com/docs/en/parts/communication/rc-100/#code-map)
* and Remote Controller Packet(http://emanual.robotis.com/docs/en/parts/communication/rc-100/#communication-packet)
*
#define RC100_BTN_U   (1)
#define RC100_BTN_D   (2)
#define RC100_BTN_L   (4)
#define RC100_BTN_R   (8)
#define RC100_BTN_1   (16)
#define RC100_BTN_2   (32)
#define RC100_BTN_3   (64)
#define RC100_BTN_4   (128)
#define RC100_BTN_5   (256)
#define RC100_BTN_6   (512)
*/
#include <DynamixelShield.h>

#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_MEGA2560)
  #include <SoftwareSerial.h>
  SoftwareSerial soft_serial(7, 8); // DYNAMIXELShield UART RX/TX
  #define DEBUG_SERIAL soft_serial
#elif defined(ARDUINO_SAM_DUE) || defined(ARDUINO_SAM_ZERO)
  #define DEBUG_SERIAL SerialUSB    
#else
  #define DEBUG_SERIAL Serial
#endif

#ifdef SoftwareSerial_h
RobotisRemoteController rc100;
#else
RobotisRemoteController rc100(Serial1);
#endif
const float DXL_PROTOCOL_VERSION = 1.0;

DynamixelShield dxl;  
void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:

  // For Uno, Nano, Mini, and Mega, use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  Serial.begin(115200); // 컴퓨터와의 시리얼 통신 초기화

  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(1000000);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  
  // Use UART port of DYNAMIXEL Shield to communicate with ROBOTIS Remote Controller.
  rc100.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t rc100_data;

  if (rc100.availableData() > 0)
  {
    rc100_data = rc100.readData();
    
    switch(rc100_data)
    {
      case RC100_BTN_U:
      dxl.setGoalVelocity(4, 1536);
  dxl.setGoalVelocity(5, 1536);

  dxl.setGoalVelocity(6, 512);

  dxl.setGoalVelocity(7, 512); 
        break;

      case RC100_BTN_D:

        dxl.setGoalVelocity(4, 512);
      dxl.setGoalVelocity(5, 512);

      dxl.setGoalVelocity(6, 1536);

      dxl.setGoalVelocity(7, 1536);   
        break;

      case RC100_BTN_L:
            dxl.setGoalVelocity(4, 1536);
  dxl.setGoalVelocity(5, 1536);

  dxl.setGoalVelocity(6, 0);

  dxl.setGoalVelocity(7, 0); 
      
        break;

      case RC100_BTN_R:
     dxl.setGoalVelocity(4, 0);
  dxl.setGoalVelocity(5, 0);

  dxl.setGoalVelocity(6, 512);

  dxl.setGoalVelocity(7, 512); 
        break;        

      case RC100_BTN_1:

dxl.setGoalPosition(2, 1023);
dxl.setGoalPosition(3, 512); //use default encoder value        break;        
 //use default encoder value        break;        
        break;

      case RC100_BTN_2:
dxl.setGoalPosition(11, 0);
dxl.setGoalPosition(12, 1023); //use default encoder value        break;        
 //use default encoder value        break;        
//use default encoder value        break;        
        break;

      case RC100_BTN_3:
      dxl.setGoalPosition(11, 328); //use default encoder value        break;        

        break;

      case RC100_BTN_4:
dxl.setGoalPosition(2, 640); //use default encoder value        break;        
        break;        

      case RC100_BTN_5:
              dxl.setGoalVelocity(4, 0);
  dxl.setGoalVelocity(5, 0);

  dxl.setGoalVelocity(6, 0);

  dxl.setGoalVelocity(7, 0); 
        break;

      case RC100_BTN_6:
             dxl.setGoalVelocity(4, 0);
  dxl.setGoalVelocity(5, 0);

  dxl.setGoalVelocity(6, 0);

  dxl.setGoalVelocity(7, 0); 
        break;
    }
  }
}
