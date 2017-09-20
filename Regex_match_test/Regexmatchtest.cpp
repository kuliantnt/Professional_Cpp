// Regexmatchtest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main(int argc, char* argv)
{
	/**
	std::regex r("(\\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])");
	while(true)
	{
		std::cout << "Enter a date (year/month/day) (q=quit): ";
		std::string str;
		if (!std::getline(std::cin, str) || str == "q")
			break;
		std::smatch s;
		if (regex_match(str, s, r))
		{
			try {
				int year = std::stoi(s[1]);
				int month = std::stoi(s[2]);
				int day = std::stoi(s[3]);
				std::cout << "Valid data: "
					<< "year=" << year << ", month=" << month
					<< ",day=" << day
					<< std::endl;
			}
			catch (const std::invalid_argument& e) {
				std::cout << e.what() << std::endl;
			}

		}
		else
			std::cout << "Invalid data." << std::endl;
	}
	return 0;

	std::regex r("//\\s*(.+)$");
	while (true)
	{
		std::cout << "Enter a string with optional code comments (q=quit): ";
		std::string str;
		if (!getline(std::cin, str) || str == "q")
			break;
		std::smatch m;
		if (std::regex_search(str, m, r))
			std::cout << " Found comment " << m[1] << "'" << std::endl;
		else
			std::cout << " No comment found!" << std::endl;
	}
}
*/

	std::regex reg("[\\w]+");
	while (true)
	{
		std::cout << "Enter a string to split (q=quit): ";
		std::string str;
		if (!getline(std::cin, str) || str == "q")
			break;
		const std::sregex_iterator end;
		for (std::sregex_iterator iter(cbegin(str), cend(str), reg); iter != end;
			++iter)
		{
			std::cout << "\"" << (*iter)[0] << "\"" << std::endl;
		}
	}
}