#include <iostream>

enum Type { INTS, FLOATS, DOUBLE };
struct MyStruct
{
	Type s_type;
	union
	{
		int integer;
		float floatnum;
		double doublenum;
	};
};

void OverloadFunc(MyStruct StructUnion)
{
	switch (StructUnion.s_type)
	{
	case INTS:
		std::cout << "Integer\n";
		break;

	case FLOATS:
		std::cout << "Float\n";
		break;

	case DOUBLE:
		std::cout << "Double\n";
		break;
	default:
		std::cout << "Error Type\n";
		break;
	}
}

int main()
{
	MyStruct Struc;
	Struc.s_type = INTS;
	Struc.integer = 5;
	OverloadFunc(Struc);
}