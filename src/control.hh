#ifndef CONTROL_HH
#define CONTROL_HH

#include <vector>
#include "entity.hh"

void InitControl(std::vector<Entity> *, b2World *, float *, float *);
void MouseDownHandler(int, int, int, int);
void KeyboardDownHandler(unsigned char, int, int);

#endif