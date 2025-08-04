class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0, j = 0;
        int cnt = 0;
        int highestNoOfvowel = 0;
        while( j < s.size()){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                cnt++;
            }
            if((j-l+1) > k){
                if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u'){
                    cnt--;
                }
                l++;
            }
            highestNoOfvowel = max(highestNoOfvowel,cnt);

            j++;
        }
        return highestNoOfvowel;
    }
};