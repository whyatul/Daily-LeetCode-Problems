class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
    vector<int> ans;
 for (int p : nums) {
            if (p % 2 == 0) {
                ans.push_back(-1);
                continue;
            }

            int found = -1;
            for (int x = 0; x < p; x++) {
                if ((x | (x + 1)) == p) {
                    found = x;
                    break;
                }
            }
            ans.push_back(found);
        }

        return ans;
    }
};