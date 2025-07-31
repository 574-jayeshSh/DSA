class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int l = 0, r = 0;
        int n = s.size();
        int maxlen = 0 , maxfreq = 0 ;
        vector<int> mpp(2,0);

        while( r != n){
            s[r] == 'T' ? mpp[1]++ : mpp[0]++;
            maxfreq = max(maxfreq, max(mpp[1],mpp[0]));

            if((r-l+1) - maxfreq > k){
               s[l] == 'T' ? mpp[1]-- : mpp[0]--;
               l++; 
            }
             maxlen = max(maxlen, r - l + 1);
             r++;
        }
        return maxlen;
    }
};