#ifndef COMMON_HH
#define COMMON_HH

#include <math.h>

void
Poly(float posx, float TITIK_LAYAR_Y, float LEBAR_X, float LEBAR_Y, float JUMLAH_SUDUT, float ROTASI)
{
    float derajat = (360.0f / JUMLAH_SUDUT) * M_PI / 180.0f;
    glBegin(GL_LINE_LOOP);
        float sudut = 0.0f - ROTASI;
        for (int _k = 0; _k < JUMLAH_SUDUT; ++_k)
		{
            glVertex2f(TITIK_LAYAR_X + (LEBAR_X * cos(sudut)), TITIK_LAYAR_Y + (LEBAR_Y * sin(sudut)));
            sudut += derajat;
        }
    glEnd();
}

#endif