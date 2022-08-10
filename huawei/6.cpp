#include <bits/stdc++.h>

using namespace std;

int n;
int m = 0;
int num = 0;
char input[10000] = {0};
char check[3000][12] = {0};
bool result[1000];
void func()
{
    int absenttime = 0;
    int latetime = 0;
    bool islast = false;
    int flag = 0;
    for (int i = 0; i < num; i++)
    {
        // cout << check[i] << endl;
        cout << i << ":" << check[i] << endl;

        if (!strcmp(check[i], "absent"))
        {
            // cout << "absent" << absenttime << endl;
            absenttime++;
            islast = false;
            if (absenttime > 1)
            {
                result[m++] = false;
                return;
            }
        }
        else if (!strcmp(check[i], "late"))
        {
            // cout << "late" << endl;
            if (islast)
            {
                result[m++] = false;
                return;
            }
            islast = true;
            latetime++;
        }
        else if (!strcmp(check[i], "leaveearly"))
        {
            // cout << "leaveearly" << endl;
            if (islast)
            {
                result[m++] = false;
                return;
            }
            islast = true;
            latetime++;
        }
        else if (!strcmp(check[i], "present"))
        {
            // cout << "present" << endl;
            islast = false;
        }
        if (i >= 7)
        {
            if (!strcmp(check[i - 7], "leaveearly") ||
                !strcmp(check[i - 7], "late"))
            {
                latetime--;
            }
        }
        if (latetime + absenttime > 3)
        {
            result[m++] = false;
            return;
        }
        // cout << i << ":" << check[i] << endl;
    }
    result[m++] = true;
}
int main()
{
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        memset(input, 0, 10000);
        memset(check, 0, 3000 * 12);
        char tmp;
        int size = 0;
        do
        {
            tmp = getchar();
            if (tmp != ' ')
            {
                // strcat(check[num], &tmp);
                check[num][size++] = tmp;
            }
            else if (tmp == ' ')
            {
                cout << num << ":" << check[num] << endl;
                num++;
                size = 0;
            }
        } while (tmp != '\n');
        cout << num << ":" << check[num] << endl;
        size = 0;
        num++;
        func();
        num = 0;
        // cout << "i:" << i << endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (result[i])
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }

    cin >> n;
    return 0;
}