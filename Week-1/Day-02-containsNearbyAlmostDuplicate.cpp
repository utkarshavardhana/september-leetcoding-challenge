class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int,int> > nn;
        for (int i = 0; i < nums.size(); i++) {
            nn.push_back(make_pair(nums[i], i));
        }
        sort(nn.begin(), nn.end());
        
        for (int i = 1; i < nn.size(); i++) {
            for (int j = 1; i-j >= 0 and nn[i].first <= t + nn[i-j].first; j++)
                if (abs(nn[i].second - nn[i-j].second) <= k)
                    return true;
        }
        return false;
    }
};
