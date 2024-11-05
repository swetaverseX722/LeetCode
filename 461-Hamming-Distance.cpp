class Solution {
public:
    int hammingDistance(int x, int y) {
        int XOR;
        XOR=x^y;
        int cnt=0;
        while(XOR>0){
            if(XOR%2==1) cnt++;
              XOR=XOR/2;
        }
        return cnt;
    }
};