// Complexity: time : O(n^2) : space : O(1) / auxiliary
// if we would have used a temp string, time complexity would have 
// been O(n)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == goal[0]){
                if(s.substr(i) == goal.substr(0, goal.length() - i)){
                    if(s.substr(0, i) == goal.substr(s.length() - i)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
