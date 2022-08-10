#include <bits/stdc++.h>

using namespace std;

int n = 0;
int k = 0;
in int main()
{
    cin >> n;
    cin >> k;
    for (int i = n; i > 0; i++)
    {
        cout << 1 + ((k + 1) / n);
    }

    return 0;
}

void swap(int *num, int i, int j) //全排列  回溯法
{
    int temp = num[i];
    num[i] = num[j];
    num[j] = temp;
}
void dfs(int *num, int n, int pos)
{
    if (pos == n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d", num[i]);
        }
        printf("\n");
        cnt++;
        return;
    }
    dfs(num, n, pos + 1);
    for (int j = pos + 1; j < n; j++)
    {
        if (num[pos] != num[j])
        {
            swap(num, pos, j);
            dfs(num, n, pos + 1);
            swap(num, j, pos);
        }
    }
}