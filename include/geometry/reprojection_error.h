

#include "point_3d.h"
#include "../camera/camera.h"
#include "../features/feature.h"

// Evaluate reprojection error on the given Feature and Point3D pair.
double ReprojectionError(const Feature& feature, const Point3D& point,
                         const Camera& camera);

// Repeats the ReprojectionError() function on a list of feature point pairs,
// returning the mean reprojection error.
double ReprojectionError(const FeatureList& features, const Point3DList& points,
                         const Camera& camera);

// Evaluate the reprojection error on the given Observation.
double ReprojectionError(const Observation::Ptr& observation,
                         const Camera& camera);

// Repeats the ReprojectionError() function on a list of obserations, returning
// the mean reprojection error.
double ReprojectionError(const std::vector<Observation::Ptr>& observations,
                         const Camera& camera);

