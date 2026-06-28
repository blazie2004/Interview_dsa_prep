class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int maxi = 0;
        int i = 0;
        int j = 0;
        int count_ones = 0;

        while (j < nums.size()) {

            if (nums[j] == 1) count_ones++;

            int window_size = j - i + 1;

            if (window_size == count_ones) {
                // all are ones, so valid window
                maxi = max(maxi, window_size);
                j++;
            }
            else if (window_size > count_ones) {

                // zeros = window_size - count_ones
                if (window_size - count_ones <= k) {
                    maxi = max(maxi, window_size);
                    j++;
                }
                else {
                    // more zeros than allowed, shrink window
                    while (window_size - count_ones > k) {

                        if (nums[i] == 1) {
                            count_ones--;
                        }

                        i++;
                        window_size--;
                    }

                    // after shrinking, window is valid
                    maxi = max(maxi, window_size);
                    j++;
                }
            }
        }

        return maxi;
    }
};