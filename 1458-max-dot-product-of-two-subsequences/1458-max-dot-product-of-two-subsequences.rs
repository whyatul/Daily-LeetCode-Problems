impl Solution {
    pub fn max_dot_product(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let m = nums1.len();
        let n = nums2.len();
        
        let mut dp = vec![vec![i32::MIN; n + 1]; m + 1];
        
        for i in 1..=m {
            for j in 1..=n {
                let product = nums1[i-1] * nums2[j-1];
                
                let with_prev = if dp[i-1][j-1] == i32::MIN {
                    product
                } else {
                    dp[i-1][j-1] + product
                };
                let just_current = product;
                
                let skip_first = dp[i-1][j];
                
                let skip_second = dp[i][j-1];
                
                dp[i][j] = with_prev.max(just_current).max(skip_first).max(skip_second);
            }
        }
        
        dp[m][n]
    }
}
