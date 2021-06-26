#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int allSame(string s)
{
    int n=sz(s);
    for (int i=1;i<n;++i)
    {
        if (s[i]!=s[0])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s,cur="";
    char t;
    cin>>s;
    int n=sz(s);
    map<char,int> m;
    m['a']=1;m['e']=1;m['i']=1;m['o']=1;m['u']=1;
    for (int i=0;i<n;++i)
    {
        if (m[s[i]])
        {
            reverse(cur.begin(), cur.end());
            while (sz(cur)>2)
            {
                if (allSame(cur))
                {
                    cout<<cur;
                    cur="";
                }
                else
                {
                    t=cur.back();
                    cout<<cur.back();
                    cur.pop_back();
                    if (cur.back()==t)
                    {
                        while (cur.back()==t)
                        {
                            cout<<t;
                            cur.pop_back();
                        }
                        cout<<" ";
                    }
                    else
                    {
                        cout<<cur.back()<<" ";
                        cur.pop_back();
                    }
                }
            }
            reverse(cur.begin(), cur.end());
            cout<<cur<<s[i];
            cur="";
        }
        else
        {
            cur+=s[i];
        }
    }
    reverse(cur.begin(), cur.end());
    while (sz(cur)>2)
    {
        if (allSame(cur))
        {
            cout<<cur;
            cur="";
        }
        else
        {
            t=cur.back();
            cout<<cur.back();
            cur.pop_back();
            if (cur.back()==t)
            {
                while (cur.back()==t)
                {
                    cout<<t;
                    cur.pop_back();
                }
                cout<<" ";
            }
            else
            {
                cout<<cur.back()<<" ";
                cur.pop_back();
            }
        }
    }
    reverse(cur.begin(), cur.end());
    cout<<cur;
    return 0;
}