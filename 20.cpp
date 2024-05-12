#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
    vector<int> bracket;
    bool isValid(string s) {
        for(char &a : s){
            switch(a){
                case '(':
                    bracket.push_back(1);
                    break;
                case '[':
                    bracket.push_back(2);
                    break;
                case '{':
                    bracket.push_back(3);
                    break;
                case ')':
                    if(bracket.empty() || !(bracket.back() == 1))
                        return false;
                    bracket.pop_back();
                    break;
                case ']':
                    if(bracket.empty() ||!(bracket.back() == 2))
                        return false;
                    bracket.pop_back();
                    break;
                case '}':
                    if(bracket.empty() ||!(bracket.back() == 3))
                        return false;
                    bracket.pop_back();
                    break;
            }
        }
        if(bracket.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    Solution a;
    cout << a.isValid("([)]") << endl;
}