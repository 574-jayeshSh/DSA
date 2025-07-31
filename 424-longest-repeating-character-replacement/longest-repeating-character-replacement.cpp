class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxFreq = 0;
        int maxLen = 0;
        vector<int> charCount(26, 0); // for uppercase A-Z

        for (r = 0; r < s.length(); r++) {
            charCount[s[r] - 'A']++;
            maxFreq = max(maxFreq, charCount[s[r] - 'A']);

            // if more than k chars need to be replaced
            if ((r - l + 1) - maxFreq > k) {
                charCount[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
