#include "DrawPad.hpp"
#include <math.h>

void DrawStar(int cx, int cy, int radius, double startAngle, int color)
{
    double angle = startAngle;
    int x0 = (int)(cos(angle) * radius + cx);
    int y0 = (int)(sin(angle) * radius + cy);
    for (int i = 0; i < 5; i++) {
        angle += (2.0 / 5) * M_PI * 2;
        int x1 = (int)(cos(angle) * radius + cx);
        int y1 = (int)(sin(angle) * radius + cy);
        DrawLine(x0, y0, x1, y1, color);
        x0 = x1;
        y0 = y1;
    }
}

void MyDrawTriangle2(int cx, int cy, int radius, double startAngle, int color)
{
    double angle = startAngle;
    int x0 = (int)(cos(angle) * radius + cx);
    int y0 = (int)(sin(angle) * radius + cy);
    int x1 = (int)(cos(angle + M_PI * 2/ 3) * radius + cx);
    int y1 = (int)(sin(angle + M_PI * 2/ 3) * radius + cx);
    int x2 = (int)(cos(angle - M_PI * 2/ 3) * radius + cx);
    int y2 = (int)(sin(angle - M_PI * 2/ 3) * radius + cx);
    
    DrawTriangle(x0, y0, x1, y1, x2, y2, color);
}


void DrawMain()
{
    double angleA = 0.0;
    double angleB = 0.0;
    int x = 0;
    int y = 0;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int x3 = 0;
    int y3 = 0;
    int x4 = 0;
    int y4 = 0;
    int x5 = 0;
    int y5 = 0;

    for (;;) {
        StartBatch();
        Clear(kColorBlack);
        DrawCircle(0, 0, 160, kColorGreen);
        DrawCircle(0, 0, 140, kColorGreen);
        DrawStar(x, y, 10, angleA, kColorGreen);
        DrawStar(x1, y1, 10, angleA, kColorGreen);
        DrawStar(x2, y2, 10, angleA, kColorGreen);
        DrawStar(x3, y3, 10, angleB, kColorGreen);
        DrawStar(x4, y4, 10, angleB, kColorGreen);
        DrawStar(x5, y5, 10, angleB, kColorGreen);
        MyDrawTriangle2(0, 0, 140, angleA, kColorGreen);
        MyDrawTriangle2(0, 0, 140, angleB, kColorGreen);
        DrawStar(0, 0, 50, angleA, kColorGreen);
        DrawStar(0, 0, 50, angleB, kColorGreen);
        EndBatch();
        x = (int)(cos(angleA) * 150);
        y = (int)(sin(angleA) * 150);
        x1 = (int)(cos(angleA + M_PI * 2 / 3) * 150);
        y1 = (int)(sin(angleA + M_PI * 2 / 3) * 150);
        x2 = (int)(cos(angleA - M_PI * 2 / 3) * 150);
        y2 = (int)(sin(angleA - M_PI * 2 / 3) * 150);
        x3 = (int)(cos(angleB) * 150);
        y3 = (int)(sin(angleB) * 150);
        x4 = (int)(cos(angleB + M_PI * 2 / 3) * 150);
        y4 = (int)(sin(angleB + M_PI * 2 / 3) * 150);
        x5 = (int)(cos(angleB - M_PI * 2 / 3) * 150);
        y5 = (int)(sin(angleB - M_PI * 2 / 3) * 150);
        
        angleA -= 0.01;
        angleB += 0.01;
    }
}

