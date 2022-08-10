#include<bits/stdc++.h>

using namespace std;

int ap_num = 0;
int ap_hg[20000] = {0};

int func()
{
    if(ap_num == 1)
    {
        return -1;
    }
    int result = 0;
    int min = ap_hg[0];
    int sum_xor = ap_hg[0];
    for (int i = 1; i < ap_num; i++)
    {
        sum_xor ^= ap_hg[i];
        if(min > ap_hg[i])
        {
            result += min;
            min = ap_hg[i];
        } 
        else{
            result += ap_hg[i];
        }
    }
    if(sum_xor)
    {
        result = -1;
    }

    return result;
}

int main()
{
    cin>>ap_num;
    for (int i = 0; i < ap_num; i++)
    {
        cin>>ap_hg[i];
    }
    cout<<func();
    cin>>ap_num;
    return 0;
}