class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string& word : words) {
            int l = 0, r = word.size() - 1;
            while (l < r && word[l] == word[r]) {
                l++;
                r--;
            }
            if (l >= r) return word;
        }
        return "";
    }
};
