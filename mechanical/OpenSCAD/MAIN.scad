include <inputs.scad>
include <calcs.scad>

use <base.scad>
use <cuts.scad>
use <servo.scad>
use <drive.scad>
use <wedge.scad>
use <sidewalls.scad>

union()
{
    // MAKE 3D BASE
    color("darkorange", 1.0)
    translate (v = [0, base_top-base_thickness/2, shift])
    {
        rotate(a = 90, v = [1, 0, 0])
        {
            linear_extrude(height = base_thickness, center = true, convexity = 0, twist = 0, slices = 20, scale = 1.0, $fn = 16)
            {
                base();
            }
        }
    }

    // MAKE 3D WALLS
    color( "blue", 1.0 )
    linear_extrude(height = thickness, center = true, convexity = 0, twist = 0, slices = 20, scale = 1.0, $fn = 16)
    {
        botCutClosed();
    }

    color( "yellow", 1.0 )
    translate (v = [shift, 0, shift])
    {
        rotate(a = 90, v = [0, 1, 0])
        {
            linear_extrude(height = thickness, center = true, convexity = 0, twist = 0, slices = 20, scale = 1.0, $fn = 16)
            {
                topCutHole();
            }
        }
    }

    color( "green", 1.0 )
    translate (v = [0, 0, 2*shift])
    {
        linear_extrude(height = thickness, center = true, convexity = 0, twist = 0, slices = 20, scale = 1.0, $fn = 16)
        {
            botCutOpen();
        }
    }

    color( "red", 1.0 )
    translate (v = [-shift, 0, shift])
    {
        rotate(a = 90, v = [0, 1, 0])
        {
            linear_extrude(height = thickness, center = true, convexity = 0, twist = 0, slices = 20, scale = 1.0, $fn = 16)
            {
                topCutNoHole();
            }
        }
    }
    
    // MAKE 3D SUB BASE
    *color("purple", 1.0)
    translate (v = [0, sbase_top_height - sbase_thickness/2, shift])
    {
        rotate(a = 90, v = [1, 0, 0])
        {
            linear_extrude(height = sbase_thickness, center = true, convexity = 0, twist = 0, slices = 20, scale = 1.0, $fn = 16)
            {
                sbase();
            }
        }
    }
    
    /*
    // MAKE SERVOS
    %translate(v=[shaft_width/2 + thickness+servo_length/2, base_top+servo_depth/2, shaft_width + thickness+servo_width/2])
        rotate(a = 90, v = [1, 0, 0])
            rotate(a = 90, v = [0, 0, 1])
                servo(connectors = false);

    %translate(v=[-(shaft_width/2 + thickness+servo_length/2), base_top+servo_depth/2, shaft_width + thickness+servo_width/2])
        rotate(a = 90, v = [1, 0, 0])
            rotate(a = 90, v = [0, 0, -1])
                servo(connectors = false);
    
    %translate(v = [-(shaft_width/2 + thickness+servo_depth/2),base_top+servo_depth/2, shaft_width + thickness+servo_width/2 + servo_width])
                rotate(a = 90, v = [0, 1, 0])
                    rotate(a = 180, v = [0, 0, 1])
                        servo(connectors = false);
    */
    
    
    temp2 = (robot_width-shaft_width-2*thickness)/2;

    // MAKE WHEELS
    color("aqua")
    {
    for (ii = [-1, 1])
    {
        translate(v = [ii*(robot_width/2-wheel_opening_width/2), 0, (temp2+thickness*3/2+shaft_width)])
            rotate(a = 180, v = [1, 0, 0])
                rotate(a = 180, v = [0, 0, 1])
                    drive();
    }
    
    for (ii = [-1, 1])
    {
        translate(v = [ii*(robot_width/2-wheel_opening_width/2), 0, -(temp2+thickness/2)])
        drive();
    }
    }
    
    // MAKE WEDGES
    %color("gray")
    {
        translate(v = [-robot_width/2+wedge_tol/2, base_top, shaft_width/2+thickness/2])
        wedge();
        
        mirror(v = [1, 0, 0])
        translate(v = [-robot_width/2+wedge_tol/2, base_top, shaft_width/2+thickness/2])
        wedge();
        
        //translate(v = [0, base_top, thickness/2+shaft_width/2+robot_width/2-wedge_tol/2])

        translate(v = [0, base_top, -robot_width/2+shaft_width/2+wedge_tol/2])
        rotate(a = -90, v = [0, 1, 0])
        wedge();
    }
    
    // MAKE FALSE BOTTOM
    color("gray")
    {
        translate(v = [0,base_bottom+false_bottom_height+base_thickness/2,shaft_width+storage_size+3/2*thickness])
        rotate(a = -90, v = [1, 0, 0])
        linear_extrude(height = base_thickness, center = true, convexity = 0, twist = 0, slices = 20, scale = 1.0, $fn = 16)
        false_bottom_plate();
    }
    
    // MAKE ELEVATOR PLATFORM
    color("gray")
    {
        translate(v = [-(robot_width/2-storage_size/2),robot_height-el_step_height, -thickness/2])
        rotate(a = -90, v = [1, 0, 0])
        linear_extrude(height = base_thickness, center = true, convexity = 0, twist = 0, slices = 20, scale = 1.0, $fn = 16)
        el_platform();
    }
    
    //MAKE WALLS
    color("gray")
    {
        translate(v = [robot_width/2+thickness/2, base_top, 3/2*shaft_width-thickness])
        rotate(a = 90, v = [0, 1, 0])
        linear_extrude(height = thickness, center = true, convexity = 0, twist = 0, slices = 20, scale = 1.0, $fn = 16)
            fullCornerWall1();
    }
    color("blue")
    {
        translate(v = [0, base_top, robot_width-storage_size])
        linear_extrude(height = thickness, center = true, convexity = 0, twist = 0, slices = 20, scale = 1.0, $fn = 16)
            fullCornerWall2();
    }
    color("green")
    {
        translate(v = [0, robot_height-sidewall_clearance-thickness, -storage_size-thickness])
        linear_extrude(height = thickness, center = true, convexity = 0, twist = 0, slices = 20, scale = 1.0, $fn = 16)
            fullSide();
    }
}