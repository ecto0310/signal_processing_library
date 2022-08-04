#include <complex.h>
#undef I
#include <gtest/gtest.h>
#include <signal_processing/util.h>

TEST(get_frequency, case1) {
    EXPECT_EQ(get_frequency(1000, 1, 1), 1);
    return;
}

TEST(get_frequency, case2) {
    EXPECT_EQ(get_frequency(1000, 1, 990), 10);
    return;
}

TEST(get_time, case1) {
    EXPECT_EQ(get_time(1000, 1), 0.001);
    return;
}

TEST(get_time, case2) {
    EXPECT_EQ(get_time(1000, 1024), 1.024);
    return;
}

TEST(get_power, case1) {
    EXPECT_EQ(get_power({100, 100}), 20000);
    return;
}

TEST(get_power, case2) {
    EXPECT_EQ(get_power({100, -100}), 20000);
    return;
}
