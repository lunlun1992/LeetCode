//每一位做一次
class Solution {
public:
    string intToRoman(int num) 
    {
        string ret;
        while(num >= 1000)
        {
            ret += "M";
            num -= 1000;
        }
        
        switch(num / 100)
        {
        case 9:
            ret += "CM";
            num -= 900;
            break;
        case 8:
            ret += "DCCC";
            num -= 800;
            break;
        case 7:
            ret += "DCC";
            num -= 700;
            break;
        case 6:
            ret += "DC";
            num -= 600;
            break;
        case 5:
            ret += "D";
            num -= 500;
            break;
        case 4:
            ret += "CD";
            num -= 400;
            break;
        case 3:
            ret += "CCC";
            num -= 300;
            break;
        case 2:
            ret += "CC";
            num -= 200;
            break;
        case 1:
            ret += "C";
            num -= 100;
            break;
        }
        
        switch(num / 10)
        {
        case 9:
            ret += "XC";
            num -= 90;
            break;
        case 8:
            ret += "LXXX";
            num -= 80;
            break;
        case 7:
            ret += "LXX";
            num -= 70;
            break;
        case 6:
            ret += "LX";
            num -= 60;
            break;
        case 5:
            ret += "L";
            num -= 50;
            break;
        case 4:
            ret += "XL";
            num -= 40;
            break;
        case 3:
            ret += "XXX";
            num -= 30;
            break;
        case 2:
            ret += "XX";
            num -= 20;
            break;
        case 1:
            ret += "X";
            num -= 10;
            break;
        }
        
        switch(num)
        {
        case 9:
            ret += "IX";
            num -= 90;
            break;
        case 8:
            ret += "VIII";
            num -= 80;
            break;
        case 7:
            ret += "VII";
            num -= 70;
            break;
        case 6:
            ret += "VI";
            num -= 60;
            break;
        case 5:
            ret += "V";
            num -= 50;
            break;
        case 4:
            ret += "IV";
            num -= 40;
            break;
        case 3:
            ret += "III";
            num -= 30;
            break;
        case 2:
            ret += "II";
            num -= 20;
            break;
        case 1:
            ret += "I";
            num -= 10;
            break;
        }
        return ret;
    }
};