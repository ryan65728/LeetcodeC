#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    enum sign_state{
         UNUSE_SIGN = 0,
         USE_SIGN = 1,
         REVERS_SIGN = 2
    };
    enum dot_state{
         UNUSE_DOT = 0,
         USE_DOT = 1
    };
    enum expon_state{
         UNUSE_EXP = 0,
         USE_EXP = 1
    };
    enum num_state{
         UNUSE_NUM = 0,
         USE_NUM = 1
    };
    struct string_state{
         sign_state   st;
         dot_state    dt;
         expon_state  et;
         num_state    nt;
    };
    bool isNumber(string s) {
        string_state ss;
        ss.st = UNUSE_SIGN;
        ss.dt = UNUSE_DOT;
        ss.et = UNUSE_EXP;
        ss.nt = UNUSE_NUM;
        for(char& c : s){
            switch(c){
                case '+':
                case '-':
                    if(ss.st == UNUSE_SIGN)
                        ss.st = USE_SIGN;
                    else
                        return false;
                    break;
                case '.':
                    if(ss.dt == UNUSE_DOT)
                        ss.dt = USE_DOT;
                    else
                        return false;
                    break;
                case 'e':
                case 'E':
                    if(ss.et == UNUSE_EXP && ss.nt == USE_NUM){
                        ss.et = USE_EXP;
                        ss.st = REVERS_SIGN;
                        ss.nt = UNUSE_NUM;
                        ss.dt = USE_DOT;
                    }else
                        return false;
                    break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    ss.nt = USE_NUM;
                    break;
                default:
                    return false;
            }
            if(ss.st == REVERS_SIGN){
                ss.st = UNUSE_SIGN;
            }else{
                 ss.st = USE_SIGN;
            }
        }
        if(ss.nt == USE_NUM)
            return true;
        else
            return false;
    }
};

int main()
{

    string test[] = {"2",
                     "0089",
                    "-0.1",
                    "+3.14",
                    "4.",
                    "-.9",
                    "2e10",
                    "-90E3",
                    "3e+7",
                    "+6e-1",
                    "53.5e93",
                    "-123.456e789",
                    "abc", 
                    "1a", 
                    "1e", 
                    "e3", 
                    "99e2.5", 
                    "--6", 
                    "-+3", 
                    "95a54e53",
                    "-0.0e+0",
                    "0",
                    ".",
                    "-",
                    "E",
                    "2e10+",
                    "-.E9"}; 
    Solution a;
    for(string i:test){
        cout << a.isNumber(i) <<endl;
    }
    return 0;
}