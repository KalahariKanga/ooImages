#include "core.h"

float bilint(float topLeft, float topRight, float bottomLeft, float bottomRight, float x, float y)
{
	float top = topLeft + x*(topRight - topLeft);
	float bottom = bottomLeft + x*(bottomRight - bottomLeft);
	return top + y*(bottom - top);
}