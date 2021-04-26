class Solution {
public:
    bool isNumeric(string str) {
        // 数字 -- continue
        // 加减 -- 1、要在开头或者E的后面; 2、且后面不能是E
        // E -- 1、只能出现一次; 2、且不能在开头和最后
        // 小数点 -- 3、在e前只能出现1次,e后不行; 2、小数点后要有数字
        bool hasE = false;
        int dot = 0;
        for (int i = 0; i < str.size(); ++i) {
            //cout<<str[i]<<endl;
            if (str[i] >= '0' && str[i] <= '9') continue;
            if (str[i] == '+' || str[i] == '-') {
                if (i != 0 && str[i-1] != 'e' && str[i-1] != 'E') return false;
                if (i == str.size()-1 || str[i+1] == 'E' || str[i+1] == 'e') return false;
            } else if (str[i] == 'E' || str[i] == 'e') {
                if (hasE || i == 0 || i == str.size()-1) return false;
                hasE = true;
            } else if (str[i] == '.') {
                if (hasE) return false;
                if (dot > 0) return false;
                if (i == str.size()-1 || str[i+1] < '0' || str[i+1] > '9') return false;
                dot++;
            } else return false;
        }
        return true;
    }
};