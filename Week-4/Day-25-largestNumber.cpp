class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            string s1 = to_string(a);
            string s2 = to_string(b);
            return s1+s2 > s2+s1;
        });
        string str;
        int count = 0;
        for(int i : nums) {
            str += to_string(i);
            if(i != 0)  count++;
        }
        if(!count)  return "0";
        return str;
    }
};
