#ifndef NAV_SYSTEM_H_
#define NAV_SYSTEM_H_

#include "DACHandler.h"

class NavSystem
{
public:
  NavSystem(void);
  void stopAll(void);
  void moveForward(void);
  void turnRight(void);
  void turnLeft(void);
  void turn180(void);
  void runPid(void);

  void calibratePid(void);


private:
  bool isRacing;
  double cur_v_r;
  double cur_v_l;
  volatile unsigned enc_count;
  double cur_itg;
  double cur_time;
  double old_err;
  double old_prop;
  double old_time;
  DACHandler dac;
};

#endif
