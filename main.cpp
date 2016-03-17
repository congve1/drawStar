#include <Windows.h>
#include <gl/glut.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.1415926535898 
void drawStar(float x0, float y0,
			  float theta,
			  float R,
			  float r)
{
	float rad36 =  PI / 180 * 36;
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);	
	/*
	glBegin(GL_LINE_LOOP);
	for( i = 0 ; i < 10 ; i++){
		
		if(i % 2 == 0){
			glVertex2f(x0  + R * cos(theta +i * rad36),
				y0 + R * sin(theta +i * rad36));
		}else{
			glVertex2f(x0 + r * cos(theta + i * rad36),
				y0 + r * sin(theta + i * rad36));
		}
	}
	glEnd();*/
	float x[10];
	float y[10];


	glBegin(GL_LINES);
	for(int j = 0 ; j < 100 ; j++){

	for( i = 0 ; i < 10 ; i++){			
		if(i % 2 == 0){
			x[i] = x0  + R * cos(theta +i * rad36);
			y[i] = y0 + R * sin(theta +i * rad36);				
			
		}else{
			x[i] = x0  + r * cos(theta +i * rad36);
			y[i] = y0 + r * sin(theta +i * rad36);
			
		}}
	for( i = 0 ; i < 10 ; i++){
		glVertex2f(x[i],y[i]);
		glVertex2f(x[(i + 1) % 10],y[(i+1) % 10]); 
	}
	x0 = (float)rand() / RAND_MAX * 0.7 + 0.1;
	y0 = (float)rand() / RAND_MAX* 0.7 + 0.2;
	theta = (float)rand() / RAND_MAX * PI;
	R = (float)rand() / RAND_MAX * 0.05;
	r =(float)rand() / RAND_MAX * 0.05 ;
	}
	glEnd();

	
	glFlush();
}
void display()
{
	srand(time(NULL));
	drawStar(0.5 , 0.5,
		(float)rand() / RAND_MAX * PI,
		(float)rand() / RAND_MAX * 0.05,
		(float)rand() / RAND_MAX * 0.05);
	
}
int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1024,768);
	glutCreateWindow("hehe");
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,1.0,0.1,1.0,-1.0,1.0);
	glutDisplayFunc(display);	
	glutMainLoop();	
	return 0;
}