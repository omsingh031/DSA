class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1'000'000'007LL;
        int m = s.size();

        vector<long long> V(m + 1, 0);      // s[0..i-1] ke non-zero digits ki concat value
        vector<int>       cnt(m + 1, 0);     // s[0..i-1] mein non-zero digits ki count
        vector<long long> ps(m + 1, 0);      // s[0..i-1] ke SAARE digits ka sum
        vector<long long> pow10(m + 1, 1);   // 10^i mod p

        for (int i = 1; i <= m; ++i)
            pow10[i] = pow10[i - 1] * 10 % MOD;

        for (int i = 0; i < m; ++i) {
            int d = s[i] - '0';
            ps[i + 1] = ps[i] + d;
            if (d) {
                V[i + 1]   = (V[i] * 10 + d) % MOD;
                cnt[i + 1] = cnt[i] + 1;
            } else {                          // zero: V aur cnt jaise the waise rehte hain
                V[i + 1]   = V[i];
                cnt[i + 1] = cnt[i];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int k = cnt[r + 1] - cnt[l];                             // range mein non-zero digits
            long long x   = (V[r + 1] - V[l] * pow10[k] % MOD + MOD) % MOD;
            long long sum = ps[r + 1] - ps[l];                       // <= 9*10^5, fit ho jata hai, mod ki zaroorat nahi
            ans.push_back((int)(x * sum % MOD));
        }
        return ans;
    }
};