#pragma once

/*
 * An X and Y position, defined by integers.
 */
struct Int2
{
public:
	int X;
	int Y;

	Int2(int X, int Y);

	void Set(Int2 value);
};
