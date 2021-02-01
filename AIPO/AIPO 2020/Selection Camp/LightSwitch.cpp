#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void LightSwitch(int, int);

void LightsControl(int n, int light[])
{
    for (int i=0;i<n;++i)
        if (light[i]==i&1)
            LightSwitch(i,1^(1&i));
}