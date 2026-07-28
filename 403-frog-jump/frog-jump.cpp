class Solution {
public:
    unordered_map<int, int> mp;
    map<pair<int, int>, bool> dp;

    bool f(vector<int>& stones, int n, int curr_index, int lastjump) {
        if (curr_index == n - 1)
            return true;

        if (dp.count({curr_index, lastjump}))
            return dp[{curr_index, lastjump}];

        bool ans = false;

        int currPos = stones[curr_index];

        
        if (mp.find(currPos + lastjump) != mp.end()) {
            ans |= f(stones, n, mp[currPos + lastjump], lastjump);
        }
 
        if (lastjump > 1 && mp.find(currPos + lastjump - 1) != mp.end()) {
            ans |= f(stones, n, mp[currPos + lastjump - 1], lastjump - 1);
        }

       
        if (mp.find(currPos + lastjump + 1) != mp.end()) {
            ans |= f(stones, n, mp[currPos + lastjump + 1], lastjump + 1);
        }

        return dp[{curr_index, lastjump}] = ans;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if (stones[1] != 1)
            return false;

        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        return f(stones, n, 1, 1);
    }
};