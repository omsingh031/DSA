class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // 1. Convert knowledge into a hash map for O(1) lookups
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        
        string result = "";
        string current_key = "";
        bool inside_bracket = false;
        
        // 2. Iterate through the string character by character
        for (char c : s) {
            if (c == '(') {
                inside_bracket = true;
                current_key = ""; // Reset the key buffer
            } 
            else if (c == ')') {
                inside_bracket = false;
                // Look up the key in our map
                if (dict.find(current_key) != dict.end()) {
                    result += dict[current_key];
                } else {
                    result += "?"; // Key not found
                }
            } 
            else {
                if (inside_bracket) {
                    // Build the key
                    current_key += c;
                } else {
                    // Build the normal result string
                    result += c;
                }
            }
        }
        
        return result;
    }
};