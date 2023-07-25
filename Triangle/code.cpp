#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

int x, y;
int r = 0;
void draw(float x1, float y1)
{
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(x1, y1);
	glEnd();
}

void triangle()
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(100, 100);
	glVertex2f(250, 400);
	glVertex2f(400, 100);
	glEnd();
}

GLfloat th = 0.0;
GLfloat trX = 0.0, trY = 0.0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	if (r == 1)
	{
		trX = 0.0;
		trY = 0.0;
		th += 0.1;
		draw(x, y);
	}
	if (r == 2)
	{
		trX = x;
		trY = y;
		th += 0.1;
		draw(x, y);
	}
	glTranslatef(trX, trY, 0.0);
	glRotatef(th, 0.0, 0.0, 1.0);
	glTranslatef(-trX, -trY, 0.0);
	triangle();
	glutPostRedisplay();
	glutSwapBuffers();

}

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void menu(int id)
{
	if (id == 1)
		r = 1;
	if (id == 2)
		r = 2;
	if (id == 3)
		r = 3;
}

int main(int argc, char** argv)
{
	printf("Enter the fixed points of rotation (x,y):");
	scanf_s("%d%d", &x, &y);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Triangle");
	glutDisplayFunc(display);
	glutCreateMenu(menu);
	glutAddMenuEntry("Rotate around Origin", 1);
	glutAddMenuEntry("Rotate around fixed point", 2);
	glutAddMenuEntry("Stop Rotation",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}