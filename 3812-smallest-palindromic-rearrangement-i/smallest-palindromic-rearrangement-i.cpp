class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> freqMap;
        
        // 1. Extract all characters into an ordered map
        for (char c : s) {
            freqMap[c]++;
        }
        
        string left = "";
        string mid = "";
        
        // 2 & 3. Place in alphabetical order and find the odd one
        for (auto const& [ch, count] : freqMap) {
            // If the count is odd, this character goes in the middle
            if (count % 2 != 0) {
                mid = ch;
            }
            // Append half of the occurrences to the left string
            // string(n, char) creates a string with 'n' copies of 'char'
            left += string(count / 2, ch); 
        }
        
        // 4. Create the right side by mirroring the left
        string right = left;
        reverse(right.begin(), right.end());
        
        // 5. Add all three
        return left + mid + right;
    }
};