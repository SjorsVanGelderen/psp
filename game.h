/*
  Main game logic
*/

#ifndef GAME_H
#define GAME_H

#include <pspctrl.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspgu.h>
#include "graphicsobject.h"
#include "triangle.h"

class Game
{
protected:
    int Controls();
    void Render();
    bool Load();
    
    Triangle* triangle;
    
    ScePspFMatrix4 projection;
    ScePspFMatrix4 view;
    GraphicsObject* gfx;

public:
    Game();
    ~Game();
    int Run();
};

#endif
