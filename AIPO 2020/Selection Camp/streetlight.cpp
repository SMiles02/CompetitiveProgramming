#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void LightSwitch(int, int);

void LightsControl(int n, int l[]){
    for(int i=0;i<n;++i)
        if((i&1) == l[i])
            LightSwitch(i,1^(i&1));
}