#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    char t[10050],s[1000007];
    int c;scanf("%d",&c);
    while(c--)
    {
        scanf("%s%s",t,s);
        int flink[10004]={};
        int i=0,j=-1;
        flink[0]=-1;
        int len=strlen(t);
        while(i<len)
        {
            if(j==-1 || t[i]==t[j])
                flink[++i]=++j;
            else
                j=flink[j];
        }
        int ans=0;
        i=j=0;
        int n=len;
        len=strlen(s);
        while(i<len)
        {
            if(j==-1 || s[i]==t[j])
            {
                ++i;++j;
            }
            else
            {
                j=flink[j];
            }
            if(j==n) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
