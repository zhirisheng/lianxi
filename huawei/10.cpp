#include <bits/stdc++.h>

using namespace std;

struct node
{
    int q = -1;
    int h = -1;
};
stack<node> f;
int n;
int r[100000] = {0};

void func()
{
    int result = 0;
    node p;
    node t;
    p.q = 0;
    p.h = r[0];
    f.push(p);
    for (int i = 1; i < n; i++)
    {
        p.q = i * 100 - r[i];
        p.h = i * 100 + r[i];
        t = f.top();
        while (t.h >= p.q)
        {
            if (p.q < 0)
            {
                p.q = 0;
            }
            if (p.q > t.q)
            {
                p.q = t.q;
            }
            if (t.h > p.h)
            {
                p.h = t.h;
            }
            f.pop();
            if (f.empty())
            {
                break;
            }
            t = f.top();
        }
        f.push(p);
        cout << "p.q:" << p.q << ",p.h:" << p.h << endl;
    }
    p = f.top();
    f.pop();
    if (f.empty())
    {
        cout << "result:" << 0 << endl;
        return;
    }
    while (!f.empty())
    {
        t = f.top();
        result += p.q - t.h;
        p = t;
        f.pop();
    }
    cout << "result:" << result << endl;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    func();
    cin >> n;
}