class Solution {
public:
    bool check(long long x , int tar){
        if(x  == tar) return true;
        else if(x > tar ) return false;
        return check(x*3 , tar);

    }
    bool isPowerOfThree(int n) {
        if (n <= 0) return false; // negative numbers can't be powers of 3
        return check(1, n);
    }
};