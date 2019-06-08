#ifndef RANDOM_STRING_GENERATOR_H
#define RANDOM_STRING_GENERATOR_H

#include <string>

namespace rsg
{
	// Generator class declaration
	class RandomStringGenerator
	{
		// Static members
		static std::string s_Lowercase;			// Contains all lowercase letter characters
		static std::string s_Uppercase;			// Contains all uppercase letter characters
		static std::string s_Numerical;			// Contains all numerical characters
		static std::string s_Symbols;			// Contains all other symbols

		// Instance members
		std::string m_Custom;					// Contains an instance-based custom charset

	public:
		RandomStringGenerator();
		~RandomStringGenerator();
	};
	std::string RandomStringGenerator::s_Lowercase = "";
	std::string RandomStringGenerator::s_Uppercase = "";
	std::string RandomStringGenerator::s_Numerical = "";
	std::string RandomStringGenerator::s_Symbols = "";
	
	using RandomString = RandomStringGenerator;
}
#endif
