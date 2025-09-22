class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>freq(101 , 0);
        int maxFreq = 1;
        for(auto it : nums){
            if(freq[it] != 0){ 
                freq[it]++;
                maxFreq = max(maxFreq , freq[it]);
            }
            else{
                freq[it]++;
            };
        }

        int totalFreq = 0;

        for(auto it : freq){
            if(it == maxFreq) totalFreq += maxFreq;
        }

        return totalFreq;
    }
};