#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int sum = 0;

    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    memset(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            scanf("%d", &temp);
            arr[i] = arr[i] | (temp << (n - j - 1));
        }
    }

    for (int i = 0; i < n; i++)
    {
        int max = 0;
        for (int j = 0; j < n - 1; j++)
        {
            int temp = 0;
            int mid = 0;
            for (int k = 0; k < j + 1; k++)
            {
                temp = (1 << k) & arr[i];
                mid = mid | temp;
            }
            mid = mid << (n - 1 - j);
            mid = mid | (arr[i] >> (j + 1));
            max = mid > max ? mid : max;
        }
        arr[i] = max;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
        sum += arr[i];
    }

    printf("res:%d", sum);
    cout << endl
         << "waiting" << endl;
    cin >> n;
    return 0;
}