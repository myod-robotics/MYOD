import (servo_bracket_modules.scad);

servo_bracket();


difference()
{	
	cube([48.58,15.532,24],center=true);

//- Agujero central

	translate([0,-3,0])
		cube([45.58,15.532,21],center=true);

// - Agujeros de tornillos

	translate([20.64,7,8.7])
		rotate([90,0,0])
			cylinder(r=1.5,h=8,center=true,$fn=100);

	translate([-20.64,7,8.7])
		rotate([90,0,0])
			cylinder(r=1.5,h=8,center=true,$fn=100);

	translate([20.64,7,-8.7])
		rotate([90,0,0])
			cylinder(r=1.5,h=8,center=true,$fn=100);

	translate([-20.64,7,-8.7])
		rotate([90,0,0])
			cylinder(r=1.5,h=8,center=true,$fn=100);
}

difference()
{
	translate([20.64,4.766,0])
		cube([4.3,2,21],center=true);

// - Agujeros de tornillos

	translate([20.64,7,8.7])
		rotate([90,0,0])
			cylinder(r=1.5,h=8,center=true,$fn=100);

	translate([20.64,7,-8.7])
		rotate([90,0,0])
			cylinder(r=1.5,h=8,center=true,$fn=100);
}

difference()
{
	translate([-20.64,4.766,0])
		cube([4.3,2,21],center=true);

	translate([-20.64,7,8.7])
		rotate([90,0,0])
			cylinder(r=1.5,h=8,center=true,$fn=100);

	translate([-20.64,7,-8.7])
		rotate([90,0,0])
			cylinder(r=1.5,h=8,center=true,$fn=100);
}

difference()
{
	translate([0,6,0])
		rotate([90,0,90])
			cylinder(r=12,h=50,center=true,$fn=100);

	translate([0,-3,0])
		cube([48,15.532,21],center=true);

// - Agujeros de tornillos

	translate([20.64,7,8.7])
		rotate([90,0,0])
			cylinder(r=1.5,h=8,center=true,$fn=100);

	translate([-20.64,7,8.7])
		rotate([90,0,0])
			cylinder(r=1.5,h=8,center=true,$fn=100);

	translate([20.64,7,-8.7])
		rotate([90,0,0])
			cylinder(r=1.5,h=8,center=true,$fn=100);

	translate([-20.64,7,-8.7])
		rotate([90,0,0])
			cylinder(r=1.5,h=8,center=true,$fn=100);

}

	translate([0,0,-13.5])
		cube([30,15.532,3],center=true);
