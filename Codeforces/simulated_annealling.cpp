#include <bits/stdc++.h>
using namespace std;
int n = 100;  // размер доски
const int k = 1000, INF =1e9; // количество итераций алгоритма
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int f(vector<int> &p) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        int d = 1;
        for (int j = 0; j < i; j++)
            if (abs(i - j) == abs(p[i] - p[j]))
                d = 0;
        s += d;
    }
    return s;
}

// генерирует действительное число от 0 до 1
double rnd()
{ 
    int X = uniform_int_distribution<int>(INF,2*INF)(rng);
    return double(rng()%X) / X;
}

int main() {
    cin>>n;
    // генерируем начальную перестановку
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    shuffle(v.begin(), v.end(), rng);
    int ans = f(v); // текущий лучший ответ 

    double t = 1;
    for (int i = 0; i < k && ans < n; i++) {
        t *= 0.99;
        vector<int> u = v;
        swap(u[rand() % n], u[rand() % n]);
        int val = f(u);
        if (val > ans || rnd() < exp((val - ans) / t)) {
            v = u;
            ans = val;
        }
    }

    for (int x : v)
        cout << x + 1 << " ";

    return 0;
}
