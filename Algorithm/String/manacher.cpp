//16163 ac code
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(), v.end()
string s;

int a[4000005];

void solve() {
    cin >> s;
    string ns = "";
    for(int i = 0; i < s.size(); i++){
        ns.push_back('@');
        ns.push_back(s[i]);
    }
    ns.push_back('@');
    ll n = ns.size();
    int r = 0, p = 0;
    for (int i = 0; i < ns.size(); i++) {
        // step 1
        if (i <= r) a[i] = min(a[2 * p - i], r - i);
        else a[i] = 0;
        // step 2
        while (i - a[i] - 1 >= 0 && i + a[i] + 1 < n && ns[i - a[i] - 1] == ns[i + a[i] + 1]) a[i]++;
        // step 3
        if (r < i + a[i]) {
            r = i + a[i];
            p = i;
        }
    }
    ll res = 0;
    for(int i = 0; i < n; i++){
        res += (a[i] + 1) / 2;
    }
    cout << res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}
