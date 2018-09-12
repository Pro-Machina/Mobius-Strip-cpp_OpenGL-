#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#define PI 3.14159265358979323846

float abso(float x)
{
    //Just a function to return absolute value of a floating number
    if(x < 0)
        return (-x);
    else    
        return (x);
}

void display()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    float x=0, y=0, z=0;

    double r=0, t=0;
    for(t=0; t<(2*PI)+0.01; t+=0.005)
    {
        glBegin(GL_LINE_STRIP);
        for(r=-1; r<=1; r+=0.005)
        {
            //Following contains the equation of mobius strip in x,y,z co-ordinate varying r and theta
            x = (cos(t))*( 2 + (r/2)*cos(t/2) );
            y = (sin(t))*( 2 + (r/2)*cos(t/2) );
            z = ( (r/2)*sin(t/2) );

            glColor3f(abso(x/2), abso(y/2), abso(z/2));
            glVertex3f(x/2.5, y/2.5, z/2.5);
     
        }
        glEnd();

    }
    for(r=-1; r<=1; r+=0.005)
    {
        glBegin(GL_LINE_STRIP);
        for(t=0; t<(2*PI)+0.01; t+=0.005)
        {

            x = (cos(t))*( 2 + (r/2)*cos(t/2) );
            y = (sin(t))*( 2 + (r/2)*cos(t/2) );
            z = ( (r/2)*sin(t/2) );

            glColor3f(abso(x/2), abso(y/2), abso(z/2));
            glVertex3f(x/2.5, y/2.5, z/2.5);
        }
        glEnd();
    }
    glFlush();
} 

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("MOBIUS STRIP");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;

}   