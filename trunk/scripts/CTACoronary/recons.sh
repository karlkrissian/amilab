 

program=/home/karl/projects/Devel/bin/linux/GE_recons

mkdir Images
$program PolyData/vessels.vtk Images/vessels_recons.vtk -image_exemple $1 -rayon 0.6 -cylindre
