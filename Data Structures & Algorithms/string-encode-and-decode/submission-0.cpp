class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for (string s : strs) {
            result += to_string(s.size()) + "#" + s;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            // # find karo
            while (s[j] != '#') {
                j++;
            }

            // length nikalo
            int len = stoi(s.substr(i, j - i));

            // actual string nikalo
            string word = s.substr(j + 1, len);

            result.push_back(word);

            // next encoded string par jao
            i = j + 1 + len;
        }

        return result;
    }
};