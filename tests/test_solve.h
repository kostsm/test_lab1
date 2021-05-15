#ifndef TEST_SOLVE_H
#define TEST_SOLVE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C" {
#include "solve.h"
}

TEST(one_solution, test1)
{
    solves s = solve(1, 0, 0);
    EXPECT_EQ(s.count, 1);
    EXPECT_NEAR(s.x1, 0.0, 0.000001);
}

TEST(one_solution, test2)
{
    solves s = solve(2, 4, 2);
    EXPECT_EQ(s.count, 1);
    EXPECT_NEAR(s.x1, -1.0, 0.000001);
}

TEST(one_solution, test3)
{
    solves s = solve(1, -4, 4);
    EXPECT_EQ(s.count, 1);
    EXPECT_NEAR(s.x1, 2.0, 0.000001);
}

TEST(two_solutions, test1)
{
    solves s = solve(1, 1, 0);
    EXPECT_EQ(s.count, 2);
    EXPECT_NEAR(s.x1, -1.0, 0.000001);
    EXPECT_NEAR(s.x2, 0.0, 0.000001);
}

TEST(two_solutions, test2)
{
    solves s = solve(2, 2, -4);
    EXPECT_EQ(s.count, 2);
    EXPECT_NEAR(s.x1, -2.0, 0.000001);
    EXPECT_NEAR(s.x2, 1.0, 0.000001);
}

TEST(two_solutions, test3)
{
    solves s = solve(4, 6, 2);
    EXPECT_EQ(s.count, 2);
    EXPECT_NEAR(s.x1, -1.0, 0.000001);
    EXPECT_NEAR(s.x2, -0.5, 0.000001);
}

TEST(no_solution, test1)
{
    solves s = solve(4, 6, 9);
    EXPECT_EQ(s.count, 0);
}

TEST(no_solution, test2)
{
    solves s = solve(3, 6, 9);
    EXPECT_EQ(s.count, 0);
}

TEST(no_solution, test3)
{
    solves s = solve(6, -5, 20);
    EXPECT_EQ(s.count, 0);
}

TEST(extra_tests, linear)
{
    solves s = solve(0, 1, -1);
    EXPECT_EQ(s.count, 1);
    EXPECT_NEAR(s.x1, 1.0, 0.000001);
}

TEST(extra_tests, zero)
{
    solves s = solve(0, 0, 1);
    EXPECT_EQ(s.count, 0);
}

TEST(extra_tests, infinity)
{
    solves s = solve(0, 0, 0);
    EXPECT_EQ(s.count, 0);
}

TEST(extra_tests, float1)
{
    solves s = solve(1, 0.5, -3.14);
    EXPECT_EQ(s.count, 2);
    EXPECT_NEAR(s.x1, -2.039553, 0.000001);
    EXPECT_NEAR(s.x2, 1.539553, 0.000001);
}

TEST(extra_tests, float2)
{
    solves s = solve(0.25, 3, -7);
    EXPECT_EQ(s.count, 2);
    EXPECT_NEAR(s.x1, -14, 0.000001);
    EXPECT_NEAR(s.x2, 2, 0.000001);
}

#endif // TEST_SOLVE_H
