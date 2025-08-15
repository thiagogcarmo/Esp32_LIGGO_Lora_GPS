#include <TinyGPSPlus.h>  // Biblioteca para parse NMEA
#include <HardwareSerial.h>

TinyGPSPlus gps;
HardwareSerial SerialGPS(2); // UART2

// Função para imprimir link Google Maps
void printGoogleMapsLink(double lat, double lng) {
  Serial.print("Google Maps: https://www.google.com/maps?q=");
  Serial.print(lat, 6);
  Serial.print(",");
  Serial.println(lng, 6);
}

void setup() {
  Serial.begin(115200);
  SerialGPS.begin(9600, SERIAL_8N1, 16, 17); // RX=16, TX=17
  Serial.println("Iniciando leitura do GPS NEO-M8N...");
}

void loop() {
  // Ler dados do GPS
  while (SerialGPS.available() > 0) {
    char c = SerialGPS.read();
    gps.encode(c);

    // Quando nova localização for disponível
    if (gps.location.isUpdated()) {
      double lat = gps.location.lat();
      double lng = gps.location.lng();
      Serial.println("===== NOVA POSIÇÃO =====");
      Serial.print("Latitude: ");
      Serial.println(lat, 6);
      Serial.print("Longitude: ");
      Serial.println(lng, 6);

      Serial.print("Data: ");
      if (gps.date.isValid()) {
        Serial.printf("%02d/%02d/%04d\n", gps.date.day(), gps.date.month(), gps.date.year());
      } else {
        Serial.println("Inválida");
      }

      Serial.print("Hora UTC: ");
      if (gps.time.isValid()) {
        Serial.printf("%02d:%02d:%02d\n", gps.time.hour(), gps.time.minute(), gps.time.second());
      } else {
        Serial.println("Inválida");
      }

      Serial.print("Satélites: ");
      Serial.println(gps.satellites.value());

      Serial.print("Altitude: ");
      Serial.print(gps.altitude.meters());
      Serial.println(" m");

      printGoogleMapsLink(lat, lng);
      Serial.println("========================\n");
    }
  }
}
