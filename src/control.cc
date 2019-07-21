#include "control.hh"

#include <iostream>

#include "game.hh"
#include "common.hh"

void
MouseEvent(int button, int state, int x, int y)
{
    if(button == 0 && state == 1){
        AddEntity(vec2f((float)(x), (float)(y)));
    }
}

void
KeyboardDownEvent(unsigned char, int, int)
{

}

void
KeyboardUpEvent(unsigned char, int, int)
{

}