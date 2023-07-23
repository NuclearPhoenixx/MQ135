# MQ135 GAS SENSOR

![arduino-library-badge](https://www.ardu-badge.com/badge/MQ135.svg?) ![latest version](https://img.shields.io/github/release/NuclearPhoenixx/MQ135.svg?) ![issues](https://img.shields.io/github/issues/NuclearPhoenixx/MQ135.svg?) ![open pr](https://img.shields.io/github/issues-pr-raw/NuclearPhoenixx/MQ135.svg?)

Updated and improved Arduino library for the MQ135 gas/air quality sensor.

This library is also available in the Arduino IDE, see [Arduino Library List](https://www.arduinolibraries.info/libraries/mq135).

## Datasheet

Can be found [here](https://www.olimex.com/Products/Components/Sensors/SNS-MQ135/resources/SNS-MQ135.pdf).

## Application

This type of sensor is used in air quality control equipments for buildings/offices and is suitable for detecting of NH3, NOx, alcohol, Benzene, smoke, CO2, etc.

## Features

This library has:
 - Corrections for temperature and humidity
 - Measurements:
    - getResistance
    - getCorrectedResistance
    - getPPM
    - getCorrectedPPM
    - getRZero
    - getCorrectedRZero

## Calibration

To get an accurate ppm reading it is important to calibrate the sensor.

To do so put your sensor outside where there is enough fresh air (ideally at 20°C & 33% humidity according to the datasheet) and leave it powered on for 12-24 hours to burn it in and stabilize.

Then you can read out the calibrated resistance value `RZERO` like this (needs to be done when still outside!):

```cpp
float rzero = gasSensor.getRZero();
```

The best way to do this is to average multiple readings to fight ADC noise.
To finish the calibration process you now only need to pass your `RZERO` value to the constructor like this:

```cpp
MQ135 gasSensor(PIN_MQ135, RZERO);
```


## More Info

https://hackaday.io/project/3475-sniffing-trinket/log/12363-mq135-arduino-library
