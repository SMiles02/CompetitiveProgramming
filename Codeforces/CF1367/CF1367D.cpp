#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dist(int n, vector<int> v)
{
    int ans=0;
    for (int x : v)
        ans+=abs(x-n);
    return ans;
}

vector<int> addInto(vector<int> v, vector<int> w)
{
    for (int x : w)
        v.push_back(x);
    return v;
}

char getChar(int n)
{
    char c='a';
    for (int i=0;i<n;++i)
        ++c;
    return c;
}

bool done[50];
int amounts[26];
int a[50];
char ans[50];

void solve()
{
    for (int i=0;i<26;++i)
        amounts[i]=0;
    for (int i=0;i<50;++i)
        done[i]=0;
    int n;
    char A;
    string s;
    vector<int> v;
    vector<int> w;
    cin>>s;
    cin>>n;
    for (int i=0;i<50;++i)
        ans[i]='a';
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (auto c : s)
        ++amounts[c-'a'];
    while (sz(v)<n)
    {
        for (int i=0;i<n;++i)
            if (!done[i]&&dist(i,v)==a[i])
                w.push_back(i);
        for (int i=25;i>=0;--i)
        {
            if (amounts[i]>=sz(w))
            {
                A=getChar(i);
                for (int j : w)
                {
                    done[j]=1;
                    ans[j]=A;
                }
                amounts[i]=0;
                break;
            }
            else
                amounts[i]=0;
        }
        v=addInto(v,w);
        w.clear();
    }
    //cout<<"test\n";
    for (int i=0;i<n;++i)
        cout<<ans[i];
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}