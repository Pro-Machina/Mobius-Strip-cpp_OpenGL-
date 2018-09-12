
r=10;
height=3;
union()
{
    for(theta=[0:1:360])
    {
        translate([r*cos(theta),r*sin(theta),0])
        translate([1/2,1/2,height/2])
        rotate([90,0,0])
        rotate([0,theta,0])
        rotate([0,0,(180/360)*theta])
        rotate([0,-theta,0])
        rotate([-90,0,0])
        translate([-1/2,-1/2,-height/2])
        color([0,0,1]) 
        cube([1,1,height],false);
    }
    
}