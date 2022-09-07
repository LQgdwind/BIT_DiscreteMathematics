#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;
typedef pair<int, int> PII;
int e[M], ne[M], h[N], idx, n, m, st[N], graph[110][110];
void add(int a, int b) 
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool bfs(int u) 
{
    int hh = 0, tt = 0;
    PII q[N];
    q[0] = { u, 1 };
    st[u] = 1;
    while (hh <= tt)
    {
        auto t = q[hh++];
        int ver = t.first, c = t.second;
        for (int i = h[ver]; i != -1; i = ne[i]) 
        {
            int j = e[i];
            if (!st[j])
            {
                st[j] = 3 - c;
                q[++tt] = { j, 3 - c };
            }
            else if (st[j] == c) return false;
        }
    }
    return true;
}
int main() 
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
            for (int k = 1; k <= graph[i][j];k++)
                add(i, j);
        }
    int flag = true;
    for (int i = 1; i <= n; i++) 
        if (!st[i]) 
            if (!bfs(i)) 
            {
                flag = false;
                break;
            }
    if (flag) puts("yes");
    else puts("no");
    return 0;
}
