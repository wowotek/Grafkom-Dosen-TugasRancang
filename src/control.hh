/* definition of all game control related
 * Copyright (C) 2019  Erlangga Ibrahim, Aurelia Gabriele
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

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