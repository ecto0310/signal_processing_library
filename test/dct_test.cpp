#include <complex.h>
#undef I
#include <gtest/gtest.h>
#include <signal_processing/dct.h>

TEST(DCT, case1) {
    int N = 8;
    double _Complex in[N] = {1, 2, 8, 3, 7, 2, 3, 8};
    double _Complex valid[N] = {34, -5.1, -2.8, -9.3, 2.8, -5.1, 4.2, 8.1};
    double _Complex out[N];
    dct(out, N, in);
    for (int i = 0; i < N; i++) {
        EXPECT_LE(cabs(valid[i] - out[i]), 0.1);
    }
    return;
}

TEST(DCT, case2) {
    int N = 16;
    double _Complex in[N] = {2, 6, 2, 3, 10, 8, 2, 8, 9, 3, 8, 0, 14, 3, 1, 2};
    double _Complex valid[N] = {81,   1.4, -15.8, 0.5,   -9,   7.4,
                                -4.2, 9.0, 10.6,  -17.3, -5.5, -17.6,
                                6.0,  9.2, -19.7, 12.8};
    double _Complex out[N];
    dct(out, N, in);
    for (int i = 0; i < N; i++) {
        EXPECT_LE(cabs(valid[i] - out[i]), 0.1);
    }
    return;
}
