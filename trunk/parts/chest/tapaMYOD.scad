//Arduino Mega Board: 54x102x10


module pasantes(z){
	translate([29,46,-1])cylinder(r=2,h=z);
	translate([29,-46,-1])cylinder(r=2,h=z);
	translate([-19,46,-1])cylinder(r=2,h=z);
	translate([-19,-46,-1])cylinder(r=2,h=z);
}
module mega(z){
	translate([13.5,51,-1])cylinder(r=2,h=z,$fn=16);
	translate([12.5,2.5,-1])cylinder(r=2,h=z,$fn=16);
	translate([88.5,51,-1])cylinder(r=2,h=z,$fn=16);
	translate([95,2.5,-1])cylinder(r=2,h=z,$fn=16);	
	translate([13.5,51,-1.5])cylinder(r=3,h=3,$fn=6);
	translate([12.5,2.5,-1.5])cylinder(r=3,h=3,$fn=6);
	translate([88.5,51,-1.5])cylinder(r=3,h=3,$fn=6);
	//translate([95,2.5,-1.5])cylinder(r=3,h=3,$fn=6);
}

d=3;

rotate([0,180,0])difference(){
	hull(){
		translate([29+d,46+d,0])cylinder(r=1,h=4);
		translate([29+d,-46-d,0])cylinder(r=1,h=4);
		translate([-19-d,46+d,0])cylinder(r=1,h=4);
		translate([-19-d,-46-d,0])cylinder(r=1,h=4);
	}
	translate([30,-20,-1])cube([4,40,8]);
	hull(){
		translate([-6,0,-1])cylinder(r=4,h=6);
		translate([16,8,-1])cylinder(r=4,h=6);
		translate([16,-8,-1])cylinder(r=4,h=6);
	}
	hull(){
		translate([16,22,-1])cylinder(r=4,h=6);
		translate([-6,30,-1])cylinder(r=4,h=6);
		translate([-6,14,-1])cylinder(r=4,h=6);
	}
	hull(){
		translate([16,-22,-1])cylinder(r=4,h=6);
		translate([-6,-14,-1])cylinder(r=4,h=6);
		translate([-6,-30,-1])cylinder(r=4,h=6);
	}
	pasantes(10);
	translate([-21.5,49,0])rotate([0,0,-90])mega(10);


}/**/







