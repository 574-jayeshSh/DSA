class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = (n*(n+1)) / 2;
        int arraySum = 0;
        unordered_set<int>uniqueEle;

        for(auto it : nums){
            arraySum += it;
            uniqueEle.insert(it);
        }
        
        int uniqueSum = 0;
        for(auto it : uniqueEle){
            uniqueSum += it; 
        }

        return {(arraySum - uniqueSum) , (expectedSum - uniqueSum)};
    }
};