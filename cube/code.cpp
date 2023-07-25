#include<GL/glut.h>
#include<stdio.h>

GLfloat vertices[][3] = { {-1,-1,-1},{1,-1,-1},{1,1,-1},
{-1,1,-1},{-1,-1,1},{1,-1,1},{1,1,1},{-1,1,1} };
GLfloat color[][3] = { {1,0,0},{1,1,0},{0,1,0},{0,0,1},{1,0,1},{1,1,1},{0,1,1},{0.5,0.5,0.5} };

void polygon(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glColor3fv(color[a]);
	glVertex3fv(vertices[a]);
	glColor3fv(color[b]);
	glVertex3fv(vertices[b]);
	glColor3fv(color[c]);
	glVertex3fv(vertices[c]);
	glColor3fv(color[d]);
	glVertex3fv(vertices[d]);
	glEnd();
}

void colorCube()
{
	polygon(0, 3, 2, 1);
	polygon(0, 4, 7, 3);
	polygon(5, 4, 0, 1);
	polygon(2, 3, 6, 7);
	polygon(1, 2, 6, 5);
	polygon(4, 5, 6, 7);
}

GLfloat theta[] = {0.0,0.0,0.0};
GLint axis = 2;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	colorCube();
	glutSwapBuffers();
}

void spinCube()
{
	theta[axis] += 0.1;
	if (theta[axis] > 360.0)
		theta[axis] -= 360.0;
	glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		axis = 0;
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		axis = 1;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		axis = 2;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w, 2.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat)w / (GLfloat)h, 2.0 * (GLfloat)w / (GLfloat)h, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GL_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Color Cube");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(spinCube);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}