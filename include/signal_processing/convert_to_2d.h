#pragma once

#ifdef __cplusplus
extern "C" {
#endif

int convert_to_2d(double _Complex out[], int N, int M,
                  const double _Complex in[],
                  int (*func)(double _Complex out[], int N,
                              const double _Complex in[]));

#ifdef __cplusplus
}
#endif
