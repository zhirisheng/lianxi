#include <bits/stdc++.h>

using namespace std;
char str1[100] = {0};
char str2[1000] = {0};
int check[100] = {0};
int main()
{
    cin >> str1;
    cin >> str2;
    int pos = -1;
    int time = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    // cout << len1 << "," << len2;
    for (int i = 0; i < len2; i++)
    {
        for (int j = 0; j < len1; j++)
        {
            if (str1[j] == str2[i])
            {
                cout << j << ":" << str1[j] << ",time:" << time << endl;
                if (!check[j])
                {
                    if (pos == -1)
                    {
                        pos = i;
                    }
                    check[j] = 1;
                    time++;
                    break;
                }
            }
            if (j + 1 == len1)
            {
                if (pos != -1)
                {
                    i = pos + 1;
                    pos = -1;
                    time = 0;
                    memset(check, 0, 100);
                }
            }
        }
        if (time == len1)
        {
            break;
        }
    }
    if (time == len1)
    {
        cout << pos;
    }
    else
    {
        cout << -1;
    }
    cin >> pos;
    return 0;
}