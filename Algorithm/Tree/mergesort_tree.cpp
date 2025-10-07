// thank you for djs100201
const int NMAX = 2505;
const int INF = 1e9;

ll n, base, k;
vector<int> tree[100000 * 4 + 100];

int find(int l, int r) {
	l += base, r += base;
	int sum = 0;
	while (l <= r) {
		if (l % 2) {
			sum += tree[l].end() - upper_bound(tree[l].begin(), tree[l].end(), k);
			l++;
		}
		if (!(r % 2)) {
			sum += tree[r].end() - upper_bound(tree[r].begin(), tree[r].end(), k);
			r--;
		}
		l /= 2, r /= 2;
	}
	return sum;
}

void solve() {
    cin >> n;
    for (base = 1; base < n; base *= 2);
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
		tree[base + i].push_back(x);
	}
    for (int i = base - 1; i; i--) {
		tree[i].resize(tree[i * 2].size() + tree[i * 2 + 1].size());
		merge(tree[i * 2].begin(), tree[i * 2].end(), tree[i * 2 + 1].begin(), tree[i * 2 + 1].end(), tree[i].begin());
	}
    ll m; cin >> m;
    while(m--){
        ll l, r;
        cin >> l >> r >> k;
        cout << find(l - 1, r - 1) << "\n";
    }
}

