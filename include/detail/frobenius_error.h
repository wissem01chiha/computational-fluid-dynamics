#pragma once

#include <omp.h>

inline void frobeniusError(const double *R, double* frobenius_error) {
    #pragma omp parallel for
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            frobenius_error[i*3+j]=R[i]*R[j]+R[i+3]*R[j+3]+R[i+6]*R[j+6]-(i==j?1.0:0.0);
        }
    }
}
