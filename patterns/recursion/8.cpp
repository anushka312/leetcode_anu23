// Complexity: Time : O(n) Space : O(1)

class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int sign = 1;
        int i = 0;
        while(s[i] == ' ' && i < s.length()){
            i++;
        }
        while(i < s.length() && (s[i] == '+' || s[i] == '-')
        &&(isdigit(s[i+1]))){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }
        while(i < s.length() && isdigit(s[i])){
            int digit = s[i] - '0';
            
            if (ans > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            ans = ans * 10;
            ans = ans + digit;
            i++;
        }
        return sign*ans;
    }
};