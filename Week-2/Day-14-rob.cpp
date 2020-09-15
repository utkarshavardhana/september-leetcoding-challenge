class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int pre2 = 0, pre1 = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            pre2 = max(pre2 + nums[i], pre1);
            swap(pre2, pre1);
        }
        return pre1;
    }
};
