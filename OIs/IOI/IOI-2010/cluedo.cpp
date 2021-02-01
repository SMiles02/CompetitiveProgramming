#include <bits/stdc++.h>
#include "grader.h"
#include "cluedo.h"
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void Solve()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a=1,b=1,c=1,d;
    while (1)
    {
        d=Theory(a,b,c);
        if (d==0) return;
        if (d==1) ++a;
        if (d==2) ++b;
        if (d==3) ++c;
    }
}