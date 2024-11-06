class Solution {
    int countSetBits(int number) {
        int cnt = 0;
        while (number != 0) {
            number = number & (number - 1);
            cnt++;
        }
        return cnt;
    }

public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        bool swapped = true;
        for (int i = 0; i < n; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1] &&
                    countSetBits(nums[j]) == countSetBits(nums[j + 1])) {
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                } else if (nums[j] <= nums[j + 1]) {
                    continue;

                } else {
                    return false;
                }
            }
            if (swapped == false) {
                return true;
            }
        }
        return false;
    }
};