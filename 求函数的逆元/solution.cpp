#include "bits/stdc++.h"
using namespace std;
unordered_map <string, string> hashm;string input;
int main()
{
	//����������֪��������������ṹ�е�λԪ��f1;
	hashm.insert({ "f1","f1" });//f1����Ԫ���䱾��;
	hashm.insert({ "f2","f2" });//f2����Ԫ���䱾��;
	hashm.insert({ "f3","f3" });//f3����Ԫ���䱾��;
	hashm.insert({ "f4","f5" });//f4����Ԫ��f5;
	hashm.insert({ "f5","f4" });//f5����Ԫ��f4;
	hashm.insert({ "f6","f6" });//f6����Ԫ���䱾��;
	getline(cin, input),cout << hashm[input] << endl;
}