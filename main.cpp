//Basic QUADS
#include <windows.h>
#include <GL/glut.h>
#include<cstdlib>
#include <ctime>
#include<iostream>

using namespace std;
float tx=0;
float ty=0;
float px=-3;
float py=0;
float cx=-1;
float ax=1;
float stride1=0.001;
float stride2=0.002;
float stride3=0.0015;
int timer=0;
float a;
float b;
int Count=0;
int flag=0;
void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-5,5,-5,5,-5,5);
}
void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:
				tx -=1;
				glutPostRedisplay();
				break;

		case GLUT_KEY_RIGHT:
				tx +=1;
				glutPostRedisplay();
				break;

        case GLUT_KEY_DOWN:
				ty -=1;
				glutPostRedisplay();
				break;

		case GLUT_KEY_UP:
				ty +=1;
				glutPostRedisplay();
				break;
	  default:
			break;
	}
}
void background(){



glColor3f(1.0f,1.0f,1.0f);
glPointSize(3);
glBegin (GL_POINTS);

for (float i = 5; i >= -5; )
{
    for(float j=-5;j<=5;){
        int a,b;
        a=rand()%1;
        b=rand()%2;
        glVertex3f(j+a,i-b,0);
        j+=0.6;
    }
    i-=0.6;
}

glEnd ();



}
float DrawAlien(float px,float stride,float py){
    glPushMatrix();
    glTranslatef(px,py,0);

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-0.4,4,0);
        glVertex3f(-0.5,3.9,0);
        glVertex3f(-0.5,3.8,0);
        glVertex3f(0.1,3.8,0);
        glVertex3f(0.1,3.9,0);
        glVertex3f(0,4,0);
    glEnd();


    //Eyes
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-0.3,3.8,0);
        glVertex3f(-0.3,3.9,0);
        glVertex3f(-0.4,3.9,0);
        glVertex3f(-0.4,3.8,0);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(0,3.8,0);
        glVertex3f(0,3.9,0);
        glVertex3f(-0.1,3.9,0);
        glVertex3f(-0.1,3.8,0);
    glEnd();

    //
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-0.25,4,0);
        glVertex3f(-0.25,4.1,0);
        glVertex3f(-0.35,4.1,0);
        glVertex3f(-0.35,4,0);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-0.05,4,0);
        glVertex3f(-0.05,4.1,0);
        glVertex3f(-0.15,4.1,0);
        glVertex3f(-0.15,4,0);
    glEnd();




    //left hand

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,3.6,0);
        glVertex3f(-0.6,3.6,0);
        glVertex3f(-0.6,3.8,0);
        glVertex3f(-0.5,3.8,0);
    glEnd();

    //right hand
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(0.1,3.6,0);
        glVertex3f(0.1,3.8,0);
        glVertex3f(0.2,3.8,0);
        glVertex3f(0.2,3.6,0);
    glEnd();

    //Body
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-0.5,3.8,0);
        glVertex3f(-0.5,3.7,0);
        glVertex3f(0.1,3.7,0);
        glVertex3f(0.1,3.8,0);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-0.4,3.75,0);
        glVertex3f(-0.4,3.65,0);
        glVertex3f(-0.01,3.65,0);
        glVertex3f(-0.01,3.75,0);
    glEnd();

    //Legs

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-0.4,3.60,0);
        glVertex3f(-0.4,3.65,0);
        glVertex3f(-0.3,3.65,0);
        glVertex3f(-0.3,3.60,0);
    glEnd();


    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-0.01,3.65,0);
        glVertex3f(-0.11,3.65,0);
        glVertex3f(-0.11,3.60,0);
        glVertex3f(-0.01,3.60,0);
    glEnd();

    //2nd
    glPopMatrix();


    if(px<=5 && flag==0){
        px=px+stride;
    }
    else{
        flag=1;
        timer++;

    }
    if(px>=-5 && flag==1){
        px-=stride;
    }
    else{
        flag=0;
        timer++;
    }


     glutPostRedisplay();
     return px;

}




void DrawSpaceship()
{
    glPushMatrix();
    glTranslatef(tx,ty,0);
    //Body
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex3f(-0.3, -3, 0.0);//top-left
        glVertex3f(-0.3, -3.8, 0.0);//bottom-left
        glVertex3f(0, -3.8, 0.0);//bottom-right
        glVertex3f(0, -3, 0.0);//top-right
    glEnd();

    //Tail
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex3f(-0.3, -3.8, 0.0);//top-left
        glVertex3f(-0.2, -3.95, 0.0);//bottom-left
        glVertex3f(-0.1, -3.95, 0.0);//bottom-right
        glVertex3f(0, -3.8, 0.0);//top-right
    glEnd();

    //Left Wing
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-0.8, -3.2, 0.0);//top-left
        glVertex3f(-1.3, -3.8, 0.0);//bottom-left
        glVertex3f(-0.8, -3.5, 0.0);
        glVertex3f(-0.3, -3.5, 0.0);//bottom-right
        glVertex3f(-0.3, -3.2, 0.0);//top-right
    glEnd();

    //Right Wing
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(0, -3.2, 0.0);//top-left
        glVertex3f(0, -3.5, 0.0);//bottom-left
        glVertex3f(0.5, -3.5, 0.0);
        glVertex3f(1.0, -3.8, 0.0);//bottom-right
        glVertex3f(0.5, -3.2, 0.0);//top-right
    glEnd();
    //Right Thruster
     glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(0, -3.6, 0.0);//top-left
        glVertex3f(0, -3.7, 0.0);//bottom-left
        glVertex3f(0.2, -3.7, 0.0);//bottom-right
        glVertex3f(0.2, -3.6, 0.0);//top-right
    glEnd();
     //glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(0.2, -3.7, 0.0);
        glVertex3f(0.1, -3.7, 0.0);
        glVertex3f(0.1, -3.8, 0.0);
        glVertex3f(0.2, -3.8, 0.0);
    glEnd();

    //Left Thruster
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(-0.5, -3.6, 0.0);//top-left
        glVertex3f(-0.5, -3.7, 0.0);//bottom-left
        glVertex3f(-0.3, -3.7, 0.0);//bottom-right
        glVertex3f(-0.3, -3.6, 0.0);//top-right
    glEnd();
    //glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex3f(-0.5, -3.7, 0.0);
        glVertex3f(-0.5, -3.8, 0.0);
        glVertex3f(-0.4, -3.8, 0.0);
        glVertex3f(-0.4, -3.7, 0.0);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-0.6, -3.8, 0.0);

        glVertex3f(-0.3, -3.8, 0.0);
    glEnd();

    //Head
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex3f(-0.2, -2.8, 0.0);//top-left
        glVertex3f(-0.3, -3, 0.0);//bottom-left
        glVertex3f(0, -3, 0.0);//bottom-right
        glVertex3f(-0.1, -2.8, 0.0);//top-right
    glEnd();
	glPopMatrix();
	glFlush();
    //Gun



}

void bullet(){


}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (timer>=4){
        timer=0;
        py-=0.0001;
    }

    px=DrawAlien(px,stride1,py);
    cx=DrawAlien(cx,stride2,py);
    ax=DrawAlien(ax,stride3,py);
    background();
    DrawSpaceship();


}
int main()
{
    //srand(time(0));
    glutInitWindowSize(600,600);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Basic Quads");

    init();
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(spe_key);

    glutMainLoop();
    return 0;
}
