module base(){union(){
difference(){
	union(){
		cube([36,34,18]);
		translate([0,17,27])rotate([0,90,0])cylinder(r=6, h=36);

		translate([0,16.5,2])rotate([46,0,0])cube([36,18,23]);
		mirror([0,1,0])translate([0,-17.5,2])rotate([46,0,0])cube([36,18,23]);
	}
		translate([-1,17,27])rotate([0,90,0])cylinder(r=1.5, h=38, $fn=10);
		translate([5,0,20])cube([26,40,40]);
		translate([5,17,27])rotate([0,90,0])cylinder(r=7.5, h=26);
		translate([36-27,5.5,3])cube([36,23,12]);
		translate([36-5,0.5,3])cube([36,33,12]);
		translate([5,10,4])cube([4,36,10]);
		translate([13,3,9])rotate([0,90,0])cylinder(r=1, h=38, $fn=10);
		translate([13,31,9])rotate([0,90,0])cylinder(r=1, h=38, $fn=10);
}

//SOPORTE
/*
		translate([0,16.5,2])rotate([46,0,0])translate([0,5,21.5])cube([36,13,1.5]);
mirror([0,-1,0])translate([0,-17.5,2])rotate([46,0,0])translate([0,5,21.5])cube([36,13,1.5]);
		translate([0,17,31.5])rotate([0,90,0])cylinder(r=1.5, h=36, $fn=10);
/**/
}
}

module pinza(){
difference(){
	union(){
		difference(){
			translate([-4,0,0])cube([55,16,36]);
			translate([26,-23,-1])cylinder(r=30, h=38,$fn=13);
			translate([-20,-6.5,-1])rotate([0,0,35])cube([75,21,38]);
			translate([20,27,-1])rotate([0,0,-30])cube([75,21,38]);
		}
		cylinder(r=6, h=36);
	}
	translate([0,0,-1])cylinder(r=1.5, h=38, $fn=10);

	translate([-9,-5,-1])rotate([0,0,-18])cube([13,50,6]);
	translate([-9,-5,31])rotate([0,0,-18])cube([13,50,5]);
	
	translate([0,0,11.5])cylinder(r=7, h=6.5);
	translate([0,0,24.5])cylinder(r=7, h=6.5);

}
}

translate([-27,17,0])rotate([0,-90,180])base();
color("red",1)rotate([0,0,20])pinza();
color("blue",1)translate([0,0,36])rotate([180,0,-20])pinza();

