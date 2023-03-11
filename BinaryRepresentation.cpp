#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// Union 
union Union
{
	int i;
	float f;
};

int main()
{
	Union u;
	// Convert floating-point bits to integer:
	u.f = 3.14159f;
	printf("As integer: %08x\n", u.i);
}