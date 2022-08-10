#include <bits/stdc++.h>

using namespace std;

list<int> s;

int main()
{
    char input = getchar();
    int r = 0;
    while (input != '\n')
    {
        if (input == ' ')
        {
        CONTINUE:
            input = getchar();
            continue;
        }
        if (s.empty())
        {
            s.push_back(input - '0');
            input = getchar();
            continue;
        }
        else
        {
            int sum = 0;
            for (auto it = s.begin(); it != s.end(); it++)
            {
                sum += *it;
                cout << *it << ",sum:" << sum << ",input:" << input << endl;
                if (sum == input - '0')
                {
                    for (auto i = it; i != s.begin();)
                    {
                        s.erase(i--);
                    }
                    s.erase(s.begin());
                    s.push_front(sum * 2);
                    goto CONTINUE;
                }
                else if (sum > input - '0')
                {
                    goto PUSH;
                }
            }
        PUSH:
            s.push_front(input - '0');
            input = getchar();
        }
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    // cout << s.back();
    cin >> input;
    return 0;
}