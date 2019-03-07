$fn = 50;
cu = 25.4; // inch -> mm

// INPUTS
thickness = 2; // thickness of the acrylic [mm]
base_thickness = 5; // thickness of the base acrylic [mm]

side_edge = 0.25; // clearance for each side of the robot [in]
height_edge = 0.1; // clearance for top and bottom of the robot [in]

robot_height_in = 11; // overall height of the robot [in]
robot_width_in = 9; // overall width of the robot [in]

base_clearance = 2.65; // clearance of the base to ground [in]

storage_width = 2.65; // inside width of storage container [in]

block_width = 5; // width of jigsaw block [mm]

dump_height_in = 1.75; // height that platform edge will raise to dump [in]

tol = 0.001; // number used to fix rounding? [mm]


sbase_thickness = 0; // thickness of the sub base [mm]

wheel_opening_depth_tol = 5; // extra space for wheel depth [mm]

hole_dist_opposing = 33.98; // distance between middles of opposing mounting holes [mm]

hole_dist_adjacent = 6.36; // distance between middles of adjacent mounting holes [mm]

hole_diameter = 3.26; // diameter of mounting holes [mm]

hole_in_spacing = 5; // distance from edge to middle of first mount holes [mm]


servo_length = 41; // lenght of servo [mm]

servo_width = 21; // width of servo [mm]

servo_depth = 37; // height of servo to top plate [mm]

servo_mount_length = 7; // length of servo hole mount (one side) [mm]

servo_wire_clear_length = 12; // length wires protrude from side [mm]

servo_circle_d = 14.5; // diameter of circular protrusion around spline [mm]

servo_circle_offset = 10; // distance from one side to center of spline [mm]


stepper_depth = 40; // depth of stepper [mm]

stepper_lw = 42; // length/width of stepper [mm]

stepper_shaft_ext = 23; // extension of stepper shaft from face [mm]

s_shaft_d = 5; // stepper shaft diameter [mm]

mount_width = 50; // width of motor mount [mm]

mount_mount_hole_offset_w = 15; // distance from center to mount holes for motor mount [mm]

mount_mount_hole_offset_from_back = 11; // distance from back to first mount holes for motor mount [mm]

mount_mount_hole_differential = 30; // distance from first mount hole to second mount hole for motor mount [mm]

mount_mount_hole_d = 4.2; // diameter of mount mount hole[mm]

mount_motor_hole_offset = 31; // distance from top of mount to center of motor hole [mm]

mount_motor_hole_d = 22.1; // diameter of motor hole in mount [mm]

mount_length = 53.5; // length of motor mount [mm]

mount_depth = 51.5; // depth of motor mount [mm]

mount_thickness = 3; // thickness of metal for mount [mm]

wheel_d = 60; // diameter of wheel [mm]

wheel_w = 31; // width of wheel [mm]

wheel_out = 17; // how far out the shaft the wheel starts [mm]

wedge_tol = 1; // tolerance for edges of wedge [mm]

wedge_angle = 30; // angle of wedge from horizontal [deg]

wedge_thickness = 5; // thickness of wedge [mm]


wire_hole_in = 0.5; // size of hole for wires to motors

wire_tri_edge = 5; // thickness of edge on wiring triangle [mm]

false_bottom_height_in = 3; // height of false bottom in front [in]

bottom_clearance = 3; // clearance for walls on bottom of robot [mm]

false_opening_height_in = 3; // height of hole for false bottom [in]


el_step_height_in = 2; // height of steppers for elevator [in]

el_motor_size = 35; // length of elevator stepper motor [mm]

bracket_thickness = 3; // thickness of bracket for elevator stepper [mm]