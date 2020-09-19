class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)  return 0;
        int mx = 0, mn = prices[0];
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] > mn)  mx = max(mx, prices[i]-mn);
            mn = min(mn, prices[i]);
        }
        return mx;
    }
};
