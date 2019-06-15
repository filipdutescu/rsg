#include "rsg.h"

// To remove
#include <iostream>

namespace rsg
{
	std::string RandomStringGenerator::s_Lowercase = "abcdefghijklmnopqrstuvwxyz";
	std::string RandomStringGenerator::s_Uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string RandomStringGenerator::s_Numerical = "1234567890";
	std::string RandomStringGenerator::s_Symbols = " .,\\/|_+=-@#!$%^&*()`~?><\"';:][{}";

	RandomStringGenerator::RandomStringGenerator(std::string customCharset)
	{
		m_Custom = customCharset;
	}

	RandomStringGenerator::RandomStringGenerator(STRING_TYPE charsetType)
	{
		switch (charsetType)
		{
		case STRING_TYPE::LOWER:                        m_Custom = s_Lowercase;                                             break;
		case STRING_TYPE::UPPER:                        m_Custom = s_Uppercase;                                             break;
		case STRING_TYPE::NUMERICAL:                    m_Custom = s_Numerical;                                             break;
		case STRING_TYPE::SYMBOLS:                      m_Custom = s_Symbols;                                               break;
		case STRING_TYPE::LOWER_NUMERICAL:              m_Custom = s_Lowercase + s_Numerical;                               break;
		case STRING_TYPE::LOWER_SYMBOLS:                m_Custom = s_Lowercase + s_Symbols;                                 break;
		case STRING_TYPE::LOWER_NUMERICAL_SYMBOLS:      m_Custom = s_Lowercase + s_Numerical + s_Symbols;                   break;
		case STRING_TYPE::UPPER_NUMERICAL:              m_Custom = s_Uppercase + s_Numerical;                               break;
		case STRING_TYPE::UPPER_SYMBOLS:                m_Custom = s_Uppercase + s_Symbols;                                 break;
		case STRING_TYPE::UPPER_NUMERICAL_SYMBOLS:      m_Custom = s_Uppercase + s_Numerical + s_Symbols;                   break;
		case STRING_TYPE::NUMERICAL_SYMBOLS:            m_Custom = s_Numerical + s_Symbols;                                 break;
		case STRING_TYPE::ALPHA:                        m_Custom = s_Lowercase + s_Uppercase;                               break;
		case STRING_TYPE::ALPHA_NUMERICAL:              m_Custom = s_Lowercase + s_Uppercase + s_Numerical;                 break;
		case STRING_TYPE::ALPHA_SYMBOLS:                m_Custom = s_Lowercase + s_Uppercase + s_Symbols;                   break;
		case STRING_TYPE::ALPHA_NUMERICAL_SYMBOLS:      m_Custom = s_Lowercase + s_Uppercase + s_Numerical + s_Symbols;     break;
		default:                                        m_Custom = "";                                                      break;
		}
	}
	std::string RandomStringGenerator::operator()(int stringLength)
	{
		if (stringLength < 1) throw new std::exception("String length must be a non-zero positive integer.");

		std::random_device rd;
		std::mt19937 engine(rd());
		std::uniform_int_distribution<> rng(0, stringLength);

		std::string result = "";
		for (int i = 0; i < stringLength; ++i)
			result += m_Custom[rng(engine)];

		return result;
	}

	std::string RandomStringGenerator::operator()(int stringLength, std::uniform_int_distribution<> rng)
	{
		if (stringLength < 1) throw new std::exception("String length must be a non-zero positive integer.");

		return std::string();
	}
}
