#ifndef RANDOM_STRING_GENERATOR_H
#define RANDOM_STRING_GENERATOR_H

#include <string>

namespace rsg
{
	// Generator (main) class declaration
	class RandomStringGenerator;

	// Other names for the generator class (for ease of writing)
	using RandomString = RandomStringGenerator;
	using random_string = RandomStringGenerator;

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

	// Generator class implementation
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

		// Static method to get predefined charsets
		template<STRING_TYPE T>
		inline static const std::string GetCharset() { return ""; }
	};
	std::string RandomStringGenerator::s_Lowercase = "abcdefghijklmnopqrstuvwxyz";
	std::string RandomStringGenerator::s_Uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string RandomStringGenerator::s_Numerical = "1234567890";
	std::string RandomStringGenerator::s_Symbols = " .,\\/|_+=-@#!$%^&*()`~?><\"';:][{}";
	
#pragma region GET_CHARSET
#pragma region LOWER
	template<>
	inline const std::string RandomStringGenerator::GetCharset<STRING_TYPE::LOWER>()
	{
		return RandomStringGenerator::s_Lowercase;
	}
	template<>
	inline const std::string RandomStringGenerator::GetCharset<STRING_TYPE::LOWER_NUMERICAL>()
	{
		return RandomStringGenerator::s_Lowercase + RandomStringGenerator::s_Numerical;
	}
	template<>
	inline const std::string RandomStringGenerator::GetCharset<STRING_TYPE::LOWER_SYMBOLS>()
	{
		return RandomStringGenerator::s_Lowercase + RandomStringGenerator::s_Symbols;
	}
	template<>
	inline const std::string RandomStringGenerator::GetCharset<STRING_TYPE::LOWER_NUMERICAL_SYMBOLS>()
	{
		return RandomStringGenerator::s_Lowercase + RandomStringGenerator::s_Numerical + RandomStringGenerator::s_Symbols;
	}
#pragma endregion LOWER
#pragma region UPPER
	template<>
	inline const std::string RandomStringGenerator::GetCharset<STRING_TYPE::UPPER>()
	{
		return RandomStringGenerator::s_Uppercase;
	}
	template<>
	inline const std::string RandomStringGenerator::GetCharset<STRING_TYPE::UPPER_NUMERICAL>()
	{
		return RandomStringGenerator::s_Uppercase + RandomStringGenerator::s_Numerical;
	}
	template<>
	inline const std::string RandomStringGenerator::GetCharset<STRING_TYPE::UPPER_SYMBOLS>()
	{
		return RandomStringGenerator::s_Uppercase + RandomStringGenerator::s_Symbols;
	}
	template<>
	inline const std::string RandomStringGenerator::GetCharset<STRING_TYPE::UPPER_NUMERICAL_SYMBOLS>()
	{
		return RandomStringGenerator::s_Uppercase + RandomStringGenerator::s_Numerical + RandomStringGenerator::s_Symbols;
	}
#pragma endregion UPPER
#pragma region NUMERICAL
	template<>
	inline static const std::string RandomStringGenerator::GetCharset<STRING_TYPE::NUMERICAL>()
	{
		return RandomStringGenerator::s_Numerical;
	}
	template<>
	inline static const std::string RandomStringGenerator::GetCharset<STRING_TYPE::NUMERICAL_SYMBOLS>()
	{
		return RandomStringGenerator::s_Numerical + RandomStringGenerator::s_Symbols;
	}
#pragma endregion NUMERICAL
#pragma region SYMBOLS
	template<>
	inline static const std::string RandomStringGenerator::GetCharset<STRING_TYPE::SYMBOLS>()
	{
		return RandomStringGenerator::s_Symbols;
	}
#pragma endregion SYMBOLS
#pragma region ALPHA
	template<>
	inline const std::string RandomStringGenerator::GetCharset<STRING_TYPE::ALPHA>()
	{
		return RandomStringGenerator::s_Lowercase + RandomStringGenerator::s_Uppercase;
	}
	template<>
	inline const std::string RandomStringGenerator::GetCharset<STRING_TYPE::ALPHA_NUMERICAL>()
	{
		return RandomStringGenerator::s_Lowercase + RandomStringGenerator::s_Uppercase + RandomStringGenerator::s_Numerical;
	}
	template<>
	inline const std::string RandomStringGenerator::GetCharset<STRING_TYPE::ALPHA_SYMBOLS>()
	{
		return RandomStringGenerator::s_Lowercase + RandomStringGenerator::s_Uppercase + RandomStringGenerator::s_Symbols;
	}
	template<>
	inline const std::string RandomStringGenerator::GetCharset<STRING_TYPE::ALPHA_NUMERICAL_SYMBOLS>()
	{
		return RandomStringGenerator::s_Lowercase + RandomStringGenerator::s_Uppercase + RandomStringGenerator::s_Numerical + RandomStringGenerator::s_Symbols;
	}
#pragma endregion ALPHA
#pragma endregion GET_CHARSET
}
#endif
