S=3;
X=(61-2*S)/2;
Y=(86-2*S)/2;
Z=(38.5-2*S)/2;
tornillo=1.8;
H=5; //Altura regulable

difference(){

	//%cube([61,86,38.5],center=true);
	hull(){
	
		translate([X,Y,Z-H])sphere(S,$fn=40);
		translate([-X,Y,Z-H])sphere(S,$fn=40);
		translate([X,-Y,Z-H])sphere(S,$fn=40);
		translate([-X,-Y,Z-H])sphere(S,$fn=40);
		translate([X,Y,-Z])cylinder(r=S,h=S,center=true,$fn=40);
		translate([-X,Y,-Z])cylinder(r=S,h=S,center=true,$fn=40);
		translate([X,-Y,-Z])cylinder(r=S,h=S,center=true,$fn=40);
		translate([-X,-Y,-Z])cylinder(r=S,h=S,center=true,$fn=40);

		translate([-X-6,20,Z-H-2]) sphere(S,$fn=40);
		translate([-X-6,-20,Z-H-2]) sphere(S,$fn=40);
		translate([-X-6,20,-Z]) cylinder(r=S,h=S,center=true,$fn=40);
		translate([-X-6,-20,-Z]) cylinder(r=S,h=S,center=true,$fn=40);
	}

//- Agujero central

	cube([41,20,40],center=true);
	translate([0,0,15.25])cube([55,20,10],center=true);
	translate([0,0,-13.5])cube([55,20,15],center=true);
	translate([-18,0,-15.3])cube([30,8,8],center=true);
	translate([25.34,4.8,0])cylinder(r=tornillo,h=40,center=true,$fn=100);
	translate([25.34,-4.8,0])cylinder(r=tornillo,h=40,center=true,$fn=100);
	translate([-25.34,4.8,0])cylinder(r=tornillo,h=40,center=true,$fn=100);
	translate([-25.34,-4.8,0])cylinder(r=tornillo,h=40,center=true,$fn=100);
	translate([25.34,4.8,-6.1])cylinder(r=2.6,h=3,$fn=6);
	translate([25.34,-4.8,-6.1])cylinder(r=2.6,h=3,$fn=6);
	translate([-25.34,4.8,-6.1])cylinder(r=2.6,h=3,$fn=6);
	translate([-25.34,-4.8,-6.1])cylinder(r=2.6,h=3,$fn=6);
	translate([-19.5,0,0])cylinder(r=4,h=40,center=true,$fn=8);

//- Agujero +y

	translate([0,33.5,0])cube([41,21,40],center=true);
	translate([-40,30,13])cube([30,30,10]);
	translate([25.34,28.02,-20])cylinder(r=tornillo,h=25,$fn=100);
	translate([25.34,37.92,-20])cylinder(r=tornillo,h=25,$fn=100);
	translate([-25.34,28.02,-20])cylinder(r=tornillo,h=25,$fn=100);
	translate([-25.34,37.92,-20])cylinder(r=tornillo,h=25,$fn=100);

//- Agujero -y

	translate([0,-33.5,0])cube([41,21,40],center=true);
	mirror([0,1,0])translate([-40,30,13])cube([30,30,10]);
	translate([25.34,-28.02,-20])cylinder(r=tornillo,h=25,$fn=100);
	translate([25.34,-37.92,-20])cylinder(r=tornillo,h=25,$fn=100);	
	translate([-25.34,-28.02,-20])cylinder(r=tornillo,h=25,$fn=100);
	translate([-25.34,-37.92,-20])cylinder(r=tornillo,h=25,$fn=100);

// agujeros para tuercas

	translate([0,-37.91,0])cube([70,4,2],center=true); 
	translate([0,37.91,0])cube([70,4,2],center=true);
	translate([0,-28.01,0])cube([70,4,2],center=true);  
	translate([0,28.01,0])cube([70,4,2],center=true);

//agujeros para pestañas de servos en los laterales.

	translate([23.5,-34,-9.25])cube([8,21,4],center=true);
	translate([-23.5,-34,-9.25])cube([8,21,4],center=true);
	translate([23.5,34,-9.25])cube([8,21,4],center=true);
	translate([-23.5,34,-9.25])cube([8,21,4],center=true);

}/**/



