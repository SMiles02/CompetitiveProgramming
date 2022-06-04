#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int lBiggerThanR(string l, string r)
{
    int n=sz(l);
    for (int i=0;i<n;++i)
    {
        if ((l[i]-'0')>(r[i]-'0')) return 1;
        if ((l[i]-'0')<(r[i]-'0')) return 0;
    }
    return 0;
}

int getSum(string s)
{
    int ans=0;
    for (int i=0;i<7;++i) ans+=(s[i]-'0');
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,score;
    cin>>n>>k;
    string previous[k+1];
    string s;
    string newOne[k+1];
    previous[0]="";
    for (int i=1;i<=k;++i)
    {
        previous[i]=":";
    }
    while (n--)
    {
        for (int i=0;i<=k;++i)
        {
            newOne[i].clear();
            newOne[i]=":";
        }
        cin>>s;
        score=getSum(s);
        if (s[3]=='0')
        {
            for (int i=6-score;i<=k;++i)
            {
                if (previous[i-6+score]!=":")
                {
                    newOne[i]=previous[i-6+score]+"0";
                }
            }
        }
        if (s[0]=='0'&&s[1]=='0'&&s[3]=='0'&&s[4]=='0'&&s[6]=='0')
        {
            for (int i=2-score;i<=k;++i)
            {
                if (previous[i-2+score].back()!=':')
                {
                    if (newOne[i].back()==':') newOne[i]=previous[i-2+score]+"1";
                    else if (lBiggerThanR(previous[i-2+score]+"1",newOne[i])) newOne[i]=previous[i-2+score]+"1";
                }
            }
        }
        if (s[4]=='0'&&s[2]=='0')
        {
            for (int i=5-score;i<=k;++i)
            {
                if (previous[i-5+score].back()!=':')
                {
                    if (newOne[i].back()==':') newOne[i]=previous[i-5+score]+"5";
                    else if (lBiggerThanR(previous[i-5+score]+"5",newOne[i])) newOne[i]=previous[i-5+score]+"5";
                }
            }
        }
        else if (s[1]=='0'&&s[4]=='0')
        {
            for (int i=5-score;i<=k;++i)
            {
                if (previous[i-5+score].back()!=':')
                {
                    if (newOne[i].back()==':') newOne[i]=previous[i-5+score]+"3";
                    else if (lBiggerThanR(previous[i-5+score]+"3",newOne[i])) newOne[i]=previous[i-5+score]+"3";
                }
            }
        }
        else if (s[1]=='0'&&s[5]=='0')
        {
            for (int i=5-score;i<=k;++i)
            {
                if (previous[i-5+score].back()!=':')
                {
                    if (newOne[i].back()==':') newOne[i]=previous[i-5+score]+"2";
                    else if (lBiggerThanR(previous[i-5+score]+"2",newOne[i])) newOne[i]=previous[i-5+score]+"2";
                }
            }
        }
        if (s[0]=='0'&&s[4]=='0'&&s[6]=='0')
        {
            for (int i=4-score;i<=k;++i)
            {
                if (previous[i-4+score].back()!=':')
                {
                    if (newOne[i].back()==':') newOne[i]=previous[i-4+score]+"4";
                    else if (lBiggerThanR(previous[i-4+score]+"4",newOne[i])) newOne[i]=previous[i-4+score]+"4";
                }
            }
        }
        if (s[4]=='0')
        {
            for (int i=6-score;i<=k;++i)
            {
                if (previous[i-6+score].back()!=':')
                {
                    if (newOne[i].back()==':') newOne[i]=previous[i-6+score]+"9";
                    else if (lBiggerThanR(previous[i-6+score]+"9",newOne[i])) newOne[i]=previous[i-6+score]+"9";
                }
            }
        }
        else if (s[2]=='0')
        {
            for (int i=6-score;i<=k;++i)
            {
                if (previous[i-6+score].back()!=':')
                {
                    if (newOne[i].back()==':') newOne[i]=previous[i-6+score]+"6";
                    else if (lBiggerThanR(previous[i-6+score]+"6",newOne[i])) newOne[i]=previous[i-6+score]+"6";
                }
            }
        }
        if (s[1]=='0'&&s[3]=='0'&&s[4]=='0'&&s[6]=='0')
        {
            for (int i=3-score;i<=k;++i)
            {
                if (previous[i-3+score].back()!=':')
                {
                    if (newOne[i].back()==':') newOne[i]=previous[i-3+score]+"7";
                    else if (lBiggerThanR(previous[i-3+score]+"7",newOne[i])) newOne[i]=previous[i-3+score]+"7";
                }
            }
        }
        if (1)
        {
            for (int i=7-score;i<=k;++i)
            {
                if (previous[i-7+score].back()!=':')
                {
                    if (newOne[i].back()==':') newOne[i]=previous[i-7+score]+"8";
                    else if (lBiggerThanR(previous[i-7+score]+"8",newOne[i])) newOne[i]=previous[i-7+score]+"8";
                }
            }
        }
        for (int i=0;i<=k;++i)
        {
            previous[i]=newOne[i];
        }
    }
    if (previous[k]==":")
    {
        cout<<-1;
        return 0;
    }
    cout<<previous[k];
    return 0;
}