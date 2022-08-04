#include <complex.h>
#undef I
#include <gtest/gtest.h>
#include <signal_processing/signal_processing.h>

TEST(convert_to_2D, DCT) {
    const int N = 4, M = 4;
    double _Complex in[4][4] = {
        {1, 2, 4, -1}, {3, 5, 11, 4}, {-4, 23, 2, -10}, {4, 9, -3, 2}};
    double _Complex valid[4][4] = {{52, 17.9, -38.2, -19.7},
                                   {-1, -11.4, 4.2, 20.5},
                                   {-11.3, -2, 21, 3},
                                   {-13.4, 13.5, -21.2, -15.6}};
    double _Complex out[4][4];
    convert_to_2d((double _Complex *)out, N, M, (double _Complex *)in, dct);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            EXPECT_LE(cabs(valid[i][j] - out[i][j]), 0.1);
        }
    }
    return;
}

TEST(convert_to_2D, IDCT) {
    const int N = 4, M = 4;
    double _Complex in[4][4] = {{52, 17.9, -38.2, -19.7},
                                {-1, -11.4, 4.2, 20.5},
                                {-11.3, -2, 21, 3},
                                {-13.4, 13.5, -21.2, -15.6}};
    double _Complex valid[4][4] = {
        {1, 2, 4, -1}, {3, 5, 11, 4}, {-4, 23, 2, -10}, {4, 9, -3, 2}};
    double _Complex out[4][4];
    convert_to_2d((double _Complex *)out, N, M, (double _Complex *)in, idct);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            EXPECT_LE(cabs(valid[i][j] - out[i][j]), 0.1);
        }
    }
    return;
}

TEST(convert_to_2D, DFT) {
    const int N = 4, M = 4;
    double _Complex in[4][4] = {
        {1, 2, 4, -1}, {3, 5, 11, 4}, {-4, 23, 2, -10}, {4, 9, -3, 2}};
    double _Complex valid[4][4] = {{52, {-10, -44}, -16, {-10, 44}},
                                   {{-5, -11}, {9, 45}, {19, -15}, {-3, -15}},
                                   {-18, {-8, -28}, -6, {-8, 28}},
                                   {{-5, 11}, {-3, 15}, {19, 15}, {9, -45}}};
    double _Complex out[4][4];
    convert_to_2d((double _Complex *)out, N, M, (double _Complex *)in, dft);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            EXPECT_LE(cabs(valid[i][j] - out[i][j]), 0.1);
        }
    }
    return;
}

TEST(convert_to_2D, IDFT) {
    const int N = 4, M = 4;
    double _Complex in[4][4] = {{52, {-10, -44}, -16, {-10, 44}},
                                {{-5, -11}, {9, 45}, {19, -15}, {-3, -15}},
                                {-18, {-8, -28}, -6, {-8, 28}},
                                {{-5, 11}, {-3, 15}, {19, 15}, {9, -45}}};
    double _Complex valid[4][4] = {
        {1, 2, 4, -1}, {3, 5, 11, 4}, {-4, 23, 2, -10}, {4, 9, -3, 2}};
    double _Complex out[4][4];
    convert_to_2d((double _Complex *)out, N, M, (double _Complex *)in, idft);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            EXPECT_LE(cabs(valid[i][j] - out[i][j]), 0.1);
        }
    }
    return;
}

TEST(convert_to_2D, FFT) {
    const int N = 4, M = 4;
    double _Complex in[4][4] = {
        {1, 2, 4, -1}, {3, 5, 11, 4}, {-4, 23, 2, -10}, {4, 9, -3, 2}};
    double _Complex valid[4][4] = {{52, {-10, -44}, -16, {-10, 44}},
                                   {{-5, -11}, {9, 45}, {19, -15}, {-3, -15}},
                                   {-18, {-8, -28}, -6, {-8, 28}},
                                   {{-5, 11}, {-3, 15}, {19, 15}, {9, -45}}};
    double _Complex out[4][4];
    convert_to_2d((double _Complex *)out, N, M, (double _Complex *)in, fft);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            EXPECT_LE(cabs(valid[i][j] - out[i][j]), 0.1);
        }
    }
    return;
}

TEST(convert_to_2D, IFFT) {
    const int N = 4, M = 4;
    double _Complex in[4][4] = {{52, {-10, -44}, -16, {-10, 44}},
                                {{-5, -11}, {9, 45}, {19, -15}, {-3, -15}},
                                {-18, {-8, -28}, -6, {-8, 28}},
                                {{-5, 11}, {-3, 15}, {19, 15}, {9, -45}}};
    double _Complex valid[4][4] = {
        {1, 2, 4, -1}, {3, 5, 11, 4}, {-4, 23, 2, -10}, {4, 9, -3, 2}};
    double _Complex out[4][4];
    convert_to_2d((double _Complex *)out, N, M, (double _Complex *)in, ifft);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            EXPECT_LE(cabs(valid[i][j] - out[i][j]), 0.1);
        }
    }
    return;
}
