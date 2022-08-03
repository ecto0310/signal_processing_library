#include "../include/signal_processing/ifft.h"

#include <complex.h>
#undef I
#include <stdlib.h>

#include "../include/signal_processing/fft.h"

int ifft(double _Complex out[], int N, const double _Complex in[]) {
    double _Complex *con_in = malloc(sizeof(double _Complex) * N);
    double _Complex *con_out = malloc(sizeof(double _Complex) * N);
    for (int i = 0; i < N; i++) {
        con_in[i] = conj(in[i]);
    }

    fft(con_out, N, con_in);
    for (int i = 0; i < N; i++) {
        out[i] = conj(con_out[i]) / N;
    }
    return 0;
}
