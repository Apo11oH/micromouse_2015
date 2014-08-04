#include <iostream>
#include "mazecell.h"
#include "gtest/gtest.h"

TEST(MazeCell, DefaultConstructor)
{
    MazeCell* cell = new MazeCell();

    ASSERT_EQ(-1, (cell->getCor()).x);
    ASSERT_EQ(-1, (cell->getCor()).y);
    ASSERT_EQ(std::numeric_limits<unsigned>::max(), cell->getWeight());
    ASSERT_EQ(false, cell->isChecked());
    ASSERT_EQ(0, cell->getWallMask());
}

TEST(MazeCell, Constructor1)
{
    MazeCell* cell = new MazeCell(10, 10);

    ASSERT_EQ(-1, (cell->getCor()).x);
    ASSERT_EQ(-1, (cell->getCor()).y);
    ASSERT_EQ(std::numeric_limits<unsigned>::max(), cell->getWeight());
    ASSERT_EQ(false, cell->isChecked());
    ASSERT_EQ(0, cell->getWallMask());
}
