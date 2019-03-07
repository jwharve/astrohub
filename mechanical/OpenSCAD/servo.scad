include <inputs.scad>
include <calcs.scad>

module servo(connectors)
{
    union()
    {
        cube(size = [servo_width, servo_length, servo_depth], center = true);
        if (connectors)
        {
            for (ii = [-1,1])
            {
                translate(v = [0, ii*(servo_length+servo_mount_length)/2, servo_depth/2-8])
                {
                    cube(size = [servo_width, servo_mount_length, 4],center = true);
                }
            }
        }
        translate(v = [0, servo_length/2-servo_circle_offset,servo_depth/2])
        {
            cylinder(h = 2*thickness, d = servo_circle_d, center = true);
        }
        
        translate(v = [0, servo_length/2-servo_circle_offset,servo_depth/2+thickness])
        {
            cylinder(h = 50, d = 0.25*cu, center = false);
        }
    }
}

servo();