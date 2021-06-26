#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
    {
        return a;
    }
    return b;
}

void solve()
{
    int lengthPosNext=0,lengthNegNext=0,lastPosTaken=1000000000,lastNegTaken=1000000000;
    ll sumPosNext=0,sumNegNext=0;
    int n,k;
    cin>>n;
    while (n--)
    {
        cin>>k;
        if (k>0)
        {
            if (lengthNegNext<=lengthPosNext)
            {
                lengthNegNext=lengthPosNext+1;
                lastPosTaken=k;
                sumNegNext=sumPosNext+k;
            }
            else if (lengthNegNext==lengthPosNext+1&&sumNegNext<sumPosNext+k)
            {
                lengthNegNext=lengthPosNext+1;
                lastPosTaken=k;
                sumNegNext=sumPosNext+k;
            }
            if (lastPosTaken<k)
            {
                sumNegNext-=lastPosTaken;
                sumNegNext+=k;
                lastPosTaken=k;
            }
        }
        else
        {
            if (lengthPosNext<=lengthNegNext)
            {
                lengthPosNext=lengthNegNext+1;
                lastNegTaken=k;
                sumPosNext=sumNegNext+k;
            }
            else if (lengthPosNext==lengthNegNext+1&&sumPosNext<sumNegNext+k)
            {
                lengthPosNext=lengthNegNext+1;
                lastNegTaken=k;
                sumPosNext=sumNegNext+k;
            }
            if (lastPosTaken<k)
            {
                sumPosNext-=lastNegTaken;
                sumPosNext+=k;
                lastNegTaken=k;
            }
        }
    }
    if (lengthNegNext>lengthPosNext)
    {
        cout<<sumNegNext<<"\n";
        return;
    }
    if (lengthNegNext<lengthPosNext)
    {
        cout<<sumPosNext<<"\n";
        return;
    }
    cout<<max(sumNegNext,sumPosNext)<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}