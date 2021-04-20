#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const double pi = 3.14159265358979;

double sq(double a)
{
    return a*a;
}

double dist(int a, int b, int c, int d)
{
    return sqrt(sq(a-c)+sq(b-d));
}

double cosRule(double b, double c, double A)
{
    return sqrt(b*b+c*c-2*b*c*cos(A));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b,c,d;
    cin>>n;
    cin>>a>>b;
    cin>>c>>d;
    double dt = dist(a,b,c,d);
    double side=dt*sin(pi/n),ang;
    ang = ((double)(pi*(n-2))/(2*n));
    cout<<side<<" "<<ang;
    return 0;
}