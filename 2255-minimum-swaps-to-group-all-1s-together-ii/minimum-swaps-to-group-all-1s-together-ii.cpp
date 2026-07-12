class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int n = nums.size();

        vector<int> newnums;
        for (auto it : nums)
            newnums.push_back(it);

       
        for (auto it : nums)
            newnums.push_back(it);

        int count_ones = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                count_ones++;
        }

        if (count_ones == 0 || count_ones == 1)
            return 0;

        int i = 0;
        int j = 0;

        int curr_ones = 0;
        int ans = INT_MAX;

        while (j < newnums.size()) {

            if (newnums[j] == 1)
                curr_ones++;

          
            while (j - i + 1 > count_ones) {
                if (newnums[i] == 1)
                    curr_ones--;
                i++;
            }

           
            if (j - i + 1 == count_ones && i < n) {
                ans = min(ans, count_ones - curr_ones);
            }

            j++;
        }

        return ans;
    }
};