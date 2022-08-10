#include <bits/stdc++.h>

using namespace std;

int len = 0;
int num = 0;
int pos[1000] = {0};
int pn[1000] = {0};
int arr[1000][100] = {0};

void func()
{
    int finish = 0;
    int sum = 0;
    int s = 0;
    int result[100000] = {0};
    // for (int i = 0; i < num; i++)
    // {
    //     sum += pn[i];
    // }

    while (finish != num)
    {
        for (int i = 0; i < num; i++)
        {
            // cout << "i-pn:" << pn[i] << endl;
            if (pn[i] == -1)
            {
                continue;
            }
            for (int j = 0; j < len; j++)
            {
                if (pos[i] < pn[i])
                {
                    result[s++] = arr[i][pos[i]];
                    pos[i] += 1;
                }
                else
                {
                    pn[i] = -1;
                    finish++;
                    break;
                }
            }
        }
        cout << finish << endl;
    }
    for (int i = 0; i < s; i++)
    {
        cout << result[i] << ",";
    }
}
int main()
{
    cin >> len;
    cin >> num;
    getchar();
    char input[1000] = {};
    for (int i = 0; i < num; i++)
    {
        memset(input, 0, 1000);
        gets(input);
        int p = 0;
        int tmp = 0;
        while (input[p] != '\0')
        {
            if (input[p] == ',')
            {
                p++;
                continue;
            }
            tmp = tmp * 10 + (input[p] - '0');
            if (input[p + 1] == ',' || input[p + 1] == '\0')
            {
                arr[i][pn[i]] = tmp;
                // cout << "in:" << tmp << ",";
                pn[i]++;
                tmp = 0;
            }
            p++;
        }
        // cout << endl;
    }
    func();
    cin >> len;
    return 0;
}