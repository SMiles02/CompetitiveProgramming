#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
map<char,int> charToInt;
int godLength;
vector<int> god;
char c;
//int godAnswer;
int mod=1000000007;
vector<ll> powers;

void solve()
{
    string s;
    cin>>s;
    int good;
    int n=sz(s);
    for (int i=0;i+godLength-1<n;++i)
    {
        good=1;
        for (int j=0;j<godLength-1;++j)
        {
            if ((((charToInt[s[i+j+1]]+26)-(charToInt[s[i+j]]))%26)!=god[j])
            {
                good=0;
                break;
            }
        }
        if (good&&((charToInt[s[i]]+26)-(charToInt[c]))%26)
        {
            cout<<((charToInt[s[i]]+26)-(charToInt[c]))%26<<"\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    for (int i=0;i<26;++i)
    {
        charToInt[alpha[i]]=i;
        //cout<<alpha[i]<<" "<<i<<"\n";
    }
    string s;
    cin>>s;
    n=sz(s);
    /**for (int i=0;i<n-1;++i)
    {
        powers.push_back(num);
        num*=31;
        num%=mod;
    }**/
    //godAnswer=0;
    godLength=n;
    for (int i=0;i<n-1;++i)
    {
        god.push_back(((charToInt[s[i+1]]+26)-(charToInt[s[i]]))%26);
        //cout<<god[i]<<" ";
    }
    c=s[0];
    //cout<<"\n";
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}