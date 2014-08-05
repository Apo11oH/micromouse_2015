#ifndef RADAR_SYSTEM_H_
#define RADAR_SYSTEM_H_

#include <vector>
#include "mazecell.h"

#define SENS_NUM 6

class RadarSystem
{
public:
  RadarSystem(void);
  double getSensorThresFor(int idx);

  void calibrateSensors(void);


private:
  std::vector<double> thres;
  bool isCalibrated = false;
};

#endif
