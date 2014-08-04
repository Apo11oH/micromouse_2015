#ifndef ALGORITHM_H_
#define ALGORITHM_H_
#include "mazecell.h"

class Algorithm
{
public:
  Algorithm(void);
  Algorithm(std::string n);
  virtual void runAlgorithm(std::vector<MazeCell*> maze);

private:
  std::string name;
}

#endif // ALGORITHM_H_
