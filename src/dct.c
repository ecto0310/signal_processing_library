#include "../include/signal_processing/dct.h"

#include <math.h>

int dct_calc(double _Complex *ret, int N, const double _Complex in[], int k) {
    *ret = 0;
    for (int n = 0; n < N; n++) {
        *ret += in[n] * cos((2 * n + 1) * k * M_PI / (2 * N));
    }
    return 0;
}

int dct(double _Complex out[], int N, const double _Complex in[]) {
    for (int i = 0; i < N; i++) {
        dct_calc(&out[i], N, in, i);
    }
    return 0;
}
