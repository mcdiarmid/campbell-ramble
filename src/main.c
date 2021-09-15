/*
* Beginning with the guide found on:
* https://openglbook.com/
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#define WINDOW_TITLE_PREFIX "Test window"


// Prototypes
void ResizeFunction(int w, int h);
void RenderFunction(void);
int InitializeWindow(int w, int h, int argc, char* argv[]);


// Functions
void ResizeFunction(int width, int height)
{
    glViewport(0, 0, width, height);
}


void RenderFunction(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
    glutPostRedisplay();
}


int InitializeWindow(
    int window_width,
    int window_height,
    int argc, 
    char* argv[]
)
{
    glutInit(&argc, argv);
    glutInitContextVersion(4, 0);
    glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
    glutInitContextProfile(GLUT_CORE_PROFILE);
    glutSetOption(
        GLUT_ACTION_ON_WINDOW_CLOSE,
        GLUT_ACTION_GLUTMAINLOOP_RETURNS
    );
    glutInitWindowSize(
        window_width,
        window_height
    );
    glutInitDisplayMode(
        GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA
    );
    int window_handle = glutCreateWindow(WINDOW_TITLE_PREFIX);

    if (window_handle < 1){
        fprintf(stderr, "ERROR: creating new rendering window\n.");
        exit(EXIT_FAILURE);
    }
#ifdef DEBUG
    fprintf(
        stdout, 
        "INFO: OpenGL Version: %s\n", 
        glGetString(GL_VERSION)
    );
#endif
    glutReshapeFunc(ResizeFunction);
    glutDisplayFunc(RenderFunction);

    return window_handle;
}


int main(int argc, char* argv[])
{
    int window_width = 800;
    int window_height = 600;
    
    int window_handle = InitializeWindow(
        window_width,
        window_height,
        argc,
        argv
    );
    fprintf(
        stdout, 
        "INFO: Window Handle: %d\n", 
        window_handle
    );
    glClearColor(1.0f, 0.75f, 1.0f, 0.0f);
    glutMainLoop();
    exit(EXIT_SUCCESS);
}