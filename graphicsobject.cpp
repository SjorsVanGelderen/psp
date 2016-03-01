#include "graphicsobject.h"

//For storing GU information
static unsigned int __attribute__((aligned(16))) list[262144];

//Initialize pointer
GraphicsObject* GraphicsObject::_instance = 0;

GraphicsObject* GraphicsObject::Instance()
{
    if(_instance == 0)
    {
	//Create sole instance
	//_instance = new GraphicsObject;
	_instance = new GraphicsObject();
    }

    return _instance;
}

GraphicsObject::GraphicsObject()
{

}

GraphicsObject::~GraphicsObject()
{
    
}

bool GraphicsObject::Init3DGraphics()
{
    //Initialize the graphical system
    sceGuInit();
    gumInit();
    sceGuStart(GU_DIRECT, list);
    sceGuDrawBuffer(GU_PSM_8888, (void*)0, 512);
    sceGuDispBuffer(480, 272, (void*) 0x88000, 512);
    sceGuDepthBuffer((void*)0x110000, 512);
    sceGuOffset(2048 - (480 / 2), 2048 - (272 / 2));

    //Create a viewport centered at 2048, 2048 width 480 and height 272
    sceGuViewport(2048, 2048, 480, 272);
    sceGuDepthRange(0xc350, 0x2710);

    //Set GU flags
    sceGuScissor(0, 0, 480, 272);
    sceGuEnable(GU_SCISSOR_TEST);
    sceGuDepthFunc(GU_GEQUAL);
    sceGuEnable(GU_DEPTH_TEST);
    sceGuFrontFace(GU_CW);
    sceGuEnable(GU_SMOOTH);
    sceGuEnable(GU_CULL_FACE);
    sceGuEnable(GU_TEXTURE_2D);
    sceGuEnable(GU_CLIP_PLANES);
    sceGuEnable(GU_LIGHTING);
    sceGuEnable(GU_BLEND);
    sceGuBlendFunc(GU_ADD, GU_SRC_ALPHA, GU_ONE_MINUS_SRC_ALPHA, 0, 0);
    
    sceGuFinish();

    //Wait until the list has finished
    sceGuSync(0, 0);

    //Turn on the display
    sceGuDisplay(GU_TRUE);
    return true;
}
