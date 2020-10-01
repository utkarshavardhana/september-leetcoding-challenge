class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s == "") return true;
        vector<int> dp(s.size(), -1);
        return wordBreakHelper(s, wordDict, 0, dp);
    }
    
    bool wordBreakHelper(string s, vector<string>& wordDict, int start, vector<int>& dp) { 
        if (start == s.size()) return true; 
        if (dp[start] != -1) {
            return dp[start];
        } else {  
            bool wordBroken = false;
            for (auto &word : wordDict) {
                size_t found = s.find(word, start);
                if (((int) found) == start) {
                    if (wordBreakHelper(s, wordDict, start + word.size(), dp)) {
                        wordBroken = true;
                        break;
                    }
                }
            }
            dp[start] = wordBroken ? 1 : 0;
            return dp[start];
        }
        
    }
};
