union(){
	
	mirror([0,0,0])difference(){
		hull(){
			translate([6.98,-19,0])cylinder(r=0.1,h=4.8,$fn=10);
			translate([7.,49,0])cylinder(r=0.1,h=4.8,$fn=10);
			translate([16,-6,0])cylinder(r=3,h=4.8,$fn=10);
			translate([16,6,0])cylinder(r=3,h=4.8,$fn=10);
			translate([0,-18,0])cylinder(r=6,h=4.8,$fn=30);
			translate([0,51,0])cylinder(r=6,h=4.8,$fn=30);
		}
		translate([15,-6,-0.5])cylinder(r=1.5,h=5.8,$fn=10);
		translate([15,6,-0.5])cylinder(r=1.5,h=5.8,$fn=10);
		translate([0,-18,-1])cylinder(r=2,h=7,$fn=30);
		translate([0,51,-1])cylinder(r=2,h=7,$fn=30);
	}		
}
