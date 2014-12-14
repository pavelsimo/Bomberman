#include <iostream>
#include "LOpenGL.h"
#include "LDevIL.h"
#include "SpriteSheet.h"
#include "TileManager.h"
#include "Drawing.h"

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


SpriteSheet *spriteSheet = nullptr;
TileManager *tileManager = nullptr;

std::string curBmanSpriteStr = "Bman_F_f00.png";
Sprite curBmanSprite;

int bX = 128, bY = 128;
int bFS = 0, bBS = 0, bLS = 0, bRS = 0;
int NFS = 8, NBS = 8, NLS = 8, NRS = 8;

std::string bmanFront[] = {
    "Bman_F_f00.png",
    "Bman_F_f01.png",
    "Bman_F_f02.png",
    "Bman_F_f03.png",
    "Bman_F_f04.png",
    "Bman_F_f05.png",
    "Bman_F_f06.png",
    "Bman_F_f07.png",
};

std::string bmanBack[] = {
    "Bman_B_f00.png",
    "Bman_B_f01.png",
    "Bman_B_f02.png",
    "Bman_B_f03.png",
    "Bman_B_f04.png",
    "Bman_B_f05.png",
    "Bman_B_f06.png",
    "Bman_B_f07.png"
};

std::string bmanLSide[] = {
    "Bman_LS_f00.png",
    "Bman_LS_f01.png",
    "Bman_LS_f02.png",
    "Bman_LS_f03.png",
    "Bman_LS_f04.png",
    "Bman_LS_f05.png",
    "Bman_LS_f06.png",
    "Bman_LS_f07.png"
};

std::string bmanRSide[] = {
    "Bman_RS_f00.png",
    "Bman_RS_f01.png",
    "Bman_RS_f02.png",
    "Bman_RS_f03.png",
    "Bman_RS_f04.png",
    "Bman_RS_f05.png",
    "Bman_RS_f06.png",
    "Bman_RS_f07.png"
};

bool InitializeGL()
{
    glViewport(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, -1.0, 1.0);
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

    return true;
}

bool LoadingMedia()
{
    spriteSheet = new SpriteSheet();
    spriteSheet->LoadFromFile("/home/pavelsimo/workspace/Games_Cpp/Bomberman/resources/BombermanSpriteSheet.png");
    spriteSheet->LoadSpritesFromXML("/home/pavelsimo/workspace/Games_Cpp/Bomberman/resources/BombermanSpriteSheet.xml");

    tileManager = new TileManager(spriteSheet, 64, 64, 10, 10);
    tileManager->AddTile("Block_Background.png");
    tileManager->AddTile("Block_Solid.png");
    tileManager->AddTile("Block_Explodable.png");
    tileManager->AddTile("Block_Portal.png");

    return true;
}

void Render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    tileManager->Render();
    curBmanSprite = spriteSheet->GetSprite(curBmanSpriteStr);

    Rect rect2;
    rect2.x = curBmanSprite.x;
    rect2.y = curBmanSprite.y;
    rect2.w = curBmanSprite.w;
    rect2.h = curBmanSprite.h;

    DrawTexture(bX, bY,
            spriteSheet->GetTexId(),
            spriteSheet->GetImgWidth(),
            spriteSheet->GetImgHeight(),
            spriteSheet->GetTexWidth(),
            spriteSheet->GetTexHeight(),
            &rect2
    );

    glutSwapBuffers();
}

void Update()
{

}

void OnKeyDownEvent(unsigned char key, int x, int y)
{

    switch(key)
    {
        case 'w':
        case 'W':
            bY -= 5;
            curBmanSpriteStr = bmanBack[bBS];
            bBS = (bBS + 1) % 8;
            break;
        case 'a':
        case 'A':
            bX -= 5;
            curBmanSpriteStr = bmanLSide[bLS];
            bLS = (bLS + 1) % 8;
            break;
        case 's':
        case 'S':
            bY += 5;
            curBmanSpriteStr = bmanFront[bFS];
            bFS = (bFS + 1) % 8;
            break;
        case 'd':
        case 'D':
            bX += 5;
            curBmanSpriteStr = bmanRSide[bRS];
            bRS = (bRS + 1) % 8;
            break;
    }

}

void OnKeyUpEvent(unsigned char key, int x, int y)
{

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
    if(spriteSheet != nullptr)
    {
        delete spriteSheet;
        spriteSheet = nullptr;
    }

    if(tileManager != nullptr)
    {
        delete tileManager;
        tileManager = nullptr;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow(SCREEN_TITLE);

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
