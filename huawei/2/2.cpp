#include<bits/stdc++.h>

using namespace std;

char num[32] = {0};
int move_num = 0;

void func()
{
    int len1 = strlen(num);
    int len2 = len1 - move_num;
    char result[32] = {0};
    char min = '9';
    int pos=0;
    int rpos = 0;
    for (int i = 0; i < len1; i++)
    {
        for (int j = pos; j < len1; j++)
        {
            if(num[j]<min)
            {
                pos = j;
                min = num[j];
            }
        }
        result[rpos++]=num[pos];
        // len1 -= pos;
        move_num -= 1;
        min = '9';  
    }
    cout<<result;
}

int main()
{
    cin>>num;
    cin>>move_num;
    // cout<<sizeof(num)<<endl<<strlen(num)<<endl;
    cin>>move_num;
    // func();
    return 0;
}