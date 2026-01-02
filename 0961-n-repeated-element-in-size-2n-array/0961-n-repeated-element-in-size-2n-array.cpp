class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for(auto i = 0; i < n-1 ; i++){
            if(i+2 < n && nums[i] == nums[i+2]){
                return nums[i];
            }
            if(nums[i] == nums[i+1]){
                return nums[i];
            }
        }
        return nums[0];
    }
};