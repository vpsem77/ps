// thank you for djs100201
// O(nlog^2n)
// sa[i]: 사전순으로 i번째 위치의 접미사가 원래 문자열의 몇 번째 문자부터 시작하냐 
// lcp[i]: 정렬된 접미사들끼리, 인접한 접미사와 몇 칸까지 겹치냐
class LCP {
   public:
    string s;
    int n, d, lim;
    vector<int> group, sa, num, cnt, temp, rev_sa, lcp;
    bool cmp(ll x, ll y) {
        if (group[x] != group[y]) return group[x] < group[y];
        x += d, y += d;
        if (x < n && y < n) return group[x] < group[y];
        return x > y;
    }
    void make_lcp() {
        int n, m;
        n = s.size();
        m = lim;
        for (d = 1; d < n; d *= 2) {
            for (int i = 0; i <= m; i++) num[i] = 0;
            for (int i = 0; i < n; i++) num[group[i + d]]++;
            for (int i = 1; i < m; i++) num[i] += num[i - 1];
            for (int i = n - 1; i >= 0; i--) cnt[--num[group[i + d]]] = i;

            for (int i = 0; i <= m; i++) num[i] = 0;
            for (int i = 0; i < n; i++) num[group[i]]++;
            for (int i = 1; i < m; i++) num[i] += num[i - 1];
            for (int i = n - 1; i >= 0; i--) sa[--num[group[cnt[i]]]] = cnt[i];

            temp[0] = 1;
            for (int i = 1; i < n; i++) temp[i] = temp[i - 1] + cmp(sa[i - 1], sa[i]);
            for (int i = 0; i < n; i++) group[sa[i]] = temp[i];
            if (temp[n - 1] == n) break;
        }
        for (int i = 0; i < n; i++) rev_sa[sa[i]] = i;
        ll len = 0;
        for (int i = 0; i < n; i++) {
            if (!rev_sa[i]) continue;
            for (int j = sa[rev_sa[i] - 1]; s[i + len] == s[j + len]; len++);
            lcp[rev_sa[i]] = len;
            len--;
            if (len < 0) len++;
        }
    }
    LCP(string S) {
        s = S;
        n = s.size();
        lim = max(27, n + 1);
        group.resize(lim*2 + 1), sa.resize(lim*2 + 1), num.resize(lim*2 + 1), cnt.resize(lim*2 + 1);
        temp.resize(lim*2 + 1), rev_sa.resize(lim*2 + 1), lcp.resize(lim*2 + 1);
        for (int i = 0; i < n; i++) {
            group[i] = s[i] - 'a' + 1;
            sa[i] = i;
        }
        make_lcp();
    }
};
