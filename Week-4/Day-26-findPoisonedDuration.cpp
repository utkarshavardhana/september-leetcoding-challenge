class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        long long res = 0;
        if(timeSeries.empty())  return 0;
        res = duration * timeSeries.size();
        for(int i=1; i<timeSeries.size(); i++)  if((timeSeries[i]-timeSeries[i-1]) < duration)  
            res -= duration - (timeSeries[i] - timeSeries[i-1]);
        return res;
    }
};
