#include "bits/stdc++.h"
using namespace std;
const int N = 50; char aa[N];bool ta[N];int cvt[N],va[N];
int order(char c)
{
    switch (c)
    {
    case '#': return -1;case '(': return 0;case '+': return 1;case '-':  return 2;case '|': return 3;case '&': return 4;case '!': return 5;default: return 0;
    }
}
  void postfix()
{
    char post[N] = { '\0' }, sa[N] = { '#' };int in = -1, sub = 0, len = strlen(aa);
    for (int i = 0; i < len; i++)
    {
        if (aa[i] >= 'a' && aa[i] <= 'z')
        {
            post[++in] = aa[i];
            continue;
        }
        if (aa[i] == '!' || aa[i] == '&' || aa[i] == '|' || aa[i] == '-' || aa[i] == '+')
        {
            while (order(aa[i]) <= order(sa[sub]))
                post[++in] = sa[sub--];
            sa[++sub] = aa[i];
            continue;
        }
        if (aa[i] == '(')
        {
            sa[++sub] = aa[i];
            continue;
        }
        if (aa[i] == ')')
        {
            while (sa[sub] != '(')
                post[++in] = sa[sub--];
            sub--;
            continue;
        }
    }
    while (sub) post[++in] = sa[sub--];
    strcpy(aa, post);
}
  int btoi()
{
    int sum = 0, weight = 1;
    for (int i = 25; i >= 0; i--)
        if (ta[i])
        {
            if (cvt[i]) sum += weight;
            weight *= 2;
        }
    return sum;
}
  int calc(int a, int b, char c)
{
    switch (c)
    {
    case '&': return a * b;case '|': if (a + b) return 1; else return 0;case '-': if (a == 1 && b == 0) return 0; else return 1;case '+': return !((a + b) & 1);
    }
}
  int work()
{
    int sa[N], ps = -1;int len = strlen(aa);
    for (int i = 0; i < len; i++)
    {
        if (aa[i] >= 'a' && aa[i] <= 'z')
        {
            sa[++ps] = cvt[aa[i] - 'a']; continue;
        }
        if (aa[i] == '!')
        {
            sa[ps] = (sa[ps] + 1) & 1; continue;
        }
        int ans = calc(sa[ps - 1], sa[ps], aa[i]);
        sa[--ps] = ans;
    }
    return sa[0];
}
  void assign()
{
    int x = btoi();int ans = work(); va[x] = ans;
}
  void generate(char c)
{
    while (c <= 'z' && ta[c - 'a'] == false) c++;
    if (c > 'z')
    {
        assign();return;
    }
    cvt[c - 'a'] = 0, generate(c + 1);cvt[c - 'a'] = 1, generate(c + 1);
}
  int set_order()
{
    int v = 0,len = strlen(aa);memset(ta, 0, sizeof(ta));
    for (int i = 0; i < len; i++)
        if (aa[i] >= 'a' && aa[i] < 'z')
            ta[aa[i] - 'a'] = true;
    for (int i = 0; i < 26; i++)
        if (ta[i])
            v++;
    v = pow(2, v);return v;
}
  void outDis(int sum)
{
    int i = 0;
    while (i < sum && !va[i]) i++;
    if (i >= sum)
    {
        cout<<"0 ; "; return;
    }
    printf("m%d", i);
    for (i++; i < sum; i++)
        if (va[i]) printf(" ¡Å m%d", i);
    cout<<" ; ";
}
  void outCon(int sum)
{
    int i = 0;while (i < sum && va[i]) i++;
    if (i >= sum)
    {
        printf("1\n");return;
    }
    printf("M%d", i);
    for (i++; i < sum; i++)
        if (!va[i]) printf(" ¡Ä M%d", i);
    cout.put('\n');
}
  void result(int sum)
{
    generate('a'),outDis(sum),outCon(sum);
}
int main()
{
    cin.getline(aa, 10000), postfix();
    int sum = set_order();result(sum);
    return 0;
}
