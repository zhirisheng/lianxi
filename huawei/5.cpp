#include <bits/stdc++.h>

using namespace std;
char s[1000] = {0};

void func()
{
    char t = 'z';
    int pos = 0;
    int p = 0;
    for (int j = 0; j < strlen(s); j++)
    {
        t = s[j];
        for (int i = j + 1; i < strlen(s); i++)
        {
            if (s[i] < t)
            {
                t = s[i];
                pos = i;
            }
        }
        if (pos != 0)
        {
            p = j;
            break;
        }
    }
    cout << p << "," << pos << endl;
    if (pos != 0)
    {
        t = s[p];
        s[p] = s[pos];
        s[pos] = t;
    }
    cout << s << endl;
}

int main()
{
    cin >> s;
    func();
    cin >> s;
    return 0;
}