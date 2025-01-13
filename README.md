
deformable structure from motion :



x = K[R t] X R(3*3) t(3*1) K(3*3) X(x,y,z,1)

The translation matrix in 3D space (using homogeneous coordinates) is:

$
T = \begin{pmatrix}
1 & 0 & 0 & t_x \\
0 & 1 & 0 & t_y \\
0 & 0 & 1 & t_z \\
0 & 0 & 0 & 1
\end{pmatrix}
$

Where \( t_x, t_y, t_z \) represent the translations along the x, y, and z axes, respectively.


$
R_x(\theta) = \begin{pmatrix}
1 & 0 & 0 \\
0 & \cos(\theta) & -\sin(\theta) \\
0 & \sin(\theta) & \cos(\theta)
\end{pmatrix}
$


$
R_y(\theta) = \begin{pmatrix}
\cos(\theta) & 0 & \sin(\theta) \\
0 & 1 & 0 \\
-\sin(\theta) & 0 & \cos(\theta)
\end{pmatrix}
$

$
R_z(\theta) = \begin{pmatrix}
\cos(\theta) & -\sin(\theta) & 0 \\
\sin(\theta) & \cos(\theta) & 0 \\
0 & 0 & 1
\end{pmatrix}
$

The scaling matrix for non-uniform scaling in 3D is:

$
S = \begin{pmatrix}
s_x & 0  & 0  & 0 \\
0  & s_y & 0  & 0 \\
0  & 0  & s_z & 0 \\
0  & 0  & 0  & 1
\end{pmatrix}
$

Where \( s_x, s_y, s_z \) are the scaling factors along the x, y, and z axes.


The shearing matrix can distort an object along the axes and is represented as:

$
Sh = \begin{pmatrix}
1 & sh_{xy} & sh_{xz} & 0 \\
sh_{yx} & 1 & sh_{yz} & 0 \\
sh_{zx} & sh_{zy} & 1 & 0 \\
0 & 0 & 0 & 1
\end{pmatrix}
$

Where \( sh_{xy}, sh_{xz}, sh_{yx}, sh_{yz}, sh_{zx}, sh_{zy} \) are the shear factors that control the distortion along the respective axes.

To combine translation, rotation, and scaling transformations, the final transformation matrix is the product of these matrices:

$
M = T \times R \times S
$

Where \( T \), \( R \), and \( S \) are the translation, rotation, and scaling matrices, respectively.

Datasets
----------

[1](https://wuminye.github.io/NHR/datasets.html)

[2](https://www.cs.toronto.edu/~kyros/soft-data/dynamic/index.html)

each folder frame %d is the capture from all images of the time t : 0->200s
for 57 camera each capture
[4](https://github.com/wuminye/NHR)

softwares
-----------
[Berkly-sfm](https://github.com/erik-nelson/berkeley_sfm)