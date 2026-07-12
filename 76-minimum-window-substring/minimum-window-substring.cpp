class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> mp;

        for (int i = 0; i < t.length(); i++) {
            mp[t[i]]++;
        }

        int n = s.length();

        int count = mp.size();
        int mini_window = INT_MAX;

        int idx1 = -1;
        int idx2 = -1;

        int i = 0;
        int j = 0;

        while (j < n) {

            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;

                if (mp[s[j]] == 0)
                    count--;
            }

            while (count == 0) {

                int window = j - i + 1;

                if (window < mini_window) {
                    mini_window = window;
                    idx1 = i;
                    idx2 = j;
                }

                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;

                    if (mp[s[i]] > 0)
                        count++;
                }

                i++;
            }

            j++;
        }

        if (idx1 == -1)
            return "";

        return s.substr(idx1, mini_window);
    }
};