// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn max_product(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
   const MOD: i64 = 1_000_000_007;
        let mut max_prod: i64 = 0;
        let total_sum = Self::calculate_sum(&root);
        
        Self::find_max_product(&root, total_sum, &mut max_prod);
        
        (max_prod % MOD) as i32
    }
    
    
    fn calculate_sum(node: &Option<Rc<RefCell<TreeNode>>>) -> i64 {
        match node {
            None => 0,
            Some(n) => {
                let n = n.borrow();
                n.val as i64 
                    + Self::calculate_sum(&n.left) 
                    + Self::calculate_sum(&n.right)
            }
        }
    }
    
    fn find_max_product(
        node: &Option<Rc<RefCell<TreeNode>>>,
        total_sum: i64,
        max_prod: &mut i64
    ) -> i64 {
        match node {
            None => 0,
            Some(n) => {
                let n = n.borrow();
                let left_sum = Self::find_max_product(&n.left, total_sum, max_prod);
                let right_sum = Self::find_max_product(&n.right, total_sum, max_prod);
                let curr_sum = n.val as i64 + left_sum + right_sum;
                let product = curr_sum * (total_sum - curr_sum);
                *max_prod = (*max_prod).max(product);
                
                curr_sum
            }
        }
    }
}