

#include<GL/freeglut.h>
#include<iostream>


float escala = 1.1;
float tx = 0;
float ty = 0;
float angulo = 0;

void desenha(void) {

glClear( GL_COLOR_BUFFER_BIT );

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-10,10,-10,10);



glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

glScalef(escala, escala, 0);
glTranslatef(tx, ty, 0);
glRotatef( angulo, 0, 0, 1);

glBegin (GL_LINES);
        //Letra G
        glVertex2f(-2.5,0);
        glVertex2f(-2.5,-2);

        glVertex2f(-2.5,0);
        glVertex2f(-1.5,0);

        glVertex2f(-2.5,-2);
        glVertex2f(-1.5,-2);

        glVertex2f(-1.5,-2);
        glVertex2f(-1.5,-1.2);

        glVertex2f(-1.5,-1.2);
        glVertex2f(-1.9,-1.2);

        //Letra U

        glVertex2f(-1,0);
        glVertex2f(-1,-2);

        glVertex2f(-1,-2);
        glVertex2f(-0,-2);

        glVertex2f(-0,0);
        glVertex2f(-0,-2);

        //Letra S

        glVertex2f(0.5,0);
        glVertex2f(1.5,0);

        glVertex2f(0.5,0);
        glVertex2f(0.5,-1);

        glVertex2f(0.5,-1);
        glVertex2f(1.5,-1);

        glVertex2f(1.5,-1);
        glVertex2f(1.5,-2);

        glVertex2f(1.5,-2);
        glVertex2f(0.5,-2);

        //Letra T

        glVertex2f(2,0);
        glVertex2f(3,0);

        glVertex2f(2.5,0);
        glVertex2f(2.5,-2);

        //Letra A

        glVertex2f(3.5,-2);
        glVertex2f(4,0);

        glVertex2f(4,0);
        glVertex2f(4.5, -2);

        glVertex2f(3.8, -1.3);
        glVertex2f(4.2, -1.3);

        //Letra V

        glVertex2f(5,0);
        glVertex2f(5.5,-2);

        glVertex2f(5.5,-2);
        glVertex2f(6,0);

        glVertex2f(6.5,0);
        glVertex2f(6.5, -2);

        glVertex2f(6.5,0);
        glVertex2f(7.5,0);

        glVertex2f(6.5,0);
        glVertex2f(6.5,-2);

        glVertex2f(6.5,-2);
        glVertex2f(7.5,-2);

        glVertex2f(7.5,-2);
        glVertex2f(7.5,0);



    glEnd();
glFlush();
}
void listeningKey (unsigned char tecla,GLint x, GLint y) {
    switch(tecla) {

    case '+': escala +=0.5;

                break;

    case '-': escala -=0.5;

                break;

    case 'd': tx +=0.5;

                break;

    case 'a': tx -=0.5;

                break;

    case 'w': ty +=0.5;

                break;

    case 's': ty -=0.5;

                break;

    case 'q': angulo += 0.5;

                break;

    case 'e': angulo -= 0.5;

                break;
                }
        desenha();
    }

int main(int argc, char* argv[]) {
glutInit(&argc,  argv);
glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
glutInitWindowSize(800,600);
glutInitWindowPosition(300,100);
glutCreateWindow("Ola Glut");
glutKeyboardFunc(listeningKey);
glutDisplayFunc(desenha);
glClearColor( 0, 0, 1, 0);
glutMainLoop();
return 0;
}
