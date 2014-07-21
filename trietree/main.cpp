/**
通过构造trie树统计给定前缀的单词个数
输入：
m，单词个数 单词
n，输入前缀个数，前缀
输出：
每个前缀所对应的单词个数
*/

#include <iostream>
#include <string>
using namespace std;

typedef struct trie
{
	char c;
	int count;
	struct trie* next[26];
} Trie;

int main()
{
	Trie* root = new Trie;
	for (unsigned i(0); i < 26; ++i)
		root->next[i] = NULL;
	int n, m;
	string s;
	cin >> n;
	while (n--)
	{
		cin >> s;
		Trie* p = root;
		for (unsigned i(0); i < s.size(); ++i)
		{
			unsigned j = s[i] - 'a';
			if (p->next[j])
			{
				++p->next[j]->count;
			}
			else
			{
				Trie* q = new Trie;
				q->c = s[i];
				q->count = 1;
				for (unsigned k(0); k < 26; ++k)
					q->next[k] = NULL;
				p->next[j] = q;
			}
			p = p->next[j];
		}
	}
	cin >> m;
	while (m--)
	{
		cin >> s;
		bool flag = false;
		Trie* p = root;
		for (unsigned i(0); i < s.size(); ++i)
		{
			unsigned j = s[i] - 'a';
			if (!p->next[j])
			{
				flag = true;
				break;
			}
			p = p->next[j];
		}
		if (flag) cout << '0' << endl;
		else cout << p->count << endl;
	}
	return 0;
}
/*
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct node
{
    int next[26];
    int cnt;
    void init()
    {
        cnt=0;
        memset(next,-1,sizeof(next));
    }
}T[1000000];
int le;
void insert(char *s)
{
    int i=0,p=0;
    while(s[i])
    {
        int x=s[i]-'a';
        if(T[p].next[x]==-1)
        {
            T[le].init();
            T[p].next[x]=le++;
        }
        p=T[p].next[x];
        T[p].cnt++;
        i++;
    }
}
void query(char *s)
{
    int i=0,p=0;
    while(s[i])
    {
        int x=s[i]-'a';
        if(T[p].next[x]==-1)
        {
            puts("0");
            return ;
        }
        p=T[p].next[x];
        i++;
    }
    printf("%d\n",T[p].cnt);
}
int main()
{
    int n,m;
    char str[20];
    while(~scanf("%d",&n))
    {
        le=1;
        T[0].init();
        while(n--)
        {
        scanf("%s",str);
        insert(str);
        }
        scanf("%d",&m);
        while(m--)
        {
        scanf("%s",str);
        query(str);
        }
    }
}

*/