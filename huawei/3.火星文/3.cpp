#include <bits/stdc++.h>

using namespace std;

char qst[200] = {0};
int len = 0;
int fh[200] = {0};
int nums[200] = {0};
int n[200] = {0};
int s1 = 0;
int s2 = 0;
int t1 = 0;
int t2 = 0;
int result = 0;

int func_j(int x, int y)
{
    return 2 * x + 3 * y + 4;
}
int func_s(int x, int y)
{
    return 3 * x + y + 2;
}
void func()
{
    int result = 0;
    for (int i = 0; i < len; i++)
    {
        if (qst[i] > '0' && qst[i] <= '9')
        {
            nums[s1] = nums[s1] * 10 + (qst[i] - '0');
        }
        else if (qst[i] == '#')
        {
            fh[s2] = 1;
            cout << nums[s1] << endl
                 << fh[s2] << endl;
            s2++;
            s1++;
        }
        else if (qst[i] == '$')
        {
            fh[s2] = 2;
            cout << nums[s1] << endl
                 << fh[s2] << endl;
            s2++;
            s1++;
        }
    }
    for (int i = 0;; i++)
    {
        if (fh[i] == 0)
        {
            break;
        }
        if (fh[i] == 1)
        {
            n[t1] = nums[i];
            t1++;
        }
        else if (fh[i] == 2)
        {
            if (n[t1] == 0)
            {
                n[t1] = nums[i];
            }
            n[t1] = func_s(n[t1], nums[i + 1]);
            if (fh[i + 1] == 1)
            {
                t1++;
                i++;
                if (fh[i + 1] == 0)
                {
                    n[t1] = nums[i + 1];
                    t1++;
                    break;
                }
            }
        }
    }
    result = n[0];
    cout << "n:" << result << endl;
    for (int i = 1; i < t1; i++)
    {
        cout << "n:" << n[i] << endl;
        result = func_j(result, n[i]);
    }
    cout << "result:" << result;
}

int main()
{
    // char i = '0';
    // int j = i - '0';
    // cout << i << endl
    //      << j;
    cin >> qst;
    len = strlen(qst);
    func();
    cin >> qst;
}