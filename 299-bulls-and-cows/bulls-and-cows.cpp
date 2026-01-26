class Solution {
public:
    string getHint(string secret, string guess) {
       int bulls = 0, cows = 0;
        unordered_map<char, int> freq;

        // First pass: count bulls & store non-bulls
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                freq[secret[i]]++;
            }
        }

        // Second pass: count cows
        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] != guess[i] && freq[guess[i]] > 0) {
                cows++;
                freq[guess[i]]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};