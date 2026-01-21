class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
    vector<int> ans;

        for (int p : nums) {
            // count trailing 1s
            int k = 0;
            int temp = p;
            while (temp & 1) {
                k++;
                temp >>= 1;
            }

            if (k == 0) {
                ans.push_back(-1);
                continue;
            }

            // flip the highest trailing 1
            int x = p ^ (1 << (k - 1));
            ans.push_back(x);
        }

        return ans;
    }
};