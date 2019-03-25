include <inputs.scad>
include <calcs.scad>
use <sidewalls.scad>

module piece() // base piece the correct size to cut from
{
    difference()
    {
        translate (v = [-robot_width/2, 0, 0])
        {
            square(size = [robot_width, robot_height], center = false);
        }
        
        for (ii = [-1, 1])
        {
            translate (v = [ii*(robot_width/2-(storage_size)/2), base_top/2, 0])
            {
                square(size = [storage_size, base_top], center = true);
            }
        }
    }
}

module storage_areas() // both areas that pieces are stored in
{
    for (ii = [-1, 1])
    {
        translate (v = [ii*(robot_width/2 - storage_size/2), base_top+storage_height/2, 0])
        {
            square(size = [storage_size, storage_height], center = true);
        }
    }
}

module dump_area()
{
    translate (v = [0, robot_height - dump_height/2, 0])
    {
        square(size = [shaft_width, dump_height], center = true);
    }
}

module top_cut()
{
    for (ii = [-1, 1])
    {
        
        translate (v = [ii*(shaft_width/2 + thickness/2), cut_height + top_cut_height/2, 0])
        {
            square(size = [thickness, top_cut_height], center = true);
        }
        // cut storage area sides
        translate (v = [ii*(shaft_width/2 + thickness/2), robot_height-dump_height/2, 0])
        {
            square(size = [thickness, dump_height], center = true);
        }
    }
}

module bottom_cut()
{
    for (ii = [-1, 1])
    {
        translate (v = [ii*(shaft_width/2 + thickness/2), base_top + bottom_cut_height/2, 0])
        {
            square(size = [thickness, bottom_cut_height], center = true);
        }
        // cut shaft bottom sides
        translate (v = [ii*(shaft_width/2 + thickness/2), base_top/2, 0])
        {
            square(size = [thickness, base_top], center = true);
        }
    }
}

module jigsaw1()
{
    for (ii = [-1, 1])
    {
        for (jj = [2:2:floor(storage_size/block_width)-1])
        {
            translate (v = [ii*(robot_width/2-jj*block_width+block_width/2), base_top-base_thickness/2, 0])
            {
                square(size = [block_width, base_thickness+tol], center = true);
            }
        }
    }
}

module jigsaw2()
{
    for (ii = [-1, 1])
    {
        for (jj = [2:2:floor(storage_size/block_width)-1])
        {
            translate (v = [ii*(robot_width/2-jj*block_width+block_width/2), base_top-base_thickness/2, 0])
            {
                square(size = [block_width+tol, base_thickness+tol], center = true);
            }
        }
    }
}

module wire_holes()
{
    /*
    translate(v = [-(robot_width/2 - storage_size + wire_hole*5/8), base_top+wire_hole*5/8, 0])
    {
        circle(d = wire_hole);
    }
    translate(v = [robot_width/2 - storage_size + wire_hole*5/8, base_top+wire_hole*5/8, 0])
    {
        circle(d = wire_hole);
    }
    */
    for (ii = [-1, 1])
    {
    translate(v = [ii*(robot_width/2 - storage_size + wire_tri_edge), base_top+wire_tri_edge, 0])
    {
        polygon([[0,0],[0,tan(wedge_angle)*(storage_size-2*wire_tri_edge-tan(90-wedge_angle)*wedge_thickness)],[ii*(storage_size-2*wire_tri_edge-tan(90-wedge_angle)*wedge_thickness),0]]);
    }
    }
}

module el_jigsaw()
{
    for (jj = [2:2:floor(storage_size/block_width)-1])
    {
        translate (v = [(jj*block_width+block_width/2), 0, 0])
        {
            square(size = [block_width+tol, base_thickness+tol], center = true);
        }
    }
}


// Pieces
module topCut()
{
    difference()
    {
        piece();
        dump_area();
        bottom_cut();
        wire_holes();
        translate(v = [0,false_bottom_height,0])
        {
            difference()
            {
                jigsaw2();
                square(1000);
            }
        }
        square(size = [1000, 2*bottom_clearance], center = true);
        
        translate(v = [shaft_width/2, robot_height-el_step_height, 0])
            el_jigsaw();
        mirror()
        translate(v = [shaft_width/2, robot_height-el_step_height, 0])
            el_jigsaw();
    }
    jigsaw1();
}

module topCutNoHole()
{
    union()
    {
        topCut();
        // notches for side walls
        translate(v = [(robot_width/2+thickness/2),base_top+sidewall_clearance,0])
        notchOut(sidewall_height);
        translate(v = [-(robot_width/2+thickness/2),base_top,0])
        difference()
        {
            notchOut(robot_height-base_top);
            square(2*false_bottom_height, center = true);
        }
    }
}

module topCutHole()
{
    difference()
    {
        union()
        {
            topCut();
            // notches for side walls
            translate(v = [(robot_width/2+thickness/2),base_top+sidewall_clearance,0])
                notchOut(sidewall_height);
            
            translate(v = [-(robot_width/2+thickness/2),base_top,0])
                notchOut(robot_height-base_top);
            
        }
        // the -25 and +50 are used to delete the notches on the side
        translate(v = [-(robot_width/2-storage_size/2)-25, base_top+false_bottom_height+storage_size/2, 0])
        {
            square(size = [storage_size+50, storage_size], center = true);
        }
    }
}

module botCut()
{
    difference()
    {
        piece();
        dump_area();
        top_cut();
        wire_holes();
        square(size = [1000, 2*bottom_clearance], center = true);
        translate(v = [shaft_width/2, robot_height-el_step_height, 0])
            el_jigsaw();
        mirror()
        translate(v = [shaft_width/2, robot_height-el_step_height, 0])
            el_jigsaw();
    }
    jigsaw1();
    
}

module botCutClosed()
{
    union()
    {
        botCut();
        // notches for side walls
        translate(v = [(robot_width/2+thickness/2),base_top+sidewall_clearance,0])
            notchOut(sidewall_height);
        translate(v = [-(robot_width/2+thickness/2),base_top+sidewall_clearance,0])
            notchOut(sidewall_height);
    }
}

module botCutOpen()
{
    difference()
    {
        union()
        {
            botCut();
            // notches for side walls
            translate(v = [(robot_width/2+thickness/2),base_top,0])
                notchOut(robot_height-base_top);
            
            translate(v = [-(robot_width/2+thickness/2),base_top+sidewall_clearance,0])
                notchOut(sidewall_height);
        }
        translate (v = [0, base_bottom/2, 0])
        {
            square(size = [shaft_width+2*thickness, base_bottom], center = true);
        }
        translate(v = [0, 3/4*base_bottom, 0])
        circle(d = shaft_width);
        translate(v = [shaft_width/2+storage_size/2,false_bottom_height,0])
            difference()
            {
                jigsaw2();
                square(1000);
            }
        square(size = [1000, 2*bottom_clearance], center = true);
    }
}

module false_bottom_plate()
{
    intersection()
    {
        union()
        {
            translate(v = [0,storage_size/2,0])
            {
                square(size = [shaft_width,storage_size], center = true);
            }
            translate(v = [shaft_width/2+storage_size/2,-(base_top)+storage_size+base_thickness,0])
            {
                difference()
                {
                    jigsaw1();
                    square(1000);
                }
            }
            translate(v = [shaft_width/2, storage_size/2 + thickness, 0]) rotate(90) translate(v = [shaft_width/2+storage_size/2,-(base_top),0])
            {
                difference()
                {
                    jigsaw1();
                    square(1000);
                }
            }
            
            mirror()
            translate(v = [shaft_width/2, storage_size/2 + thickness, 0]) rotate(90) translate(v = [shaft_width/2+storage_size/2,-(base_top),0])
            {
                difference()
                {
                    jigsaw1();
                    square(1000);
                }
            }
        }
        
        translate(v = [0, storage_size/2, 0])
            square(size = [shaft_width+2*thickness, storage_size+2*thickness], center = true);
    }
    
}

module el_platform()
{
    translate(v = [0, storage_size/2, 0])
    {
        square(size = storage_size, center = true);
    }
    
    translate(v = [storage_size/2-base_thickness/2+thickness, -thickness, 0])
    rotate(90)
    el_jigsaw();
    
    translate(v = [storage_size/2+thickness, base_thickness/2-thickness, 0])
    mirror()
    el_jigsaw();
}

*topCutNoHole();
topCutHole();
*botCutClosed();
*botCutOpen();
*false_bottom_plate();
*el_platform();