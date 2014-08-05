#include "dachandler.h"

DACHandler::DACHandler(void)
{
}

void DACHandler::addPorts(unsigned port)
{
  ports.push_back(port);
}

unsigned DACHandler::getNumOfPorts(void)
{
  return ports.size();
}

void DACHandler::calibratePorts(void)
{
}
