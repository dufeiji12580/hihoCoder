#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

void compute_next(char *par,int next[])
{
    int m,k;
    m = strlen(par);
    next[1] = 0;
    k = 0;
    for(int q = 2;q<m;q++)
    {
        while(k>0 && par[k+1]!=par[q])
            k = next[k];
        if(par[k+1] == par[q])
            k = k+1;
        next[q] = k;
    }
}
int kmp(char *ori,char *par)
{
    int m ,n,cnt = 0,q = 0;
    m = strlen(ori);
    n = strlen(par);
    int next[n];
    next[0] = -1;
    compute_next(par,next);
    for(int i = 1;i < m;i++)
    {
        while(q>0 && par[q+1]!=ori[i])
            q = next[q];
        if(par[q+1] == ori[i])
            q = q+1;
        if(q == n-1)
        {
            cnt++;
            q = next[q];
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    char ori[1000001],par[10001];
    par[0] = '#';
    ori[0] = '#';
    while(n--)
    {
        cin >> (par+1) >> (ori+1);
        cout << kmp(ori,par)<<endl;
    }
    return 0;
}
