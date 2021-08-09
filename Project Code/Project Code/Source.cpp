#include<windows.h>
#include<glut.h>

GLfloat d = 0, m = 0, retrograde = 0, angle = 0, view = 0, f = 0;

//Variables used for menu
static int menu_id;
static int submenu_id;
static int value = 0;

//Colors
GLfloat Black[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat Cyan[] = { 0.0, 1.0, 1.0, 1.0 };
GLfloat White[] = { 1, 1, 1, 0.5 };
GLfloat Brown[] = { 0.8, 0.4, 0.2, 0.2 };
GLfloat Gray[] = { 0.5, 0.5, 0.5, 0 };

GLfloat a[100] = { 0.55, 0.54, 0.97, 0.27, 0.64, 0.14, 1.00, 0.48, 0.73, 0.32,
                   0.24, 0.10, 0.37, 0.94, 0.10, 0.40, 0.74, 0.29, 0.91, 0.63,
                   0.05, 0.10, 0.43, 0.02, 0.00, 0.67, 0.79, 0.43, 0.49, 0.58,
                   0.41, 0.76, 0.53, 0.77, 0.44, 0.97, 0.93, 0.08, 0.88, 0.13,
                   0.95, 0.44, 0.23, 0.86, 0.83, 0.37, 0.96, 0.40, 0.06, 0.67,
                   0.89, 0.76, 1.00, 0.01, 0.10, 0.60, 0.66, 0.49, 0.93, 0.57,
                   0.13, 0.79, 0.80, 0.88, 0.91, 0.15, 0.38, 0.59, 0.99, 0.13,
                   0.23, 0.52, 0.68, 0.99, 0.71, 0.53, 0.86, 0.26, 0.39, 0.65,
                   0.23, 0.53, 0.66, 0.94, 0.86, 0.52, 0.86, 0.64, 0.79, 0.91,
                   0.78, 0.40, 0.04, 0.24, 0.80, 0.87, 0.64 };

void spin() {

    d += 0.15;
    m += 0.015;

    if (d > 360)
        d = 0;
    if (m > 360)
        m = 0;
    if (f > 360)
        f = 0;

    glutPostRedisplay();
}

void drawText(GLdouble x, GLdouble y, GLdouble  z, GLdouble scale, const char* s) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(scale, scale, scale);
    for (int i = 0; i < strlen(s); i++)
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, s[i]);
    glPopMatrix();
}

void introPage() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1, 0, 0);
    drawText(-1.5, 0.8, 0, 0.001, "DEPARTMENT OF COMPUTER SCIENCE");
    drawText(-0.8, 0.6, 0, 0.001, "AND ENGINEERING");

    glColor3f(0, 0, 1);
    drawText(-0.6, 0.4, 0, 0.0005, "AN OPENGL MINI PROJECT");

    glColor3f(0, 1, 0);
    drawText(-1.4, 0.15, 0, 0.0005, "Simuation Of Motions Of A Satellite Around A Planet");

    glColor3f(1, 1, 0);
    drawText(0.8, -0.2, 0, 0.0002, "SUBMITTED BY :-");

    glColor3f(1, 0.5, 0);
    drawText(0.9, -0.25, 0, 0.00029, "YADUNANDANA V R");

    glColor3f(1, 1, 0);
    drawText(0.94, -0.3, 0, 0.0002, "(1JB18CS178)");

    glColor3f(1, 0.5, 0);
    drawText(0.9, -0.4, 0, 0.00029, "SYED MOHAMMED SHAZEB");

    glColor3f(1, 1, 0);
    drawText(0.94, -0.45, 0, 0.0002, "(1JB18CS162)");

    glColor3f(1, 1, 0);
    drawText(-1.2, -0.2, 0, 0.0002, "UNDER THE GUIDENCE OF :-");

    glColor3f(1, 0.5, 0);
    drawText(-0.9, -0.25, 0, 0.00029, "MRS MANASA B S");

    glColor3f(1, 1, 0);
    drawText(-0.89, -0.3, 0, 0.0002, "Assistant Professor");

    glColor3f(1, 1, 0);
    drawText(-0.83, -0.35, 0, 0.0002, "Dept. Of CSE");

    glColor3f(1, 0.5, 0);
    drawText(-0.9, -0.45, 0, 0.00029, "MRS CHAITRA H K");

    glColor3f(1, 1, 0);
    drawText(-0.89, -0.5, 0, 0.0002, "Assistant Professor");

    glColor3f(1, 1, 0);
    drawText(-0.83, -0.55, 0, 0.0002, "Dept. Of CSE");

    glColor3f(1, 1, 1);
    drawText(-0.7, -0.8, 0, 0.0005, "S. J. B INSTITUTE OF TECHNOLOGY");

    glColor3f(1, 1, 1);
    drawText(-0.4, -0.9, 0, 0.0003, "B G S HEALTH AND EDUCATION CITY");

    glColor3f(1, 1, 1);
    drawText(-0.25, -0.98, 0, 0.00025, "Kengeri, Bangalore-560060");

    glColor3f(1, 1, 1);
    drawText(1.28, -0.95, 0, 0.00015, "Press (h) to show Help Menu ...");

    glutSwapBuffers();
}

void help() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1, 0.5, 0);
    drawText(-1.5, 0.8, 0, 0.001, "Key Controls");

    glColor3f(1, 1, 1);
    drawText(-1.4, 0.6, 0, 0.0004, "1 --> Front View");
    drawText(-1.4, 0.5, 0, 0.0004, "2 --> Top View");
    drawText(-1.4, 0.4, 0, 0.0004, "3 --> Side View");
    drawText(-1.4, 0.3, 0, 0.0004, "4 --> About");
    drawText(-1.4, 0.2, 0, 0.0004, "a --> Angled Motion");
    drawText(-1.4, 0.1, 0, 0.0004, "n --> Non Angled Motion");
    drawText(-1.4, 0.0, 0, 0.0004, "r --> Retrograde Motion");
    drawText(-1.4, -0.1, 0, 0.0004, "n --> Non Retrograde Motion");
    drawText(-1.4, -0.2, 0, 0.0004, "h --> Help");
    drawText(-1.4, -0.3, 0, 0.0004, "+ --> Move Satellite Forward");
    drawText(-1.4, -0.4, 0, 0.0004, "- --> Move Satellite Backward");

    glutSwapBuffers();
}

void about() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1, 0.5, 0);
    drawText(-0.3, 0.7, 0, 0.001, "About");

    glColor3f(1, 1, 1);
    drawText(-1.7, 0.4, 0, 0.0004, "This project aims to simulate the different motions of a satellite around a planet.");
    drawText(-1.7, 0.3, 0, 0.0004, "It also provides top view and bottom view for better understanding of retrograde");
    drawText(-1.7, 0.2, 0, 0.0004, "motion and angled motion along with normal motions of a satellite. This will help");
    drawText(-1.7, 0.1, 0, 0.0004, "the common user to understand the complex science behind satellite motions.");

    glutSwapBuffers();
}

//To resize without changing shape
void reshape(int w, int h) {

    GLdouble aspect = (GLdouble)w / (GLdouble)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, w, h);
}

//Randomly Draws points to create stars
void background() {

    glPointSize(2);
    for (int i = 1; i < 90; i++) {

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
    glFlush();
}

//To draw satellite
void drawArtSat() {

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
//By defalut view = 0 so front view is displayed by default
void frontview()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Light Source
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat AmbientLight[] = { 0.1, 0.1, 0.1, 1.0 };  //R,G,B,Alpha 0.1, 0.1, 0.1, 1.0
    GLfloat DiffuseLight[] = { 0.5, 0.5, 0.5, 0.1 }; //R,G,B,Alpha
    GLfloat LightPosition[] = { -0.9,0.2, 0.9, 0.1 }; // Set the light position

    glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

    //To draw sphere or earth
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Cyan);    //glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Black); 
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Cyan);
    glPushMatrix();
    glRotatef(d, 0, 1, 0);                                //With repect to y-axis
    glutSolidSphere(0.5, 35, 32);                         // glutSolidSphere(GLdouble radius,GLint slices, GLint stacks); //glutWireSphere
    glPopMatrix();
    glPopAttrib();

    //To draw satellite
    glPushMatrix();
    //Non-angled motion
    if (angle == 0) {
        glRotatef(f, 0, 1, 0);
        glRotatef(125, 1, 0, 0.5);
    }
    //Angled motion
    else {
        glRotatef(f, 0.2, 1, 0.3);
        glRotatef(125, 1, 0, 0.5);
    }

    glScalef(0.05, 0.05, 0.05);
    glTranslatef(4, -15, 5);
    drawArtSat();
    glPopMatrix();

    //For Moon
    //retrograde motion is the apparent motion of a planet in a direction opposite to that of other bodies within its system.
    //For anti-clock wise or rotating along with the earth rotation by default (retograde = 0)
    if (retrograde == 0)
    {
        glPushAttrib(GL_ALL_ATTRIB_BITS);
        glMaterialfv(GL_FRONT, GL_AMBIENT, Gray);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Gray);
        glPushMatrix();
        //Non Angled Motion by default angle=0
        if (angle == 0)
            glRotatef(m, 0, 1, 0.1);
        else //Angled Motion
            glRotatef(m, 0.2, 1, 0.3);

        glTranslatef(0.9, 0, 0.1);
        glScalef(0.1, 0.1, 0.1);
        glutSolidSphere(0.5, 32, 32);
        glPopMatrix();
        glPopAttrib();
    }

    //For clock wise or rotating opposite to the earth rotation if retograde = 1;
    if (retrograde == 1)  //Retrograde Motion
    {
        glPushAttrib(GL_ALL_ATTRIB_BITS);
        glMaterialfv(GL_FRONT, GL_AMBIENT, Gray);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Gray);
        glPushMatrix();

        //Non-Angled Motion by default angle=0
        if (angle == 0)
            glRotatef(-m, 0, 1, 0);
        else  //Angled Motion
            glRotatef(-m, 0.2, 1, 0.3);

        glTranslatef(0.9, 0, 0.1);
        glScalef(0.1, 0.1, 0.1);
        glutSolidSphere(0.5, 32, 32);
        glPopMatrix();
        glPopAttrib();
    }

    //To draw the stars
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, White);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, White);
    glPushMatrix();
    background();
    glPopMatrix();
    glPopAttrib();

    glutSwapBuffers();
}

//If view = 1 (topView)
void topview()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Light Source
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat AmbientLight[] = { 0.1, 0.1, 0.1, 1.0 };  //R,G,B,Alpha
    GLfloat DiffuseLight[] = { 0.5f, 0.5f, 0.5f, 0.1f }; //R,G,B,Alpha
    GLfloat LightPosition[] = { -0.9, 0.9,0.2, 0.1 }; // Set the light position

    glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

    //Sphere
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Cyan);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Cyan);
    glPushMatrix();
    glRotatef(d, 0, 0, 1);               //With repect to z-axis
    glutSolidSphere(0.5, 32, 32);
    glPopMatrix();
    glPopAttrib();

    //Satellite
    glPushMatrix();
    glRotatef(f, 0, 0, 1);              //With repect to z-axis
    glRotatef(125, 1, 0.2, 0);
    glScalef(0.05, 0.05, 0.05);
    glTranslatef(9, 5, -15);
    drawArtSat();
    glPopMatrix();

    if (retrograde == 0)
    {
        glPushAttrib(GL_ALL_ATTRIB_BITS);
        glMaterialfv(GL_FRONT, GL_AMBIENT, Gray);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Gray);
        glPushMatrix();
        if (angle == 0)
            glRotatef(m, 0, 0.1, 1);
        else
            glRotatef(m, 0.2, 0.3, 1);

        glTranslatef(0.9, 0.1, 0);
        glScalef(0.1, 0.1, 0.1);
        glutSolidSphere(0.5, 32, 32);
        glPopMatrix();
        glPopAttrib();
    }

    //Retrograde Motion
    if (retrograde == 1)
    {
        glPushAttrib(GL_ALL_ATTRIB_BITS);
        glMaterialfv(GL_FRONT, GL_AMBIENT, Gray);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Gray);
        glPushMatrix();
        if (angle == 0)
            glRotatef(-m, 0, 0, 1);
        else
            glRotatef(-m, 0.2, 0.3, 1);

        glTranslatef(0.9, 0.1, 0);
        glScalef(0.1, 0.1, 0.1);
        glutSolidSphere(0.5, 32, 32);
        glPopMatrix();
        glPopAttrib();
    }

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, White);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, White);
    glPushMatrix();
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
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat AmbientLight[] = { 0.1, 0.1, 0.1, 1.0 };  //R,G,B,Alpha
    GLfloat DiffuseLight[] = { 0.5f, 0.5f, 0.5f, 0.1f }; //R,G,B,Alpha
    GLfloat LightPosition[] = { -0.6, -2.5, 1.9, 0.1 }; // Set the light position

    glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

    //Earth or sphere
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Cyan);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Cyan);
    glPushMatrix();
    glRotatef(-d, 1, 0, 0);
    glutSolidSphere(0.5, 32, 32);
    glPopMatrix();
    glPopAttrib();


    //For Satellite
    glPushMatrix();
    if (angle == 0) {
        glRotatef(f, 1, 0, 0);
        glRotatef(60, 1, 1, 0);
    }
    else {
        glRotatef(f, 1, 0.2, 0.3);
        glRotatef(60, 1, 1, 0);
    }

    glScalef(0.05, 0.05, 0.05);
    glTranslatef(5, 4, -15);
    drawArtSat();
    glPopMatrix();

    //For Moon
    if (retrograde == 0)
    {
        glPushAttrib(GL_ALL_ATTRIB_BITS);
        glMaterialfv(GL_FRONT, GL_AMBIENT, Gray);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Gray);
        glPushMatrix();
        if (angle == 0)
            glRotatef(-m, 1, 0, 0.1);
        else
            glRotatef(-m, 1, 0.2, 0.3);

        glTranslatef(0.1, 0.9, 0);
        glScalef(0.1, 0.1, 0.1);
        glutSolidSphere(0.5, 32, 32);
        glPopMatrix();
        glPopAttrib();
    }

    //Retrograde Motion
    if (retrograde == 1)
    {
        glPushAttrib(GL_ALL_ATTRIB_BITS);
        glMaterialfv(GL_FRONT, GL_AMBIENT, Gray);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, Gray);
        glPushMatrix();
        if (angle == 0)
            glRotatef(m, 1, 0, 0);
        else
            glRotatef(m, 1, 0.2, 0.3);

        glTranslatef(0.1, 0.9, 0);
        glScalef(0.1, 0.1, 0.1);
        glutSolidSphere(0.5, 32, 32);
        glPopMatrix();
        glPopAttrib();
    }

    //For stars
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, White);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, White);
    glPushMatrix();
    background();
    glPopMatrix();
    glPopAttrib();

    glutSwapBuffers();
}

void Key(unsigned char ch, int x, int y) {

    if (ch == 'r') //For Retrograde
        retrograde = 1;
    if (ch == 'n')  //For Normal Motion
        retrograde = 0;
    if (ch == 'a') //For Angled Motion
        angle = 1;
    if (ch == 's') //For Non Angular Motion
        angle = 0;
    if (ch == 'h') //For help menu
        view = 4;
    if (ch == '4') //For about page
        view = 5;
    if (ch == '0') //For intro page
        view = 0;
    if (ch == '1') //For front View
        view = 1;
    if (ch == '2') //For top view
        view = 2;
    if (ch == '3') //For side view
        view = 3;
    //Controlling Artificial Satellite
    if (ch == '+')
        f += 2;
    if (ch == '-')
        f -= 2;

    glutPostRedisplay();
}

void display() {

    if (value == 2)
        retrograde = 1;
    else if (value == 3)
        retrograde = 0;
    else if (value == 1)
        view = 0;
    else if (value == 4)
        view = 1;
    else if (value == 5)
        view = 2;
    else if (value == 6)
        view = 3;
    else if (value == 7)
        angle = 1;
    else if (value == 8)
        angle = 0;
    else if (value == 9) {
        f += 5;
        value = 0;
    }
    else if (value == 10) {
        f -= 5;
        value = 0;
    }
    else if (value == 11)
        view = 4;
    else if (value == 12)
        view = 5;

    if (view == 0)
        introPage();
    else if (view == 1)
        frontview();
    else if (view == 2)
        topview();
    else if (view == 3)
        sideview();
    else if (view == 4)
        help();
    else
        about();

    glutPostRedisplay();
}

void menu(int num) {

    if (num == 13)
        exit(0);
    else
        value = num;

    glutPostRedisplay();
}

void createMenu(void) {

    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Front View (Keyboard Shortcut->1)", 4);
    glutAddMenuEntry("Top View (Keyboard Shortcut->2)", 5);
    glutAddMenuEntry("Side View (Keyboard Shortcut->3)", 6);
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("IntroPage (Keyboard Shortcut->0)", 1);
    glutAddMenuEntry("Retrograde Motion (Keyboard Shortcut->r)", 2);
    glutAddMenuEntry("Non Retrograde Motion (Keyboard Shortcut->n)", 3);
    glutAddSubMenu("Views", submenu_id);
    glutAddMenuEntry("Angular Motion (Keyboard Shortcut->a)", 7);
    glutAddMenuEntry("Non Angular Motion (Keyboard Shortcut->s)", 8);
    glutAddMenuEntry("Help (Keyboard Shortcut->h)", 11);
    glutAddMenuEntry("About (Keyboard Shortcut->4)", 12);
    glutAddMenuEntry("Quit", 13);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Move Artificial Satellite Forward (Keyboard Shortcut->+)", 9);
    glutAddMenuEntry("Move Artificial Satellite Backward (Keyboard Shortcut->-)", 10);
    glutAttachMenu(GLUT_LEFT_BUTTON);
}

int main(int C, char* V[]) {

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