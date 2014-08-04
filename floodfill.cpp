#include "floodfill.h"
#include "mazecell.h"

// Default Constructor
Floodfill::Floodfill(void):Algorithm("floodfill")
{
}

// Executes the floodfill algorithm
void Floodfill::runAlgorithm(std::vector<MazeCell*> maze)
{
  std::queue<MazeCell*> nxt_batch;
  // Add center to the nxt_batch
  nxt_batch.push(maze[MazeCell::coordToIdx(8, 8)]);
  nxt_batch.push(maze[MazeCell::coordToIdx(8, 9)]);
  nxt_batch.push(maze[MazeCell::coordToIdx(9, 8)]);
  nxt_batch.push(maze[MazeCell::coordToIdx(9, 9)]);

  // while nxt_batch is not empty
  while (!nxt_batch.empty()) {
    MazeCell *cur = nxt_batch.front();
    nxt_batch.pop();
    for (auto i=N; i!=LAST; ++i) {
      if (!cur->isWallInDirec(i)) {
        MazeCell *temp = cur->getNodeInDirec(i);
        if (cur->getWeight() <= temp->getWeight()) {
          temp->setWeight((cur->getWeight())+1)
          nxt_batch.push(temp);
        }
      }
    } // inner for loop
  } // while loop
}
