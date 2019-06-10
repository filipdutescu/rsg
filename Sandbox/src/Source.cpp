#include <iostream>

#include "rsg.h"

int main()
{
	std::cout << rsg::random_string::GetCharset<rsg::ALPHA_NUMERICAL_SYMBOLS>() << "\n\n";

	return 0;
}