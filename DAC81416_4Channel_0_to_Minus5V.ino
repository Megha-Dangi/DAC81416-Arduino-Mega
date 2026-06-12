#include <SPI.h>

#define CS 53

#define SPICONFIG  0x03
#define BRDCONFIG  0x05
#define DACPWDWN   0x09

#define DACRANGE0  0x0A
#define DACRANGE1  0x0B
#define DACRANGE2  0x0C
#define DACRANGE3  0x0D

#define DAC0 0x10
#define DAC1 0x11
#define DAC2 0x12
#define DAC3 0x13

void writeRegister(byte regAddress, uint16_t data)
{
  digitalWrite(CS, LOW);

  SPI.transfer(regAddress & 0x3F);
  SPI.transfer((data >> 8) & 0xFF);
  SPI.transfer(data & 0xFF);

  digitalWrite(CS, HIGH);
}

uint16_t voltageToCode(float v)
{
  // STRICT LIMITS

  if (v > 0.0)
    v = 0.0;

  if (v < -5.0)
    v = -5.0;

  // DAC81416 in ±10V mode
  float code = ((v + 10.0) / 20.0) * 65535.0;

  return (uint16_t)code;
}

void setup()
{
  Serial.begin(115200);

  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);

  SPI.begin();

  SPI.beginTransaction(
    SPISettings(1000000, MSBFIRST, SPI_MODE1)
  );

  delay(100);

  writeRegister(SPICONFIG, 0x0A84);

  writeRegister(DACRANGE0, 0xAAAA);
  writeRegister(DACRANGE1, 0xAAAA);
  writeRegister(DACRANGE2, 0xAAAA);
  writeRegister(DACRANGE3, 0xAAAA);

  writeRegister(DACPWDWN, 0xF000);
  writeRegister(BRDCONFIG, 0xFFFF);

  delay(100);

  writeRegister(DAC0, voltageToCode(-2.0));
  writeRegister(DAC1, voltageToCode(-3.0));
  writeRegister(DAC2, voltageToCode(-4.0));
  writeRegister(DAC3, voltageToCode(-5.0));

  Serial.println("DAC outputs set");
}

void loop()
{
}