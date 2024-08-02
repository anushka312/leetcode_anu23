// https://leetcode.com/problems/valid-anagram/
// Complexity: Time: O(n) Space: O(CHAR)
// 256 is used because it covers ASCII character set
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int char_array[256];
        for(int i = 0; i<s.size(); i++){
            char_array[s[i]]++;
            char_array[t[i]]--;
        }
        for(int i = 0; i<256; i++){
            if(char_array[i] != 0){
                return false;
            }
        }
        return true;

    }
};
// first approach: 
// Complexity: Time: O(nlogn) Space: O(1)
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         int i = 0, j = 0;
//         int m = s.size();
//         int n = t.size();
//         while(i<m || j<n){
//             if(s[i] == t[j]){
//                 i++;
//                 j++;
//             }else{
//                 return false;
//             }
//         }
//         return true;
//     }
// };