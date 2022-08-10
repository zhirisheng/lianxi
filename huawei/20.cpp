#include <bits/stdc++.h>

using namespace std;

struct player
{
    int no = -1;
    int count[100] = {0};
    int all = 0;
    int result = 0;
};

bool cmp2(int a, int b)
{
    return a > b;
}
bool cmp(player a, player b)
{
    if (a.result == b.result)
    {
        return a.no > b.no;
    }
    else
        return a.result > b.result;
}

int main()
{
    int n;
    int m = 0;
    cin >> n;
    int *no = (int *)malloc(sizeof(int) * n);
    int *cnt = (int *)malloc(sizeof(int) * n);
    // player *p = (player *)malloc(sizeof(player) * n);
    player p[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &no[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cnt[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (p[j].all == 0)
            {
                p[j].all++;
                p[j].count[0] = cnt[i];
                p[j].no = no[i];
                m++;
                break;
            }
            else if (p[j].no == no[i])
            {
                p[j].count[p[j].all] = cnt[i];
                p[j].all++;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        sort(p[i].count, p[i].count + p[i].all, cmp2);
        int result = 0;
        for (int j = 0; j < p[i].all; j++)
        {
            // cout << i << ":" << p[i].count[j] << endl;
            if (j == 3)
            {
                break;
            }
            result += p[i].count[j];
        }
        p[i].result = result;
    }

    sort(p, p + 100, cmp);
    for (int i = 0; i < m; i++)
    {
        if (p[i].all < 3)
        {
            continue;
        }
        cout << p[i].no << ":" << p[i].result << endl;
    }
    cin >> n;
    return 0;
}