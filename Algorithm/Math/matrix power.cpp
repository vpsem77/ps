const ll mod = 1e9;

typedef vector<vector<ll>> matrix;
matrix operator*(const matrix &a, const matrix &b) {
    ll size = a.size(), size2 = b[0].size(), size3 = b.size();
    matrix res(size, vector<ll>(size2));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size2; j++) {
            for (int k = 0; k < size3; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
            res[i][j] %= mod;
        }
    return res;
}
matrix power(matrix a, ll n) {  // a행렬을 n제곱 하겠다!
    ll size = a.size();
    matrix res(size, vector<ll>(size));
    for (int i = 0; i < size; i++) res[i][i] = 1;  // 단위 행렬 생성
    while (n) {
        if (n % 2) res = res * a;
        n /= 2;
        a = a * a;
    }
    return res;
}
