#include "myglwidget.h"
#include <GL/gl.h>

MyGLWidget::MyGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
    startTimer(16); // ~60 FPS
}


void MyGLWidget::timerEvent(QTimerEvent*)
{
    angle += 1.0f;
    if(angle > 360.f) angle -= 360.f;
    update();
}
void MyGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
std::srand(std::time(nullptr));
    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
}

void MyGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

static void triangle(float x1, float y1, float x2,float y2, float x3, float y3)
{
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);



}


static void DegradedTriangle(float x1, float y1, float x2,float y2, float x3, float y3)
{
    glColor3f(0.f, 0.25f, 0.25f);

    glVertex2f(x1,y1);
    glColor3f(0.50f, 0.f, 0.50f);
    glVertex2f(x2,y2);
    glColor3f(0.75f, 0.75f, 0.f);
    glVertex2f(x3,y3);



}



static void rectangle(float x1, float y1, float x2,float y2){

    glVertex2f(x1,y1);
    glVertex2f(x2,y1);
    glVertex2f(x2,y2);

    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x1,y2);

}



static void Flag(float x, float y, float r, float g, float b, bool isDegraded)
{

    float poleW = 0.03f;
    float poleH = 0.55f;

    float flagW = 0.35f;
    float flagH = 0.18f;

    // el mastil siempre tendra el mismo color
    glColor3f(0.25f, 0.25f, 0.25f);
    rectangle(x, y, x + poleW, y + poleH);

    // la bandera que cambia segun el color que se le dice
    glColor3f(r, g, b);

    float baseX = x + poleW;
    float baseY = y + poleH * 0.75f;

    if(!isDegraded)
        triangle(
            baseX, baseY + flagH / 2.0f,   // vertice de arriba
            baseX, baseY - flagH / 2.0f,   // vertice de  abajo
            baseX + flagW, baseY           // punta hacia la derecha
            );

    if(isDegraded)
    {

        DegradedTriangle(
            baseX, baseY + flagH / 2.0f,   // vertice de arriba
            baseX, baseY - flagH / 2.0f,   // vertice de  abajo
            baseX + flagW, baseY           // punta hacia la derecha
            );
    }
}



void MyGLWidget::paintGL()
{
    glClearColor(0.55f, 0.75f, 0.95f, 1.f);


    // creador de relámpagos

    static int flash = 0;

    if (flash > 0){
        glClearColor(1.f, 1.f, 1.f, 1.f);
        flash--;
    } else {
        glClearColor(0.55f, 0.75f, 0.95f, 1.f);
    }

    // probabilidad del relámpago

    if ((std::rand() % 200) == 0) flash = 2;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);








    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


     glBegin(GL_TRIANGLES);






    // Suelo
    glColor3f(0.4f, 0.55f, 0.5f);
    rectangle(-1.f, -1.f, 1.f, -0.55f);






    // Banderas (misma capa)
    glColor3f(0.3f, 0.45f, 0.35f);
    int flag = 6;
    float step = 2.0f / flag;

    // posiciones de las banderas
    float x = -1.0f;

    float y = -0.6;

    // variables rgb

    float r = 0;
    float g = 0.5;
    float b = 0;

    for(int i = 0; i < flag; i++)
    {

        Flag(x,y,r,g,b,false);

        x += step;

        r += 0.1f;
        g += 0.1f;
        b += 0.1f;

    }



    // bandera cliping

    Flag(0.8f,0.6f, 0.f,0.f,0.f,false);


    //bandera con degradado







    // Sol simple (4 triángulos alrededor del centro)
    glColor3f(1.f, 0.9f, 0.2f);
    float cx = 0.7f, cy = 0.7f, s = 0.1f;

    triangle(cx, cy, cx + s, cy, cx, cy + s);
    triangle(cx, cy, cx, cy + s, cx - s, cy);
    triangle(cx, cy, cx - s, cy, cx, cy - s);
    triangle(cx, cy, cx, cy - s, cx + s, cy);



    glEnd();





    //rotacion moviendo los ejes

    float px = 0.0f;
    float py = -0.0f;

    glPushMatrix();

    // mover al punto donde está la bandera
    glTranslatef(px, py, 0.f);

    // rotar alrededor de la base
    glRotatef(angle, 0.f, 0.f, 1.f);

    // dibujar en origen
    glBegin(GL_TRIANGLES);
   Flag(0.f,0.f, 0.f,0.f,0.f,true);
    glEnd();

    glPopMatrix();
}
