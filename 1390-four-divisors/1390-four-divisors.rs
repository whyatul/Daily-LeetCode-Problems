impl Solution {
    pub fn sum_four_divisors(nums: Vec<i32>) -> i32 {
        
 let mut total_sum = 0;
        
        for &num in &nums {
            let mut divisor_count = 0;
            let mut divisor_sum = 0;
            let sqrt_num = (num as f64).sqrt() as i32;
            
            for i in 1..=sqrt_num {
                if num % i == 0 {
                    divisor_count += 1;
                    divisor_sum += i;
                    
                    if i != num / i {
                        divisor_count += 1;
                        divisor_sum += num / i;
                    }
                    if divisor_count > 4 {
                        break;
                    }
                }
            }
            if divisor_count == 4 {
                total_sum += divisor_sum;
            }
        }
        
        total_sum
    }
}