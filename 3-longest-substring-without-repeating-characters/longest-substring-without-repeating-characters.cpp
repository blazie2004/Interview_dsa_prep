class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i=0, j = 0;
        int n = s.length();
        int maxi = 0;
        while (j < n) {
            mp[s[j]]++;
            int len = j - i + 1;

            if (mp.size() == len) {
                // all unique;
                maxi = max(len, maxi);
            }
            if (mp.size() < len) {
                // means repeating characters;
                while (mp.size() < len) {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                    len--;
                }
            }
            j++;
        }
        return maxi;
    }
};