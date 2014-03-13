module dedo(){
	union(){
		translate([0,0,10]){cylinder(r=5,h=20);}
		translate([0,0,30]){rotate([-90,0,0]){cylinder(r=5,h=20);}}
		translate([0,20,16]){rotate([0,0,0]){cylinder(r=5,h=14);}}
		translate([0,0,30]){sphere(5);}
		translate([0,20,30]){sphere(5);}
		translate([0,20,16]){sphere(5);}
		translate([0,0,10]){sphere(5);}
	}
}

module taladros(){
	translate([0,0,0]){cylinder(r=1,h=20, $fn=50);}
	translate([0,16,0]){cylinder(r=1,h=20, $fn=50);}
	translate([16,0,0]){cylinder(r=1,h=20, $fn=50);}
	translate([16,16,0]){cylinder(r=1,h=20, $fn=50);}
}



difference(){
	union(){
		translate([4,-10,5]){rotate([0,-10,0]){dedo();}}
		translate([8,-10,5]){dedo();}
		translate([16,-10,5]){dedo();}
		translate([20,-10,5]){rotate([0,10,0]){dedo();}}
		translate([0,-10,15]){rotate([-55,0,15]){
			union(){
				translate([0,0,3]){sphere(5);}
				translate([0,0,3]){cylinder(r=5,h=27, $fn=50);}
				translate([0,0,30]){sphere(5);}
				translate([0,0,30]){rotate([0,105,0]){
					union(){
						cylinder(r=5,h=20);
						translate([0,0,20]){sphere(5);}
					}			
				}} //TR
			} 
		}} //TR
		translate([0,-12,12]){cube([24,24,18]);}
		translate([12,0,0]){cylinder(r1=12,r2=18,h=12, $fn=100);}
	}
	translate([4,-8,0]){taladros();}
}
