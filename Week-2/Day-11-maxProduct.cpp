class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        vector<int> pos(nums.size(), 1), neg(nums.size(), 1);
        pos[0] = max(nums[0], 0), neg[0] = min(nums[0], 0);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] >= 0) {
                pos[i] = max(nums[i], pos[i-1]*nums[i]);
                neg[i] = min(nums[i]*neg[i-1], 0);
            } else {
                pos[i] = max(0, neg[i-1]*nums[i]);
                neg[i] = min(nums[i], nums[i]*pos[i-1]);
            }
        }
        int mx = INT_MIN;
        for(int i : pos)    mx = max(mx, i);
        for(int i : neg)    mx = max(mx, i);
        return mx;
    }
};
