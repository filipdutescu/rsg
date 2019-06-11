#include <iostream>

#include "rsg.h"


int main()
{
	rsg::random_string rs;
	std::cout << rsg::random_string::GetCharset<rsg::ALPHA_NUMERICAL_SYMBOLS>()
		<< "\n\n" << rs.getCharset() << "\t|\t" << rs.getLength()
		<< "\n\n";

	return 0;
}