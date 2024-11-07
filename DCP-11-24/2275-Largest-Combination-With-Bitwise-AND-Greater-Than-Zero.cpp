class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int result = 0;
        for (int i = 0; i < 24; i++) {  //Why 24? Since candidates is less than or equal to 10^7... the number of bits required would be less than or equal to log(10^7)+1

            int cnt = 0;
            for (int& num : candidates) {
                if ((num & (1 << i)) != 0) {
                    cnt++;
                }
            }
            result = max(result, cnt);
        }
        return result;
    }
};