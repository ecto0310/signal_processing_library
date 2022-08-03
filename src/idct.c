#include "../include/signal_processing/idct.h"

#include <math.h>

int idct_calc(double _Complex *ret, int N, const double _Complex in[], int n) {
    *ret = in[0] / 2;
    for (int k = 1; k < N; k++) {
        *ret += in[k] * cos((2 * n + 1) * k * M_PI / (2 * N));
    }
    *ret *= 2.0 / N;
    return 0;
}

int idct(double _Complex out[], int N, const double _Complex in[]) {
    for (int i = 0; i < N; i++) {
        idct_calc(&out[i], N, in, i);
    }
    return 0;
}
