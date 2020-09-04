class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 1; i <= n/2; i++) {
            if(!(n%i)){
                string temp = s.substr(0, i);
                int times = n/i;
                string tempFinal = "";
                while(times--){
                    tempFinal += temp;
                }
                if(tempFinal == s){
                    return true;
                }
            }
        }
        return false;
    }
};
