#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool dp[11];

string makeString(char c)
{
    string s="";
    s+=c;
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string s;
    cin>>s;
    n=sz(s);
    map<string,int> m;
    ++m["H"];
    ++m["HE"];
    ++m["LI"];
    ++m["BE"];
    ++m["B"];
    ++m["C"];
    ++m["N"];
    ++m["O"];
    ++m["F"];
    ++m["NE"];
    ++m["NA"];
    ++m["MG"];
    ++m["AL"];
    ++m["SI"];
    ++m["P"];
    ++m["S"];
    ++m["CL"];
    ++m["AR"];
    ++m["K"];
    ++m["CA"];
    ++m["SC"];
    ++m["TI"];
    ++m["V"];
    ++m["CR"];
    ++m["MN"];
    ++m["FE"];
    ++m["CO"];
    ++m["NI"];
    ++m["CU"];
    ++m["ZN"];
    ++m["GA"];
    ++m["GE"];
    ++m["AS"];
    ++m["SE"];
    ++m["BR"];
    ++m["KR"];
    ++m["RB"];
    ++m["SR"];
    ++m["Y"];
    ++m["ZR"];
    ++m["NB"];
    ++m["MO"];
    ++m["TC"];
    ++m["RU"];
    ++m["RH"];
    ++m["PD"];
    ++m["AG"];
    ++m["CD"];
    ++m["IN"];
    ++m["SN"];
    ++m["SB"];
    ++m["TE"];
    ++m["I"];
    ++m["XE"];
    ++m["CS"];
    ++m["BA"];
    ++m["LA"];
    ++m["CE"];
    ++m["PR"];
    ++m["ND"];
    ++m["PM"];
    ++m["SM"];
    ++m["EU"];
    ++m["GD"];
    ++m["TB"];
    ++m["DY"];
    ++m["HO"];
    ++m["ER"];
    ++m["TM"];
    ++m["YB"];
    ++m["LU"];
    ++m["HF"];
    ++m["TA"];
    ++m["W"];
    ++m["RE"];
    ++m["OS"];
    ++m["IR"];
    ++m["PT"];
    ++m["AU"];
    ++m["HG"];
    ++m["TL"];
    ++m["PB"];
    ++m["BI"];
    ++m["PO"];
    ++m["AT"];
    ++m["RN"];
    ++m["FR"];
    ++m["RA"];
    ++m["AC"];
    ++m["TH"];
    ++m["PA"];
    ++m["U"];
    ++m["NP"];
    ++m["PU"];
    ++m["AM"];
    ++m["CM"];
    ++m["BK"];
    ++m["CF"];
    ++m["ES"];
    ++m["FM"];
    ++m["MD"];
    ++m["NO"];
    ++m["LR"];
    ++m["RF"];
    ++m["DB"];
    ++m["SG"];
    ++m["BH"];
    ++m["HS"];
    ++m["MT"];
    ++m["DS"];
    ++m["RG"];
    ++m["CN"];
    ++m["NH"];
    ++m["FL"];
    ++m["MC"];
    ++m["LV"];
    ++m["TS"];
    ++m["OG"];
    dp[0]=1;
    for (int i=0;i<n;++i)
    {
        if (dp[i])
        {
            if (m[makeString(s[i])])
            {
                dp[i+1]=1;
            }
            if (i+1<n)
            {
                if (m[makeString(s[i])+makeString(s[i+1])])
                {
                    dp[i+2]=1;
                }
            }
        }
    }
    if (dp[n])
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
}