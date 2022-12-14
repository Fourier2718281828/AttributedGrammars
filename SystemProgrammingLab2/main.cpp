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
using std::ostream;

ostream& operator<<(ostream& o, const INonTerminal& nt)
{
	return o << nt.view();
}

int main()
{
	string input;
	regex reg("[01]+[.][01]+");
	const double phi = (1 + sqrt(5)) / 2;
	while (true)
	{
		cin >> input;
		if(!regex_match(input, reg))
			break;
		
		auto ss = build_tree(input.begin(), std::find(input.begin(), input.end(), '.'), input.end(), StandardEvaluator{phi});
		cout << *ss << '\n';
		//const S& res = dynamic_cast<S&>(*ss);
		//cout << "res = " << res.value() << '\n';
	}

	return 0;
}