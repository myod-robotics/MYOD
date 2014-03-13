S=3;
X=(61-2*S)/2;
Y=(86-2*S)/2;
Z=(38.5-2*S)/2;
tornillo=1.8;
H=5; //Altura regulable

difference(){

	//%cube([61,86,38.5],center=true);
	union(){
	hull(){
	
		translate([X,Y,Z-H])sphere(S,$fn=40);
		translate([X-20,Y,Z-H])sphere(S,$fn=40);
		translate([-X,Y,Z-H-10])sphere(S,$fn=40);
		translate([X,-Y,Z-H])sphere(S,$fn=40);
		translate([X-20,-Y,Z-H])sphere(S,$fn=40);
		translate([-X,-Y,Z-H-10])sphere(S,$fn=40);
		translate([X,Y,-Z])cylinder(r=S,h=S,center=true,$fn=40);
		translate([-X,Y,-Z])cylinder(r=S,h=S,center=true,$fn=40);
		translate([X,-Y,-Z])cylinder(r=S,h=S,center=true,$fn=40);
		translate([-X,-Y,-Z])cylinder(r=S,h=S,center=true,$fn=40);

		translate([-X-6,8,Z-H-10]) sphere(S,$fn=40);
		translate([-X-6,-8,Z-H-10]) sphere(S,$fn=40);
		translate([-X,20,Z-H]) sphere(S,$fn=40);
		translate([-X,-20,Z-H]) sphere(S,$fn=40);
		translate([-X-6,8,-Z]) cylinder(r=S,h=S,center=true,$fn=40);
		translate([-X-6,-8,-Z]) cylinder(r=S,h=S,center=true,$fn=40);
	}
	//translate([-15,0,0])cylinder(r=18,h=22.5,$fn=200);
	translate([-10,0,0])cylinder(r=21,h=22.5,$fn=200);
	}

//- Agujero central

	cube([41.5,20,60],center=true);
	translate([0,0,20.25])cube([55,20,20],center=true);
	translate([0,0,-13.5])cube([55,20,15],center=true);
	translate([25,4.8,0])cylinder(r=tornillo,h=40,center=true,$fn=100);
	translate([25,-4.8,0])cylinder(r=tornillo,h=40,center=true,$fn=100);
	translate([-25,4.8,0])cylinder(r=tornillo,h=40,center=true,$fn=100);
	translate([-25,-4.8,0])cylinder(r=tornillo,h=40,center=true,$fn=100);
	translate([25.34,4.8,-6.1])cylinder(r=2.6,h=3,$fn=6);
	translate([25.34,-4.8,-6.1])cylinder(r=2.6,h=3,$fn=6);
	translate([-25.34,4.8,-6.1])cylinder(r=2.6,h=3,$fn=6);
	translate([-25.34,-4.8,-6.1])cylinder(r=2.6,h=3,$fn=6);
	translate([-20.5,0,0])cylinder(r=4,h=40,center=true,$fn=6);

//- Agujero +y

	translate([0,33.5,0])cube([41,21,40],center=true);
	translate([25.34,28.02,-20])cylinder(r=tornillo,h=25,$fn=100);
	translate([25.34,37.92,-20])cylinder(r=tornillo,h=25,$fn=100);
	translate([-25.34,28.02,-20])cylinder(r=tornillo,h=25,$fn=100);
	translate([-25.34,37.92,-20])cylinder(r=tornillo,h=25,$fn=100);

//- Agujero -y

	translate([0,-33.5,0])cube([41,21,40],center=true);
	translate([25.34,-28.02,-20])cylinder(r=tornillo,h=25,$fn=100);
	translate([25.34,-37.92,-20])cylinder(r=tornillo,h=25,$fn=100);	
	translate([-25.34,-28.02,-20])cylinder(r=tornillo,h=25,$fn=100);
	translate([-25.34,-37.92,-20])cylinder(r=tornillo,h=25,$fn=100);

// agujeros para tuercas

	translate([0,-37.91,0])cube([56,4,2],center=true); 
	translate([0,37.91,0])cube([56,4,2],center=true);
	translate([0,-28.01,0])cube([56,4,2],center=true);  
	translate([0,28.01,0])cube([56,4,2],center=true);

//agujeros para pestañas de servos en los laterales.

	translate([23.5,-34,-9.25])cube([8,21,4],center=true);
	translate([-23.5,-34,-9.25])cube([8,21,4],center=true);
	translate([23.5,34,-9.25])cube([8,21,4],center=true);
	translate([-23.5,34,-9.25])cube([8,21,4],center=true);

//agujeros para agarrar bateria

	translate([24,16,0])cylinder(r=3,h=50,center=true);
	translate([24,-16,0])cylinder(r=3,h=50,center=true);

}/**/


