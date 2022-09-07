#pragma GCC optimize(3,"Ofast","inline")
#define re register

#include "bits/stdc++.h"

using namespace std;

int graph[20][20];

int main()
{
	string temp;
	int row = 0;
	while (getline(cin, temp))
	{
		row++;
		int len = (int)temp.size();
		for (int i = 0,cnt=1; i < len; i = i + 2,cnt++)
		{
			graph[row][cnt] = temp[i] - '0';
		}
	}
	for (re int k = 1; k <= row; k++)
	{
		for (re int i = 1; i <= row; i++)
		{
			for (re int j = 1; j <= row; j++)
			{
				if (graph[i][k] == graph[k][j] && graph[i][k] == 1)
				{
					graph[i][j] = 1;
				}
			}
		}
	}
	for (re int i = 1; i <= row; i++)
	{
		for (re int j = 1; j <= row; j++)
		{
			cout << graph[i][j];
			if (j == row)cout << endl;
			else cout << ' ';
		}
	}
}
