#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int node, rudu[N], chudu[N];
inline void add(char a0, char b0)
{
	int a = a0 - 'a', b = b0 - 'a';
	rudu[b]++,chudu[a]++;
}
int main()
{
	string temp;
	getline(cin, temp);
	node = (temp.size() + 1) >> 1;
	char ch = ' ';
	while (ch != '\n')
	{
		char a, b;
		scanf("<%c,%c>", &a, &b);
		add(a, b);
		ch = cin.get();
	}
	bool judge = false;
	for (int i = 0; i < node; i++)
	{
		if (rudu[i] == 0 && judge == false) cout << (char)('a' + i), judge = true;
		else if (rudu[i] == 0 && judge) cout << "," << (char)('a' + i);
	}
	cout.put('\n');judge = false;
	for (int i = 0; i < node; i++)
	{
		if (chudu[i] == 0 && judge == false) cout << (char)('a' + i), judge = true;
		else if (chudu[i] == 0 && judge) cout << "," << (char)('a' + i);
	}
	cout.put('\n');
	return 0;
}