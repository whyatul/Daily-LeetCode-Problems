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
    pub fn max_level_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut level_sums = Vec::new();
        Self::dfs(&root, 0, &mut level_sums);
        
        level_sums.iter()
            .enumerate()
            .max_by(|a, b| {
                // Compare sums, but if equal, prefer smaller index (earlier level)
                match a.1.cmp(b.1) {
                    std::cmp::Ordering::Equal => b.0.cmp(&a.0), // reverse index comparison
                    other => other,
                }
            })
            .map(|(idx, _)| (idx + 1) as i32)
            .unwrap_or(1)
    }
    
    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, level: usize, level_sums: &mut Vec<i32>) {
        if let Some(n) = node {
            let n_ref = n.borrow();
            
            if level >= level_sums.len() {
                level_sums.push(0);
            }
            
            level_sums[level] += n_ref.val;
            
            Self::dfs(&n_ref.left, level + 1, level_sums);
            Self::dfs(&n_ref.right, level + 1, level_sums);
        }
    }
}