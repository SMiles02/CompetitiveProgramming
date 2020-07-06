#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string alpha="abcdefghijklmnopqrstuvwxyz";
int godLength;
int godAnswer;
int mod=1000000007;
vector<ll> powers;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<char,int> charToInt;
    ll num=1;
    int n;
    for (int i=0;i<26;++i)
    {
        charToInt[alpha[i]]=i;
    }
    string s;
    cin>>s;
    n=sz(s);
    for (int i=0;i<n-1;++i)
    {
        powers.push_back(num);
        num*=31;
        num%=mod;
    }
    godAnswer=0;
    for (int i=0;i<n-1;++i)
    {
        godAnswer+=(((((charToInt[i+1]+26)-charToInt[i])%26)*powers[i])%mod);
    }
    cout<<godAnswer;
    return 0;
}