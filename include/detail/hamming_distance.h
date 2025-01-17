#pragma once

#include <omp.h>
#include <cmath>
#include <glog/logging.h>
#include "../util/types.h"

inline void hammingDistance(const Descriptor& d1, const Descriptor& d2, double* distance) {
 
    CHECK(d1.size() != d2.size()) << "descriptors must have the same size";
    const int size = d1.size();
    int hamming_count = 0;

    #pragma omp parallel for reduction(+:hamming_count)
    for (int i = 0; i < size; ++i) {
        if (std::abs(d1[i] - d2[i]) > 1e-9) { 
            hamming_count += 1;
        }
    }
    *distance = static_cast<double>(hamming_count);
}