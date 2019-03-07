include <inputs.scad>
include <calcs.scad>

module stepper()
{
    cube(size = [stepper_lw, stepper_lw, stepper_depth], center = true);
    translate(v = [0,0,stepper_depth/2])
        cylinder(h = stepper_shaft_ext, d = s_shaft_d, center = false);
}

module bracket_base()
{
    difference()
    {
        union()
        {
            cube(size = [mount_width, mount_length, mount_thickness], center = true);
            translate(v = [0, -mount_length/2+mount_thickness/2, mount_depth/2-mount_thickness/2])
                cube(size = [mount_width, mount_thickness, mount_depth], center = true);
        }
        
        rotate(a = 90, v = [1, 0, 0])
        translate(v = [0, mount_motor_hole_offset, 0])
        cylinder(h = mount_length, d = mount_motor_hole_d, center = false);
    }
}

module bracket_holes()
{
    hull() {
            translate(v = [mount_mount_hole_offset_w, mount_length/2-mount_mount_hole_offset_from_back, 0])
                #cylinder(h = 5*mount_thickness, d = mount_mount_hole_d, center = true);
            translate(v = [mount_mount_hole_offset_w, mount_length/2-mount_mount_hole_offset_from_back-mount_mount_hole_differential, 0])
            #cylinder(h = 5*mount_thickness, d = mount_mount_hole_d, center = true);
        }
        
        hull() {
            translate(v = [-mount_mount_hole_offset_w, mount_length/2-mount_mount_hole_offset_from_back, 0])
                #cylinder(h = 5*mount_thickness, d = mount_mount_hole_d, center = true);
            translate(v = [-mount_mount_hole_offset_w, mount_length/2-mount_mount_hole_offset_from_back-mount_mount_hole_differential, 0])
            #cylinder(h = 5*mount_thickness, d = mount_mount_hole_d, center = true);
        }
}

module bracket()
{
    translate(v = [0, mount_length/2, mount_thickness/2])
    difference()
    {
        bracket_base();
        bracket_holes();
    }
}

module wheel()
{
    rotate(a = 90, v = [1, 0, 0])
        cylinder(h = wheel_w, d = wheel_d, center = false);
}

*stepper();
*bracket();
*wheel();

module drive()
{
    rotate(a = 90, v = [1, 0, 0])
    translate(v = [0, wheel_w+wheel_out+mount_thickness, mount_motor_hole_offset - drive_height])
    {
        translate(v = [0, 0, -mount_motor_hole_offset])
        {
            bracket();
            translate(v = [0, stepper_depth/2+mount_thickness, mount_motor_hole_offset])
                rotate(a = 90, v = [1, 0, 0])
                    stepper();
        }
        translate(v = [0, -wheel_out-mount_thickness, 0])
            wheel();
    }
}


drive();