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