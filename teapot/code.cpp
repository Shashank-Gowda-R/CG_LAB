#include<GL/glut.h>
int i;
void display()
{
	GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f};
	GLfloat mat_diffuse[]={0.5f,0.5f,0.5f,1.0f};
	GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f,};
	GLfloat mat_shininess[]={10.0f};

	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

	GLfloat lightIntensity[]={0.7f,0.7f,0.7f,0.1f};
	GLfloat light_position[]={170.0f,175.0f,0.0f,0.0f};

	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);

	glMatrixMode(GL_PROJECTION);
	double h=1.0;
	glOrtho(-h*64/48.0,h*64/48.0,-h,h,0.1,100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	gluLookAt(0.3,1.3,20.0,0.0,0.25,0.0,0.0,10.0,10.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glClearColor(1.0,1.0,0.5,1.0);
	glColor3f(1.0,1.0,1.0);

	glBegin(GL_POLYGON);
	glVertex2f(25,100);
	glVertex2f(250,100);
	glVertex2f(300,175);
	glVertex2f(75,175);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(25,0);
	glVertex2f(40,0);
	glVertex2f(40,100);
	glVertex2f(25,100);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(235,0);
	glVertex2f(250,0);
	glVertex2f(250,100);
	glVertex2f(235,100);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(285,75);
	glVertex2f(300,75);
	glVertex2f(300,175);
	glVertex2f(285,175);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(75,75);
	glVertex2f(90,75);
	glVertex2f(75,175);
	glVertex2f(90,175);
	glEnd();

	glTranslatef(170,175,0);
	glFlush();

	glColor3f(1.0,1.0,1.0);
	glutSolidTeapot(50.08);
	glEnd();
	glFlush();
}

void myinit()
{
	glClearColor(0.0,0.2,0.5,1.0);
	glColor3f(0.0,0.0,1.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-499.0,500.0,-499.0,500.0);
}

void main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("TEA POT");
	glutDisplayFunc(display);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	myinit();
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
}