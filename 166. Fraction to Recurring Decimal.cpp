//本题十分繁琐
//1.首先要确定符号，对于0直接返回0
//2.类型全部采用64bit类型
//3.先把整形数打上去
//4.然后再把小数打上去，方式是用map记录每一次的被除数（不是余数！！）
class Solution {
public:
    unordered_map<int64_t, int64_t> mp;
    string fractionToDecimal(int numerator, int denominator) {
        string ret = "";
        int64_t nu = (int64_t)numerator;
        int64_t de = (int64_t)denominator;
        if(nu == 0)
            return "0";
        if(nu < 0 ^ de < 0)
            ret += "-";
        nu = abs(nu);
        de = abs(de);
        ret += to_string(nu / de);
        
        
        int64_t res = (nu % de) * 10;
        if (res)
            ret.push_back('.');
        while (res) {
            if (mp.count(res)) {
                ret.insert(mp[res], 1, '(');
                ret.push_back(')');
                break;
            }
            mp[res] = ret.size();
            ret.append(to_string(res / de));
            res = (res % de) * 10;
        }
        return ret;
    }
};