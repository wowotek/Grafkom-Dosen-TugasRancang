#ifndef COMMON_HH
#define COMMON_HH

template <typename T>
struct vec2_t {
    T x, y;
}

void
vec2_t::operator+(vec2_t othervec){
    x += othervec.x;
    y += othervec.y;
}

#endif