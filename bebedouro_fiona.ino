#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
// Insira sua rede e sua senha

    const char* nome = "FIONA";
    const char* senha = "J531128550";
    const int pino_led = D8; // pino onde o LED está conectado
    char auth[] = "aa96cccfd1db43fba6d2ab45491496a5";          
 
    int wifiStatus;
 
    void setup() {
      
      Serial.println("Ola, seja muito bem vindo!");
      
        
      // Fazendo a conexão
 
      Serial.print("Iniciando a conexão na rede >>> ");
      Serial.println(nome);
      Serial.println("Por favor, aguarde alguns instantes");
 
      WiFi.begin(nome, senha);
     
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(">");
        
      }
        Blynk.begin(auth, nome, senha);
      
 }   
 
void loop() {
      wifiStatus = WiFi.status();

      if(wifiStatus == WL_CONNECTED){
         Serial.println("Uhulllllllll... O nodeMCU esta conectado!");  
         Serial.print("O IP utilizado na conexão é: ");
         Serial.println(WiFi.localIP()); 
        }  
      else{
         Serial.println("Ahhhhhhhhhhh...O nodeMCU não esta conectado!");
      }
      delay(1000);
      Blynk.run();
 
}
