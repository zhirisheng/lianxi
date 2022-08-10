#include <bits/stdc++.h>

using namespace std;

int num[100] = {0};
int s = 0;

void func()
{
    int result = -1;
    int tmp = 0;
    int pos = 0;
    for (int i = 1; i < s / 2; i++)
    {
        pos += i;
        tmp += 1;
        while (pos <= s - 1)
        {
            // cout << "s:" << s << "i:" << i << "pos:" << pos
            //      << "pos + num[pos]:" << pos + num[pos] << endl;
            if (pos + num[pos] < s - 1)
            {
                // cout << "pos + num[pos] < s - 1";
                tmp += 1;
                pos += num[pos];
                cout << "result1:" << result << ",tmp:" << tmp << endl;
            }
            else if (pos + num[pos] == s - 1)
            {
                cout << "i:" << i << ",result:" << result << ",tmp:" << tmp << endl;
                if (result == -1 || result > tmp)
                {
                    result = tmp + 1;
                }
                break;
            }
            else
            {
                break;
            }
        }
        pos = 0;
        tmp = 0;
    }
    cout << result << endl;
}
int main()
{
    char input = getchar();
    while (input != '\n')
    {
        if (input == ' ')
        {
            input = getchar();
            continue;
        }
        num[s] = num[s] * 10 + (input - '0');
        input = getchar();
        if (input == ' ' || input == '\n')
        {
            // cout << s << ":" << num[s] << endl;
            s++;
        }
    }
    func();
    // for (int i = 0; i < s; i++)
    // {
    //     cout << i << ":" << num[i] << endl;
    // }
    cin >> s;
    return 0;
}