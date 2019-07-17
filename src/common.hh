#ifndef COMMON_HH
#define COMMON_HH

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
};

#endif