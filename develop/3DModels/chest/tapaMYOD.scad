//Arduino Mega Board: 54x102x10


module pasantes(){

translate([28,46,-1])cylinder(r=2,h=70);
translate([28,-46,-1])cylinder(r=2,h=70);
translate([-19,46,-1])cylinder(r=2,h=70);
translate([-19,-46,-1])cylinder(r=2,h=70);
}

difference(){
	union(){
		translate([-64/2,-102/2,0])cube([64,102,4]);

	}

	translate([-29,-61,-4])rotate([0,0,20])cube([10,100,100]);
	mirror([0,1,0])translate([-29,-61,-4])rotate([0,0,20])cube([10,100,100]);

translate([28,-20,-1])cube([5,40,8]);

translate([-20,-20,-1])cube([30,40,8]);



	pasantes();





}/**/





