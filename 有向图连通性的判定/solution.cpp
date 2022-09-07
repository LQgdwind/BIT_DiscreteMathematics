#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 10;
int graph[N][N];

int n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> graph[i][j];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for (int j = 1; j <= n; j++)
				if (graph[i][k] > 0 && graph[k][j] > 0)
					graph[i][j] = 1;
	bool panqiangliantong = true;
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (graph[i][j] == 0) panqiangliantong = false;
		}
	if (panqiangliantong)
	{
		cout.put('A').put('\n');
		return 0;
	}
	bool pandanliantong = true;
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (graph[i][j] == 0 && graph[j][i] == 0) pandanliantong = false;
		}
	if (pandanliantong)
	{
		cout.put('B').put('\n');
		return 0;
	}
	cout.put('C').put('\n');
	return 0;
}