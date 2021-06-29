#include <ESP8266WiFi.h>
#include <WiFiClient.h>

//const char* SSID = "Lau 1 A";
const char* SSID = "LAU 1B";
const char* PASSWORD = "88888888"; 

const char* IP = "54.192.22.61";
int port = 80;

WiFiClient Socket;
char* bitcoin = "GET /v1/bpi/currentprice.json HTTP/1.1\r\nHost: api.coindesk.com\r\n\r\n";
char* buf = (char*)malloc(1024);
char* key = "Dollar\",\"rate_float\":";

void setup(void)
{
  Serial.begin(115200);
  Serial.println();

  Serial.printf("Connecting to %s \n", SSID);
  WiFi.begin(SSID, PASSWORD);
 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println();
  while (!Socket.connect(IP, port))
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Client is connected");
  delay(1000);
  
  Socket.write("GET /v1/bpi/currentprice.json HTTP/1.1\r\nHost: api.coindesk.com\r\n\r\n");
  delay(500);

  while (Socket.available())
  {
    Socket.read (buf, sizeof(buf));
    }
  Serial.printf(buf);
  //buf.toCharArray(res, sizeof(buf));
  //char* Position = strstr(key, res);
 
  //Serial.print(String(Position[4]));
  //while(Position[indx + strlen(key)] != '}')
  //{ 
  //  Serial.printf("Bitcoin = %s USD\r\n", Price[indx]);
  //  indx++;
  //}
  free(buf);
}

void loop() {}
