#include "../include/signal_processing/util.h"

#include <complex.h>
#undef I

double get_frequency(double sampling_frequency, double time, int index) {
    int N = sampling_frequency * time;
    if (index <= N / 2) {
        return index / time;
    }
    return (N - index) / time;
}

double get_time(double sampling_frequency, int index) {
    return index / sampling_frequency;
}

double get_power(double _Complex spectrum) {
    double size = cabs(spectrum);
    return size * size;
}
