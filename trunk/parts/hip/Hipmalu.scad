
difference()
{
	cube([61,86,38.5],center=true);

//- Agujero central

		cube([41,20,40],center=true);

		translate([0,0,15.25])
			cube([55,20,10],center=true);

		translate([0,0,-13.5])
			cube([55,20,15],center=true);

		translate([-35,0,-15.3])
			cube([70,8,8],center=true);

		translate([25.34,4.8,0])
			cylinder(r=1.5,h=40,center=true,$fn=100);

		translate([25.34,-4.8,0])
			cylinder(r=1.5,h=40,center=true,$fn=100);

		translate([-25.34,4.8,0])
			cylinder(r=1.5,h=40,center=true,$fn=100);

		translate([-25.34,-4.8,0])
			cylinder(r=1.5,h=40,center=true,$fn=100);

//- Agujero +y

	translate([0,33.5,0])
		cube([41,21,40],center=true);

	translate([-35,33,16.3])
		cube([70,6,6],center=true);

	translate([25.34,28.02,0])
		cylinder(r=1.5,h=40,center=true,$fn=100);

	translate([25.34,37.92,0])
		cylinder(r=1.5,h=40,center=true,$fn=100);
	
	translate([-25.34,28.02,0])
		cylinder(r=1.5,h=40,center=true,$fn=100);

	translate([-25.34,37.92,0])
		cylinder(r=1.5,h=40,center=true,$fn=100);
	
//- Agujero -y

	translate([0,-33.5,0])
		cube([41,21,40],center=true);

	translate([-35,-33,16.3])
		cube([70,6,6],center=true);

	translate([25.34,-28.02,0])
			cylinder(r=1.5,h=40,center=true,$fn=100);

	translate([25.34,-37.92,0])
			cylinder(r=1.5,h=40,center=true,$fn=100);
	
	translate([-25.34,-28.02,0])
			cylinder(r=1.5,h=40,center=true,$fn=100);

	translate([-25.34,-37.92,0])
			cylinder(r=1.5,h=40,center=true,$fn=100);

//Adornos

	translate([31.50,16.50,0])
			cylinder(r=4.5,h=40,center=true,$fn=100);

	translate([31.50,-16.50,0])
			cylinder(r=4.5,h=40,center=true,$fn=100);

	translate([-31.50,16.50,0])
			cylinder(r=4.5,h=40,center=true,$fn=100);

	translate([-31.50,-16.50,0])
			cylinder(r=4.5,h=40,center=true,$fn=100);

// agujeros para tuercas

	translate([0,-37.91,0])
		cube([70,4,2],center=true); 

	translate([0,37.91,0])
		cube([70,4,2],center=true);

	translate([0,-28.01,0])
		cube([70,4,2],center=true);  

	translate([0,28.01,0])
		cube([70,4,2],center=true);

//agujeros para pestañas de servos en los laterales.

	translate([23.5,-33.5,-9.25])
		cube([8,21,4],center=true);

	translate([-23.5,-33.5,-9.25])
		cube([8,21,4],center=true);

	translate([23.5,33.5,-9.25])
		cube([8,21,4],center=true);

	translate([-23.5,33.5,-9.25])
		cube([8,21,4],center=true);

}








