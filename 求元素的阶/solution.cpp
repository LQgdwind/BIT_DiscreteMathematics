#include "bits/stdc++.h"
using namespace std;
int n, cnt, res;
int main()
{
	cin >> n;
	while (true)
	{
		res += n, cnt++;
		if (res % 18 == 0) break;//0�ǵ�λԪ��ͨ����һ�������С������n��cnt�η�=0��cntֵ��
	}
	cout << cnt << endl;
	return 0;
}