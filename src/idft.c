#include "../include/signal_processing/idft.h"

#include <complex.h>
#undef I
#include <math.h>

int idft_calc(double _Complex *ret, int N, const double _Complex in[], int k) {
    *ret = 0;
    for (int n = 0; n < N; n++) {
        *ret += in[n] * cexp(CMPLX(0, 1) * 2 * M_PI * k * n / N);
    }
    *ret /= N;
    return 0;
}

int idft(double _Complex out[], int N, const double _Complex in[]) {
    for (int i = 0; i < N; i++) {
        idft_calc(&out[i], N, in, i);
    }
    return 0;
}
