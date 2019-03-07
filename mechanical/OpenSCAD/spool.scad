$fn = 100;

band_thickness = 3;
height = 15;

difference()
{
    union()
    {
        // center shaft
        cylinder(h = height,d = 10, center = false);
        
        // bottom band
        difference()
        {
            cylinder(h = band_thickness, d = 25, center = false);
            translate([7, 0, 0])
                cylinder(h = 2*band_thickness, d = 3, center = true);
            cylinder(h = band_thickness, d = 9, center = false);
        }
        
        // top band
        translate([0,0,height-band_thickness])
        cylinder(h=band_thickness, d = 25, center=false);
    }
    cylinder(h = height,d = 6, center = false);
}
// key shaft
translate([-3, 0, height/2])
    cube([2, 5, height],center=true);




