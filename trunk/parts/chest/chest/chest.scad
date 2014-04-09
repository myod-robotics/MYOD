//Arduino Mega Board: 54x102x10


module pasantes(y){
y=y-10;
	translate([30,y/2,-1])cylinder(r=2,h=70);
	translate([30,-y/2,-1])cylinder(r=2,h=70);
	translate([-19,y/2,-1])cylinder(r=2,h=70);
	translate([-19,-y/2,-1])cylinder(r=2,h=70);
	translate([30,y/2-18,-1])cylinder(r=2,h=70);
	translate([30,-y/2+18,-1])cylinder(r=2,h=70);
	translate([-19,y/2-18,-1])cylinder(r=2,h=70);
	translate([-19,-y/2+18,-1])cylinder(r=2,h=70);
}

module servo(z){
	cube([41.5,22,z]);
	translate([-3,6,0])union(){
		//cylinder(r=2, h=z,$fn=20);
		//translate([48,0,0])cylinder(r=2, h=z,$fn=20);
		//translate([48,10,0])cylinder(r=2, h=z,$fn=20);
		//translate([0,10,0])cylinder(r=2, h=z,$fn=20);
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
	cylinder(r=2.6, h=4,$fn=6);
}

xmax=67;
ymax=122;
R=8;
difference(){
	union(){
		translate([-64/2+R,-ymax/2,0])cube([xmax-R,ymax,28]);
		translate([-64/2+20,-20,0])cube([47,40,35]);		
	}
	translate([-20,-30,2])cube([51,60,34]); //cajeado

	difference(){
		translate([-15,75,6.01])rotate([90,0,0])servo(150);
		translate([30.8,0,6])cube([10,59.9,70],center=true);
	}
	
//Huecos para tuercas
//	translate([-18,28,12])rotate([90,0,0]){
//		translate([0,0,-5.5])rotate([0,0,30])tuerca();
//		translate([48,0,-5.5])rotate([0,0,30])tuerca();
//		translate([48,10,-5.5])rotate([0,0,30])tuerca();
//		translate([0,10,-5.5])rotate([0,0,30])tuerca();
//	}
//	mirror([0,1,0])translate([-18,28,12])rotate([90,0,0]){
//		translate([0,0,-5.5])rotate([0,0,30])tuerca();
//		translate([48,0,-5.5])rotate([0,0,30])tuerca();
//		translate([48,10,-5.5])rotate([0,0,30])tuerca();
//		translate([0,10,-5.5])rotate([0,0,30])tuerca();
//	}






	translate([40,-7,6])rotate([0,-90,0])miniservo(30);

//Cruceta del servo	
	translate([-50,0,17])rotate([0,90,0])cylinder(r=5.5,h=40);
	translate([-50,+15,17])rotate([0,90,0])cylinder(r=2,h=40);
	translate([-50,-15,17])rotate([0,90,0])cylinder(r=2,h=40);
	translate([-62.5,+15,17])rotate([0,90,0])cylinder(r=3,h=40,$fn=6);
	translate([-62.5,-15,17])rotate([0,90,0])cylinder(r=3,h=40,$fn=6);


	translate([-32,ymax/2-13,6])cube([72,3.5,23]);
	mirror([0,1,0])translate([-32,ymax/2-13,6])cube([72,3.5,23]);

//Agujeros chasis
	pasantes(ymax);





}/**/





