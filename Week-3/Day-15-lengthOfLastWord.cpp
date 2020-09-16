class Solution {
public:
    int lengthOfLastWord(string s) {
        int j=0;
        const auto strBegin = s.find_first_not_of(" \t");
        if (strBegin == std::string::npos)  return 0;
        const auto strEnd = s.find_last_not_of(" \t");
        const auto strRange = strEnd - strBegin + 1;
        s = s.substr(strBegin, strRange);
        for(int i=0; i<s.size(); i++) if(s[i] == ' ')    j = i+1;
        return s.size()-j;
    }
};
