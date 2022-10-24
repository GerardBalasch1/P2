#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
    float sum = 1e-12;
    for(int i=0; i<N; i++){
        sum += x[i]*x[i];
    }
    return 10*log10(sum/N);
}

float compute_am(const float *x, unsigned int N) {
    float sum = 0;
    for(int i=0; i<N; i++){
        sum += fabs(x[i]);
    }
    return sum/N;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    float sum = 0;
    for(int i=1; i<N; i++){
        sum += (float) (x[i-1]*x[i] < 0);
    }
    return 16000/2/(N-1)*sum;
}
