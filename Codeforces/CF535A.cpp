#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<int,string> tens;
    map<int,string> ones;
    tens[0]="";
    tens[2]="twenty";
    tens[3]="thirty";
    tens[4]="forty";
    tens[5]="fifty";
    tens[6]="sixty";
    tens[7]="seventy";
    tens[8]="eighty";
    tens[9]="ninety";
    ones[1]="one";
    ones[2]="two";
    ones[3]="three";
    ones[4]="four";
    ones[5]="five";
    ones[6]="six";
    ones[7]="seven";
    ones[8]="eight";
    ones[9]="nine";
    int n;
    cin>>n;
    if (n==0)
    {
        cout<<"zero";
        return 0;
    }
    if (n==10)
    {
        cout<<"ten";
        return 0;
    }
    if (n==11)
    {
        cout<<"eleven";
        return 0;
    }
    if (n==12)
    {
        cout<<"twelve";
        return 0;
    }
    if (n==13)
    {
        cout<<"thirteen";
        return 0;
    }
    if (n==15)
    {
        cout<<"fifteen";
        return 0;
    }
    if (n==18)
    {
        cout<<"eighteen";
        return 0;
    }
    if (n/10==1)
    {
        cout<<ones[n%10]+"teen";
        return 0;
    }
    if (n<10)
    {
        cout<<ones[n];
        return 0;
    }
    if (n%10)
    {
        cout<<tens[n/10]<<"-"<<ones[n%10];
        return 0;
    }
    cout<<tens[n/10];
    return 0;
}