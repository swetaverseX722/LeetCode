class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int index = 0;
        while (i < n) {
            int cnt = 0;
            char ch = chars[i];
            while (i < n && ch == chars[i]) {
                cnt++;
                i++;
            }
            chars[index++] = ch;
            if (cnt > 1) {
                string str = to_string(cnt);
                for (char c : str) {
                    chars[index++] = c;
                }
            }
        }
        return index;
    }
};