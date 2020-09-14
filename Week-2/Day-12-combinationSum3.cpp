class Solution {
public:
    
    void helper(vector<int>& cur_arr, int k, int n, vector<vector<int>>& rtn) {
        if (cur_arr.size() == k) {
            if (accumulate(cur_arr.begin(), cur_arr.end(), 0) == n) {
                rtn.push_back(cur_arr);
            }
            return;
        }
        for (auto i = 1; i < 10; i++) {
            if (cur_arr.size() > 0 && i <= cur_arr.back()) continue;
            cur_arr.push_back(i);
            helper(cur_arr, k, n, rtn);
            cur_arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> rtn;
        vector<int> cur_arr;
        helper(cur_arr, k, n, rtn);
        return rtn;
    }
};
