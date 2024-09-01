#include "Grid.h"
#include <gtest/gtest.h>

TEST(GridTest, GridInit) {
    Grid g{4, 4};
    g.setBit(2, 3);
    EXPECT_TRUE(g.isSet(2, 3));
}

TEST(GridTest, GridTestAllTrue) {
    Grid g{4, 4};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            g.setBit(i, j);
        }
    }
    for (int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            EXPECT_TRUE(g.isSet(i,j));
        }
    }
}

TEST(GridTest, GridInitToZero) {
    Grid g{4, 4};
    for (int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            EXPECT_FALSE(g.isSet(i,j));
        }
    }
}

TEST(GridTest, GridNextState) {
    Grid g{5,5};
    g.setBit(1,1);
    g.setBit(2,2);
    g.setBit(3,1);
    g.nextState();
    EXPECT_TRUE(g.isSet(2,1));
}
