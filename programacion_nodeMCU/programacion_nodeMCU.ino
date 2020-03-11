//programacion de nodeMCU
/* Para preparar el Arduino IDE para poder programar el nodeMCU
    file>>preferences
    En "additional Boards managers URLs" pegar el siguiente link:
    http://arduino.esp8266.com/stable/package_esp8266com_index.json
    Luego tools>>board>>board manager
    en la barra buscadora escribir esp8266
   Para escoger la tarjeta en el IDE tools>>boards>> "Generic ESP8266 MOdule"
   Para el diagrama de pines ir al link
   https://www.instructables.com/id/Quick-Start-to-Nodemcu-ESP8266-on-Arduino-IDE/
   Informacion para la generacino de PWM
   https://randomnerdtutorials.com/esp8266-pwm-arduino-ide/
   codigo para conectar nodeMCU via wifi con Android
   https://github.com/guzelcihad/android-nodemcu-connection/blob/master/arduino/nodemcu/nodemcu.ino
*/
void setup() {
  pinMode(15, OUTPUT);

}

void loop() {
  for(int a=0;a<1024;a++)
  {
    analogWrite(15,a);//generacion de PWM desde 0 hasta 90%
    delay(50);
  }

}
