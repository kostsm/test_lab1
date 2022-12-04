#ifndef TEST_SOLVE_H
#define TEST_SOLVE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C" {
#include "solve.h"
}

TEST(sum, test1)
{
    std::string output = "ok";
    testing::internal::CaptureStdout();
    solves s = solve(1, 2, '+');
    EXPECT_NEAR(s.result, 3.0, 0.000001);

    std::string text = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(text.c_str(), output.c_str());
}

TEST(sum, test2)
{
    std::string output = "ok";
    testing::internal::CaptureStdout();
    solves s = solve(6, 4, '+');
    EXPECT_NEAR(s.result, 10.0, 0.000001);

    std::string text = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(text.c_str(), output.c_str());
}

TEST(minus, test1)
{
    std::string output = "ok";
    testing::internal::CaptureStdout();
    solves s = solve(1, -4, '-');
    EXPECT_NEAR(s.result, 5.0, 0.000001);

    std::string text = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(text.c_str(), output.c_str());
}

TEST(minus, test2)
{
    std::string output = "ok";
    testing::internal::CaptureStdout();
    solves s = solve(1, 1, '-');
    EXPECT_NEAR(s.result, 0.0, 0.000001);

    std::string text = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(text.c_str(), output.c_str());
}

TEST(devide, test1)
{
    std::string output = "ok";
    testing::internal::CaptureStdout();
    solves s = solve(2, 2, '/');
    EXPECT_NEAR(s.result, 1.0, 0.000001);

    std::string text = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(text.c_str(), output.c_str());
}

TEST(devide, test2)
{
    std::string output = "ok";
    testing::internal::CaptureStdout();
    solves s = solve(4, 6, '/');
    EXPECT_NEAR(s.result, 0.6666666, 0.000001);

    std::string text = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(text.c_str(), output.c_str());
}

TEST(devide, test3)
{
    std::string output = "error";
    testing::internal::CaptureStdout();
    solves s = solve(4, 0, '/');
    EXPECT_NEAR(s.result, 0.0, 0.000001);

    std::string text = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(text.c_str(), output.c_str());
}

TEST(multiple, test1)
{
    std::string output = "ok";
    testing::internal::CaptureStdout();
    solves s = solve(3, 0, '*');
    EXPECT_NEAR(s.result, 0.0, 0.000001);

    std::string text = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(text.c_str(), output.c_str());
}

TEST(multiple, test2)
{
    std::string output = "ok";
    testing::internal::CaptureStdout();
    solves s = solve(6, -5, '*');
    EXPECT_NEAR(s.result, -30.0, 0.000001);

    std::string text = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(text.c_str(), output.c_str());
}

#endif // TEST_SOLVE_H
