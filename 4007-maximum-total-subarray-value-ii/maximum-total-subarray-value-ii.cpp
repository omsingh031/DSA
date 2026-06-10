#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

class SparseTable {
    vector<vector<int>> st_max;
    vector<vector<int>> st_min;
    vector<int> lg;

public:
    void init(const vector<int>& nums) {
        int n = nums.size();
        int max_log = 32 - __builtin_clz(n);
        st_max.assign(n, vector<int>(max_log));
        st_min.assign(n, vector<int>(max_log));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        for (int i = 0; i < n; i++) {
            st_max[i][0] = nums[i];
            st_min[i][0] = nums[i];
        }

        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i <= n - (1 << j); i++) {
                st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
                st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query_max(int l, int r) {
        int k = lg[r - l + 1];
        return max(st_max[l][k], st_max[r - (1 << k) + 1][k]);
    }

    int query_min(int l, int r) {
        int k = lg[r - l + 1];
        return min(st_min[l][k], st_min[r - (1 << k) + 1][k]);
    }
};

struct Subarray {
    long long value;
    int l;
    int r;
    bool operator<(const Subarray& other) const {
        return value < other.value;
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SparseTable st;
        st.init(nums);

        priority_queue<Subarray> pq;

        for (int l = 0; l < n; l++) {
            long long val = (long long)st.query_max(l, n - 1) - st.query_min(l, n - 1);
            pq.push({val, l, n - 1});
        }

        long long total_value = 0;

        for (int i = 0; i < k; i++) {
            Subarray curr = pq.top();
            pq.pop();

            total_value += curr.value;

            if (curr.r > curr.l) {
                long long next_val = (long long)st.query_max(curr.l, curr.r - 1) - st.query_min(curr.l, curr.r - 1);
                pq.push({next_val, curr.l, curr.r - 1});
            }
        }

        return total_value;
    }
};