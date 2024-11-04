// class Solution {
// public:
//     string compressedString(string word) {
//         int n =word.length();
//         int i=0;
//         int cnt=0;
//         char ch=word[0];
//         string ans="";
//         while(i<n){
//             if(word[i]==ch && cnt<9){
//                 cnt++;
//             }else if(word[i]==ch && cnt==9){
//                 ans=ans+to_string(cnt)+ch;
//                 cnt=1;
//             }
//             else if(word[i]!=ch){
//                 ans=ans+to_string(cnt)+ch;
//                 ch=word[i];
//                 cnt=1;
//             }
//             i++;
//         }
//         ans=ans+to_string(cnt)+ch;
//         return ans;
//     }
// };

class Solution {
public:
    string compressedString(string word) {
        int n =word.length();
        string ans="";
        int i=0;
        while(i<n){
            int cnt=0;
            char ch=word[i];
            while(i<n && cnt<9 && word[i]==ch){
                cnt++;
                i++;
            }
            ans+=to_string(cnt)+ch;
        }
        return ans ;
    }
};