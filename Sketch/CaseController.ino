#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN 5
int brightness = 50;

Adafruit_NeoMatrix *matrix = new Adafruit_NeoMatrix(32, 8, PIN,
    NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
    NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
    NEO_GRB            + NEO_KHZ800);

String ssid = "MagicalWifi";
String password = "REDACTED";

bool rainbow = false;

int defaultColor = 0;
String defaultText = "";
int defaultTextColor = 0;

ESP8266WebServer server(80);

void draw(int x, int y, int color)
{
  int first = 0;
  int second = x / 4;

  if (x % 2 == 0)
    first = (x * 8) % 32 + y % 8;
  else
    first = (x * 8) % 32 + (7 - y % 8);

  if (second % 2 == 1)
    first = 31 - first;

  matrix->drawPixel(first, second, color);
}

int drawFullLetter(int index, char letter, int color)
{
  int letterWidth = 4;
  switch (letter)
  {
    case 'A':
      {
        for (int i = 1; i < 8; i++)
          draw(index, i, color);
        for (int i = 1; i < 8; i++)
          draw(index + 3, i, color);
        draw(index + 1, 4, color);
        draw(index + 2, 4, color);
        draw(index + 1, 0, color);
        draw(index + 2, 0, color);
      }
      break;

    case 'B':
      {
        for (int i = 0; i < 8; i++)
          draw(index, i, color);
        draw(index + 1, 0, color);
        draw(index + 2, 0, color);
        draw(index + 3, 1, color);
        draw(index + 3, 2, color);
        draw(index + 2, 3, color);
        draw(index + 1, 3, color);
        draw(index + 3, 4, color);
        draw(index + 3, 5, color);
        draw(index + 3, 6, color);
        draw(index + 2, 7, color);
        draw(index + 1, 7, color);
      }
      break;

    case 'C':
      {
        for (int i = 1; i < 7; i++)
          draw(index, i, color);
        draw(index + 1, 0, color);
        draw(index + 2, 0, color);
        draw(index + 3, 1, color);
        draw(index + 1, 7, color);
        draw(index + 2, 7, color);
        draw(index + 3, 6, color);
      }
      break;

    case 'D':
      {
        for (int i = 0; i < 8; i++)
          draw(index, i, color);
        draw(index + 1, 0, color);
        draw(index + 2, 0, color);
        for (int i = 1; i < 7; i++)
          draw(index + 3, i, color);
        draw(index + 1, 7, color);
        draw(index + 2, 7, color);
      }
      break;

    case 'E':
      {
        for (int i = 0; i < 8; i++)
          draw(index, i, color);
        for (int i = 1; i < 4; i++)
        {
          draw(index + i, 0, color);
          draw(i > 2 ? index + 2 : index + i, 3, color);
          draw(index + i, 7, color);
        }
      }
      break;

    case 'F':
      {
        for (int i = 0; i < 8; i++)
          draw(index, i, color);
        for (int i = 1; i < 4; i++)
        {
          draw(index + i, 0, color);
          draw(i > 2 ? index + 2 : index + i, 3, color);
        }
      }
      break;

    case 'G':
      {
        for (int i = 1; i < 7; i++)
          draw(index, i, color);
        draw(index + 1, 0, color);
        draw(index + 2, 0, color);
        draw(index + 3, 1, color);
        draw(index + 1, 7, color);
        draw(index + 2, 7, color);
        draw(index + 3, 6, color);
        draw(index + 3, 5, color);
        draw(index + 3, 4, color);
        draw(index + 2, 4, color);
      }
      break;

    case 'H':
      {
        for (int i = 0; i < 8; i++)
          draw(index, i, color);
        for (int i = 0; i < 8; i++)
          draw(index + 3, i, color);
        draw(index + 1, 3, color);
        draw(index + 2, 3, color);
      }
      break;

    case 'I':
      {
        for (int i = 0; i < 8; i++)
          draw(index, i, color);
        letterWidth = 1;
      }
      break;

    case 'J':
      {
        for (int i = 0; i < 7; i++)
          draw(index + 3, i, color);
        draw(index, 5, color);
        draw(index, 6, color);
        draw(index + 1, 7, color);
        draw(index + 2, 7, color);
      }
      break;

    case 'K':
      {
        for (int i = 0; i < 8; i++)
          draw(index, i, color);
        draw(index + 3, 0, color);
        draw(index + 3, 1, color);
        draw(index + 2, 2, color);
        draw(index + 1, 3, color);
        draw(index + 2, 4, color);
        draw(index + 3, 5, color);
        draw(index + 3, 6, color);
        draw(index + 3, 7, color);
      }
      break;

    case 'L':
      {
        for (int i = 0; i < 8; i++)
          draw(index, i, color);
        for (int i = 1; i < 4; i++)
          draw(index + i, 7, color);
      }
      break;

    case 'M':
      {
        for (int i = 0; i < 8; i++)
        {
          draw(index, i, color);
          draw(index + 4, i, color);
        }
        draw(index + 1, 1, color);
        draw(index + 2, 2, color);
        draw(index + 3, 1, color);
        letterWidth = 5;
      }
      break;

    case 'N':
      {
        for (int i = 0; i < 8; i++)
        {
          draw(index, i, color);
          draw(index + 3, i, color);
        }
        draw(index + 1, 3, color);
        draw(index + 2, 4, color);
      }
      break;

    case 'O':
      {
        for (int i = 1; i < 7; i++)
        {
          draw(index, i, color);
          draw(index + 3, i, color);
        }
        for (int i = 1; i < 3; i++)
        {
          draw(index + i, 0, color);
          draw(index + i, 7, color);
        }
      }
      break;

    case 'P':
      {
        for (int i = 0; i < 8; i++)
          draw(index, i, color);
        draw(index + 1, 0, color);
        draw(index + 2, 0, color);
        draw(index + 3, 1, color);
        draw(index + 3, 2, color);
        draw(index + 2, 3, color);
        draw(index + 1, 3, color);
      }
      break;

    case 'Q':
      {
        for (int i = 1; i < 7; i++)
        {
          draw(index, i, color);
          draw(index + 3, i < 6 ? i : 5, color);
        }
        for (int i = 1; i < 3; i++)
          draw(index + i, 0, color);
        draw(index + 1, 7, color);
        draw(index + 2, 6, color);
        draw(index + 3, 7, color);
      }
      break;

    case 'R':
      {
        for (int i = 0; i < 8; i++)
          draw(index, i, color);
        draw(index + 1, 0, color);
        draw(index + 2, 0, color);
        draw(index + 3, 1, color);
        draw(index + 3, 2, color);
        draw(index + 2, 3, color);
        draw(index + 1, 3, color);
        draw(index + 1, 4, color);
        draw(index + 2, 5, color);
        draw(index + 3, 6, color);
        draw(index + 3, 7, color);
      }
      break;

    case 'S':
      {
        for (int i = 1; i < 3; i++)
        {
          draw(index + i, 0, color);
          draw(index + i, 3, color);
          draw(index + i, 7, color);
        }
        draw(index, 1, color);
        draw(index, 2, color);
        draw(index + 3, 4, color);
        draw(index + 3, 5, color);
        draw(index + 3, 6, color);
        draw(index + 3, 0, color);
        draw(index, 7, color);
      }
      break;

    case 'T':
      {
        for (int i = 1; i < 8; i++)
          draw(index + 2, i, color);

        for (int i = 0; i < 5; i++)
          draw(index + i, 0, color);

        letterWidth = 5;
      }
      break;

    case 'U':
      {
        for (int i = 0; i < 7; i++)
        {
          draw(index, i, color);
          draw(index + 3, i, color);
        }
        draw(index + 1, 7, color);
        draw(index + 2, 7, color);
      }
      break;

    case 'V':
      {
        for (int i = 0; i < 4; i++)
        {
          draw(index, i, color);
          draw(index + 4, i, color);
        }
        for (int i = 4; i < 7; i++)
        {
          draw(index + 1, i, color);
          draw(index + 3, i, color);
        }
        draw(index + 2, 7, color);
        letterWidth = 5;
      }
      break;

    case 'W':
      {
        for (int i = 0; i < 7; i++)
        {
          draw(index, i, color);
          draw(index + 4, i, color);
        }
        draw(index + 1, 7, color);
        draw(index + 2, 6, color);
        draw(index + 3, 7, color);
        draw(index + 2, 5, color);

        letterWidth = 5;
      }
      break;

    case 'X':
      {
        for (int i = 0; i < 3; i++)
        {
          draw(index, i, color);
          draw(index + 3, i, color);
          draw(index, 5 + i, color);
          draw(index + 3, 5 + i, color);
        }
        draw(index + 1, 3, color);
        draw(index + 2, 3, color);
        draw(index + 1, 4, color);
        draw(index + 2, 4, color);
      }
      break;

    case 'Y':
      {
        for (int i = 0; i < 8; i++)
          draw(index + 3, i, color);
        draw(index + 1, 3, color);
        draw(index + 2, 3, color);
        draw(index, 0, color);
        draw(index, 1, color);
        draw(index, 2, color);
      }
      break;

    case 'Z':
      {
        for (int i = 0; i < 4; i++)
        {
          draw(index + i, 0, color);
          draw(index + i, 7, color);
        }
        draw(index + 3, 1, color);
        draw(index + 3, 2, color);
        draw(index, 5, color);
        draw(index, 6, color);
        draw(index + 2, 3, color);
        draw(index + 1, 4, color);
      }
      break;

    case ' ':
      letterWidth = 3;
      break;
  }

  matrix->show();
  return letterWidth;
}

void drawString(String text, int color)
{
  Serial.println(color);
  int let = 0;
  for (char c : text)
    let += drawFullLetter(let, c, color) + 1;
}

int rgbColor = 0;
bool s0 = true, s1 = false, s2 = false, s3 = false, s4 = false, s5 = false;
int sVal = 0;
int rgbMlt = 10;
long rgbLast = 0;

void turnFalse()
{
  s0 = false;
  s1 = false;
  s2 = false;
  s3 = false;
  s4 = false;
  s5 = false;
}
void updateRGB()
{
  if (millis() - rgbLast > 100)
    rgbLast = millis();
  else
    return;

  if (s0)
  {
    rgbColor = matrix->Color(255, sVal, 0);
    sVal += rgbMlt;
    if (sVal > 255)
    {
      sVal = 255;
      turnFalse();
      s1 = true;
    }
  }
  if (s1)
  {
    rgbColor = matrix->Color(sVal, 255, 0);
    sVal -= rgbMlt;
    if (sVal <= 0)
    {
      sVal = 0;
      turnFalse();
      s2 = true;
    }
  }
  if (s2)
  {
    rgbColor = matrix->Color(0, 255, sVal);
    sVal += rgbMlt;
    if (sVal > 255)
    {
      sVal = 255;
      turnFalse();
      s3 = true;
    }
  }
  if (s3)
  {
    rgbColor = matrix->Color(0, sVal, 255);
    sVal -= rgbMlt;
    if (sVal <= 0)
    {
      sVal = 0;
      turnFalse();
      s4 = true;
    }
  }
  if (s4)
  {
    rgbColor = matrix->Color(sVal, 0, 255);
    sVal += rgbMlt;
    if (sVal > 255)
    {
      sVal = 255;
      turnFalse();
      s5 = true;
    }
  }
  if (s5)
  {
    rgbColor = matrix->Color(255, 0, sVal);
    sVal -= rgbMlt;
    if (sVal <= 0)
    {
      sVal = 0;
      turnFalse();
      s0 = true;
    }
  }
}

IPAddress ip(192, 168, 1, 125);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

void setup()
{
  Serial.begin(115200);
  pinMode(PIN, OUTPUT);
  matrix->begin();
  matrix->setBrightness(brightness);
  matrix->clear();
  matrix->fillScreen(0);
  matrix->show();
  delay(100);

  Serial.println("");
  Serial.println("Connecting to:");
  Serial.print(ssid);


  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266"))
    Serial.println("mDNS started!");
  else
    Serial.println("mDNS error...");

  server.on("/", HTTP_POST, handleRoot);
  server.onNotFound(handleNotFound);

  matrix->fillScreen(matrix->Color(255, 255, 255));
  matrix->show();

  server.begin();
}

void loop()
{
  int ll = rgbLast;
  updateRGB();

  server.handleClient();

  if (rainbow && millis() - ll > 30)
  {
    matrix->fillScreen(rgbColor);
    matrix->show();
  }
}

//Utils
String split(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++)
    if (data.charAt(i) == separator || i == maxIndex)
    {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}


//Handlers
void handleRoot()
{
  if (server.hasArg("colour") && server.arg("colour") != NULL)
  {
    String color = server.arg("colour");
    defaultColor = matrix->Color(split(color, ':', 0).toInt(), split(color, ':', 1).toInt(), split(color, ':', 2).toInt());
    matrix->fillScreen(defaultColor);
    matrix->show();
  }

  if (server.hasArg("toggleRainbow") && server.arg("toggleRainbow") != NULL)
  {
    rainbow = !rainbow;
    rgbColor = 0;
    matrix->fillScreen(defaultColor);
    drawString(defaultText, defaultTextColor);
    matrix->show();
  }

  if (server.hasArg("phrase") && server.arg("phrase") != NULL)
  {
    matrix->fillScreen(defaultColor);
    matrix->show();
    defaultText = split(server.arg("phrase"), ':', 0);
    defaultTextColor = matrix->Color(split(server.arg("phrase"), ':', 1).toInt(), split(server.arg("phrase"), ':', 2).toInt(), split(server.arg("phrase"), ':', 3).toInt());
    drawString(defaultText, defaultTextColor);
  }
  
  if (server.hasArg("brightness") && server.arg("brightness") != NULL)
  {
    matrix->setBrightness(server.arg("brightness").toInt());
    matrix->show();
  }

  server.send(200, "text/plain", "OK");
}

void handleNotFound()
{
  server.send(404, "text/plain", "404: Not Found!");
}
