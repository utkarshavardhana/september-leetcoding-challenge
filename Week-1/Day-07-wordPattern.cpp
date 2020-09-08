class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = split(str, ' ');
        map<char, string> table;
        if (pattern.size() != words.size()) {
            return false;
        }
        for (auto i = 0; i < pattern.size(); ++ i) {
            auto c = pattern[i];
            auto iter = table.find(c);
            if (iter == table.end()) {
                for (auto item : table) {
                    if (item.second == words[i]) {
                        return false;
                    }
                }
                table.insert(make_pair(c, words[i]));
            } else {
                if (iter->second != words[i]) {
                    return false;
                }
            }
        }
        return true;
	}

	vector<string> split(const std::string& str, char delim) {
        vector<string> words;
        stringstream ss;
        ss.str(str);
        string item;
        while (getline(ss, item, delim)) {
            words.push_back(item);
        }
        return std::move(words);
	}
};
