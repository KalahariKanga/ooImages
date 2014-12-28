#include "core.h"
bool and(bool a, bool b)
{
	return (a&&b);
}
bool or(bool a, bool b)
{
	return (a || b);
}
bool nand(bool a, bool b)
{
	return !(a&&b);
}
bool xor(bool a, bool b)
{
	return (a || b) && !(a&&b);
}
bool not(bool a)
{
	return !a;
}
float distance(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}