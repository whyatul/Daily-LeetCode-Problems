impl Solution {
    pub fn repeated_n_times(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        for i in 0..n - 1{
            if i+2 < n && nums[i] == nums[i+2]{
                return nums[i];
            }
            if nums[i] == nums[i + 1]{
                return nums[i];
            }
        }
        nums[0]
    }
}