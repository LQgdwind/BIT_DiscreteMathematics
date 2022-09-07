#include "bits/stdc++.h"
using namespace std;
unordered_map <string, string> hashm;string input;
int main()
{
	//由题意我们知道，在这个代数结构中单位元是f1;
	hashm.insert({ "f1","f1" });//f1的逆元是其本身;
	hashm.insert({ "f2","f2" });//f2的逆元是其本身;
	hashm.insert({ "f3","f3" });//f3的逆元是其本身;
	hashm.insert({ "f4","f5" });//f4的逆元是f5;
	hashm.insert({ "f5","f4" });//f5的逆元是f4;
	hashm.insert({ "f6","f6" });//f6的逆元是其本身;
	getline(cin, input),cout << hashm[input] << endl;
}