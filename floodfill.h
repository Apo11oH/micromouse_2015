#ifndef FLOODFILL_H_
#define FLOODFILL_H_
#include "algorithm.h"
#include "mazecell.h"

class Floodfill : public Algorithm
{
public:
  Floodfill(void);
  void runAlgorithm(std::vector<MazeCell> maze);

private:

}

#endif // FLOODFILL_H_
