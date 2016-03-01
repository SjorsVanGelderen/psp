#include "game.h"

//For storing GU information
static unsigned int __attribute__((aligned(16))) list[262144];

Game::Game()
{

}

Game::~Game()
{
    
}

int Game::Run()
{
    if(Load() < 0)
    {
	return -1;
    }

    while(true)
    {
	if(Controls() == 9)
	{
	    break;
	}

	Render();
    }

    return 0;
}

bool Game::Load()
{
    //Create the graphics object
    gfx = GraphicsObject::Instance();
    gfx->Init3DGraphics();

    //Set the projection
    sceGumMatrixMode(GU_PROJECTION);
    sceGumLoadIdentity();
    sceGumPerspective(45.0f, 16.0f / 9.0f, 2.0f, 1000.0f);

    //Create the triangle
    triangle = new Triangle();
    
    return 0;
}

int Game::Controls()
{
    //Read controls
    SceCtrlData pad;
    sceCtrlPeekBufferPositive(&pad, 1);

    //Check for input
    if(pad.Buttons != 0)
    {
	if(pad.Buttons & PSP_CTRL_CROSS)
	{
	    return 9;
	}
    }

    return 0;
}

void Game::Render()
{
    //Start the GU
    sceGuStart(GU_DIRECT, list);

    //Clear the screen
    sceGuClearColor(0xff000000);
    sceGuClearDepth(0);
    sceGuClear(GU_COLOR_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);

    //Set the ambient light
    sceGuAmbient(0xffffffff);
    
    //Set the view
    sceGumMatrixMode(GU_VIEW);
    sceGumLoadIdentity();

    //Render the triangle
    triangle->Render();

    //Finish rendering
    sceGuFinish();
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}
