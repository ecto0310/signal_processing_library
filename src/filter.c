#include "../include/signal_processing/filter.h"

#include <complex.h>
#undef I

#include "../include/signal_processing/util.h"

int filter(double _Complex out[], double sampling_frequency, double time,
           double lower_limit, double upper_limit, const double _Complex in[]) {
    int N = sampling_frequency * time;
    for (int i = 0; i < N; i++) {
        double frequency = get_frequency(sampling_frequency, time, i);
        if (lower_limit <= frequency && frequency <= upper_limit) {
            out[i] = in[i];
        } else {
            out[i] = 0;
        }
    }
    return 0;
}
