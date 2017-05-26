#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
char server[] = "www.madslind.nu";   
float temp = 666;

// Token key to php file.
String tokenkey = "token1234";
// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192,168,1,177);

void setup() {
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
}

void loop() {

// Initialize the Ethernet client library.
EthernetClient client;

// start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
  }
   if (client.connect(server, 80)) {
     client.print("GET /add.php?token=");
     client.print(String(tokenkey));
     client.print("&temp=");
     client.print(temp);
     client.println(" HTTP/1.1");
     client.println("Host: www.madslind.nu");
     client.println("User-Agent: Arduino");
     client.println("Accept: text/html");
     client.println("Connection: close");
     client.println();
     
     Serial.print("Connected -  temp ");
     Serial.print(temp);
     Serial.print(" is saved!");
     Serial.println();
     
  } else {
    Serial.println("Connection failed");
  }
  
  // Skal vente 5 sec med at lave næste måling.
  delay(5000);
}
