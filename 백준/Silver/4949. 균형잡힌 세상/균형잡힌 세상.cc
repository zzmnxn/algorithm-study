#include <iostream>
#include <stack>
#include<string>
using namespace std;

bool balance(string str) {
	stack<char> p;
	for (char c : str) {
		if (c == '('|| c == '[')
			p.push(c);
		else if (c == ')' || c == ']') {
			if (p.empty())
				return false;
			char s = p.top();
			p.pop();
			if (s == '(' && c == ']')
				return false;
			if (s == '[' && c == ')')
				return false;
		}

	}
	return p.empty();
}

int main() {
	
	string str;
	while (true) {
		getline(cin, str);
		if (str == ".")
			break;
		if (balance(str))
			cout << "yes\n";
		else
			cout << "no\n";
		
	}

	return 0;
}