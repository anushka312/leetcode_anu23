// https://leetcode.com/problems/largest-odd-number-in-string/
// Complexity: Time: O(n) Space: O(1)
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size() - 1;
        // checking the ones place
        if(num[n] % 2 != 0){
            return num;
        }else{
            while(n>=0 && num[n]%2 == 0){
                --n;
            }
        }
        if(n < 0){
            return "";
        }
        // return num.substr(0, n+1);
        return num.erase(n+1);
    }
};