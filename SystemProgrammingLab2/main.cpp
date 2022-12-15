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

template<std::forward_iterator Itor>
double no_tree_eval
(
	Itor begin,
	Itor dot_position,
	const Itor end,
	const double base
)
{
	const std::string int_part(begin, dot_position);
	const std::string frc_part(++dot_position, end);
	signed long long size = int_part.size() - 1;
	double res = 0.0;
	auto to_num = [](const char digit) { return static_cast<double>(digit - '0'); };

	for (auto it = int_part.begin(); it != int_part.end(); ++it, --size)
	{
		res += to_num(*it) * std::pow(base, size);
	}

	for (auto it = frc_part.begin(); it != frc_part.end(); ++it, --size)
	{
		res += to_num(*it) * std::pow(base, size);
	}

	return res;
}

int main()
{
	static const string eval = "eval";
	static const string set_state = "set";
	static const char* const sep = "-------------------------------------------------------";

	string input;
	regex eval_reg("eval[ ]+[01]+[.][01]+");
	regex set_reg("set[ ]+[0-9]+[.][0-9]+");
	regex set_phi("set phi");
	const double phi = (1 + sqrt(5)) / 2;

	double base = phi;
	bool is_phi = true;

	while (true)
	{
		cout << (is_phi ? "phi" : std::to_string(base)) << '>';
		std::getline(cin, input);

		auto it = input.begin();
		const auto en = input.end();

		if (regex_match(input, eval_reg))
		{
			cout << sep << '\n';
			for (; it != en && (*it == 'e' || *it == 'v' || *it == 'a' || *it == 'l' || *it == ' '); ++it);
			decltype(it) cp(it);
			auto ss = build_tree(it, std::find(cp, en, '.'), en, StandardEvaluator{ base });
			cout << "NO-TREE RESULT = " << no_tree_eval(it, std::find(cp, en, '.'), en, base) << '\n';
			cout << "TREE RESULT = " << dynamic_cast<const S&>(*ss).value() << '\n';
			cout << sep << '\n';
			cout << "TREE:\n";
			cout << *ss << '\n';
			cout << sep << '\n';
		}
		else if (regex_match(input, set_reg))
		{
			for (; it != en && (*it == 's' || *it == 'e' || *it == 't' || *it == ' '); ++it);
			string read(it, en);
			base = std::stod(read.c_str());
			is_phi = false;
		}
		else if (regex_match(input, set_phi))
		{
			double base = phi;
			bool is_phi = true;
		}
		else cout << "not matched :" << input << '\n';
	}

	/*while (true)
	{
		cin >> input;
		if(!regex_match(input, reg))
			break;
		
		auto ss = build_tree(input.begin(), std::find(input.begin(), input.end(), '.'), input.end(), StandardEvaluator{phi});
		cout << *ss << '\n';
	}*/

	return 0;
}