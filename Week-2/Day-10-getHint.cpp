class Solution {
public:
    string getHint(string secret, string guess) {
        int b = 0, c = 0;
        map<char, int> ss, gs;
        for(int i=0; i<secret.size(); i++) {
            if(secret[i] == guess[i])   b++;
            else {
                ss[guess[i]]++;
                gs[secret[i]]++;
            }
        }
        for(auto it=ss.begin(); it!=ss.end(); it++) {
            if(gs[(*it).first]) {
                c += min(gs[(*it).first], (*it).second);
                gs[(*it).first] -= min(gs[(*it).first], (*it).second);
            }
        }
        string str = to_string(b) + "A" + to_string(c) + "B";
        return str;
    }
};
