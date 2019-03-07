include <inputs.scad>
include <calcs.scad>


module wedge()
{
    linear_extrude(height = shaft_width-wedge_tol, center = true, convexity = 0, twist = 0, slices = 20, scale = 1.0, $fn = 16)
        polygon(points = [[0,0],[tan(90-wedge_angle)*wedge_thickness,0],[storage_size-wedge_tol,tan(wedge_angle)*(storage_size-wedge_tol)-wedge_thickness],[storage_size-wedge_tol,tan(wedge_angle)*(storage_size-wedge_tol)]]);
}


module wedge2()
{
    linear_extrude(height = storage_size-wedge_tol, center = true, convexity = 0, twist = 0, slices = 20, scale = 1.0, $fn = 16)
        polygon(points = [[0,0],[tan(90-wedge_angle)*wedge_thickness,0],[shaft_width-wedge_tol,tan(wedge_angle)*(shaft_width-wedge_tol)-wedge_thickness],[shaft_width-wedge_tol,tan(wedge_angle)*(shaft_width-wedge_tol)]]);
}

*wedge();
wedge2();