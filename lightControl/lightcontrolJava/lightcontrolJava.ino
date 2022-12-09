#include <ESP8266WiFi.h>

// Variables de acceso a wifi
#define WIFI_SSID "Redmi Note 8"
#define WIFI_PASSWORD "76543210"

WiFiClient client;

// Pin de los LED
#define LED1 12  //pin D6 en la tarjeta
#define LED2 13  //pin D7 en la tarjeta
#define LED3 15  //pin D8 en la tarjeta

String dato = "";

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);     //Coexión a la red WiFi

  //Serial.print("Conectando");
  while (WiFi.status() != WL_CONNECTED) {
    delay(50);
    //Serial.print(".");
  }
  //Serial.println("\nConexión establecida");  
  
  pinMode(LED1, OUTPUT);    //Configuración de los puestos como salida
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  digitalWrite(LED1, 0);    //Se inicializan las salidas en 0
  digitalWrite(LED2, 0); 
  digitalWrite(LED3, 0); 
}

void loop() {

  if(Serial.available()){                   //Se escribe en cada puerto según el mensaje que se lea
    String value = Serial.readString();
    if(value == "11") digitalWrite(LED1, 1);
    if(value == "10") digitalWrite(LED1, 0);

    if(value == "21") digitalWrite(LED2, 1);
    if(value == "20") digitalWrite(LED2, 0);
    
    if(value == "31") digitalWrite(LED3, 1);
    if(value == "30") digitalWrite(LED3, 0);
 
    Serial.println(value);                  //Se envia el valor por el puerto Serial
  }
}
