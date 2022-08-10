#include <bits/stdc++.h>

using namespace std;

int num[1000] = {0};
int s = 0;
void func()
{
    int min = -1;
    int r1 = 0, r2 = 0;
    for (int i = 0; i < s; i++)
    {
        for (int j = i + 1; j < s; j++)
        {
            int ab = abs(num[i] + num[j]);
            cout << min << ":" << ab << endl;
            if (min == -1 || min > ab)
            {
                min = ab;
                r1 = num[i];
                r2 = num[j];
            }
        }
    }
    cout << endl
         << r1 << " " << r2 << " " << min;
}
int main()
{
    char input[1000] = {0};
    gets(input);
    int p = 0;
    int tmp = 0;
    int f = 1;
    while (input[p] != '\0')
    {
        if (input[p] == ' ')
        {
            p++;
            continue;
        }
        if (input[p] == '-')
        {
            f = -1;
            p++;
            continue;
        }
        tmp = tmp * 10 + (input[p] - '0');
        if (input[p + 1] == ' ' || input[p + 1] == '\0')
        {
            num[s++] = f * tmp;
            f = 1;
            tmp = 0;
        }
        p++;
    }

    func();
    cin >> input;
    return 0;
}