#include <bits/stdc++.h>

using namespace std;

void zhixingshichang()
{
    int deal_num;
    int task_num;
    int task[100];
    int store = 0;
    int day = 0;

    scanf("%d", &deal_num);
    scanf("%d", &task_num);
    for (int i = 0; i < task_num; i++)
    {
        scanf("%d", &task[i]);
    }

    for (int i = 0; i < task_num; i++)
    {
        if ((store + task[i]) <= deal_num)
        {
            day++;
            store = 0;
        }
        else
        {
            day = day + (store + task[i]) / deal_num;
            store = (store + task[i]) % deal_num;
        }
    }
    if (store != 0)
    {
        day++;
    }
    printf("%d", day);
    scanf("%d", &deal_num);
}

int main()
{
    zhixingshichang();
    return 0;
}