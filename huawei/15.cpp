#include <bits/stdc++.h>

using namespace std;

int num[6] = {0};
int check[6] = {0};
void func()
{
    int n1 = -1, n2 = -1, n3 = -1, n4 = -1, n5 = -1, n6 = -1;
    int p1 = 0, p2 = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == j)
            {
                continue;
            }
            int tmp = num[i] * 10 + num[j];
            if (tmp < 24)
            {
                if (tmp >= n1 * 10 + n2)
                {
                    n1 = num[i];
                    n2 = num[j];
                    p1 = i;
                    p2 = j;
                }
            }
        }
    }
    if (p1 == 0 && p2 == 0)
    {
        cout << "invalid";
        return;
    }
    check[p1] = 1;
    check[p2] = 1;
    p1 = 0;
    p2 = 0;
    for (int i = 0; i < 6; i++)
    {
        if (check[i])
        {
            continue;
        }
        for (int j = 0; j < 6; j++)
        {
            if (check[j])
            {
                continue;
            }
            if (i == j)
            {
                continue;
            }
            int tmp = num[i] * 10 + num[j];
            if (tmp < 60)
            {
                if (tmp >= n3 * 10 + n4)
                {
                    n3 = num[i];
                    n4 = num[j];
                    p1 = i;
                    p2 = j;
                }
            }
        }
    }
    if (p1 == 0 && p2 == 0)
    {
        cout << "invalid";
        return;
    }
    check[p1] = 1;
    check[p2] = 1;
    p1 = 0;
    p2 = 0;
    for (int i = 0; i < 6; i++)
    {
        if (check[i])
        {
            continue;
        }
        for (int j = 0; j < 6; j++)
        {
            if (check[j])
            {
                continue;
            }
            if (i == j)
            {
                continue;
            }
            int tmp = num[i] * 10 + num[j];
            if (tmp < 60)
            {
                if (tmp >= n5 * 10 + n6)
                {
                    n5 = num[i];
                    n6 = num[j];
                    p1 = i;
                    p2 = j;
                }
            }
        }
    }
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << i << ":" << check[i] << " ";
    // }
    // cout << endl;
    if (p1 != p2)
    {
        printf("%d%d:%d%d:%d%d", n1, n2, n3, n4, n5, n6);
    }
    else
    {
        cout << "invalid";
    }
}

int main()
{
    char input[12] = {0};
    gets(input);
    sscanf(input, "[%d,%d,%d,%d,%d,%d]",
           &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);

    // for (int i = 0; i < 6; i++)
    // {
    //     cout << num[i] << endl;
    // }

    func();
    cin >> input;
}