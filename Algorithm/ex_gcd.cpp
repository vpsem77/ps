ll ex_gcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

ll a, b, x, y;
ll G = ex_gcd(a,b,x,y);
ll L = a*b/G;

// cout << a*x + b*y;
// G = ax + by = gcd(a,b)
// x,y는 gcd(a,b) = ax+by를 만족시키는 x,y이다.
