/**************************************************************************/
/*!
@file     MQ135.h
@author   G.Krocker (Mad Frog Labs)
@license  GNU GPLv3

First version of an Arduino Library for the MQ135 gas sensor
TODO: Review the correction factor calculation. This currently relies on
the datasheet but the information there seems to be wrong.

@section  HISTORY

v1.0 - First release
*/
/**************************************************************************/
#ifndef MQ135_H
#define MQ135_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

/// For details about the parameters below, see:
/// http://davidegironi.blogspot.com/2014/01/cheap-co2-meter-using-mq135-sensor-with.html
/// https://hackaday.io/project/3475-sniffing-trinket/log/12363-mq135-arduino-library

/// Parameters for calculating ppm of CO2 from sensor resistance
#define PARA 116.6020682
#define PARB 2.769034857

/// Parameters to model temperature and humidity dependence
#define CORA .00035
#define CORB .02718
#define CORC 1.39538
#define CORD .0018
#define CORE -.003333333
#define CORF -.001923077
#define CORG 1.130128205

/// Atmospheric CO2 level for calibration purposes,
/// from "Globally averaged marine surface monthly mean data"
/// available at https://gml.noaa.gov/ccgg/trends/gl_data.html
#define ATMOCO2 426.89 // Global CO2 May 2025

class MQ135 {
 private:
  uint8_t _pin;
  float _rload; // The load resistance on the board in kOhm
  float _rzero; // Calibration resistance at atmospheric CO2 level

 public:
  MQ135(uint8_t pin, float rzero=76.63, float rload=10.0);
  float getCorrectionFactor(float t, float h);
  float getResistance();
  float getCorrectedResistance(float t, float h);
  float getPPM();
  float getCorrectedPPM(float t, float h);
  float getRZero();
  float getCorrectedRZero(float t, float h);
};
#endif
