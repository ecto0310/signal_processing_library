#include "../include/signal_processing/graph.h"

#include <complex.h>
#undef I
#include <stdlib.h>

#include "../include/signal_processing/util.h"

typedef struct {
    double frequency, power;
} FrequencyPower;

int compare(const void *a, const void *b) {
    if (((FrequencyPower *)a)->power < ((FrequencyPower *)b)->power) {
        return 1;
    } else {
        return -1;
    }
}

int plot_signal(double sampling_frequency, double time,
                const double _Complex signal[], const char path[], FILE *info) {
    int N = sampling_frequency * time;
    FILE *gp = popen("gnuplot", "w");
    fprintf(gp, "set terminal png\n");
    fprintf(gp, "set output \"%s\"\n", path);
    fprintf(gp, "set xlabel 'time[sec]'\n");
    fprintf(gp, "set ylabel 'pressure'\n");
    fprintf(gp, "plot '-' w l\n");
    for (int i = 0; i < N; i++) {
        fprintf(gp, "%f %f\n", get_time(sampling_frequency, i),
                creal(signal[i]));
        fprintf(info, "%f %f\n", get_time(sampling_frequency, i),
                creal(signal[i]));
    }
    fprintf(gp, "e\n");
    pclose(gp);
    return 0;
}

int plot_spectrum(double sampling_frequency, double time,
                  const double _Complex spectrum[], const char path[],
                  FILE *info) {
    int N = sampling_frequency * time;
    FILE *gp = popen("gnuplot", "w");
    fprintf(gp, "set terminal png\n");
    fprintf(gp, "set output \"%s\"\n", path);
    fprintf(gp, "set xlabel 'frequency[Hz]'\n");
    fprintf(gp, "set ylabel 'power'\n");
    fprintf(gp, "plot '-' w l\n");
    FrequencyPower *power = malloc(sizeof(FrequencyPower) * (N / 2 + 1));
    for (int i = 0; i <= N / 2; i++) {
        power[i].frequency = get_frequency(sampling_frequency, time, i);
        power[i].power = get_power(spectrum[i]);
        fprintf(gp, "%f %f\n", power[i].frequency, power[i].power);
    }
    fprintf(gp, "e\n");
    pclose(gp);
    qsort(power, N / 2 + 1, sizeof(FrequencyPower), compare);
    for (int i = 0; i <= N / 2; i++) {
        fprintf(info, "%f,%f\n", power[i].frequency, power[i].power);
    }
    return 0;
}
