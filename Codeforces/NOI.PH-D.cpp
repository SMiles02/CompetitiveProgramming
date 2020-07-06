#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<string,int> nameToNumber;
    map<string,int> nicknameToNumber;
    map<int,int> numberIn;
    int inside=0;
    string s,t;
    for (int i=0;1;++i)
    {
        cin>>s;
        if (s[0]=='-')
        {
            break;
        }
        cin>>t;
        nameToNumber[t]=i;
        cin>>s>>t;
        nicknameToNumber[t]=i;
    }
    while (1)
    {
        cin>>s;
        if (s[0]=='E')
        {
            return 0;
        }
        if (s[0]=='U')
        {
            cout<<inside<<"\n";
        }
        else if (s[0]=='+')
        {
            cin>>s>>t;
            ++inside;
            if (s[0]=='t')
            {
                numberIn[nicknameToNumber[t]]=1;
            }
            else
            {
                numberIn[nameToNumber[t]]=1;
            }
        }
        else if (s[0]=='-')
        {
            cin>>s>>t;
            --inside;
            if (s[0]=='t')
            {
                numberIn[nicknameToNumber[t]]=0;
            }
            else
            {
                numberIn[nameToNumber[t]]=0;
            }
        }
        else
        {
            cin>>s>>t;
            if (s[0]=='t')
            {
                if (numberIn[nicknameToNumber[t]])
                {
                    cout<<"FOUND\n";
                }
                else
                {
                    cout<<"404\n";
                }
            }
            else
            {
                if (numberIn[nameToNumber[t]])
                {
                    cout<<"FOUND\n";
                }
                else
                {
                    cout<<"404\n";
                }
            }
        }
    }
}