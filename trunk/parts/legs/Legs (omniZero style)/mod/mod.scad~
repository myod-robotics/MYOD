module pieza(){
	import("lower left servo arm.stl");
}

union(){
	translate([0,0,2.5])difference(){
		pieza();
		translate([0,0,102.3])cube(200,center=true);
	}
	mirror([0,1,0])difference(){
		hull(){
			translate([6.98,-19,0])cylinder(r=0.1,h=4.8,$fn=10);
			translate([7.,49,0])cylinder(r=0.1,h=4.8,$fn=10);
			translate([16,-6,0])cylinder(r=3,h=4.8,$fn=10);
			translate([16,6,0])cylinder(r=3,h=4.8,$fn=10);
		}
		translate([15,-6,-0.5])cylinder(r=1.5,h=5.8,$fn=10);
		translate([15,6,-0.5])cylinder(r=1.5,h=5.8,$fn=10);
	}		
}