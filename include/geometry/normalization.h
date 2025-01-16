
#include <eigen3/Eigen/Core>
#include "point_3d.h"
#include "../matching/feature.h"
#include "../matching/feature_match.h"


// Compute a matrix that when used to left-multiply the input features will
// normalize them. Since both sets of features are stored in the
// FeatureMatchList, the 'use_feature_set1' parameter must be specified to
// pick out a normalization for either feature set 1 or feature set 2.
Matrix3d ComputeNormalization(const FeatureMatchList& matched_features,
                              bool use_feature_set1);

// Compute a matrix that when used to left-multiply the input features will
// normalize them.
Matrix3d ComputeNormalization(const FeatureList& features);

// Compute a matrix that when used to left-multiply the input points will
// normalize them.
Matrix4d ComputeNormalization(const Point3DList& points);

