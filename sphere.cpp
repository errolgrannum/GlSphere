#include <GLUT/glut.h>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <unistd.h>
#include <math.h>

#define RESL 0.05


// Based off of strip concept with Trig functions approach by TheShellWave

void draw(void)
{


    static int angle; // why is angle given a static value
    static float pos = 0.0;

    float angle1, angle2;
    float xx, yy, zz, xxp, yyp, zzp;


    glClearColor(0.7f,0.7f,0.7f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glRotatef(angle, 1.0, 1.0, 0.0);
    
    for(angle2 = -3.1416/2; angle2 <= 3.1416/2; angle2 += RESL)
    {
        glBegin(GL_QUAD_STRIP);

            for(angle1 = 0.0; angle1 <= 3.1416*2.0; angle1 += RESL)
            {
                yy = sin(angle2);
                xx = cos(angle1)*cos(angle2);
                zz = sin(angle1)*cos(angle2);

                yyp = sin(angle2 + RESL);
                xxp = cos(angle1)*cos(angle2 + RESL);
                zzp = sin(angle1)*cos(angle2 + RESL);


                glColor3f(zz*zz, xx*xx, 1.0f);
                glVertex3f(xx, yy, zz);
                glVertex3f(xxp, yyp, zzp);
            }
            glEnd();
    }

    glPopMatrix();
    glutSwapBuffers();
    usleep(5000);

    

    angle += 1;
    if(angle == 360){
        angle = 0;
    }
        

    pos += 0.001;

    if(pos >= 1.0){
        pos = 0.0;
    }
        


    
}

void keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case 27:
			exit(0);
	}
}

void display(void){
    draw();


}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); //change glut_single to glut_double, so you use a double buffer
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("New window");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

//Glpush
//pushing a matrix to a stack/queue saves a state
//draw your first cube

// Glpop
//going to where you were before, preserving model view


//Things happen in the order you write them in
//






