class Solution {
public:
    // Sum of first 'index' natural numbers
    long long calculate(long long index){
        return index * (index + 1) / 2;
    }

    // Sum of one side (left or right) given side length and peak value
    long long getSumByFormula(long long side, long long mid) {
        if (side < mid - 1) {
            // strictly decreasing sequence
            return calculate(mid - 1) - calculate(mid - 1 - side);
        } else {
            // decreasing down to 1, then fill remaining with 1's
            return calculate(mid - 1) + (side - (mid - 1));
        }
    }

    // Total sum of array if peak value at index is 'mid'
    long long check(long long mid, long long n, long long index){
        long long leftSum = getSumByFormula(index, mid);
        long long rightSum = getSumByFormula(n - index - 1, mid);
        return leftSum + mid + rightSum;
    }

    int maxValue(int n, int index, int maxSum) {
        int low = 1, high = maxSum;
        int result = 0;

        while (low <= high){
            int mid = low + (high - low) / 2;

            if (check(mid, n, index) <= maxSum){
                result = mid;  // safe, always increasing
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};
