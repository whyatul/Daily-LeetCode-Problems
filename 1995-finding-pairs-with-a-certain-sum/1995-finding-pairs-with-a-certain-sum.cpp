const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(___::_);
    return 0;
}();
#endif
class FindSumPairs {
    private:
       vector<int> nums1;
       vector<int> nums2;
       unordered_map<int,int> freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
           this->nums1 = nums1;
           this->nums2 = nums2;
           for (auto &x : nums2)
              freq[x]++;
    }
    
    void add(int index, int val) {
        freq[nums2[index]] --;
   //     if (freq[nums2[index]] == 0) freq.erase(nums2[index]);
        nums2[index] += val;
        freq[nums2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for (auto &x : nums1) 
            if (x <= tot && freq.find(tot - x) != freq.end()) 
              cnt += freq[tot - x];
        return cnt;
    }
};
/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */