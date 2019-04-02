include <inputs.scad>
include <calcs.scad>

module sidewall()
{
    translate(v = [0,sidewall_height/2,0])
    square(size = [shaft_width+2*thickness, sidewall_height], center = true);
}

module notchIn(h)
{
    num_blocks = floor(h/block_width/2);
    
    translate(v = [0,h/2,0])
    for (i = [0:num_blocks-1])
    {
        translate(v = [0, 2*i*block_width-h/2+block_width,0])
        square(size = [thickness+tol, block_width+tol], center = true);
    }
}

module notchOut(h)
{    
    num_blocks = floor(h/block_width/2);
    
    translate(v = [0,h/2,0])
    for (i = [0:num_blocks-1])
    {
        translate(v = [0, 2*i*block_width-h/2+block_width,0])
        square(size = [thickness, block_width], center = true);
    }
}

module fullSide()
{
    difference()
    {
        sidewall();
        translate(v = [-(shaft_width/2+0.5*thickness),0,0])
            notchIn(sidewall_height);
        translate(v = [shaft_width/2+0.5*thickness,0,0])
            notchIn(sidewall_height);
    }
}


//cHeight = (robot_height-el_step_height-base_top);

module cornerWall1()
{
    translate(v = [thickness/2, (robot_height-el_step_height-base_top)/2, 0])
        square(size = [storage_size + thickness, (robot_height-el_step_height-base_top)], center = true);
}

module cornerWall2()
{
    translate(v = [0, (robot_height-el_step_height-base_top)/2, 0])
        square(size = [storage_size + 2*thickness, (robot_height-el_step_height-base_top)], center = true);
}

module fullCornerWall1()
{
    difference()
    {
        union()
        {
            cornerWall1();
            translate(v = [storage_size/2+shaft_width/2+thickness, sidewall_clearance, 0])
                difference()
                {
                    sidewall();
                    translate(v = [(shaft_width/2+0.5*thickness),0,0])
                        notchIn(sidewall_height);
                }
        }
        translate(v = [(storage_size/2+thickness/2), 0, 0])
            notchOut(robot_height-base_top);
    }
    translate(v = [-(storage_size/2+thickness/2), 0, 0])
            notchIn(robot_height-base_top-el_step_height);
}


module fullCornerWall2()
{
    translate(v = [storage_size/2+thickness+shaft_width/2, 0, 0])
    difference()
    {
        union()
        {
            cornerWall2();
            translate(v = [-(storage_size/2+shaft_width/2+thickness), false_bottom_height, 0])
                difference()
                {
                    translate(v = [0,(robot_height-base_top-false_bottom_height)/2,0])
                    {
                        square(size = [shaft_width+2*thickness, robot_height-base_top-false_bottom_height], center = true);
                    }
                    translate(v = [-(shaft_width/2+0.5*thickness),-false_bottom_height,0])
                        notchIn(robot_height-base_top);
                }
        }
        translate(v = [(storage_size/2+thickness/2), 0, 0])
            notchIn(robot_height-base_top);
        translate(v = [-(storage_size/2+thickness/2), 0, 0])
            notchIn(robot_height-base_top);
    }
    
    translate(v = [shaft_width/2,false_bottom_height+storage_size/2.7-1,0])
        square(size = [storage_size/2,storage_size/1.4], center = true);
    
    // triangle to cover false_bottom
    polygon([[-shaft_width/2-thickness,102],[shaft_width/2+thickness,104],[shaft_width/2+thickness,54]]);
}


fullSide();
*fullCornerWall1();
*fullCornerWall2();