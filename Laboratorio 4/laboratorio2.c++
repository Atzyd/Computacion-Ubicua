#include <DHT.h>    
#include <DHT_U.h>

int SENSOR = 2;     
float TEMPERATURA;
float HUMEDAD;

DHT dht(SENSOR, DHT22);   
        
void setup(){
  Serial.begin(9600);   
  dht.begin();      
} 

void loop(){
  
  TEMPERATURA = dht.readTemperature();  
  HUMEDAD = dht.readHumidity();   

  if (isnan(TEMPERATURA) || isnan(HUMEDAD)) {
    Serial.println("Error al leer el sensor DHT22");
  } else {
    Serial.print("Temperatura: ");  
    Serial.print(TEMPERATURA);
    Serial.print(" °C | ");
    Serial.print("Humedad: ");
    Serial.print(HUMEDAD);
    Serial.println(" %");
  }

  delay(2000); 
}