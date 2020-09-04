//Basic QUADS
#include <windows.h>
#include <GL/glut.h>
#include<cstdlib>
#include <ctime>
#include<iostream>
#include <cmath>
#define PI 3.14
using namespace std;
int bulletFlag=0;

float left_hand_x_1=-0.6;
float right_hand_x_1=0.2;

char buffer[10];
int quit=0;
int stop=0;
float alienship_x=-4;
float alienship_y=3;
int score=0;
int highscore=0;
float by=0;


float alien_ship_x1=-0.3;
float alien_ship_x2=-0.2;
float alien_ship_x3=0.2;
float alien_ship_x4=0.3;

int hit_flag_1=0;
int hit_flag_2=0;
int hit_flag_3=0;
int hit_flag_4=0;

float tx=0;
float btx=0;
float ty=0;
float px=-3;

float py=0;
float qy=0;
float ry=0;

float cx=-1;
float ax=1;
 float stride1=0.002;
 float stride2=0.0025;
 float stride3=0.0029;
float stride4=0.002;
int timer1=0;
int timer2=0;
int timer3=0;
int timer4=0;
float a;
float b;
int Count=0;
int flag1=0;
int flag2=0;
int flag3=0;
int flag4=0;


float bodyx1_1=-0.4;
float bodyx2_1=-0.4;
float bodyx3_1=-0.01;
float bodyx4_1=-0.01;

float bodyy1_1=3.75;
float bodyy2_1=3.65;
float bodyy3_1=3.65;
float bodyy4_1=3.75;

float bullet_x1=-0.2;
float bullet_x2=-0.2;
float bullet_x3=-0.1;
float bullet_x4=-0.1;

float bullet_y1=-2.4;
float bullet_y2=-2.7;
float bullet_y3=-2.7;
float bullet_y4=-2.4;

float bodyy1_2=3.75;
float bodyy2_2=3.65;
float bodyy3_2=3.65;
float bodyy4_2=3.75;

float bodyy1_3=3.75;
float bodyy2_3=3.65;
float bodyy3_3=3.65;
float bodyy4_3=3.75;


void drawText(char ch[],int xpos, float ypos)//draw score/message on screen
{
    int numofchar = strlen(ch);
    //glLoadIdentity ();
    glRasterPos2f( xpos, ypos);
    for (int i = 0; i < numofchar; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);
    }
}


void drawTextNum(char ch[],int numtext,float xpos, float ypos)//counting the score
{
    int len;
    int k;
    k = 0;
    len = numtext - strlen (ch);
    //glLoadIdentity ();
    glRasterPos2f( xpos, ypos);
    for (int i = 0; i <=numtext - 1; i++)
    {
        if ( i < len )
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'0');
        else
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[k]);
            k++;
        }

    }
}


float* centroid(float x1,float x2,float x3,float x4,float y1,float y2,float y3,float y4){
   float X=(x1+x2+x3+x4)/4;
   float Y=(y1+y2+y3+y4)/4;
   static float arr[2];
   arr[0]=X;
   arr[1]=Y;
   return arr;
   //cout<<X<<" "<<Y<<endl;

}
float dist(float x1,float x2,float y1,float y2){
   float X=(x1-x2)*(x1-x2);
    float Y=(y1-y2)*(y1-y2);
    return sqrt(X+Y);
}


class Bullet{
public:
void drawBullet(float tx){
    if (bulletFlag==0){
        return;
    }

    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(tx,by,0);
    glBegin(GL_QUADS);
        glVertex3f(bullet_x1, bullet_y1, 0.0);//top-left
        glVertex3f(bullet_x2, bullet_y2, 0.0);//bottom-left
        glVertex3f(bullet_x3, bullet_y3, 0.0);//bottom-right
        glVertex3f(bullet_x4, bullet_y4, 0.0);//top-right
    glEnd();

    glPopMatrix();

    by+=0.0045;
    //centroid(bullet_x1+tx,bullet_x2+tx,bullet_x3+tx,bullet_x4+tx,bullet_y1,bullet_y2,bullet_y3,bullet_y4);
    glutPostRedisplay();
}

};
Bullet bull;


void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-5,5,-5,5,-5,5);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case ' ':
        btx=tx;
        bulletFlag=1;
        by=0;
        PlaySound("laser.wav",NULL,SND_FILENAME|SND_ASYNC);
        break;
    case 'q':
        quit=1;
        exit(EXIT_SUCCESS);
    case 'n':
        stop=0;
        py=0;
        stride1=0.002;
        stride2=0.0025;
        stride3=0.0029;


            tx=0;
            btx=0;
            ty=0;
            px=-3;
            py=0;
            qy=0;
            ry=0;
            cx=-1;
            ax=1;
            //by=0;
            timer1=0;
            timer2=0;
            timer3=0;
            flag1=0;
            flag2=0;
            flag3=0;
            hit_flag_1=0;
            hit_flag_2=0;
            hit_flag_3=0;
            bulletFlag=0;
            hit_flag_4=0;
            alienship_x=-4;
            alienship_y=3;
        break;
    }
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

	  default:
			break;
	}
}
void background(){



glColor3f(1.0f,1.0f,1.0f);
glPointSize(2);
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
float DrawAlien1(float px,float stride,float py){
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

    //glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-0.5,3.6,0);
        glVertex3f(-0.6,3.6,0);//Need this
        glVertex3f(-0.6,3.8,0);
        glVertex3f(-0.5,3.8,0);
    glEnd();

    //right hand
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(0.1,3.6,0);
        glVertex3f(0.1,3.8,0);
        glVertex3f(0.2,3.8,0);  //Need this
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

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(bodyx1_1,bodyy1_1,0);
        glVertex3f(bodyx2_1,bodyy2_1,0);
        glVertex3f(bodyx3_1,bodyy3_1,0);
        glVertex3f(bodyx4_1,bodyy4_1,0);
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


    if(px<=5 && flag1==0){
        px=px+stride;
    }
    else{
        flag1=1;
        timer1++;

    }
    if(px>=-5 && flag1==1){
        px-=stride;
    }
    else{
        flag1=0;
        timer1++;
    }
     //centroid(bodyx1_1+px,bodyx2_1+px,bodyx3_1+px,bodyx4_1+px,bodyy1_1+py,bodyy2_1+py,bodyy3_1+py,bodyy4_1+py);
     glutPostRedisplay();
     return px;

}


float DrawAlien2(float px,float stride,float py){
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
        glVertex3f(-0.6,3.6,0); //Need This
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

    glColor3f(1.0f, 1.0f, 0.0f);
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


    if(px<=5 && flag2==0){
        px=px+stride;
    }
    else{
        flag2=1;
        timer2++;

    }
    if(px>=-5 && flag2==1){
        px-=stride;
    }
    else{
        flag2=0;
        timer2++;
    }


     glutPostRedisplay();
     return px;

}

float DrawAlien3(float px,float stride,float py){
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

    glColor3f(0.0f, 0.0f, 1.0f);
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


    if(px<=5 && flag3==0){
        px=px+stride;
    }
    else{
        flag3=1;
        timer3++;

    }
    if(px>=-5 && flag3==1){
        px-=stride;
    }
    else{
        flag3=0;
        timer3++;
    }


     glutPostRedisplay();
     return px;

}






void semiCircle(int orientation,float x,float y ,float rx,float ry,int r,int g, int b)   // the filled one
{
    float angle=0;
    glBegin(GL_POLYGON);
    glColor3ub(r,g,b);
    for(int i=0;i<700;i++){
        angle=(PI*i)/700;

        glVertex2f(orientation*cos(angle)*rx+x,orientation*sin(angle)*ry+y);
    }
    glEnd();
    //glFlush();

}

void DrawSpaceship()
{
    glPushMatrix();
    glTranslatef(tx,ty,0);
        //Head
    semiCircle(1,-0.15,-2.5,0.1,0.2,226,124,72);
    glColor3ub(128,182,252);
    glBegin(GL_QUADS);
        glVertex3f(-0.25, -2.5, 0.0);//top-left
        glVertex3f(-0.35, -3, 0.0);//bottom-left
        glVertex3f(0.05, -3, 0.0);//bottom-right
        glVertex3f(-0.05, -2.5, 0.0);//top-right
    glEnd();
    //Body
    glColor3ub(128,182,252);
    glBegin(GL_QUADS);
        glVertex3f(-0.35, -3, 0.0);//top-left
        glVertex3f(-0.35, -3.35, 0.0);//bottom-left
        glVertex3f(0.05, -3.35, 0.0);//bottom-right
        glVertex3f(0.05, -3, 0.0);//top-right
    glEnd();

    //Left Wing
   glColor3ub(88,142,212);
    glBegin(GL_QUADS);
        glVertex3f(-0.33, -2.9, 0.0);//top-right
        glVertex3f(-0.8, -3.1, 0.0);//top-left
        glVertex3f(-0.8, -3.35, 0.0);//bottom-left
        glVertex3f(-0.33, -3.35, 0.0);//bottom-right
    glEnd();

    glColor3ub(140,129,143);
    glBegin(GL_QUADS);
        glVertex3f(-0.8, -3.4, 0.0);
        glVertex3f(-0.8, -2.8, 0.0);
        glVertex3f(-0.9, -2.8, 0.0);
        glVertex3f(-0.9, -3.4, 0.0);
    glEnd();
    //Right Wing

    glColor3ub(88,142,212);
    glBegin(GL_QUADS);
        glVertex3f(0.03, -2.9, 0.0);//top-left
        glVertex3f(0.03, -3.35, 0.0);//bottom-left
        glVertex3f(0.52, -3.35, 0.0);//bottom-right
        glVertex3f(0.52, -3.1, 0.0);//top-right
    glEnd();

    glColor3ub(140,129,143);
    glBegin(GL_QUADS);
        glVertex3f(0.48, -3.4, 0.0);
        glVertex3f(0.48, -2.8, 0.0);
        glVertex3f(0.58, -2.8, 0.0);
        glVertex3f(0.58, -3.4, 0.0);
    glEnd();

    //Left Thruster

    glColor3ub(221,235,253);
    glBegin(GL_QUADS);
        glVertex3f(-0.5, -3.4, 0.0);
        glVertex3f(-0.5, -3.15, 0.0);
        glVertex3f(-0.6, -3.15, 0.0);
        glVertex3f(-0.6, -3.4, 0.0);
    glEnd();

    //Right Thruster

    glColor3ub(221,235,253);
    glBegin(GL_QUADS);
        glVertex3f(0.3, -3.4, 0.0);
        glVertex3f(0.3, -3.15, 0.0);
        glVertex3f(0.2, -3.15, 0.0);
        glVertex3f(0.2, -3.4, 0.0);
    glEnd();

    //Primary Thruster
    glColor3ub(140,129,143);
    glBegin(GL_QUADS);
        glVertex3f(-0.25, -3.35, 0.0);//top-left
        glVertex3f(-0.35, -3.5, 0.0);//bottom-left
        glVertex3f(0.05, -3.5, 0.0);//bottom-right
        glVertex3f(-0.05, -3.35, 0.0);//top-right
    glEnd();


    semiCircle(1,-0.15,-2.9,0.1,0.1,255,255,255);
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
        glVertex3f(-0.245, -2.9, 0.0);//top-left
        glVertex3f(-0.245, -3.1, 0.0);//bottom-left
        glVertex3f(-0.045, -3.1, 0.0);//bottom-right
        glVertex3f(-0.045, -2.9, 0.0);//top-right
    glEnd();
    semiCircle(-1,-0.15,-3.1,0.1,0.1,255,255,255);

    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex3f(-0.245, -2.95, 0.0);
      glVertex3f(-0.045, -2.95, 0.0);//top-right
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex3f(-0.245, -3.1, 0.0);
    glVertex3f(-0.045, -3.1, 0.0);//top-right
    glEnd();

    float G=rand()%167;
    float B=rand()%95;

    if(G<116){
        G=116;
    }

    glColor3ub(255,G,B);
    glBegin(GL_POLYGON);
    glVertex3f(-0.3, -3.5, 0.0);//bottom-left
    glVertex3f(-0.15, -3.7, 0.0);
    glVertex3f(0.0, -3.5, 0.0);//bottom-right
    glEnd();


/*
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
    */
	glPopMatrix();
	glFlush();
    //Gun



}

void AlienShip(float rx,float ry){
    glPushMatrix();
    glTranslatef(alienship_x,alienship_y,0);
    //Head
    semiCircle(1,0,0.4,0.15,0.15,0,231,240);

    glColor3ub(62,61,66);
    glBegin(GL_QUADS);
        glVertex3f(-0.3, 0.0, 0.0);
        glVertex3f(-0.2, 0.4, 0.0);
        glVertex3f(0.2, 0.4, 0.0);
        glVertex3f(0.3, 0.0, 0.0);
    glEnd();

    //Left post
    glColor3ub(0,231,240);
    glBegin(GL_QUADS);
        glVertex3f(-0.352, 0.0, 0.0);
        glVertex3f(-0.352, 0.4, 0.0);
        glVertex3f(-0.452, 0.4, 0.0);
        glVertex3f(-0.452, 0.0, 0.0);
    glEnd();
    glColor3ub(62,61,66);
    glBegin(GL_QUADS);
        glVertex3f(-0.5, 0.0, 0.0);
        glVertex3f(-0.5, 0.3, 0.0);
        glVertex3f(-0.3, 0.3, 0.0);
        glVertex3f(-0.3, 0.0, 0.0);
    glEnd();
    //Right post

    glColor3ub(0,231,240);
    glBegin(GL_QUADS);
        glVertex3f(0.452, 0.0, 0.0);
        glVertex3f(0.452, 0.4, 0.0);
        glVertex3f(0.352, 0.4, 0.0);
        glVertex3f(0.352, 0.0, 0.0);
    glEnd();
    glColor3ub(62,61,66);
        glBegin(GL_QUADS);
        glVertex3f(0.3, 0.0, 0.0);
        glVertex3f(0.3, 0.3, 0.0);
        glVertex3f(0.5, 0.3, 0.0);
        glVertex3f(0.5, 0.0, 0.0);
    glEnd();

        //Legs
    /*glColor3ub(255,255,255);
    glBegin(GL_QUADS);
        glVertex3f(-0.3, -0.3, 0.0);
        glVertex3f(-0.3, 0.0, 0.0);
        glVertex3f(-0.1, 0.0, 0.0);
        glVertex3f(-0.1, -0.3, 0.0);
    glEnd();*/
    semiCircle(-1,0,0,rx,ry,255,98,67);
    semiCircle(1,0,0,rx,ry,171,35,0);
    glPopMatrix();

    if(alienship_x<=5 && flag4==0){
        alienship_x=alienship_x+stride4;
    }
    else{
        flag4=1;
        //timer4++;

    }
    if(alienship_x>=-5 && flag4==1){
        alienship_x-=stride4;
    }
    else{
        flag4=0;
        //timer4++;
    }

     glutPostRedisplay();




}



void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //semiCircle(-1,0,4,0.6,0.2,255,255,255);

    if(hit_flag_4==0){
    AlienShip(0.6,0.2);
    }

  if (py<=-6 || ry<=-6 ||qy<=-6){
       drawText("GAME OVER:", -1,2);
       alienship_y=7;
       hit_flag_1=1;
       hit_flag_2=1;
       hit_flag_3=1;
       stop=1;
    }

    glColor3f(1,1,1);
    drawText("Score:", -5,4);
    itoa (score, buffer, 10);
    drawTextNum(buffer, 2, -4,4);

    drawText("High Score:",-5,4.4);
        if(score>highscore)
        {
            highscore = score;
            itoa(highscore,buffer,10);
            drawTextNum(buffer,2,-3.3,4.4);
        }
        else
        {
            itoa(highscore,buffer,10);
            drawTextNum(buffer,2,-3.3,4.4);
        }

    if(hit_flag_1==1 && hit_flag_2==1 && hit_flag_3==1  && hit_flag_4==1 &&stop==0){

            tx=0;
            btx=0;
            ty=0;
            px=-3;
            py=0;
            qy=0;
            ry=0;
            cx=-1;
            ax=1;
            //by=0;
            timer1=0;
            timer2=0;
            timer3=0;
            flag1=0;
            flag2=0;
            flag3=0;
            hit_flag_1=0;
            hit_flag_2=0;
            hit_flag_3=0;
            bulletFlag=0;
            hit_flag_4=0;
            alienship_x=-4;
            alienship_y=3;


    }

    //cout<<Alien_cen[0]<<endl;
    //float Alien_x_1=(bodyx1_1+bodyx2_1+bodyx3_1+bodyx4_1)/4;
    float Alien_y_1=(bodyy1_1+py+bodyy2_1+py+bodyy3_1+py+bodyy4_1+py)/4;
    float Alien_y_2=(bodyy1_1+qy+bodyy2_1+qy+bodyy3_1+qy+bodyy4_1+qy)/4;
    float Alien_y_3=(bodyy1_1+ry+bodyy2_1+ry+bodyy3_1+ry+bodyy4_1+ry)/4;

    float bull_x=(bullet_x1+btx+bullet_x2+btx+bullet_x3+btx+bullet_x4+btx)/4;
    float bull_y=(bullet_y4+by);

    //float bull_x=(bullet_x1+btx+bullet_x2+btx+bullet_x3+btx+bullet_x4+btx)/4;
    //float bull_y=(bullet_y1+by+bullet_y2+by+bullet_y3+by+bullet_y4+by)/4;




    if(abs(alienship_y-bull_y)<=0.2 && hit_flag_4==0 && (bullet_x1+btx)>=(-0.3+alienship_x) && (bullet_x4+btx)<=(0.3+alienship_x)){

            stride1=0.001;
            stride2=0.0015;
            stride3=0.0019;
            score+=5;
            hit_flag_4=1;
           // cout<<score;
            by=10;
            PlaySound("explosion.wav",NULL,SND_FILENAME|SND_ASYNC);

            //exit(0);


    }


    if(abs(Alien_y_1-bull_y)<=0.2 && hit_flag_1==0 && (bullet_x1+btx)>=(left_hand_x_1+px) && (bullet_x4+btx)<=(right_hand_x_1+px)){

            score+=1;
            hit_flag_1=1;
            cout<<score;
            by=10;
            PlaySound("explosion.wav",NULL,SND_FILENAME|SND_ASYNC);
            //exit(0);


    }
    if(abs(Alien_y_2-bull_y)<=0.2&& hit_flag_2==0 &&(bullet_x1+btx)>=(left_hand_x_1+cx) && (bullet_x4+btx)<=(right_hand_x_1+cx)){

            score+=1;
            hit_flag_2=1;
            cout<<score;
            by=10;
            PlaySound("explosion.wav",NULL,SND_FILENAME|SND_ASYNC);
            //exit(0);

    }

   if(abs(Alien_y_3-bull_y)<=0.2 && hit_flag_3==0 && (bullet_x1+btx)>=(left_hand_x_1+ax) && (bullet_x4+btx)<=(right_hand_x_1+ax)){

            score+=1;
            hit_flag_3=1;
            cout<<score;
            by=10;
            PlaySound("explosion.wav",NULL,SND_FILENAME|SND_ASYNC);
            //exit(0);

    }



    //float distance=dist(Alien_cen[0],bull_cen[0],Alien_cen[1],bull_cen[1]);




    if (timer1>=4){
        timer1=0;
        py-=0.001;
    }
    if (timer2>=4){
        timer2=0;
        qy-=0.001;
    }
    if (timer3>=4){
        timer3=0;
        ry-=0.001;
    }





    if (hit_flag_1==0){
     px=DrawAlien1(px,stride1,py);
    }

    if (hit_flag_2==0){
     cx=DrawAlien2(cx,stride2,qy);
    }

    if (hit_flag_3==0){
    ax=DrawAlien3(ax,stride3,ry);
    }

    bull.drawBullet(btx);
    background();
    DrawSpaceship();


    //myEllipse(0,0,4,2);
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
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
