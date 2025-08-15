📍 ESP32 com GPS NEO-M8N — Leitura e Conversão para Google Maps

Este projeto demonstra como ler dados de localização de um módulo GPS NEO-M8N usando um ESP32 via UART, fazer o parse das sentenças NMEA com a biblioteca TinyGPSPlus e exibir a latitude/longitude em graus decimais, prontos para uso no Google Maps.

🚀 Funcionalidades

Leitura de sentenças NMEA do NEO-M8N via UART (Serial2 no ESP32).

Conversão automática de latitude/longitude para graus decimais.

Exibição de:

Data e hora (UTC)

Latitude e longitude

Altitude

Número de satélites

Link direto para Google Maps

Compatível com qualquer módulo GPS que envie NMEA 0183.

🔌 Conexões (NEO-M8N → ESP32)
GPS Pin	ESP32 Pin
VCC	3V3
GND	GND
TX	GPIO16 (RX2)
RX	GPIO17 (TX2)

(Os pinos podem ser alterados no código.)

📦 Dependências

Instale a biblioteca TinyGPSPlus de Mikal Hart pelo Gerenciador de Bibliotecas do Arduino IDE.

🛠 Exemplo de uso

Após carregar o código no ESP32 e abrir o Serial Monitor a 115200 baud, a saída será semelhante a:

===== NOVA POSIÇÃO =====
Latitude: 41.242500
Longitude: -9.024833
Data: 16/01/2015
Hora UTC: 11:52:09
Satélites: 10
Altitude: 130.60 m
Google Maps: https://www.google.com/maps?q=41.242500,-9.024833
========================

📜 Licença

Este projeto é de uso livre sob a licença MIT.
