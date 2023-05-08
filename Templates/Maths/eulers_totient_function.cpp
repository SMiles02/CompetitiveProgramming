// count of 1 <= i <= n s.t. gcd(i, n) = 1

long long etf(long long n) {
    long long m = n;
    for (int i = 2; 1LL * i * i <= m; ++i)
        if (m % i == 0) {
            n /= i;
            n *= i - 1;
            while (m % i == 0)
                m /= i;
        }
    if (m > 1) {
        n /= m;
        n *= m - 1;
    }
    return n;
}