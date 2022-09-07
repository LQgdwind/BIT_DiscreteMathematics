#include "bits/stdc++.h"
using namespace std;
int n, cnt, res;
int main()
{
	cin >> n;
	while (true)
	{
		res += n, cnt++;
		if (res % 18 == 0) break;//0是单位元，通过这一步求出最小的满足n的cnt次方=0的cnt值。
	}
	cout << cnt << endl;
	return 0;
}