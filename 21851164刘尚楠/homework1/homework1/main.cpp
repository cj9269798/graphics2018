#include <GLUT/GLUT.h>
#include <stdlib.h>
#include <math.h>

GLfloat rtri = 1;//金字塔旋转角度
double Move_x, Move_y, Move_z;
void init(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glShadeModel(GL_SMOOTH);//设为smooth处理方式，注意看区别
    glEnable(GL_DEPTH_TEST);//激活深度测试
}
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    //清除颜色缓存和深度缓存
    glLoadIdentity();
    glTranslatef(-1.5f, 0.0f, -6.0f);
    glTranslatef(Move_x, Move_y, Move_z);
    glRotatef(rtri, 0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();
    glutSwapBuffers();//交换双缓存
}

void reshape (int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void timer(int op) {
    rtri += 5.0 * op;
    glutPostRedisplay();
    glutTimerFunc(5, timer, op);
}

void mouse(int botton, int state, int x, int y) {
    if(botton == GLUT_MIDDLE_BUTTON) {
        exit(0);
        return ;
    }
    if(botton == GLUT_LEFT_BUTTON) {
        if(state == GLUT_DOWN) {
            glutTimerFunc(5, timer, -1);
        }
    }
    if(botton == GLUT_RIGHT_BUTTON) {
        if(state == GLUT_DOWN) {
            glutTimerFunc(5, timer, 1);
        }
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'x': exit(0); break;
        case 'w': Move_y += 0.1; break;
        case 's': Move_y -= 0.1; break;
        case 'a': Move_x -= 0.1; break;
        case 'd': Move_x += 0.1; break;
        case 'f': Move_z += 0.1; break;
        case 'b': Move_z -= 0.1; break;
    }
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//使用双缓存模式和深度缓存
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Marveliu for Graphes 2018");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    //glutIdleFunc(display);//设置空闲时调用的函数
    glutMainLoop();
    return 0;
}

