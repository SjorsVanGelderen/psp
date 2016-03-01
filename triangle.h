/*
  Simple triangle primitive
*/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <psptypes.h>
#include <pspgu.h>
#include <pspgum.h>
#include <malloc.h>
#include "vertex.h"
#include "graphics.h"

/*
extern "C" {
    #include "graphics.h"
}
*/

class Triangle
{
protected:
    Vertex* triangle;
    Image* texture;
    float rotation;
    ScePspFMatrix4 world;

public:
    Triangle();
    ~Triangle();
    void Render();
};

#endif
