#include "color.h"

int get_gradient(int s, int e, float t)
{
	int r;
	int g;
	int b;
	int r_start;
	int g_start;
	int b_start;
	int r_end;
	int g_end;
	int b_end;

	t = pow(t, 1.5);
	r_start = (s >> 16) & 0xFF;
	r_end = (e >> 16) & 0xFF;
	g_start = (s >> 8) & 0xFF;
	g_end = (e >> 8) & 0xFF;
	b_start = s & 0xFF;
	b_end = e & 0xFF;
	r = r_start + (r_end  - r_start) * t;
	g = g_start + (g_end  - g_start) * t;
	b = b_start + (b_end  - b_start) * t;
	return ((r << 16) | (g << 8) | b);
}
void set_fire(int *palette)
{
	palette[0] = 0x00000000;
	palette[1] = 0x00FF0000;
	palette[2] = 0x00FFFF00;
	palette[3] = 0x00FFFFFF;
	palette[4] = 0x00FFFF00;
	palette[5] = 0x00FF0000;
	palette[6] = 0x00000000;
}
void set_rainbow(int *palette)
{
	palette[0] = 0x00FF0000;
	palette[1] = 0x00FFFF00;
	palette[2] = 0x0000FF00;
	palette[3] = 0x0000FFFF;
	palette[4] = 0x000000FF;
	palette[5] = 0x00FF00FF;
	palette[6] = 0x00FF0000;
}

void set_hotncold(int *palette)
{
	palette[0] = 0x00FFFFFF;
	palette[1] = 0x000066FF;
	palette[2] = 0x000000FF;
	palette[3] = 0x00333333;
	palette[4] = 0x00FF0080;
	palette[5] = 0x00FF00CC;
	palette[6] = 0x00FFFFFF;
}

void set_grayscale(int *palette)
{
	palette[0] = 0x00000000;
	palette[1] = 0x00555555;
	palette[2] = 0x00AAAAAA;
	palette[3] = 0x00FFFFFF;
	palette[4] = 0x00AAAAAA;
	palette[5] = 0x00555555;
	palette[6] = 0x00000000;
}
