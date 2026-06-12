# DAC81416-Arduino-Mega

DAC81416 control using Arduino Mega, output limited from 0V to -5V.

## SPI Connections

| DAC81416 Pin | Arduino Mega Pin |
|--------------|------------------|
| CS           | 53 |
| MOSI (SDI)   | 51 |
| MISO (SDO)   | 50 |
| SCLK         | 52 |
| GND          | GND |

## LDAC Connection

LDAC → GND

LDAC is permanently connected to GND so the DAC output updates immediately after every SPI write.

## Feedback Connections

| DAC Output | Arduino Pin |
|------------|-------------|
| DAC0 | A0 |
| DAC1 | A2 |
| DAC2 | A6 |
| DAC3 | A4 |

## Output Range

The software limits DAC outputs to:

0V to -5V

Examples:

- DAC0 = -1V
- DAC1 = -2V
- DAC2 = -3V
- DAC3 = -4V
  

## Notes

- Arduino Mega 2560 used
- DAC81416 EVM used
- LDAC connected to GND
- SPI communication verified
- DAC outputs verified using a multimeter
