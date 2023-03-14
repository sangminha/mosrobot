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

const float DXL_PROTOCOL_VERSION = 1.0;

DynamixelShield dxl;

//This namespace is required to use Control table item names

void setup() {
  // put your setup code here, to run once:

  // For Uno, Nano, Mini, and Mega, use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  Serial.begin(115200); // 컴퓨터와의 시리얼 통신 초기화

  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(1000000);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.

}

void loop() {
  // put your main code here, to run repeatedly:
  
if(DEBUG_SERIAL.available()){
//  Serial.write(BTSerial.read());
 byte data = DEBUG_SERIAL.read();
  
  Serial.println(data);
  
 if(data == 0) {
  dxl.setGoalVelocity(4, 500);
  dxl.setGoalVelocity(5, 500);

  dxl.setGoalVelocity(6, 1500);

  dxl.setGoalVelocity(7, 1500);

 }

  }
  
}
