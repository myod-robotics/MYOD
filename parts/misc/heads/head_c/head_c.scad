module pico(){
difference(){
rotate([0,90,0])translate([0,0,0])cylinder(r=60,h=3);
translate([0,45,0])rotate([0,90,0])translate([0,0,-1])cylinder(r=85,h=5);
}

module ok(){

	translate([0,-5,0])cylinder(r=1,h=60);
	translate([0,5,0])cylinder(r=1,h=60);
}

}

difference(){
union(){
translate([0,0,4])hull(){

	sphere(r=34);
	translate([0,22,0])sphere(r=26);
	translate([0,24,0])sphere(r=22);
	translate([0,28,0])sphere(r=12);
	translate([0,32,0])sphere(r=16);
	translate([0,48,0])sphere(r=14);
	//%translate([0,33,0])sphere(r=10);
	translate([0,60,0])sphere(r=8);

}
translate([-1.5,40,-5])pico();
translate([-1.5,70,-10])pico();
translate([-1.5,90,-25])pico();
}
translate([0,0,-300])cube(600, center=true);

translate([-45/2,-60,3])cube([45,50,20]);


translate([0,0,-1])cylinder(r=2,h=10);

translate([-8,0,-1])cylinder(r=1.5,h=10);
translate([8,0,-1])cylinder(r=1.5,h=10);
translate([0,8,-1])cylinder(r=1.5,h=10);
translate([0,-8,-1])cylinder(r=1.5,h=10);
translate([0,50,-2])rotate([75,0,0])cylinder(r=4,h=190);

}

