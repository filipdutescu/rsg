#include <iostream>
#include <string>
#include <map>
#include <iomanip>

#include "rsg.h"


int main()
{
	rsg::random_string rs;
	std::cout << rsg::random_string::GetCharset<rsg::ALPHA_NUMERICAL_SYMBOLS>()
		<< "\n\n" << rs.getCharset()
		<< "\n\n" << rs(3);

	return 0;
}