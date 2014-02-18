#include <GLUT/glut.h>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <math.h>

#define RESL 0.05

void draw(void)
{
    //find points you want to draw. put them in an array then draw.
    // glPushMatrix();
    // glLoadIdentity();
    // glTranslatef(5,2,-20);
    // glBegin(GL_QUADS);   // quad takes up to 4 vertexes, connects them and creates a surface. For each quad, is use 2 of the previous vertexes
    //     glColor3f(1,0,0);
    //     glVertex3f(-3,-3,-4);
    //     glVertex3f(-3,-3,-4);
    //     glVertex3f(2,3,-5);
    //     glVertex3f(3,-3,-4);
    // glEnd();
    // glPopMatrix();

    // glPushMatrix();
    // glLoadIdentity();
    // glTranslatef(2,2,-20);
    // glBegin(GL_QUADS);   // quad takes up to 4 vertexes, connects them and creates a surface. For each quad, is use 2 of the previous vertexes
    //     glColor3f(0,0,1);
    //     glVertex3f(-3,-3,-4);
    //     glVertex3f(-3,-3,-4);
    //     glVertex3f(2,3,-5);
    //     glVertex3f(3,-3,-4);
    // glEnd();
    // glPopMatrix();

    static int angle; // why is angle given a static value
    static float pos = 0.0;

    float angle1, angle2;
    float xx, yy, zz, xxp, yyp, zzp;


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

                glVertex3f(xx, yy, zz);
                glVertex3f(xxp, yyp, zzp);
            }
            glEnd();
    }


    
}

void keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case 27:
			exit(0);
	}
}

void display(void){
    glClearColor(0.7f,0.7f,0.7f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0f, 0.9f, 1.0f);
    draw();
    //glFlush();
    glutSwapBuffers();

}

void init(void){
    glEnable(GL_DEPTH_TEST); // open more than one buffer
    glMatrixMode(GL_PROJECTION); // matrix for you camera or view
    glLoadIdentity(); 
    gluPerspective(40,1,0.01,100); //initial angle (cone like), last two are near and fire clipping planes. Where you can first see something to the end of your view. Rep z-index

    glMatrixMode(GL_MODELVIEW); //TELL'S gl the state you're about to draw in
    glLoadIdentity();
    glTranslatef(0,0,-10); //move the drawing view in the negatize z space directions

}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); //change glut_single to glut_double, so you use a double buffer
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("New window");

    glutDisplayFunc(display);
    init();
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














