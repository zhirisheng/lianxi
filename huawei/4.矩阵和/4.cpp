#include <bits/stdc++.h>

using namespace std;
int size = 0;
int mx[20][20] = {0};
int sum_bin(int pos, int pr)
{
    int re = 0;
    for (int i = 0; i < size; i++)
    {
        if (i + pos < size)
        {
            re = mx[pr][i + pos] + re * 2;
            cout << mx[pr][i + pos] << ",";
        }
        else if (i + pos >= size)
        {
            re = mx[pr][i + pos - size] + re * 2;
            cout << mx[pr][i + pos - size] << ",";
        }
    }
    cout << endl;
    return re;
}
void func()
{
    int sum = 0, result = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (mx[i][j])
            {
                int tmp = sum_bin(j, i);
                if (sum < tmp)
                {
                    sum = tmp;
                }
            }
        }
        cout << "sum" << i << ":" << sum << endl;
        result += sum;
        sum = 0;
    }
    cout << "result:" << result << endl;
}

int main()
{
    cin >> size;
    // cout << size << endl;
    char input[100];
    for (int i = 0; i < size; i++)
    {
        cin >> input;
        for (int j = 0; j < size; j++)
        {
            mx[i][j] = input[j * 2] - '0';
        }
        memset(input, 0, 100);
    }
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         cout << mx[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    func();
    cin >> size;
    return 0;
}