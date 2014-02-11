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
	translate([13.5,51,-1.5])cylinder(r=3.3,h=3,$fn=6);
	translate([12.5,2.5,-1.5])cylinder(r=3.3,h=3,$fn=6);
	translate([88.5,51,-1.5])cylinder(r=3.3,h=3,$fn=6);
	//translate([95,2.5,-1.5])cylinder(r=3.3,h=3,$fn=6);
}

d=3;

rotate([0,180,0])difference(){

	translate([-64/2+8,-102/2,0])cube([58,102,4]);
	translate([30,-20,-1])cube([5,40,8]);
	translate([26,-6,-1])cube([8,12,8]);
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







