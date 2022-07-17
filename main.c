#include <GL/glut.h>
#include <math.h>

GLfloat angle1 =0;
GLfloat angle2 =0;
GLfloat angle3 =0;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
}

void spin(){
  angle1 +=0.02;
  angle2 +=0.001;
  angle3 +=0.01;

  if(angle1 > 360.0){
    angle1 = 0;
  }
  if(angle2 > 360.0){
    angle2 = 0;
  }
  if(angle3 > 360.0){
    angle3 = 0;
  }
  glutPostRedisplay(); // marks the current window as needing to be redisplayed.
}


void display(void) {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// sun
glColor3f( 1, 0.65, 0);
glTranslatef(0,0,0);
glutSolidSphere(0.2,100,20);
glLoadIdentity();

// first planet
glColor3f( 1, 1, 1);
glBegin(GL_POINTS);
for(int i =0;i<150;i++){
glVertex2f(0.5f*cosf(i*6.2904846/150),0.5f*sinf(i*6.2904846/150));
}
glEnd();
glRotatef(angle1,0,0,1);
glTranslatef(0.5,0,0);
glColor3f( 0.1, 0.5, 1);
glutSolidSphere(0.01,10,10);
glTranslatef(-0.5,0,0);

// second planet
glLoadIdentity();
glColor3f( 1, 1, 1);
glBegin(GL_POINTS);
for(int i =0;i<200;i++){
glVertex3f(0.6f*cosf(i*6.2904846/200),0,0.6f*sinf(i*6.2904846/200));
}
glEnd();
glRotatef(angle2,0,1,0);
glTranslatef(0.6,0,0);
glColor3f( 0.3, 0.5, 0.7);
glutSolidSphere(0.03,10,10);
glTranslatef(-0.6,0,0);

// third planet
glPopMatrix();
glPushMatrix();
//glRotatef(100,-0.8,1,-0.5);
glRotatef(95,-0.8,1,-0.5);
glColor3f( 1, 1, 1);
glBegin(GL_POINTS);
for(int i =0;i<300;i++){
glVertex3f(0.7f*cosf(i*6.2904846/300),0.4f*sinf(i*6.2904846/300),0.7f*cosf(i*6.2904846/300));
}
glEnd();
glPopMatrix();
glPushMatrix();
glRotatef(angle3,0.5,1,0.2);
glTranslatef(-0.8,0.45,0);
glColor3f( 0.1, 0.5, 1);
glutSolidSphere(0.09,50,10);
glTranslatef(0.8,-0.45,0);

glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION); /*Loading Projection Matrix*/
	glLoadIdentity(); /*This will clear the current matrix (Projection Matrix)*/
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0); /*Projection trnasformation*/
	glMatrixMode(GL_MODELVIEW); /*Loading ModelView Matrix*/
}

int main(int argc, char **argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(100,50);

	glutCreateWindow("Transformations");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(spin);
	//glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
