class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<bool> toRemove(n, false);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                if (!stk.empty()) {
                    stk.pop();
                } else {
                    toRemove[i] = true;
                }
            }
        }
        while (!stk.empty()) {
            toRemove[stk.top()] = true;
            stk.pop();
        }
        string result;
        for (int i = 0; i < n; i++) {
            if (!toRemove[i]) {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
