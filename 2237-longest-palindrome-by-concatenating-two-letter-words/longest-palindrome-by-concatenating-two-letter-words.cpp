class Solution {
public:
    int longestPalindrome(vector<string>& words) {

        unordered_map<string, int> not_similar;
        unordered_map<string, int> similar;
        int count = 0;
        bool center = false;

        for (auto it : words) {
            if (it[0] == it[1]) {
                similar[it]++;
            } else {
                not_similar[it]++;
            }
        }

        // Handle non-similar words like "ab" and "ba"
        for (auto it : not_similar) {
            string key = it.first;
            string s = "";

            s += key[1];   // reverse string
            s += key[0];

            if (not_similar.find(s) != not_similar.end()) {
                count += 4 * min(not_similar[s], not_similar[key]);

                // avoid double counting
                not_similar[s] = 0;
                not_similar[key] = 0;
            }
        }

        // Handle similar words like "aa", "bb"
        for (auto it : similar) {

            count += (it.second / 2) * 4;

            // one odd frequency word can be center
            if (it.second % 2 == 1) {
                center = true;
            }
        }

        if (center) count += 2;

        return count;
    }
};