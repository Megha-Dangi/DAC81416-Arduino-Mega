# Hardware Connections

## SPI Connections

DAC81416 ↔ Arduino Mega 2560

| DAC81416 Pin | Arduino Mega Pin |
|--------------|------------------|
| CS           | 53 |
| MOSI (SDI)   | 51 |
| MISO (SDO)   | 50 |
| SCLK         | 52 |
| GND          | GND |

---

## LDAC Connection

LDAC → GND

LDAC is tied permanently to GND so DAC outputs update immediately after each SPI write.

---

## Feedback Connections

| DAC Channel | Arduino Analog Input |
|-------------|----------------------|
| DAC0        | A0 |
| DAC1        | A2 |
| DAC2        | A6 |
| DAC3        | A4 |

---

## Output Range

The software limits the DAC outputs to:

0V to -5V

Examples:

- DAC0 = -1V
- DAC0 = -2V
- DAC0 = -3V
- DAC0 = -4V
- DAC0 = -5V

Values outside this range are not used.

---

## Arduino Mega SPI Pins

| Signal | Pin |
|---------|-----|
| MOSI | 51 |
| MISO | 50 |
| SCLK | 52 |
| CS | 53 |
