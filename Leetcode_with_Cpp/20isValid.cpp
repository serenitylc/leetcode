class Solution {
public:
    bool isValid(string s) {
        stack<int> S;
        for(int i = 0; i < s.size(); i++) {
            if(S.size() == 0)   S.push(s[i]);
            else if(S.top() =='(' && s[i] == ')')   S.pop();
            else if(S.top() =='{' && s[i] == '}')   S.pop(); 
            else if(S.top() =='[' && s[i] == ']')   S.pop(); 
            else S.push(s[i]);
        }
        if(S.size() == 0) 
            return true;
        else 
            return false;   
    }
};