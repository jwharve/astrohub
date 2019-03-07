include <inputs.scad>
include <calcs.scad>

module bracket()
{
    linear_extrude(height = 2*bracket_thickness, center = true, convexity = 0, twist = 0, slices = 20, scale = 1.0, $fn = 16)
    {
        // right
        translate(v = [el_motor_size/2, 0, 0])
            square(size = [bracket_thickness, el_motor_size], center = false);
        // left
        translate(v = [-el_motor_size/2-bracket_thickness, 0, 0])
            square(size = [bracket_thickness, el_motor_size], center = false);
        // top
        translate(v = [-el_motor_size/2-bracket_thickness, el_motor_size-tol, 0])
            square(size = [el_motor_size+ 2*bracket_thickness, bracket_thickness], center = false);
        
        // feet
        translate(v = [-el_motor_size/2-2*bracket_thickness, 0, 0])
            square(size = [bracket_thickness, bracket_thickness], center = false);
        translate(v = [+el_motor_size/2+bracket_thickness, 0, 0])
            square(size = [bracket_thickness, bracket_thickness], center = false);
    }
}

bracket();