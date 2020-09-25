class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch = 0;
        for(char c : s)    ch = ch xor c;
        for(char c : t)    ch = ch xor c;
        return ch;
    }
};
