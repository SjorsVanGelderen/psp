/*
  3D sample for PSP
*/

#include <psptypes.h>
#include <pspmoduleinfo.h>
#include <pspthreadman.h>
#include <pspkernel.h>
#include <pspgu.h>
#include <psppower.h>
#include "game.h"

PSP_MODULE_INFO("PSP test", 0x0000, 1, 1);

int ExitCallback(int _arg1, int _arg2, void* _common)
{
    sceKernelExitGame();
    return 0;
}

int CallbackThread(SceSize _args, void* _argp)
{
    int callbackID = sceKernelCreateCallback("Exit callback", ExitCallback, NULL);
    sceKernelRegisterExitCallback(callbackID);
    sceKernelSleepThreadCB();
    return 0;
}

int SetupCallbacks()
{
    int threadID = sceKernelCreateThread("Update thread", CallbackThread, 0x11, 0xFA0, 0, 0);
    if(threadID >= 0)
    {
	sceKernelStartThread(threadID, 0, 0);
    }
    return threadID;
}

int main()
{
    //Enable debugging
    //pspDebugScreenInit();

    //Set up the main callbacks
    SetupCallbacks();

    //Run the game and check for its status
    Game* game = new Game();
    int status = game->Run();

    //Exit the game
    sceGuTerm();
    sceKernelExitGame();
    return 0;
}
