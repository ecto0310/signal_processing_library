#include "../include/signal_processing/fft.h"

#include <complex.h>
#undef I
#include <math.h>
#include <stdlib.h>

int get_bit_length(int N) {
    int ret = 0;
    while (1 < N) {
        N /= 2;
        ret++;
    }
    return ret;
}

int get_bit_reverse(int N, int x) {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (x & (1 << i)) {
            ret |= (1 << (N - i - 1));
        }
    }
    return ret;
}

double _Complex get_rotor(int N, int m) {
    return cexp(-CMPLX(0, 1) * 2 * m * M_PI / N);
}

int fft_calc(double _Complex ret[], int N, const double _Complex in[]) {
    if (N == 1) {
        ret[0] = in[0];
        return 0;
    }
    double _Complex *up = malloc(sizeof(double _Complex) * N / 2);
    double _Complex *down = malloc(sizeof(double _Complex) * N / 2);
    fft_calc(up, N / 2, &in[0]);
    fft_calc(down, N / 2, &in[N / 2]);
    for (int i = 0; i < N / 2; i++) {
        ret[i] = up[i] + get_rotor(N, i) * down[i];
        ret[i + N / 2] =
            get_rotor(N, 0) * up[i] + get_rotor(N, i + N / 2) * down[i];
    }
    free(up);
    free(down);
    return 0;
}

int fft(double _Complex out[], int N, const double _Complex in[]) {
    double _Complex *tmp = malloc(sizeof(double _Complex) * N);
    int bit_length = get_bit_length(N);
    for (int i = 0; i < N; i++) {
        tmp[get_bit_reverse(bit_length, i)] = in[i];
    }

    fft_calc(out, N, tmp);
    free(tmp);
    return 0;
}
