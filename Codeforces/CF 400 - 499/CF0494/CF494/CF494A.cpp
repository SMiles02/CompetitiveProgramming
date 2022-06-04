#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,total=0,score=0,cur=0,newScore=0;
    string s;
    cin>>s;
    n=sz(s);
    for (int i=0;i<n;++i)
    {
        if (s[i]=='(')
        {
            ++score;
        }
        else
        {
            --score;
            if (s[i]=='#')
            {
                ++total;
            }
            if (score<0)
            {
                cout<<-1;
                return 0;
            }
        }
    }
    for (int i=0;i<n;++i)
    {
        if (s[i]=='(')
        {
            ++newScore;
        }
        else
        {
            --newScore;
            if (s[i]=='#')
            {
                ++cur;
                if (cur==total)
                {
                    newScore-=score;
                }
            }
            if (newScore<0)
            {
                cout<<-1;
                return 0;
            }
        }
    }
    for (int i=1;i<total;++i)
    {
        cout<<"1\n";
    }
    cout<<1+score;
    return 0;
}