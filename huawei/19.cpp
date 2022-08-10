#include <bits/stdc++.h>

using namespace std;

int pk[15] = {0};
bool isshun = false;
bool ishua = false;
int tiao()
{
    int p2 = 0, p3 = 0, p4 = 0;
    for (int i = 2; i < 15; i++)
    {
        if (pk[i] > 1000)
        {
            p4 = 1;
        }
        else if (pk[i] > 100)
        {
            p3 = 1;
        }
        else if (pk[i] > 10)
        {
            p2 = 1;
        }
    }
    if (p4)
    {
        return 2;
    }
    if (p2 && p3)
    {
        return 3;
    }
    if (p3)
    {
        return 6;
    }
    return 0;
}
bool shun()
{
    int flag = 0;
    for (int i = 2; i < 15; i++)
    {
        if ((pk[i] == 0 && flag != 0) || pk[i] > 4)
        {
            // cout << i << " not shun" << endl;
            return false;
        }
        else if (pk[i] != 0)
        {
            if (i == 2)
            {
                if (pk[14] != 0)
                {
                    flag++;
                }
            }
            flag++;
        }
        // cout << i << ":" << flag << endl;
        if (flag == 5)
        {
            isshun = true;
            return true;
        }
    }
}
bool hua()
{
    int h = 0;
    for (int i = 2; i < 14; i++)
    {
        if (pk[i] != 0)
        {
            if (pk[i] > 10)
            {
                return false;
            }
            if (h == 0)
            {
                h = pk[i];
            }
            else if (h != pk[i])
            {
                return false;
            }
        }
    }
    ishua = true;
    return true;
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        char c1;
        int p = 0, h = 0;
        cin >> c1;
        if (c1 >= '2' && c1 <= '9')
        {
            p = c1 - '0';
        }
        else if (c1 == '1')
        {
            p = 10;
            cin >> c1;
        }
        else if (c1 == 'J')
        {
            p = 11;
        }
        else if (c1 == 'Q')
        {
            p = 12;
        }
        else if (c1 == 'K')
        {
            p = 13;
        }
        else if (c1 == 'A')
        {
            p = 14;
        }

        cin >> c1;

        if (c1 == 'H')
        {
            h = 1;
        }
        else if (c1 == 'S')
        {
            h = 2;
        }
        else if (c1 == 'C')
        {
            h = 3;
        }
        else if (c1 == 'D')
        {
            h = 4;
        }
        pk[p] = pk[p] * 10 + h;
    }

    // for (int i = 2; i < 15; i++)
    // {
    //     if (pk[i] != 0)
    //     {
    //         cout << i << ":" << pk[i] << endl;
    //     }
    // }
    if (hua() && shun())
    {
        cout << 1 << endl;
    }
    else if (tiao() == 2 || tiao() == 3)
    {
        cout << tiao() << endl;
    }
    else if (hua())
    {
        cout << 4 << endl;
    }
    else if (shun())
    {
        cout << 5 << endl;
    }
    else if (tiao())
    {
        cout << tiao() << endl;
    }
    else
    {
        cout << "xiao pai" << endl;
    }
    // cout << ishua << " " << isshun << endl;
    cin >> pk[1];
    return 0;
}