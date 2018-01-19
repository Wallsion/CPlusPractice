#include "stdafx.h"
#include <vector>
#include <stack>
using namespace std;
static string str[2] = { "Hello World!"," HELLO WORLD" };
char p[] = "hello world!";
int main(void)
{
	vector<string> strArr1(2, "");
	strArr1.insert(strArr1.begin(),str[0]);
	strArr1[1] = str[1];
	cout << strArr1[0] << " " << strArr1[1] << endl;
	string::reverse_iterator striter_r = str[0].rbegin();
	while (striter_r != str[0].rend())
	{
		cout << *striter_r;
		striter_r++;
	}
	const char *char_p = strArr1[0].c_str();
	cout << endl << *char_p << " " << sizeof(*char_p) << " " << sizeof(p);
	string test("");
	cout << endl << "´óÐ´¼ì²â~\n";
	stack<string> stack_str;
	for (int i = 0; i < strlen(char_p); i++)
	{
		if (isupper(*(char_p + i)))
			cout <<*(char_p + i) << "->" << (char)toupper(*(char_p + i)) << endl;
	}
	return 0;
}