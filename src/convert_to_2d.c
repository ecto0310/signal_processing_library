#include "../include/signal_processing/convert_to_2d.h"

#include <complex.h>
#undef I
#include <stdlib.h>

int convert_to_2d(double _Complex out[], int N, int M,
                  const double _Complex in[],
                  int (*func)(double _Complex out[], int N,
                              const double _Complex in[])) {
    double _Complex *tmp = malloc(sizeof(double _Complex) * N * M);
    for (int i = 0; i < N; i++) {
        func(&tmp[i * M], M, &in[i * M]);
    }
    for (int i = 0; i < M; i++) {
        double _Complex *v_in = malloc(sizeof(double _Complex) * N);
        double _Complex *v_out = malloc(sizeof(double _Complex) * N);
        for (int j = 0; j < N; j++) {
            v_in[j] = tmp[j * M + i];
        }
        func(v_out, N, v_in);
        for (int j = 0; j < N; j++) {
            out[j * M + i] = v_out[j];
        }
    }
    return 0;
}
