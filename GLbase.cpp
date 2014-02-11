#include <GLUT/glut.h>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

void draw(void)
{
    //find points you want to draw. put them in an array then draw.
    glPushMatrix();
    glBegin(GL_QUADS);   // quad takes up to 4 vertexes, connects them and creates a surface. For each quad, is use 2 of the previous vertexes
        glColor3f(1,0,0);
        glVertex3f(-3, -3, -4);
        glVertex3f(-3, -3, -4);
        glVertex3f(3,3,-4);
        glVertex3f(3,-3,-4);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUADS);   // quad takes up to 4 vertexes, connects them and creates a surface. For each quad, is use 2 of the previous vertexes
        glColor3f(0,1,0);
        glVertex3f(-3, -3, -4);
        glVertex3f(-3, -3, -4);
        glVertex3f(3,3,-4);
        glVertex3f(3,-3,-4);
    glEnd();
    glTranslatef(2,2,2);

    glPopMatrix();
    
}

void keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case 27:
			exit(0);
	}
}

void display(void){
    glClearColor(0,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT| GLUT_DEPTH_BUFFER_BIT);
    draw();
    glFlush();
    glutSwapBuffers();
}

void init(void){
    glEnable(GLUT_DEPTH_TEST); // open more than one buffer
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
    glutCreateWindow("Red window");

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














