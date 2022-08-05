#pragma once

#ifdef __cplusplus
extern "C" {
#endif

int filter(double _Complex out[], double sampling_frequency, double time,
           double lower_limit, double upper_limit, const double _Complex in[]);

#ifdef __cplusplus
}
#endif
