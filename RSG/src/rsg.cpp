#include "rsg.h"

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

		return std::string();
	}
}
