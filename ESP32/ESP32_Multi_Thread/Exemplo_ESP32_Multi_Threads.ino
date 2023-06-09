TaskHandle_t Thread_1;
TaskHandle_t Thread_2;

int threshold = 40;

void setup() {
  Serial.begin(115200);
  xTaskCreatePinnedToCore(Thread_1Codigo,"Thread_1",10000,NULL,1,&Thread_1,0);                
  delay(500);
  xTaskCreatePinnedToCore(Thread_2Codigo,"Thread_2",10000,NULL,1,&Thread_2,1);          
  delay(500); 
} 

void Thread_1Codigo( void * pvParameters ){
  Serial.print("Core ");
  Serial.println(xPortGetCoreID());
  touchAttachInterrupt(T3, gotToqueT3, threshold);

}
void Thread_2Codigo( void * pvParameters ){
  Serial.print("Core ");
  Serial.println(xPortGetCoreID());
  touchAttachInterrupt(12, gotToque12, threshold);
}

void gotToque12(){ 
 digitalWrite(23,HIGH);
}

void gotToqueT3(){ 
 digitalWrite(23,LOW);
}

void loop() {
  
}
