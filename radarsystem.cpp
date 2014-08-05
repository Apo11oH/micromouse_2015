#include "radarsystem.h"

RadarSystem::RadarSystem(void)
{
  for (unsigned i=0; i<SENS_NUM; ++i) {
    thresh.push_back(0);
  }
  isCalibrated = true;
}

double RadarSystem::getSensorThresFor(int idx)
{
  if (!isCalibrated) { calibrateSensors(); }
  return thres[idx];
}

void RadarSystem::calibrateSensors(void)
{
  for (unsigned i=0; i<SENS_NUM; ++i) {

  }
}
