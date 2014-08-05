#include <limits>
#include <vector>
#include "mazecell.h"

MazeCell::MazeCell(void):index(-1),weight(std::numeric_limits<unsigned>::max())
{
  loc.x = -1;
  loc.y = -1;
  checked = false;
  wall.mask = 0;
  for (unsigned i=0; i<DIREC_NUM; ++i) {
    adj_cell.push_back(nullptr);
  }
}

MazeCell::MazeCell(unsigned idx, unsigned w):index(idx),weight(w)
{
  loc.x = idx % MAZE_MAX;
  loc.y = idx / MAZE_MAX;
  checked = false;
  wall.mask = 0;
  for (unsigned i=0; i<DIREC_NUM; ++i) {
    adj_cell.push_back(nullptr);
  }
}

MazeCell::MazeCell(unsigned x, unsigned y, unsigned w):weight(w)
{
  loc.x = x;
  loc.y = y;
  checked = false;
  index = (y-1) * MAZE_MAX + x;
  wall.mask = 0;
  for (unsigned i=0; i<DIREC_NUM; ++i) {
    adj_cell.push_back(nullptr);
  }
}

void MazeCell::setX(unsigned x)
{
  loc.x = x;
}

void MazeCell::setY(unsigned y)
{
  loc.y = y;
}

void MazeCell::setWeight(unsigned w)
{
  weight = w;
}

Coord MazeCell::getCor(void)
{
  return loc;
}

unsigned MazeCell::getWeight(void)
{
  return weight;
}

void MazeCell::setChecked(void)
{
  checked = true;
}

void MazeCell::clearChecked(void)
{
  checked = false;
}

bool MazeCell::isChecked(void)
{
  return checked;
}

unsigned MazeCell::getIndex(void)
{
  return index;
}

void MazeCell::setWallInDirec(Compass direc)
{
  switch(direc) {
  case Compass::N: wall.NORTH = 1; break;
  case Compass::E: wall.EAST = 1; break;
  case Compass::S: wall.SOUTH = 1; break;
  case Compass::W: wall.WEST = 1; break;
  default: return;
  }
}

void MazeCell::unsetWallInDirec(Compass direc)
{
  switch(direc) {
  case Compass::N: wall.NORTH = 0; break;
  case Compass::E: wall.EAST = 0; break;
  case Compass::S: wall.SOUTH = 0; break;
  case Compass::W: wall.WEST = 0; break;
  default: return;
  }
}

bool MazeCell::isWallInDirec(Compass direc)
{
  switch(direc) {
  case Compass::N: return wall.NORTH;
  case Compass::E: return wall.EAST;
  case Compass::S: return wall.SOUTH;
  case Compass::W: return wall.WEST;
  default: return false;
  }
}

unsigned MazeCell::getWallMask(void)
{
  return wall.mask;
}

void MazeCell::addNodeInDirec(Compass direc, MazeCell* node)
{
  adj_cell[direc] = node;
}

MazeCell* MazeCell::getNodeInDirec(Compass direc)
{
  return adj_cell[direc];
}

void MazeCell::delNodeInDirec(Compass direc)
{
  delete adj_cell[direc];
  adj_cell[direc] = nullptr;
}

unsigned MazeCell::coordToIdx(Coord loc)
{
  return (loc.y-1) * MAZE_MAX + loc.x;
}

unsigned MazeCell::coordToIdx(unsigned x, unsigned y)
{
  return (y-1) * MAZE_MAX + x;
}

Coord MazeCell::idxToCoord(unsigned idx)
{
  Coord res;

  res.x = idx % MAZE_MAX;
  res.y = idx / MAZE_MAX;

  return res;
}

Coord MazeCell::compassToCoord(Coord cur, Compass direc)
{
    Coord nxt = cur;

    switch (direc) {
        case Compass::N: --nxt.y; break;
        case Compass::NE: ++nxt.x; --nxt.y; break;
        case Compass::E: ++nxt.x; break;
        case Compass::SE: ++nxt.x; ++nxt.y; break;
        case Compass::S: ++nxt.y; break;
        case Compass::SW: --nxt.x; ++nxt.y; break;
        case Compass::W: --nxt.x; break;
        case Compass::NW: --nxt.x; ++nxt.y; break;
        default: nxt.x = -1; nxt.y = -1;
    }
    return nxt;
}

unsigned MazeCell::compassToIdx(Coord cur, Compass direc)
{
    unsigned res;
    Coord nxt = compassToCoord(cur, direc);

    if (nxt.x < 0 || nxt.y < 0 || nxt.x >= MAZE_MAX || nxt.y >= MAZE_MAX) {
        res = 404;
    } else {
        res = coordToIdx(nxt);
    }
    return res;
}
