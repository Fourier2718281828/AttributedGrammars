#include <iostream>
#include <regex>
#include <algorithm>
#include "StandardEvaluator.h"
#include "ExprTree.h"
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
	const double phi = (1 + sqrt(5)) / 2;
	while (true)
	{
		cin >> input;
		/*if(!regex_match(input, reg))
			break;*/
		auto a = processPart(input.begin(), input.end());
		//a->evaluate(StandardEvaluator{ phi });
		//cout << a->value() << '\n';
		//auto ss = build_tree(input.begin(), std::find(input.begin(), input.end(), '.'), input.end(), StandardEvaluator{phi});
		//const S& res = dynamic_cast<S&>(*ss);
		//cout << "res = " << res.value() << '\n';
	}

	return 0;
}