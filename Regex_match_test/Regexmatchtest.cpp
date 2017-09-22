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



	std::regex reg("[\\w]+");
	while (true)
	{
		std::cout << "Enter a string to split (q=quit): ";
		std::string str;
		if (!getline(std::cin, str) || str == "q")
			break;
		const std::sregex_token_iterator end;
		for (std::sregex_token_iterator iter(cbegin(str), cend(str), reg); iter != end;
			++iter)
		{
			std::cout << "\"" << *iter << "\"" << std::endl;
		}
	}

	std::regex reg("^(\\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])$");
	while (true)
	{
		std::cout << "Enter a data (yyyy/mm/dd) (q=quit): ";
		std::string str;
		if (!getline(std::cin, str) || str == "q")
		{
			break;
		}
		std::vector<int> indices{ 2,3 };
		const std::sregex_token_iterator end;
		for (std::sregex_token_iterator iter(cbegin(str), cend(str), reg, indices);
			iter != end;
			++iter)
		{
			std::cout << "\"" << *iter << "\"" << std::endl;
		}
	}


	std::regex reg(R"(\s*[,;]\s*)");
	while (true)
	{
		std::cout << "Enter a string to spilt on ',' and ';' (q=quit): ";
		std::string str;
		if (!getline(std::cin, str) || str == "q")
			break;
		const std::sregex_token_iterator end;
		for (std::sregex_token_iterator iter(cbegin(str), cend(str), reg, -1);
			iter != end; ++iter)
			std::cout << "\"" << *iter << "\"" << std::endl;
	}

	const std::string str("<body><h1>header</h1><p>some text</p></header>");
	std::regex r("<h1>(.*)</h1><p>(.*)</p>");
	const std::string format("H1=$1 and P=$2");
	std::string result = std::regex_replace(str, r, format,std::regex_constants::format_no_copy);
	std::cout << "Original string: '" << str << "'" << std::endl;
	std::cout << "New string: '" << result << "'" << std::endl;
	system("pause");
	*/
	std::regex reg("([\\w]+|[\\d]+)");
	const std::string format("$1\n");
	while (true)
	{
		std::cout << "Enter a string to split over multiple lines(q=quit): ";
		std::string str;
		if (!getline(std::cin, str) | str == "q")
			break;
		std::cout << std::regex_replace(str, reg, format
			,std::regex_constants::format_no_copy) << std::endl;
	}

}