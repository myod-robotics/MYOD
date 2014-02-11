use <write.scad>

//Arduino Mega Board: 54x102x10




module pasantes(){
	translate([29,46,-1])cylinder(r=2,h=70);
	translate([29,-46,-1])cylinder(r=2,h=70);
	translate([-19,46,-1])cylinder(r=2,h=70);
	translate([-19,-46,-1])cylinder(r=2,h=70);
}

module pasantesGordos(){
	translate([29,46,-1])cylinder(r=4,h=70);
	translate([29,-46,-1])cylinder(r=4,h=70);
	translate([-19,46,-1])cylinder(r=4,h=70);
	translate([-19,-46,-1])cylinder(r=4,h=70);
}

module servo(z){
	cube([42,22,z]);
	translate([-3,6,0])union(){
		cylinder(r=2, h=z,$fn=20);
		translate([48,0,0])cylinder(r=2, h=z,$fn=20);
		translate([48,10,0])cylinder(r=2, h=z,$fn=20);
		translate([0,10,0])cylinder(r=2, h=z,$fn=20);
	}
}

module miniservo(z){
	//cube([24,14,z]);
	translate([15,7,0])rotate([0,0,0])cylinder(r=8,h=z);
	translate([-1.75,7,0])union(){
		cylinder(r=1.5, h=z,$fn=20);
		translate([27.5,0,0])cylinder(r=1.5, h=z,$fn=20);
		
	}
}

module tuerca(){ //M3
	cylinder(r=3, h=4,$fn=6);
}

xmax=66;
ymax=102;

difference(){
hull(){
	difference(){
		translate([-64/2,-102/2,0])cube([xmax,ymax,3]);
		translate([-29,-61,-4])rotate([0,0,20])cube([10,100,100]);
		mirror([0,1,0])translate([-29,-61,-4])rotate([0,0,20])cube([10,100,100]);
	}
	translate([20,0,7])rotate([90,0,0])cylinder(r=7,h=70,center=true,$fn=8);
	translate([-3,+20,9])sphere(5);
	translate([-3,-20,9])sphere(5);

}
translate([8,-1,15])rotate([0,0,-90])write("MYOD",t=4,h=15,center=true);
pasantes(10);
translate([0,0,3])pasantesGordos(10);
}




