class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
      int lo = 0, hi = letters.size();

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (letters[mid] <= target)
                lo = mid + 1;  
            else
                hi = mid;       
        }

        return letters[lo % letters.size()];
    }
};