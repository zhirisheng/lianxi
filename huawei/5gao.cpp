#include <bits/stdc++.h>

using namespace std;
void swap(char *s, int pos1, int pos2)
{
    char temp = s[pos1];
    s[pos1] = s[pos2];
    s[pos2] = temp;
}
typedef struct
{
    char s;
    int org_idx;
    int now_idx;
} Dis;
void change_min()
{
    Dis temp[1000];
    char str[1000];
    int len;

    scanf("%s", str);
    len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        temp[i].s = str[i];
        temp[i].org_idx = i;
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (temp[j].s > temp[j + 1].s)
            {
                Dis mid;
                memcpy(&mid, &temp[j], sizeof(Dis));
                memcpy(&temp[j], &temp[j + 1], sizeof(Dis));
                memcpy(&temp[j + 1], &mid, sizeof(Dis));
            }
        }
    }

    for (int i = 0; i < len; i++)
    {
        temp[i].now_idx = i;
        if (temp[i].now_idx != temp[i].org_idx)
        {
            swap(str, temp[i].now_idx, temp[i].org_idx);
            printf("%s", str);
            return;
        }
    }
    printf("%s", str);
}