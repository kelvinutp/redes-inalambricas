#include <ESP8266WiFi.h>

WiFiServer server(80);

String header;

String Fuente = "off";
String output8State = "off";
String output7State = "off";
String output6State = "off";
String output5State = "off";
String output4State = "off";
String output3State = "off";
String output2State = "off";
String output1State = "off";

const int pfuente = 0;
const int output8 = 8;
const int output7 = 7;
const int output6 = 6;
const int output5 = 5;
const int output4 = 4;
const int output3 = 3;
const int output2 = 2;
const int output1 = 1;

unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);

  digitalWrite(output8, LOW);
  digitalWrite(output7, LOW);
  digitalWrite(output6, LOW);
  digitalWrite(output5, LOW);
  digitalWrite(output4, LOW);
  digitalWrite(output3, LOW);
  digitalWrite(output2, LOW);
  digitalWrite(output1, LOW);
  digitalWrite(pfuente, LOW);
  Serial.println("conexion via AP");
  server.begin();
  WiFi.mode(WIFI_AP);
  WiFi.softAP("aplicaCHON","12345678");
  IPAddress local_ip(192, 168, 43, 119);                           //Modifica la dirección IP 
  IPAddress gateway(192, 168, 1, 1);   
  IPAddress subnet(255, 255, 255, 0);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  Serial.println();
  Serial.print("Access Point - La direccion IP: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) {
      currentTime = millis();
      if (client.available()) {
        char c = client.read();
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();


            if (header.indexOf("GET /5/on HTTP/1.1") >= 0) {//5
              Serial.println("cambio en GPIO 5");
              output5State = "on";
              digitalWrite(output5, HIGH);
            } else if (header.indexOf("GET /5/off") >= 0) {//5
              Serial.println("GPIO 5 off");
              output5State = "off";
              digitalWrite(output5, LOW);
            } else if (header.indexOf("GET /4/on") >= 0) {//4
              Serial.println("GPIO 4 on");
              output4State = "on";
              Serial.println("entra4");
              digitalWrite(output4, HIGH);
            } else if (header.indexOf("GET /4/off") >= 0) {//4
              Serial.println("GPIO 4 off");
              output4State = "off";
              digitalWrite(output4, LOW);
            } else if (header.indexOf("GET /3/on") >= 0) {//3
              Serial.println("GPIO 3 on");
              output3State = "on";
              Serial.println("entra3");
              digitalWrite(output3, HIGH);
            } else if (header.indexOf("GET /3/off") >= 0) {//3
              Serial.println("GPIO 3 off");
              output3State = "off";
              digitalWrite(output3, LOW);
            } else if (header.indexOf("GET /2/on") >= 0) {//2
              Serial.println("GPIO 2 on");
              output2State = "on";
              Serial.println("entra2");
              digitalWrite(output2, HIGH);
            } else if (header.indexOf("GET /2/off") >= 0) {//2
              Serial.println("GPIO 2 off");
              output2State = "off";
              digitalWrite(output2, LOW);
            } else if (header.indexOf("GET /1/on") >= 0) {//1
              Serial.println("GPIO 1 on");
              output1State = "on";
              Serial.println("entra1");
              digitalWrite(output1, HIGH);
            } else if (header.indexOf("GET /1/off") >= 0) {//1
              Serial.println("GPIO 1 off");
              output1State = "off";
              digitalWrite(output1, LOW);
            } else if (header.indexOf("GET /6/on") >= 0) {//6
              Serial.println("GPIO 6 on");
              output6State = "on";
              Serial.println("entra6");
              digitalWrite(output6, HIGH);
            } else if (header.indexOf("GET /6/off") >= 0) {//6
              Serial.println("GPIO 6 off");
              output6State = "off";
              digitalWrite(output6, LOW);
            }  else if (header.indexOf("GET /7/on") >= 0) {//7
              Serial.println("GPIO 7 on");
              output7State = "on";
              Serial.println("entra7");
              digitalWrite(output7, HIGH);
            } else if (header.indexOf("GET /7/off") >= 0) {//7
              Serial.println("GPIO 7 off");
              output7State = "off";
              digitalWrite(output7, LOW);
            } else if (header.indexOf("GET /8/on") >= 0) {//8
              Serial.println("GPIO 8 on");
              output8State = "on";
              Serial.println("entra8");
              digitalWrite(output8, HIGH);
            } else if (header.indexOf("GET /8/off") >= 0) {//8
              Serial.println("GPIO 8 off");
              output8State = "off";
              digitalWrite(output8, LOW);
            } else if (header.indexOf("GET /fuente/on") >= 0) {//fuente
              Serial.println("Fuente on");
              Fuente = "on";
              digitalWrite(pfuente, HIGH);
            } else if (header.indexOf("GET /fuente/off") >= 0) {//fuente
              Serial.println("Fuente off");
              Fuente = "off";
              digitalWrite(pfuente, LOW);
            }

            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");

            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button");
            client.println(".button2");
            client.println(".button3");
            client.println(".button4");
            client.println(".button5");
            client.println(".button6");
            client.println(".button7");
            client.println(".button8");
            client.println(".button5</style></head>");

            client.println("<body><h1>Control de Relay</h1>");

            client.println("<p>Control de fuente " + Fuente + "</p>");
            if (Fuente == "off") {
              client.println("<p><a href=\"/fuente/on\"><button class=\"button\">ON</button></a></p>");
              output1State = "off";
              digitalWrite(output1, LOW);
              output2State = "off";
              digitalWrite(output2, LOW);
              output3State = "off";
              digitalWrite(output3, LOW);
              output4State = "off";
              digitalWrite(output4, LOW);
              output5State = "off";
              digitalWrite(output5, LOW);
              output6State = "off";
              digitalWrite(output6, LOW);
              output7State = "off";
              digitalWrite(output7, LOW);
              output8State = "off";
              digitalWrite(output8, LOW);           
            } else {
              client.println("<p><a href=\"/fuente/off\"><button class=\"button\">OFF</button></a></p>");

              client.println("<p>Relay 1 " + output1State + "</p>");
              if (output1State == "off") {
                client.println("<p><a href=\"/1/on\"><button class=\"button\">ON</button></a></p>");
              } else {
                client.println("<p><a href=\"/1/off\"><button class=\"button button\">OFF</button></a></p>");
              }

              client.println("<p>Relay 2 " + output2State + "</p>");
              if (output2State == "off") {
                client.println("<p><a href=\"/2/on\"><button class=\"button\">ON</button></a></p>");
              } else {
                client.println("<p><a href=\"/2/off\"><button class=\"button button2\">OFF</button></a></p>");
              }

              client.println("<p>Relay 3 " + output3State + "</p>");
              if (output3State == "off") {
                client.println("<p><a href=\"/3/on\"><button class=\"button\">ON</button></a></p>");
              } else {
                client.println("<p><a href=\"/3/off\"><button class=\"button button3\">OFF</button></a></p>");
              }

              client.println("<p>Relay 4 " + output4State + "</p>");
              if (output4State == "off") {
                client.println("<p><a href=\"/4/on\"><button class=\"button\">ON</button></a></p>");
              } else {
                client.println("<p><a href=\"/4/off\"><button class=\"button button4\">OFF</button></a></p>");
              }


              client.println("<p>Relay 5 " + output5State + "</p>");
              if (output5State == "off") {
                client.println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
              } else {
                client.println("<p><a href=\"/5/off\"><button class=\"button button5\">OFF</button></a></p>");
              }

              client.println("<p>Relay 6 " + output6State + "</p>");
              if (output6State == "off") {
                client.println("<p><a href=\"/6/on\"><button class=\"button\">ON</button></a></p>");
              } else {
                client.println("<p><a href=\"/6/off\"><button class=\"button button\">OFF</button></a></p>");
              }

              client.println("<p>Relay 7 " + output7State + "</p>");
              if (output7State == "off") {
                client.println("<p><a href=\"/7/on\"><button class=\"button\">ON</button></a></p>");
              } else {
                client.println("<p><a href=\"/7/off\"><button class=\"button button\">OFF</button></a></p>");
              }

              client.println("<p>Relay 8 " + output8State + "</p>");
              if (output8State == "off") {
                client.println("<p><a href=\"/8/on\"><button class=\"button\">ON</button></a></p>");
              } else {
                client.println("<p><a href=\"/8/off\"><button class=\"button button\">OFF</button></a></p>");
              }

            }

            client.println("</body></html>");

            client.println();
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
