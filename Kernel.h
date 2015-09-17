#pragma once
class Kernel
{
	int size;
	int *data;
public:
	Kernel(int size);
	~Kernel();

	int get(int x, int y);
	void set(int x, int y, int value);
};

