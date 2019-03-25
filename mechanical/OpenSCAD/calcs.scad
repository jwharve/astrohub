include <inputs.scad>

// CALCS (everything ends up in [mm])
robot_height = robot_height_in*cu-height_edge*cu*2; // height of the robot
robot_width = robot_width_in*cu-side_edge*cu*2; // width of the robot

base_bottom = base_clearance*cu; // height of the bottom of the base
base_top = base_bottom + base_thickness; // height of the top of the base

storage_size = storage_width*cu; // inside depth of storage area

storage_height = robot_height-base_top; // height of storage container
wire_hole = wire_hole_in*cu; // diameter of hole for wires under storage area

dump_height = dump_height_in*cu; // height that platform edge will raise to dump

shaft_width = robot_width - 2*storage_size - 2*thickness; // inside width of elevator shaft


cut_size = (robot_height-dump_height-base_top)/2+tol; // size of vertical cut for sliding together

shift = shaft_width/2 + thickness/2; // how much the pieces need to be shifted to be put together


wheel_opening_width = wheel_d; // width of opening for wheels on sub base
wheel_opening_depth = wheel_w + wheel_opening_depth_tol; // width of opening for wheels on sub base

drive_height = max(mount_motor_hole_offset,wheel_d/2) + max(mount_motor_hole_offset-mount_motor_hole_offset,wheel_d/2); // height of wheel, motor, and mount

sbase_top_height = drive_height + sbase_thickness; // height of the top of the sub base


false_bottom_height = false_bottom_height_in*cu; // height of false bottom in front

false_opening_height = false_opening_height_in*cu; // height of hole for false bottom


cut_height = base_bottom + false_opening_height - base_thickness; // height at which cuts will meet

bottom_cut_height = cut_height - base_top + tol; // height of bottom cut

top_cut_height = robot_height - dump_height - cut_height + tol; // height of top cut

el_step_height = el_step_height_in*cu; // height of steppers for elevator


sidewall_height = robot_height-(base_top + sidewall_clearance); // hieght of sidewall


backboard_clearance = backboard_clearance_in*cu; // clearance for backboard from inside of shaft wall

// Checking
if (shaft_width < storage_size)
{
    echo("<b>THE STORAGE AREAS WILL BE TOO NARROW!!!!!!!!!!!!!!!!!!!!!!!!!!");
    echo("THIS IS A PROBLEM!!!!!!!!!!!!!!!!!!!!!!!!!!");
    echo("Width: ", shaft_width/cu, "[in]");
}
else
{
    echo("<b>Storage width will be:", shaft_width/cu, "[in]</b>");
}

echo("<b>Corner Size:", (robot_width-shaft_width-2*thickness)/2/cu, "[in]</b>");

// error check for sbase and base
if (sbase_top_height >= base_bottom)
{
    echo("<b>SUB BASE TOO TALL!!!!!!!!!!!!!!!!!!!!!!!!!!</b>");
}
else
{
    echo("<b>Spacer height should be:", (base_bottom - sbase_top_height)/cu, "[in]</b>");
}


echo(shaft_width/cu);
echo(storage_size/cu);


echo("asdf");
echo(storage_size/cu);