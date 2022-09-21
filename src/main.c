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
int prog_glut_window_init(int w, int h, int argc, char* argv[]);
void prog_glew_init(void);


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


int prog_glut_window_init(
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
    glutReshapeFunc(ResizeFunction);
    glutDisplayFunc(RenderFunction);

    return window_handle;
}


void prog_glew_init(void)
{
    GLenum GlewInitResult = glewInit();

    if (GlewInitResult != GLEW_OK)
    {
        fprintf(
            stderr,
            "ERROR: %s\n",
            glewGetErrorString(GlewInitResult)
        );
        exit(EXIT_FAILURE);
    }

#ifdef DEBUG
    fprintf(
        stdout, 
        "INFO: OpenGL Version: %s\n", 
        glGetString(GL_VERSION)
    );
#endif

    glClearColor(1.0f, 0.75f, 1.0f, 0.0f);
}


int main(int argc, char* argv[])
{
    int window_width = 800;
    int window_height = 600;
    
    int window_handle = prog_glut_window_init(
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
    prog_glew_init();
    glutMainLoop();
    exit(EXIT_SUCCESS);
}