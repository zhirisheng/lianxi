#include <bits/stdc++.h>

using namespace std;

int money[100] = {0};
int s[100] = {0};
int check[100] = {0};
int main()
{
    memset(s, -1, 100);
    int n = 0, nn = 0, m = 0;
    char p[100] = {0};
    while (scanf("%d %d %d", &n, &nn, &m))
    {
        money[n] += m;
        s[nn] += m;
        check[n] = nn;
    }
    for (int i = 0; i < 100; i++)
    {
        if (s[i] == -1 && money[i] != 0)
        {
            while (check[i])
            {
                money[check[i]] += money[i] / 100 * 15;
                i = check[i];
            }
            cout << i << endl
                 << money[i];
            return 0;
        }
    }

    return 0;
}