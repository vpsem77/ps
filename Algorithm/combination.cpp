const int mod = 1e9 + 7;
const int M = 4000000;
ll fac[M + 5], infac[M + 5];
ll mpow(ll a, ll x) {
    ll res = 1;
    if (x == 0) return 1;
    if (x % 2) {
        res *= a;
        x--;
    }
    ll t = (mpow(a, x / 2)) % mod;
    res *= (t * t) % mod;
    res %= mod;
    return res;
}

ll C(int n, int r) {
    return (fac[n] * infac[n - r]) % mod * infac[r] % mod;
}

fac[0] = 1;
for (int i = 1; i <= M; i++) {
    fac[i] = fac[i - 1] * i % mod;
}
infac[M] = mpow(fac[M], mod - 2);
for (int i = M - 1; i >= 0; i--) {
    infac[i] = infac[i + 1] * (i + 1) % mod;
}
