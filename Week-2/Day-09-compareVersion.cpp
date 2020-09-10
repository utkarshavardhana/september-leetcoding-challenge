class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        int t = 0;
        for(char c : version1) {
            if(c == '.') {
                v1.push_back(t);
                t = 0;
            } else {
                t *= 10;
                t += c - '0';
            }
        }
        v1.push_back(t);
        t = 0;
        for(char c : version2) {
            if(c == '.') {
                v2.push_back(t);
                t = 0;
            } else {
                t *= 10;
                t += c - '0';
            }
        }
        v2.push_back(t);
        if(v1.size() < v2.size()) {
            t = v2.size() - v1.size();
            while(t--) {
                v1.push_back(0);
            }
        } else if(v1.size() > v2.size()) {
            t = v1.size() - v2.size();
            while(t--) {
                v2.push_back(0);
            }
        }
        for(int i=0; i<v1.size(); i++) {
            if(v1[i] > v2[i])   return 1;
            if(v2[i] > v1[i])   return -1;
        }
        return 0;
    }
};
