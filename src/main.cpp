#include <iostream>
#include "World.h"


// Constants
//
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
const int SCREEN_FPS = 60;
const char* SCREEN_TITLE = "Bomberman";


// Methods
//
bool InitializeGL();
bool LoadingMedia();
void Render();
void Update();
void OnKeyDownEvent(unsigned char key, int x, int y);
void OnKeyUpEvent(unsigned char key, int x, int y);
void OnMouseClick(int button, int state, int x, int y);
void GameLoop(int value);
void Clean();

World* g_world = nullptr;

bool InitializeGL()
{
    glViewport(0.f, 0.f, g_world->GetWidth(), g_world->GetHeight());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(g_world->GetLeft(), g_world->GetRight(), g_world->GetBottom(), g_world->GetTop(), -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glEnable(GL_TEXTURE_2D);

    GLenum error = glGetError();
    if (error !=  GL_NO_ERROR )
    {
        std::cout << "Error initializing OpenGL! " << gluErrorString(error) << std::endl;
        return false;
    }

    // initialize DevIL and DevILU
    ilInit();
    iluInit();
    ilClearColour(0, 0, 0, 0);

    // check for errors
    ILenum ilError = ilGetError();
    if(ilError != IL_NO_ERROR)
    {
        printf( "Error initializing DevIL! %s\n", iluErrorString( ilError ) );
        return false;
    }

    // enable blend
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_ALPHA_TEST);

    // Point size
    glEnable(GL_PROGRAM_POINT_SIZE);

    return true;
}

bool LoadingMedia()
{
    g_world->OnSetup();
    return true;
}

void Render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    g_world->OnRender();

    glutSwapBuffers();
}

void Update()
{
    g_world->OnUpdate();
}

void OnKeyDownEvent(unsigned char key, int x, int y)
{
    g_world->OnKeyDown(key);
}

void OnKeyUpEvent(unsigned char key, int x, int y)
{
    g_world->OnKeyUp(key);
}

void OnMouseMoveEvent(int x, int y)
{

}

void OnMouseClick(int button, int state, int x, int y)
{

}

void GameLoop(int value)
{
    Update();
    Render();
    glutTimerFunc( 1000 / SCREEN_FPS, GameLoop, value);
}

void Clean()
{
    if(g_world != nullptr)
    {
        delete g_world;
        g_world = nullptr;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow(SCREEN_TITLE);

    g_world = new World(SCREEN_WIDTH, SCREEN_HEIGHT);

    if(!InitializeGL())
    {
        std::cout << "Unable to initalize OpenGL." << std::endl;
    }

    if(!LoadingMedia())
    {
        std::cout << "Unable to load the media." << std::endl;
    }

    glutDisplayFunc(Render);
    glutKeyboardFunc(OnKeyDownEvent);
    glutKeyboardUpFunc(OnKeyUpEvent);
    glutCloseFunc(Clean);
    glutPassiveMotionFunc(OnMouseMoveEvent);
    glutMouseFunc(OnMouseClick);
    glutTimerFunc(1000 / SCREEN_FPS, GameLoop, 0);
    glutMainLoop();

    return 0;
}
