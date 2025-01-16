
#include "point_3d.h"
#include "../camera/camera.h"
#include "../matching/feature.h"
#include "../matching/feature_match.h"


// Triangulates a single 3D point from > 2 views. The input assumes that
// features correspond to the cameras they were taken from. e.g. features[i] was
// taken from cameras[i]. Returns false if:
// 1) The number of features and cameras are not equal.
// 2) A point cannot be uniquely determined.
// 3) The triangulated point does not reproject into all cameras.
// This uses the inhomogeneous DLT method from H&Z: Multi-View Geometry, Ch 2.2.
// Also returns uncertainty as the inverse of the maximum angle used to
// triangulate the point.
bool Triangulate(const FeatureList& features,
                 const std::vector<Camera>& cameras, Point3D& point,
                 double& uncertainty);

// Triangulate the 3D position of a point from a 2D correspondence and two
// sets of camera extrinsics and intrinsics. Returns false if:
// 1) A point cannot be uniquely determined.
// 2) The triangulated point does not reproject into both cameras.
// This uses the homogeneous DLT method from H&Z: Multi-View Geometry, Ch 2.2.
// Also returns uncertainty as the inverse of the maximum angle used to
// triangulate the point.
bool Triangulate(const FeatureMatch& feature_match, const Camera& camera1,
                 const Camera& camera2, Point3D& point, double& uncertainty);

// Repeats the Triangulate() function on a list of feature matches, returning a
// list of triangulated 3D points. Returns all triangulated points, even if one
// point fails. If triangulating a point fails, that point will be stored as (0,
// 0, 0) in 'points'.
// Also returns uncertainty as the inverse of the maximum angle used to
// triangulate the point.
bool Triangulate(const FeatureMatchList& feature_matches, const Camera& camera1,
                 const Camera& camera2, Point3DList& points,
                 double& uncertainty);

// Compute the maximum angle between each angle formed from a pair of
// point-to-camera vectors.
double MaximumAngle(const std::vector<Camera>& cameras, const Point3D& point);

