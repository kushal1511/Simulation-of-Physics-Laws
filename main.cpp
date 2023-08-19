#include <windows.h>
#include<string.h>
#include<stdarg.h>
#include<stdio.h>
#include <GL/glut.h>
static double x=0.0,arm=0.0;
static bool info=false;
static double x1=0.0;
static double x2=0.0;
static double a=0.0;
static bool flow=false;

void *font;
void *currentfont;

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,1.0,1.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

//Producing Electric Current
void electroMagnet()
{
	glClearColor(0.2,0.2,0.2,0.0);
	if(x1>=1.0 && x1<=1.8){
	glClearColor(0.6,0.8,0.8,0.0);
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-13.0f);
   	//glRotated(x1,1.0,0.0,0.0);

	glPushMatrix();
	glRotated(10,1.0,0.0,0.0);

	/* Draw the Magnet*/
	glPushMatrix();
	glScaled(2.0,0.3,0.5);
	glTranslatef(x1,0.0,0.0);
	glColor3f(1.0,.05,.5);
	glutSolidCube(1.0);
	glPopMatrix();

	//Light Bulb
	glPushMatrix();
	glTranslatef(3.0,2.0,0.0);
	glScaled(1.0,1.4,1.0);
	glColor3f(0.3,0.3,0.3);
	if(x1>=1.0 && x1<=1.8){
	glColor3f(1.0,1.0,0.0);

	}
	glutSolidSphere(.3,50,50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.0,1.5,0.0);
	glScaled(0.4,1.4,0.4);
	glutSolidSphere(.3,50,50);
	glPopMatrix();

//bulb Stand
	glPushMatrix();
	glTranslatef(3.0,1.2,0.0);
	glScaled(2.0,0.3,0.5);
	glColor3f(1.0,1.05,1.5);
	glutSolidCube(0.5);
	glPopMatrix();

	//Coil
	glPushMatrix();
	glTranslatef(3.0,0.0,0.0);
	glRotatef(90,0.0,1.0,0.0);
	glScaled(1,1,5);
	glutWireTorus(.1,.5,50,10);
	glPopMatrix();

	//Wire To Bulb
	glPushMatrix();
	glTranslatef(3.0,0.8,0.0);
	glScaled(0.8,0.8,0.2);
	glutWireCube(0.8);
	glPopMatrix();

	glFlush();
    glutSwapBuffers();
}


//DC Generation Coding
void pipe()
{
	glPushMatrix();
	glRotatef(90,1,0,0);
	glScaled(0.025,0.025,2);
	glutSolidTorus(0.5,1,30,30);
	glPopMatrix();
}

void armature()
{
//horizontal pipe top
	glPushMatrix();
	glTranslatef(0,1,0);
	glRotatef(90,0,0,1);
	pipe();
	glPopMatrix();

	//horizontal pipe bottom
	glPushMatrix();
	glTranslatef(0,-1,0);
	glRotatef(90,0,0,1);
	pipe();
	glPopMatrix();

	//vertical pipe right
	glPushMatrix();
	glTranslatef(1,0,0);
	pipe();
	glPopMatrix();

	//vertical small pipe bottom
	glPushMatrix();
	glTranslatef(-1,-0.62,0);
	glScaled(1,0.38,1);
	pipe();
	glPopMatrix();

	//vertical small pipe  top
	glPushMatrix();
	glTranslatef(-1,0.62,0);
	glScaled(1,0.38,1);
	pipe();
	glPopMatrix();

	//horizontal small pipe top
	glPushMatrix();
	glTranslatef(-1.5,0.28,0);
	glRotatef(90,0,0,1);
	glScaled(1,0.5,1);
	pipe();
	glPopMatrix();

	//horizontal small pipe bottom
	glPushMatrix();
	glTranslatef(-1.5,-0.28,0);
	glRotatef(90,0,0,1);
	glScaled(1,0.5,1);
	pipe();
	glPopMatrix();
}


void magnet(){
	glPushMatrix();
	glTranslatef(0,1.5,0);
	glScaled(2.2,0.5,0.5);
	glColor3f(1,0,0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,1);
	glTranslatef(0,-1.5,0);
	glScaled(2.2,0.5,0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(1.35,0.75,0);
	glScaled(0.5,1.4,0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(1.35,-0.7,0);
	glScaled(0.5,1.5,0.5);
	glColor3f(0,0,1);
	glutSolidCube(1);
	glPopMatrix();

	//Back magnet side
	glPushMatrix();
	glTranslatef(1.33,1.3,0);
	glScaled(1.1,1.1,0.5);
	glColor3f(1,0,0);
	glutSolidSphere(0.45,30,30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.33,-1.3,0);
	glScaled(1.1,1.1,0.5);
	glColor3f(0,0,1);
	glutSolidSphere(0.45,30,30);
	glPopMatrix();

	//	front magnet side
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(-1.3,1.2,0);
	glScaled(0.4,1.1,0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.3,-1.2,0);
	glScaled(0.4,1.1,0.5);
	glColor3f(0,0,1);
	glutSolidCube(1);
	glPopMatrix();
}

void field(){
	glPushMatrix();
	glBegin(GL_LINES);

	if(x<=3){
	glVertex2f(0,1);
	}else if(x>=3 && x<=6)
	glVertex2f(0,4-x);

	if(x<=3){
	glVertex2f(0,1-x);
	}else if(x>=3 && x<=6)
	glVertex2f(0,-2);

	glEnd();

	// Interval between transmission
	if(x>=7){
	x=0;
	}

	glPopMatrix();
}

// a code for Commutator
void comm()
{
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(-1.9,0,0);
	glScaled(0.5,0.5,3);
	glutSolidCube(0.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(-2.14,0,0);
	glScaled(0.01,1,1);
	glColor3f(1,1,0);
	glutSolidSphere(0.5,30,30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.9,0,0);
	glRotatef(90,0,0,1);
	glScaled(15,0.25,15);
	pipe();
	glPopMatrix();

}

//a code for Bulb
void bulb(){

	glPushMatrix();
	if(x==6.1){
	glColor3f(0.01,0.01,0.01);
	}else
	glColor3f(1,1,1);

	glTranslatef(-3.5,0.55,0);
//	glScaled(0.5,0.5,3);
	//glutSolidCube(0.2);

	glPushMatrix();
	glRotatef(90,0,1,0);
	glScaled(0.1,0.1,0.2);
	//glColor3f(0.5,0.5,0.5);
	glutSolidTorus(0.5,1,30,30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.3,0,0);
	glScaled(0.9,0.8,0.8);
	//glColor3f(1,1,1);
	glutSolidSphere(0.3,30,30);
	glPopMatrix();

	glPopMatrix();
}

void leg(float x1,float y1,float z1)
	{
	glPushMatrix();
	glColor3f(0.1,0.1,0.1);
	glTranslatef(x1,y1,z1);
	glScaled(0.3,2,0.3);
	glutSolidCube(0.5);
	glPopMatrix();
	}

void table()
{
	glPushMatrix();
	glColor3f(0.1,0.1,0.1);
	glTranslatef(0,-1.95,0);
	glScaled(9,0.5,5);
	glutSolidCube(0.5);
	glPopMatrix();

	//front leg
	leg(-2,-2.55,1);

	//front leg
	leg(1.5,-2.55,1);

	//left leg
	leg(-2.1,-2.55,-1);

	//back leg
	leg(1,-2.55,-1);

	}
	// Start Drawing

void dcmotor()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   if(x==6.1){
   glClearColor(0,0,0,0);
   }else
   glClearColor(0.8,0.9,0.5,0);

   glLoadIdentity();
    glTranslatef(0.0f,0.0f,-13.0f);
	glRotatef(40,0.0f,1.0f,0.0f);

	table();
	magnet();

	bulb();

	// Commutator
	comm();

	//Wire
	glPushMatrix();
	glRotatef(-20,0,0,1);
	glPushMatrix();
	glTranslatef(-2.5,-0.6,0);
	glScaled(0.2,0.2,0.2);
	glRotatef(90,1,0,0);
	glColor3f(1.0,0.0,0);
	glutSolidTorus(0.2,4,30,30);
	glPopMatrix();
	glPopMatrix();

//Rotate the armature
 	for(float i=0;i<=1.7;i+=0.05){
	glPushMatrix();
	glTranslatef(-0.8+i,0.4,-0.25);
	field();
	glPopMatrix();
	}

	for(float j=0;j<=1.7;j+=0.05){
	glPushMatrix();
	glTranslatef(-0.8+j,0.4,0.2);
	field();
	glPopMatrix();
	}

	glPushMatrix();
	//glScaled(1.1,2.0,0.1);
	glTranslatef(0.0,0.0,2.0);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0,0,0);
	drawstring(-2.2,1.2,-1.0,"N");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0,0,0);
	drawstring(-2.2,-1.2,-1.0,"S");
	glPopMatrix();

	glRotatef(arm,1.0f,0.0f,0.0f);

	glColor3f(1,1,0);

	// Armeture
	armature();

	//caps

	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(-2.14,0,0);
	glScaled(0.01,1,1);
	glColor3f(1,1,0);
	glutSolidSphere(0.5,30,30);
	glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void start()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-13.0f);

	glPushMatrix();
	glTranslatef(0.0,0.0,2.0);

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	drawstring(-3.2,2.2,-1.0,"WELCOME TO ELECTROMAGNETIC INDUCTION EXPERIMENT");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	drawstring(-2.2,1.2,-1.0,"Press '1' to Start First Experiment ");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	drawstring(-2.2,0.0,-1.0,"Press '2' to Start Second Experiment ");

	glColor3f(0,0,0);
	drawstring(-2.2,-2.2,-1.0,"Press 'q/Q to Quit ");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

    glFlush();
    glutSwapBuffers();
}

void s()
{
	start();
}

void o()
{
	x+=0.1;
	arm+=5;
	dcmotor();
 }

void d()
{
	x=6.1;
	dcmotor();
}

void e()
{
electroMagnet();
}



void doInit()
{
  	/* Background and foreground color */
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(.0,1.0,1.0);
    glViewport(0,0,640,480);

	/* Select the projection matrix and reset it then
     setup our view perspective */

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0f,(GLfloat)640/(GLfloat)480,0.1f,200.0f);

    /* Select the modelview matrix, which we alter with rotatef() */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearDepth(2.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-13.0f);

	glPushMatrix();
	glTranslatef(0.0,0.0,2.0);

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	drawstring(-3.2,2.2,-1.0,"WELCOME TO ELECTROMAGNETIC INDUCTION EXPERIMENT");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	drawstring(-2.2,1.2,-1.0,"Press '1' to Start First Experiment ");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	drawstring(-2.2,0.0,-1.0,"Press '2' to Start Second Experiment ");

	glColor3f(0,0,0);
	drawstring(-2.2,-2.2,-1.0,"Press 'q/Q to Quit ");
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);

    glFlush();
    glutSwapBuffers();

    start();

	GLfloat mat_ambient[]={0.0f,1.0f,2.0f,1.0f};
	GLfloat mat_diffuse[]={0.0f,1.5f,.5f,1.0f};
	GLfloat mat_specular[]={5.0f,1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={50.0f};
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

	GLfloat lightIntensity[]={3.7f,0.7f,0.7f,1.0f};
	GLfloat light_position[]={0.0f,0.0f,4.1f,0.0f};

	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);

	GLfloat lightIntensity1[]={3.7f,0.7f,0.7f,1.0f};
	GLfloat light_position1[]={3.0f,0.0f,0.0f,5.0f};

	glLightfv(GL_LIGHT1,GL_POSITION,light_position1);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,lightIntensity1);
	glEnable(GL_COLOR_MATERIAL);

	glFlush();
	glutSwapBuffers();
}

void menu(int id)
{
	switch(id)
	{
	case 1:glutIdleFunc(e);
		break;
	case 2:glutIdleFunc(d);
		break;
	case 3:exit(0);
		break;
	}
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void mykey(unsigned char key,int x,int y)
{
	if(key=='1')
	{
		glutIdleFunc(e);
	}

	 if(key=='2')
	{
		glutIdleFunc(d);
	}

		if(key=='s' ||key=='S')
	{
	glutIdleFunc(s);
	}

	if(key=='o'||key=='O')
	{
		glutIdleFunc(o);
	}

	if(key=='p'||key=='P')
	{
		glutIdleFunc(d);
	}
	if(key=='q'||key=='Q')
	{
		exit(0);
	}

	if(key=='F' || key=='f')
	{
		flow=!flow;
	}
}

static void specialKey(int key,int x,int y){

	if(key==GLUT_KEY_RIGHT){

			x1+=0.1;
		electroMagnet();
	}
    if(key==GLUT_KEY_LEFT){

			x1-=0.1;
		electroMagnet();
	}
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1000,480);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Electromagnetic Induction");
    glutDisplayFunc(display);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glutKeyboardFunc(mykey);
	glutSpecialFunc(specialKey);
	glutCreateMenu(menu);
	glutAddMenuEntry("Press -> '1' for First Experiment",1);
	glutAddMenuEntry("Press -> '2' for Second Experiment",2);
	glutAddMenuEntry("Press -> 'q' Quit",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	doInit();
    glutMainLoop();
	return 0;
}
