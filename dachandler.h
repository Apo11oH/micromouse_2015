#ifndef DAC_HANDLER_H_
#define DAC_HANDLER_H_

#include <vector>

class DACHandler
{
public:
  DACHandler(void);
  void addPorts(unsigned port);
  unsigned getNumOfPorts(void);

  bool calibratePorts(void);

private:
  std::vector<unsigned> ports;

}

#endif
