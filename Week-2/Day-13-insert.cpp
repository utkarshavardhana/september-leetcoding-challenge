class Solution { // Whenever found 'sorted' in given input, do not forget binary search
public: // Time/Space: O(N); O(1)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {        
        auto it = upper_bound(intervals.begin(), intervals.end(), newInterval, 
                              [](auto& a, auto& b){return a[0] < b[0];}); //Time Complexity log(N)
        intervals.insert(it, newInterval);
        
        vector<vector<int>> ans;
        for(auto& e: intervals){
            if(ans.empty() ||              // thinking step2: handle corner cases to avoid crash --- defensive coding.
               e[0] > ans.back()[1])   // thinking step1: check normal case first
                ans.push_back(e);
            else ans.back()[1] = max(ans.back()[1], e[1]);
        }
        return ans;
    }
};
