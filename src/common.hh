#ifndef COMMON_HH
#define COMMON_HH

#include <math.h>


#define ENTITY_SQUARE 0
#define ENTITY_CIRCLE 1
#define ENTITY_TRIANGLE 2

#define unpack2(vec2_t) vec2_t.x, vec2_t.y

template <typename T> struct
vec2_t
{
    T x, y;

    vec2_t(void) = default;
    vec2_t(T init): x(init), y(init) {}
    vec2_t(T init_x, T init_y): x(init_x), y(init_y) {}

    vec2_t
    operator+(vec2_t othervec)
    {
        return vec2_t<T>(
            x + othervec.x,
            y + othervec.y
        );
    }

    void
    operator+=(vec2_t othervec)
    {
        x += othervec.x;
        y += othervec.y;
    }

    vec2_t
    operator-(vec2_t othervec)
    {
        return vec2_t(
            x - othervec.x,
            y - othervec.y
        );
    }

    void
    operator-=(vec2_t othervec)
    {
        x -= othervec.x;
        y -= othervec.y;
    }

    /* Vector Dot Product */
    vec2_t
    operator*(vec2_t othervec)
    {
        return vec2_t(
            x*othervec.x,
            y*othervec.y
        );
    }

    void
    operator*=(vec2_t othervec)
    {
        x *= othervec.x;
        y *= othervec.y;
    }

    /* Scalar Multiplication */
    vec2_t
    operator*(T s)
    {
        return vec2_t(x * s, y * s);
    }

    void
    operator*=(T s)
    {
        x *= s;
        y *= s;
    }

    T magnitude()
    {
        return sqrt(x*x + y*y);
    }
};

typedef vec2_t<float>   vec2f;
typedef vec2_t<double>  vec2d;
typedef vec2_t<int>     vec2i;

#endif