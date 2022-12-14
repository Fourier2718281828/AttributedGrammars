#include <iostream>
#include <regex>
#include <algorithm>
#include "ExprTree.h"
#include "StandardEvaluator.h"
using std::cout;
using std::cin;
using std::string;
using std::regex;
using std::regex_match;
using std::find;

int main()
{
	string input;
	regex reg("[01]+[.][01]+");
	while (true)
	{
		cin >> input;
		if(!regex_match(input, reg))
			break;
		build_tree(input.begin(), std::find(input.begin(), input.end(), '.'), input.end(), StandardEvaluator{});
	}
	return 0;
}