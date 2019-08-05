#ifndef CONTROL_HH
#define CONTROL_HH

#include <vector>
#include "entity.hh"
#include "joint.hh"

void InitControl(std::vector<Entity> *, b2World *, Spring *, float *, float *);
void MouseDownHandler(int, int, int, int);
void KeyboardDownHandler(unsigned char, int, int);
void MouseDragHandler(int, int);
void MouseHoverHandler(int, int);

#endif