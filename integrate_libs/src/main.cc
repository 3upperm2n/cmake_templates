#include <iostream>
#include "hello/hello.h"
#include "world/world.h"

int main(int argc, char *argv[])
{
	hello("hello");
	world("world");
	
	std::cout << "well done" << std::endl;

	return 0;	
}
