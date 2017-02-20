#include "Int2.h"

Int2::Int2(int X, int Y)
{
	this->X = X;
	this->Y = Y;
}

void Int2::Set(Int2 value)
{
	this->X = value.X;
	this->Y = value.Y;
}
