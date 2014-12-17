#include <iostream>
#include "utility/LOpenGL.h"
#include "utility/LDevIL.h"
#include "utility/SpriteSheet.h"
#include "utility/TileManager.h"
#include "utility/Drawing.h"
#include "utility/SpriteAnimation.h"

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
SpriteAnimation* curAnimation = nullptr;

SpriteAnimation walkingAnimationFront;
SpriteAnimation walkingAnimationBack;
SpriteAnimation walkingAnimationLeft;
SpriteAnimation walkingAnimationRight;

int bManSpeed = 10;
int bX = 128, bY = 128;


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

    tileManager = new TileManager(spriteSheet, 64, 64);
    tileManager->LoadTileMapFromFile("/home/pavelsimo/workspace/Games_Cpp/Bomberman/resources/levels/lvl_001.txt");
    tileManager->AddTile("Block_Background.png");
    tileManager->AddTile("Block_Solid.png");
    tileManager->AddTile("Block_Explodable.png");
    tileManager->AddTile("Block_Portal.png");

    walkingAnimationFront.SetSpriteSheet(spriteSheet);
    walkingAnimationFront.SetPosition(bX, bY);
    walkingAnimationFront.AddFrame("Bman_F_f00.png");
    walkingAnimationFront.AddFrame("Bman_F_f01.png");
    walkingAnimationFront.AddFrame("Bman_F_f02.png");
    walkingAnimationFront.AddFrame("Bman_F_f03.png");
    walkingAnimationFront.AddFrame("Bman_F_f04.png");
    walkingAnimationFront.AddFrame("Bman_F_f05.png");
    walkingAnimationFront.AddFrame("Bman_F_f06.png");
    walkingAnimationFront.AddFrame("Bman_F_f07.png");

    walkingAnimationBack.SetSpriteSheet(spriteSheet);
    walkingAnimationBack.SetPosition(bX, bY);
    walkingAnimationBack.AddFrame("Bman_B_f00.png");
    walkingAnimationBack.AddFrame("Bman_B_f01.png");
    walkingAnimationBack.AddFrame("Bman_B_f02.png");
    walkingAnimationBack.AddFrame("Bman_B_f03.png");
    walkingAnimationBack.AddFrame("Bman_B_f04.png");
    walkingAnimationBack.AddFrame("Bman_B_f05.png");
    walkingAnimationBack.AddFrame("Bman_B_f06.png");
    walkingAnimationBack.AddFrame("Bman_B_f07.png");

    walkingAnimationLeft.SetSpriteSheet(spriteSheet);
    walkingAnimationLeft.SetPosition(bX, bY);
    walkingAnimationLeft.AddFrame("Bman_LS_f00.png");
    walkingAnimationLeft.AddFrame("Bman_LS_f01.png");
    walkingAnimationLeft.AddFrame("Bman_LS_f02.png");
    walkingAnimationLeft.AddFrame("Bman_LS_f03.png");
    walkingAnimationLeft.AddFrame("Bman_LS_f04.png");
    walkingAnimationLeft.AddFrame("Bman_LS_f05.png");
    walkingAnimationLeft.AddFrame("Bman_LS_f06.png");
    walkingAnimationLeft.AddFrame("Bman_LS_f07.png");

    walkingAnimationRight.SetSpriteSheet(spriteSheet);
    walkingAnimationRight.SetPosition(bX, bY);
    walkingAnimationRight.AddFrame("Bman_RS_f00.png");
    walkingAnimationRight.AddFrame("Bman_RS_f01.png");
    walkingAnimationRight.AddFrame("Bman_RS_f02.png");
    walkingAnimationRight.AddFrame("Bman_RS_f03.png");
    walkingAnimationRight.AddFrame("Bman_RS_f04.png");
    walkingAnimationRight.AddFrame("Bman_RS_f05.png");
    walkingAnimationRight.AddFrame("Bman_RS_f06.png");
    walkingAnimationRight.AddFrame("Bman_RS_f07.png");

    curAnimation = &walkingAnimationFront;

    return true;
}

void Render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    tileManager->Render();
    curAnimation->Render();

    /*
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
    */
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
            bY -= bManSpeed;
            curAnimation = &walkingAnimationBack;
            curAnimation->SetPosition(bX, bY);
            curAnimation->Next();
            break;
        case 'a':
        case 'A':
            bX -= bManSpeed;
            curAnimation = &walkingAnimationLeft;
            curAnimation->SetPosition(bX, bY);
            curAnimation->Next();
            break;
        case 's':
        case 'S':
            bY += bManSpeed;
            curAnimation = &walkingAnimationFront;
            curAnimation->SetPosition(bX, bY);
            curAnimation->Next();
            break;
        case 'd':
        case 'D':
            bX += bManSpeed;
            curAnimation = &walkingAnimationRight;
            curAnimation->SetPosition(bX, bY);
            curAnimation->Next();
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
