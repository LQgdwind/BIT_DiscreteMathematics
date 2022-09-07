#define _CRT_SECURE_NO_WARNINGS
#define loop(i,a,b) for(int i=a;i<=b;i++)

#include "iostream"
#include "vector"
#include "string"
#include "cstring";

using namespace std;

int front = 0;
int ed = 1;
int backjudge = 2;

vector<vector<int*>>s;
vector<int*>s0;
vector<int*>s1;
vector<int*>s2;

int space[100000][26];

int spacecnt = -1;

int add()
{
	if (spacecnt == 99999) spacecnt = 0;
	else spacecnt++;
	return spacecnt;
}

bool judge(int* x)
{
	int cnt = 0;
	loop(i, 0, 25)
	{
		if (x[i] == 0)cnt++;
	}
	//cout << cnt << endl;
	if (cnt == 26) return true;
	else return false;
}

bool judgesame(int* a)
{
	if (!s[front].empty())
		loop(i, 0, s[front].size() - 1)
	{
		loop(j, 0, 25)
		{
			if (s[front][i][j] != a[j])
			{
				break;
			}
			if (j == 25) return false;
		}
	}
	if (!s[ed].empty())
		loop(i, 0, s[ed].size() - 1)
	{
		loop(j, 0, 25)
		{
			if (s[ed][i][j] != a[j])
			{
				break;
			}
			if (j == 25) return false;
		}
	}
	return true;
}

int* res(int* a, int* b,bool &cntchange)
{
	int* c = space[add()];
	int cntcount = 0;
	loop(i, 0, 25)c[i] = a[i];
	loop(i, 0, 25)
	{
		int temp = c[i];
		c[i] = a[i] + b[i];
		if ((temp == 1 && c[i] == 0) || temp == -1 && c[i] == 0)
		{
			cntcount++;
		}
		if (c[i] > 1) c[i] = 1;
		else if (c[i] < -1) c[i] = -1;
	}
	if (cntcount > 1)cntchange = true;
	return c;
}
int main()
{
	
	s.push_back(s0);
	s.push_back(s1);
	s.push_back(s2);
	string input;
	cin >> input;
	int* temp = space[add()];
	loop(i, 0, 25) temp[i] = 0;
	loop(i, 0, input.size() - 1)
	{
		if (input[i] == '0')
		{
			cout << "NO" << endl;
			return 0;
		}
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			temp[input[i] - 'a'] += 1;
		}
		else if (input[i] == '!')
		{
			temp[input[++i] - 'a'] += -1;
		}
		else if (input[i] == '&')
		{
			s[ed].push_back(temp);
			temp = space[add()];
			loop(i, 0, 25) temp[i] = 0;
		}
		if (i == input.size() - 1)
		{
			s[ed].push_back(temp);
		}
	}
	do
	{
		if (backjudge == 2) backjudge = 0;
		else backjudge++;
		s[backjudge].clear();
		if (!s[front].empty() && !s[ed].empty())
		{
			loop(i, 0, s[front].size() - 1)
			{
				loop(j, 0, s[ed].size() - 1)
				{
					bool cntchange = false;
					temp = space[add()];
					temp = res(s[front][i], s[ed][j], cntchange);
					if (judge(temp)&&!cntchange)
					{
						cout << "NO" << endl;
						return 0;
					}
					if (judgesame(temp)&&!cntchange)
					{
						s[backjudge].push_back(temp);
					}
				}
			}
		}
		if (!s[ed].empty())
		{
			loop(i, 0, s[ed].size() - 1)
			{
				loop(j, i + 1, s[ed].size() - 1)
				{
					bool cntchange = false;
					temp = space[add()];
					temp = res(s[ed][i], s[ed][j], cntchange);
					if (judge(temp)&&!cntchange)
					{
						cout << "NO" << endl;
						return 0;
					}
					if (judgesame(temp)&&!cntchange)
					{
						s[backjudge].push_back(temp);
					}
				}
			}
		}
		front = ed;
		ed = backjudge;
		//cout << s2.size() << endl;
	} while (!s[backjudge].empty());
	cout << "YES" << endl;
	return 0;
}