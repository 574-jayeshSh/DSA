class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n == 1) return {0};

        if(n % 2 == 0){
            int st = n/2;
            for(int i = n/2; i>0 ; i--){
                ans.push_back(i);
                ans.push_back(-i); 
            }
        }
        else{
            for(int i = -n/2 ; i<=n/2 ;i++){
                ans.push_back(i);
            }
        }

        return ans;
    }
};