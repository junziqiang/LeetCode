#include<bits/stdc++.h>
using namespace std;
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
*/

class Solution {
public:
    unordered_map<char,char> num={
        {'{','}'},
        {'[',']'},
        {'(',')'}
    };
    bool isValid(string s) {
        if(s.empty())
            return true;
        else if(s.size()%2)
            return false;
        else{
            stack<char> ss;
            for (int i = 0; i < s.size(); i++)
            {
                if(ss.empty())
                    ss.push(s[i]);
                else{
                    if(s[i]==num[ss.top()])
                        ss.pop();
                    else{
                        ss.push(s[i]);
                    }
                }
                /* code */
            }
            
        }

    }
};