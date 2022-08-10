#include <bits/stdc++.h>

using namespace std;

int d[100] = {0};
int p = 0;
int n = 0;
int s = 0;
void func()
{
    bool isa = false;
    for (int i = 0; i < s; i++)
    {
        if (d[i] == 1)
        {
            if (isa)
            {
                p = 1;
            }
            else
            {
                p++;
            }
        }
        else if (d[i] == 2)
        {
            if (isa)
            {
                n = p;
            }
        }
        else if (d[i] == 3)
        {
            if (isa)
            {
                n = p;
                p = 0;
            }
        }
        else if (d[i] == 4)
        {
            if (isa)
            {
                p = n;
                isa = false;
            }
            else
            {
                p = p + n;
            }
        }
        else if (d[i] == 5)
        {
            if (p)
            {
                isa = true;
            }
        }
        cout << "d:" << d[i] << "p:" << p << "n:" << n << endl;
    }
    cout << p;
}
int main()
{
    char input = getchar();
    while (input != '\n')
    {
        if (input != ' ')
        {
            d[s] = input - '0';
            s++;
        }
        input = getchar();
    }
    func();
    cin >> p;
    return 0;
}