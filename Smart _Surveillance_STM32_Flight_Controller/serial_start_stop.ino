
void start_serial(void){
  Serial.begin(9600);
}

void read_start_stop(void) {

 
  char input;
  if (Serial.available()) {                                                 
     input = Serial.read();  
    
    if (input == '`') {   
     if (start_stop == true){
      start_stop = false;
      }else{
        channel_2 = 1500;                                        ////////Resetting Channel_2 after Calibrating Compass
        start_stop = true;
      }
      
     
  }

      if (input == 'Y') {   
     if (hover_throttle == true){
      serial_throttle = 1490;
      }else{
        serial_throttle = 1520;
        hover_throttle = true;
      }  
  }


     if (input == 'C' && start_stop == false) {   
     calibrate_compass();
     channel_2 = 1500;
     }

      if(input == 'c' && start_stop == false){
      channel_2 = 2000;                                                       /////////Finishing Compass Calibration
       }
      




     if (input == 'X') {
      RTH = false;   
     serial_flight_mode = 1620;    
  }

  if (input == 'Z'){
    
    serial_flight_mode = 1980;
    if (RTH == false){
      RTH = true;
    }else{
    RTH = false;    
    }
  
  }

  if (input == 'L' && start_stop == false){
    calibrate_level();
    
  }

  



 
  }

  
}

/*void read_start_stop(void) {
  char input;
  if (Serial.available()) {                                                   
     input = Serial.read();  
    
    if (input == 'Y') {   
     if (serial_throttle == 1500){
      serial_throttle = 1000;
      }else{
        serial_throttle = 1500;
      }  
  }
  }

}
*/
