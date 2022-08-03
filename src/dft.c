#include "../include/signal_processing/dft.h"

#include <complex.h>
#undef I
#include <math.h>

int dft_calc(double _Complex *ret, int N, const double _Complex in[], int k) {
    *ret = 0;
    for (int n = 0; n < N; n++) {
        *ret += in[n] * cexp(-CMPLX(0, 1) * 2 * M_PI * k * n / N);
    }
    return 0;
}

int dft(double _Complex out[], int N, const double _Complex in[]) {
    for (int i = 0; i < N; i++) {
        dft_calc(&out[i], N, in, i);
    }
    return 0;
}
