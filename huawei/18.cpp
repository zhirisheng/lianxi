#include <bits/stdc++.h>

using namespace std;

char str[25][6] = {0};
int arr[25] = {0};
char result[200] = {0};
void prt(int arr[], int end)
{
    char tmp[200] = {0};
    for (int i = 0; i <= end; i++)
        strcat(tmp, str[arr[i]]);
    // cout << tmp << endl;
    if (!result)
    {
        memcpy(result, tmp, strlen(tmp));
    }
    else if (strcmp(tmp, result) > 0)
    {
        memcpy(result, tmp, strlen(tmp));
    }
}

void perm(int arr[], int begin, int end)
{
    //递归终止条件：当只有一个数字做全排列的时候，则它的全排列就等于其本身。
    if (begin == end)
    {
        prt(arr, end);
        // cout << endl;
        return;
    }

    for (int i = begin; i <= end; i++)
    {
        swap(arr[begin], arr[i]);  //将第i个元素放到begin起始位置
        perm(arr, begin + 1, end); //将剩下的从begin+1到最后的元素进行全排列
        swap(arr[begin], arr[i]);  //将交换的数进行还原
    }
}

int main(void)
{
    for (int i = 0; i < 25; i++)
    {
        arr[i] = i;
    }

    int n = 0;
    int p1 = 0;
    int p2 = 0;
    char input[200] = {0};
    gets(input);
    while (input[p1] != '\0')
    {
        if (input[p1] == ',')
        {
            p1++;
            continue;
        }
        str[n][p2++] = input[p1];
        if (input[p1 + 1] == ',' || input[p1 + 1] == '\0')
        {
            n++;
            p2 = 0;
        }
        p1++;
    }

    perm(arr, 0, n);
    cout << result;
    cin >> input;
}