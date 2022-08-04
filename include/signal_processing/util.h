#pragma once

#ifdef __cplusplus
extern "C" {
#endif

double get_frequency(double sampling_frequency, double time, int index);
double get_time(double sampling_frequency, int index);
double get_power(double _Complex spectrum);

#ifdef __cplusplus
}
#endif
