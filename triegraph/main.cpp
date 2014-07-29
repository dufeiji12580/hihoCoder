#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Trie
{
    int flag;
    struct Trie* behind;
    struct Trie* next[26];
};

int main()
{
    int n;
    char s[100001];
    cin >> n;
    Trie* root = new Trie;
    for (int i = 0; i < 26; i++)
    {
        root->next[i] = NULL;
    }
    root ->behind = NULL;
    root ->flag = 0;
    while (n--)
    {
        cin >> s;
        Trie* p = root;
        for (int i = 0; s[i]!='\0'; i++)
        {
            int j = s[i] - 'a';
            if (!p->next[j])
            {
                Trie* q = new Trie;
                q->flag = 0;
                for (int k = 0; k < 26; k++)
                {
                    q->next[k] = NULL;
                }
                q ->behind = NULL;
                p->next[j] = q;
            }
            p = p->next[j];
        }
        p->flag = 1;
    }

    queue<Trie*> Q;
    root->behind = root;
    for (int i = 0; i < 26; i++)
    {
        if(!root->next[i])
        {
            root->next[i] = root;
        }
        else
        {
            root->next[i]->behind = root;
            Q.push(root->next[i]);
        }
    }
    while(!Q.empty())
    {
        Trie *p = Q.front();
        Trie *q = p->behind;
        Q.pop();
        for (int i = 0; i < 26; i++)
        {
            if(!p->next[i])
            {
                p->next[i] = q->next[i];
            }
            else
            {
                p->next[i]->behind = q->next[i];
                Q.push(p->next[i]);
            }
        }
    }
    char article[1000001];
    Trie* p = root;
    cin >> article;
    bool tag = false;
    for (int i = 0; article[i]!='\0'; i++)
    {
        int j = article[i] - 'a';
        p = p->next[j];
        if(p->flag == 1)
        {
            tag = true;
            cout << "YES" <<endl;
            break;
        }
    }
    if(tag == false)
        cout << "NO" <<endl;
    return 0;
}
