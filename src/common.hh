/* a common header, called in all of the source file, a helper file basically
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

#ifndef COMMON_HH
#define COMMON_HH

// Unpack Vector of 2 coordinate
#define up2(vec2) vec2.x, vec2.y
#define up2add(vec2, ax, ay) vec2.x + ax, vec2.y + ay
#define up2div(vec2, dx, dy) (vec2.x/dx), (vec2.y/dy)

#endif