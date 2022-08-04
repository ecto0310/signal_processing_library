#pragma once

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

int plot_signal(double sampling_frequency, double time,
                const double _Complex signal[], const char path[], FILE *info);
int plot_spectrum(double sampling_frequency, double time,
                  const double _Complex spectrum[], const char path[],
                  FILE *info);

#ifdef __cplusplus
}
#endif
