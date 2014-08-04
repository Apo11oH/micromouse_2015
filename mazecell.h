#ifndef MAZE_CELL_H_
#define MAZE_CELL_H_

#include <vector>

#define DIREC_NUM 8
#define MAZE_MAX 16

typedef union {
  unsigned mask:4;
  struct {
    unsigned NORTH:1;
    unsigned EAST:1;
    unsigned SOUTH:1;
    unsigned WEST:1;
  };
} Walls;

typedef struct coord {
  unsigned x;
  unsigned y;
} Coord;

enum Compass { N, NE, E, SE, S, SW, W, NW, LAST };

class MazeCell
{
public:
  MazeCell(void);
  MazeCell(unsigned idx, unsigned w);
  MazeCell(unsigned x, unsigned y, unsigned w);
  void setX(unsigned x);
  void setY(unsigned y);
  void setWeight(unsigned w);
  Coord getCor(void);
  unsigned getWeight(void);
  void setChecked(void);
  void clearChecked(void);
  bool isChecked(void);
  void setWallInDirec(Compass direc);
  void unsetWallInDirec(Compass direc);
  bool isWallInDirec(Compass direc);
  unsigned getWallMask(void);
  void addNodeInDirec(Compass direc, MazeCell* node);
  MazeCell* getNodeInDirec(Compass direc);
  void delNodeInDirec(Compass direc);
  static unsigned coordToIdx(Coord loc);
  static unsigned coordToIdx(unsigned x, unsigned y);
  static Coord idxToCoord(unsigned idx);

private:
  Coord loc;
  unsigned index;
  unsigned weight;
  bool checked;
  Walls wall;
  std::vector<MazeCell*> adj_cell;
};

#endif
