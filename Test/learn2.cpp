#include "stdafx.h"
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <list>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

int main(void)
{
	vector<int> intvector1(5, 0);
	pair<string, string> anon("Name", "Wangxin");
	pair<string, int> word_count("Number1", 10);
	pair<string, vector<int> > line("module1", intvector1);//pair 容器提供了成对存储的功能
	map<string, int> mapWordCount;
	mapWordCount["age"] = 24;
	mapWordCount["income"] = 200000;
	map<string, int>::iterator mapIt = mapWordCount.begin();
	cout << mapIt->first << " " << mapIt->second << endl;
	cout << mapWordCount["age"] << " " << endl;
	mapWordCount.insert(make_pair("ID", 341203));
	pair < map<string, int>::iterator, bool> ret = mapWordCount.insert(make_pair("GID", 16225316));//键在map中返回false，不在里面返回True
	cout << ret.second << endl;
	cout << mapWordCount.count("ID") << " " << mapWordCount.find("age")->second << endl;
	map<string, int>::iterator insertit = mapWordCount.find("height");
	if (insertit == mapWordCount.end())
		mapWordCount.insert(map<string, int>::value_type("height", 180));
	mapWordCount.erase("GID");
	multimap<int, string> num2char;
	num2char.insert(make_pair(1, "one"));
	num2char.insert(make_pair(1, "first"));
	num2char.insert(make_pair(1, "top"));
	multimap<int, string>::size_type keynum = num2char.count(1);
	multimap<int, string>::iterator multiiter = num2char.find(1);
	for (int i = 0; i < keynum; i++, multiiter++)
	{
		cout << multiiter->first << ":" << multiiter->second << endl;
	}
	multimap<int, string>::iterator beg = num2char.lower_bound(1);
	multimap<int, string>::iterator end = num2char.upper_bound(1);
	while (beg != end)
	{
		cout << beg->second << endl;
		beg++;
	}
	pair<multimap<int, string>::iterator, multimap<int, string>::iterator > pos = num2char.equal_range(1);
	int r1[5] = { 1,2,3,4,5 };
	int r2[3] = { 4,1,2 };
	vector<int> roster1(r1, r1 + 5);
	vector<int> roster2(r2, r2 + 3);
	vector<int>::iterator rosteriter = roster1.begin();
	int cnt = 0;
	while ((rosteriter = find_first_of(rosteriter, roster1.end(), roster2.begin(), roster2.end())) != roster1.end())
	{
		cnt++;
		rosteriter++;
	}
	list<int> lList(r1, r1 + 5);
	list<int>::iterator it = find(lList.begin(), lList.end(), 2);
	cout << *it;
	ostream_iterator<string> out_iter(cout, "\n");
	istream_iterator<string> in_iter(cin), eof;
	int i = 0;
	while (in_iter != eof && i != 1)
	{
		*out_iter++ = *in_iter++;
		i++;
	}
	return 0;
}
