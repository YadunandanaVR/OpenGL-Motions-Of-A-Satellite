#include<windows.h>
#include<glut.h>
#include <ctime>
GLfloat d = 0, retrograde = 0, angle = 0, view = 0, f = 0;
// 4 Flag variables for angle and keyboard controls
static int menuRetrograde, menuAngle, menuView, menuArt;
//Variables used for menu
static int menu_id;
static int submenu_id;
static int value = 0;

GLfloat a[100] = { 0.55, 0.54, 0.97, 27, 0.64, 0.14, 1.0, 0.48,
                 0.73, 0.32, 0.24, 0.1, 0.37, 0.94, 0.1, 0.4, 0.74, 0.29, 0.91,
                 0.63, 0.05, 0.1, 0.43, 0.02, 0.0, 0.67, 0.79, 0.43, 0.49, 0.58,
                 0.41, 0.76, 0.53, 0.77, 0.44, 0.97, 0.93, 0.08, 0.88, 0.13, 0.95,
                 0.44, 0.23, 0.86, 0.83, 0.37, 0.96, 0.4, 0.06, 0.67, 0.89, 0.76, 1.0,
                 0.01, 0.1, 0.6, 0.66, 0.49, 0.93, 0.57, 0.13, 0.79, 0.8, 0.88, 0.91, 0.15,
                 0.38, 0.59, 0.99, 0.13, 0.23, 0.52, 0.68, 0.99, 0.71, 0.53, 0.86, 0.26, 0.39,
                 0.65, 0.23, 0.53, 0.66, 0.94, 0.86, 0.52, 0.86, 0.64, 0.79, 0.91, 0.78, 0.4,
                 0.04, 0.24, 0.8, 0.87, 0.64
};

void spin()
{
    d = d + 0.15;
    if (d > 360)
        d = 0;
    if (f > 360)
        f = 0;
    glutPostRedisplay();
}

//To resize without changing shape
void reshape(int w, int h)
{
    GLdouble aspect = (GLdouble)w / (GLdouble)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, w, h);
}

//Randomly Draws points to create stars
void background()
{
    glPointSize(2);
    for (int i = 0; i < 100; i++)
    {
        if (a[i] > 0.15 && a[i - 1] > 0.15 && a[i + 1] > 0.3)
        {
            glBegin(GL_POINTS);
            glVertex3f(a[i], a[i + 1], -a[i - 1]);
            glVertex3f(2 * a[i], 2 * a[i + 1], -2 * a[i - 1]);
            glVertex3f(a[i], 2 * a[i + 1], -a[i - 1]);
            glVertex3f(2 * a[i], a[i + 1], -a[i - 1]);
            glVertex3f(a[i], -a[i + 1], -a[i - 1]);
            glVertex3f(2 * a[i], -a[i + 1], -a[i - 1]);
            glVertex3f(a[i], -2 * a[i + 1], -a[i - 1]);
            glVertex3f(-a[i], a[i + 1], -a[i - 1]);
            glVertex3f(-2 * a[i], 2 * a[i + 1], -2 * a[i - 1]);
            glVertex3f(-2 * a[i], a[i + 1], -a[i - 1]);
            glVertex3f(-a[i], -a[i + 1], -a[i - 1]);
            glVertex3f(-2 * a[i], -a[i + 1], -a[i - 1]);
            glVertex3f(-a[i], -2 * a[i + 1], -a[i - 1]);
            glEnd();
        }
    }
    glFlush();
}

void drawArtSat(){

    GLfloat Y[] = { 1,0.4,0 };

    //To draw dish
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Y);
    glPushMatrix();
    glScalef(1.8, 0.45, 1.9);
    glutSolidSphere(0.5, 30, 30);
    glPopMatrix();
    glPopAttrib();

    //Main body
    glPushMatrix();
    glTranslatef(0, -0.8, 0);
    glScalef(0.7, 1.8, 0.6);
    glutSolidCube(1);
    glPopMatrix();

    //Right Wing
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT, GL_AMBIENT, Brown);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Brown);
    glPushMatrix();
    glTranslatef(-1.25, -0.7, 0);
    glScalef(2, 0.0, 1);
    glutSolidCube(1);
    glPopMatrix();
    glPopAttrib();

    //left wing
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT, GL_AMBIENT, Brown);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Brown);
    glPushMatrix();
    glTranslatef(1.25, -0.7, 0);
    glScalef(2, 0.0, 1);
    glutSolidCube(1);
    glPopMatrix();
    glPopAttrib();

    //Antina
    glPushMatrix();
    glTranslatef(0, 0.1, 0);
    glScalef(0.1, 1, 0.1);
    glutSolidCube(1);
    glPopMatrix();
}
//Front view of the scene
void frontview()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Light Source
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat AmbientLight[] = { 0.1, 0.1, 0.1, 1.0 };  //R,G,B,Alpha
    GLfloat DiffuseLight[] = { 0.5f, 0.5f, 0.5f, 0.1f }; //R,G,B,Alpha
    GLfloat LightPosition[] = { -0.9,0.2, 0.9, 0.1 }; // Set the light position
    glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

    //Colors
    GLfloat Black[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat Cyan[] = { 0.0, 1.0, 1.0, 1.0 };
    GLfloat White[] = { 1, 1, 1, 0.5 };
    GLfloat Brown[] = { 0.8, .4, 0.2, 0.2 };

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushMatrix();
    //Setting Material Properties
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Cyan);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Cyan);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100.0);
    glRotatef(d, 0, 1, 0);
    glutSolidSphere(0.5, 32, 32);
    glPopMatrix();
    glPopAttrib();

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushMatrix();
    //Setting Material Properties
    glRotatef(f, 0, 1, 0);
    glRotatef(125, 1, 0, 0.5);
    glScalef(0.05, 0.05, 0.05);
    glTranslatef(4, -15, 5);
    drawArtSat();
    glPopMatrix();
    glPopAttrib();

    if (retrograde == 0)
    {
        glPushMatrix();

        glMaterialfv(GL_FRONT, GL_AMBIENT, Brown);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Brown);
        glMaterialf(GL_FRONT, GL_SHININESS, 0.0);
        //Angled Motion
        if (angle == 0)
            glRotatef(d, 0, 1, 0.1);
        else //Normal Motion
            glRotatef(d, 0.2, 1, 0.3);
        glTranslatef(0.9, 0, 0.1);
        glScalef(0.1, 0.1, 0.1);
        glutSolidSphere(0.5, 32, 32);
        glPopMatrix();
    }
    if (retrograde == 1)  //Retrograde Motion
    {
        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, Brown);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Brown);
        glMaterialf(GL_FRONT, GL_SHININESS, 0.0);
        if (angle == 0)
            glRotatef(-d, 0, 1, 0);
        else
            glRotatef(-d, 0.2, 1, 0.3);
        glTranslatef(0.9, 0, 0.1);
        glScalef(0.1, 0.1, 0.1);
        glutSolidSphere(0.5, 32, 32);
        glPopMatrix();
    }

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, White);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, White);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 00.0);
    background();
    glPopMatrix();
    glPopAttrib();
    glutSwapBuffers();
}

void topview()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Light Source
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat AmbientLight[] = { 0.1, 0.1, 0.1, 1.0 };  //R,G,B,Alpha
    GLfloat DiffuseLight[] = { 0.5f, 0.5f, 0.5f, 0.1f }; //R,G,B,Alpha
    GLfloat LightPosition[] = { -0.9, 0.9,0.2, 0.1 }; // Set the light position
    glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

    //Colors
    GLfloat Black[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat Cyan[] = { 0.0, 1.0, 1.0, 1.0 };
    GLfloat White[] = { 1, 1, 1, 0.5 };
    GLfloat Brown[] = { 0.8, .4, 0.2, 0.2 };

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushMatrix();
    //Setting Material Properties
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Cyan);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Cyan);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100.0);
    glRotatef(d, 0, 0, 1);
    glutSolidSphere(0.5, 32, 32);
    glPopMatrix();
    glPopAttrib();

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushMatrix();
    glRotatef(f, 0, 0, 1);
    glRotatef(125, 1, 0.2, 0);
    glScalef(0.05, 0.05, 0.05);
    glTranslatef(4, 5, -15);
    drawArtSat();
    glPopMatrix();
    glPopAttrib();

    if (retrograde == 0)
    {
        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, Brown);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Brown);
        glMaterialf(GL_FRONT, GL_SHININESS, 0.0);
        //Angled Motion
        if (angle == 0)
            glRotatef(d, 0, 0.1, 1);
        else //Normal Motion
            glRotatef(d, 0.2, 0.3, 1);
        glTranslatef(0.9, 0.1, 0);
        glScalef(0.1, 0.1, 0.1);
        glutSolidSphere(0.5, 32, 32);
        glPopMatrix();
    }
    if (retrograde == 1)  //Retrograde Motion
    {
        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, Brown);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Brown);
        glMaterialf(GL_FRONT, GL_SHININESS, 0.0);
        if (angle == 0)
            glRotatef(-d, 0, 0, 1);
        else
            glRotatef(-d, 0.2, 0.3, 1);
        glTranslatef(0.9, 0.1, 0);
        glScalef(0.1, 0.1, 0.1);
        glutSolidSphere(0.5, 32, 32);
        glPopMatrix();
    }

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, White);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, White);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 00.0);
    background();
    glPopMatrix();
    glPopAttrib();
    glutSwapBuffers();
}

void sideview()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Light Source
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat AmbientLight[] = { 0.1, 0.1, 0.1, 1.0 };  //R,G,B,Alpha
    GLfloat DiffuseLight[] = { 0.5f, 0.5f, 0.5f, 0.1f }; //R,G,B,Alpha
    GLfloat LightPosition[] = { 0.9,-0.9,0.2, 0.1 }; // Set the light position
    glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

    //Colors
    GLfloat Black[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat Cyan[] = { 0.0, 1.0, 1.0, 1.0 };
    GLfloat White[] = { 1, 1, 1, 0.5 };
    GLfloat Brown[] = { 0.8, .4, 0.2, 0.2 };
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Cyan);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Cyan);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100.0);
    glRotatef(d, 1, 0, 0);
    glutSolidSphere(0.5, 32, 32);
    glPopMatrix();
    glPopAttrib();

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushMatrix();
    glRotatef(f, 1, 0, 0);
    glRotatef(125, 0.2, 1, 0);
    glScalef(0.05, 0.05, 0.05);
    glTranslatef(5, 4, -15);
    drawArtSat();
    glPopMatrix();
    glPopAttrib();

    if (retrograde == 0)
    {
        glPushMatrix();

        glMaterialfv(GL_FRONT, GL_AMBIENT, Brown);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Brown);
        glMaterialf(GL_FRONT, GL_SHININESS, 0.0);
        //Angled Motion
        if (angle == 0)
            glRotatef(d, 1, 0, 0.1);
        else //Normal Motion
            glRotatef(d, 1, 0.2, 0.3);
        glTranslatef(0.1, 0.9, 0);
        glScalef(0.1, 0.1, 0.1);
        glutSolidSphere(0.5, 32, 32);
        glPopMatrix();
    }
    if (retrograde == 1)  //Retrograde Motion
    {
        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, Brown);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Brown);
        glMaterialf(GL_FRONT, GL_SHININESS, 0.0);
        if (angle == 0)
            glRotatef(-d, 1, 0, 0);
        else
            glRotatef(-d, 1, 0.2, 0.3);
        glTranslatef(0.1, 0.9, 0);
        glScalef(0.1, 0.1, 0.1);
        glutSolidSphere(0.5, 32, 32);
        glPopMatrix();
    }

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, White);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, White);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 00.0);
    background();
    glPopMatrix();
    glPopAttrib();
    glutSwapBuffers();
}

void Key(unsigned char ch, int x, int y)
{
    if (ch == 'r') //For Retrograde
        retrograde = 1;
    if (ch == 'n')  //For Normal Motion
        retrograde = 0;
    if (ch == 'a') //For Angled Motion
        angle = 1;
    if (ch == 's') //For Non Angular Motion
        angle = 0;
    if (ch == '1') //For front view
        view = 0;
    if (ch == '2') //For top View
        view = 1;
    if (ch == '3') //For side view
        view = 2;
    //Controlling Artificial Satellite
    if (ch == '+')
        f += 5;
    if (ch == '-')
        f -= 5;
    glutPostRedisplay();
}
void display()
{
    if (value == 1)
        retrograde = 1;
    else if (value == 2)
        retrograde = 0;
    else if (value == 3)
        view = 0;
    else if (value == 4)
        view = 1;
    else if (value == 5)
        view = 2;
    else if (value == 6)
        angle = 1;
    else if (value == 7)
        angle = 0;
    else if (value == 8)
    {
        f += 5;
        value = 0;
    }
    else if (value == 9)
    {
        f -= 5;
        value = 0;
    }

    if (view == 0)
        frontview();
    else if (view == 1)
        topview();
    else
        sideview();
    glutPostRedisplay();
}

void menu(int num)
{
    if (num == 0)
        exit(0);
    else
        value = num;
    glutPostRedisplay();
}

void createMenu(void) {
    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Front View (Keyboard Shortcut->1)", 3);
    glutAddMenuEntry("Top View (Keyboard Shortcut->2)", 4);
    glutAddMenuEntry("Side View (Keyboard Shortcut->3)", 5);
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Retrograde Motion (Keyboard Shortcut->r)", 1);
    glutAddMenuEntry("Non Retrograde Motion (Keyboard Shortcut->n)", 2);
    glutAddSubMenu("Views", submenu_id);
    glutAddMenuEntry("Angular Motion (Keyboard Shortcut->a)", 6);
    glutAddMenuEntry("Non Angular Motion (Keyboard Shortcut->s)", 7);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Move Artificial Satellite Forward (Keyboard Shortcut->+)", 8);
    glutAddMenuEntry("Move Artificial Satellite Backward (Keyboard Shortcut->-)", 9);
    glutAttachMenu(GLUT_LEFT_BUTTON);
}

int main(int C, char* V[])
{
    glutInit(&C, V);
    glutInitWindowSize(1366, 768);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Simulation Of Satellite Motions Around a Planet");
    glutDisplayFunc(display);
    glutIdleFunc(spin);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(Key);
    createMenu();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
