#include <complex.h>
#undef I
#include <gtest/gtest.h>
#include <signal_processing/dft.h>

TEST(DFT, case1) {
    int N = 8;
    double _Complex in[N] = {1, 2, 8, 3, 7, 2, 3, 8};
    double _Complex valid[N] = {34, {-2.4, -1.5}, {-3, 7},  {-9.5, 8.5},
                                4,  {-9.5, -8.5}, {-3, -7}, {-2.4, 1.5}};
    double _Complex out[N];
    dft(out, N, in);
    for (int i = 0; i < N; i++) {
        EXPECT_LE(cabs(valid[i] - out[i]), 0.1);
    }
    return;
}

TEST(DFT, case2) {
    int N = 16;
    double _Complex in[N] = {2, 6, 2, 3, 10, 8, 2, 8, 9, 3, 8, 0, 14, 3, 1, 2};
    double _Complex valid[N] = {
        81,       {-15.4, -3.3}, {-9.4, -0.6},   {-1.3, -5.7},
        {22, -7}, {-2.7, -4.8},  {-16.5, 13.4},  {-8.4, -18.4},
        15,       {-8.4, 18.4},  {-16.5, -13.4}, {-2.7, 4.8},
        {22, 7},  {-1.3, 5.7},   {-9.4, 0.6},    {-15.4, 3.3}};
    double _Complex out[N];
    dft(out, N, in);
    for (int i = 0; i < N; i++) {
        EXPECT_LE(cabs(valid[i] - out[i]), 0.1);
    }
    return;
}
