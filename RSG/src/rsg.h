#ifndef RANDOM_STRING_GENERATOR_H
#define RANDOM_STRING_GENERATOR_H

#include <string>

namespace rsg
{
	// Predefined charsets
	enum STRING_TYPE
	{
		NONE = -1,
		LOWER, UPPER, NUMERICAL, SYMBOLS,									// Basic charset of single type
		LOWER_NUMERICAL, LOWER_SYMBOLS, LOWER_NUMERICAL_SYMBOLS,			// Lowercase letters/~ with numbers/~ with symbols/~ with numbers and symbols
		UPPER_NUMERICAL, UPPER_SYMBOLS, UPPER_NUMERICAL_SYMBOLS,			// Uppercase letters/~ with numbers/~ with symbols/~ with numbers and symbols
		NUMERICAL_SYMBOLS,													// Digits and symbols charset
		ALPHA, ALPHA_NUMERICAL, ALPHA_SYMBOLS, ALPHA_NUMERICAL_SYMBOLS		// All letters/~ with numbers/~ with symbols/~ with numbers and symbols
	};

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
		// Random string generator from a custom charset
		RandomStringGenerator(std::string customCharset = "");
		// Random string generator from predefined charsets
		RandomStringGenerator(STRING_TYPE charsetType = STRING_TYPE::ALPHA);
		// Default destructor
		~RandomStringGenerator() = default;

		// Static methods to get predefined charsets
		// Get lowercase charset
		inline static const std::string GetLowercase() { return s_Lowercase; }
		template<int T>
		inline static const std::string GetCharset() { return ""; }
	};
	std::string RandomStringGenerator::s_Lowercase = "abcdefghijklmnopqrstuvwxyz";
	std::string RandomStringGenerator::s_Uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string RandomStringGenerator::s_Numerical = "1234567890";
	std::string RandomStringGenerator::s_Symbols = " .,\\/|_+=-@#!$%^&*()`~?><\"';:][{}";
	
	using RandomString = RandomStringGenerator;
	using random_string = RandomStringGenerator;
}
#endif
