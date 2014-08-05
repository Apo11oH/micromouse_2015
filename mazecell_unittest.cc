#include <iostream>
#include "mazecell.h"
#include "gtest/gtest.h"

//  Default constructor
//      check index
//      check weight
//      check location
//      checked flag
//      wall mask
//      adj. node vector size
TEST(MazeCell, DefaultConstructor)
{
    MazeCell* cell = new MazeCell();

    ASSERT_EQ(-1, (cell->getCor()).x);
    ASSERT_EQ(-1, (cell->getCor()).y);
    ASSERT_EQ(-1, cell->getIndex());
    ASSERT_EQ(std::numeric_limits<unsigned>::max(), cell->getWeight());
    ASSERT_EQ(false, cell->isChecked());
    ASSERT_EQ(0, cell->getWallMask());
}

//  Constructor with 2 params
//      check index
//      check weight
//      check location
//      checked flag
//      wall mask
//      adj. node vector size
TEST(MazeCell, Constructor1)
{
    MazeCell* cell = new MazeCell(10, 10);

    ASSERT_EQ(10, (cell->getCor()).x);
    ASSERT_EQ(0, (cell->getCor()).y);
    ASSERT_EQ(10, cell->getWeight());
    ASSERT_EQ(false, cell->isChecked());
    ASSERT_EQ(0, cell->getWallMask());
}

//  Constructor with 3 params
//      check index
//      check weight
//      check location
//      checked flag
//      wall mask
//      adj. node vector size
TEST(MazeCell, Constructor1)
{
    MazeCell* cell = new MazeCell(2, 3, 8);
}

//  All the getters and setters

//  Wall setting and unsetting
//      Set two directions
//      check mask (using isWallInDirec)
//      set another direction and unset the original 2 direction
//      check mask (using getWallMask)

//  Adj node setting and unsetting
//      Set two directions
//      check by comparing with nullptr
//      set another direction and unset the delete 2 direction
//      check by comparing with nullptr

//  Cord to Idx and vice versa
//      simple check by arithmetic
