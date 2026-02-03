class Solution {
public:
    bool isTrionic(vector<int>& nums) {
       int n = nums.size();
        
        // Try all valid p and q values
        for (int p = 1; p < n - 1; p++) {  // p must be > 0 and < n-1
            for (int q = p + 1; q < n - 1; q++) {  // q must be > p and < n-1
                // Check if nums[0...p] is strictly increasing
                bool isIncreasing = true;
                for (int i = 0; i < p; i++) {
                    if (nums[i] >= nums[i + 1]) {
                        isIncreasing = false;
                        break;
                    }
                }
                
                if (!isIncreasing) {
                    continue;
                }
                
                // Check if nums[p...q] is strictly decreasing
                bool isDecreasing = true;
                for (int i = p; i < q; i++) {
                    if (nums[i] <= nums[i + 1]) {
                        isDecreasing = false;
                        break;
                    }
                }
                
                if (!isDecreasing) {
                    continue;
                }
                
                // Check if nums[q...n-1] is strictly increasing
                bool isFinalIncreasing = true;
                for (int i = q; i < n - 1; i++) {
                    if (nums[i] >= nums[i + 1]) {
                        isFinalIncreasing = false;
                        break;
                    }
                }
                
                if (isFinalIncreasing) {
                    return true;
                }
            }
        }
        
        return false;
    }
};