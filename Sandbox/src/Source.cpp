#include <iostream>
#include <string>

#include "rsg.hpp"


int main()
{
	rsg::random_string rs;

	std::cout << /*rs.getCharset() << "\n\n" <<*/ rs(1000000);

	return 0;
}