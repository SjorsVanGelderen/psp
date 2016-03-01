/*
  Object that exposes graphics functionality
*/

#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include <pspgu.h>
#include <pspgum.h>

class GraphicsObject
{
private:
    static GraphicsObject* _instance;
    
protected:    
    GraphicsObject();
    GraphicsObject(const GraphicsObject&);
    GraphicsObject& operator= (const GraphicsObject&);

public:
    static GraphicsObject* Instance();
    ~GraphicsObject();
    bool Init3DGraphics();
};

#endif
