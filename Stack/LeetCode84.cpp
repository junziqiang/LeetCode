/**
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * **/
#include<bits/stdc++.h>
using namespace std;
//使用单调递增栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> stack;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++)
        {
            while (!stack.empty()&&heights[i]<heights[stack.top()])
            {
                int index = stack.top();
                stack.pop();
                if(stack.empty())
                    ans = max(ans,i*heights[index]);
                int width = i-stack.top() -1;
                int hg = heights[index];
                ans = max(ans,width*hg);
                /* code */
            }
            stack.push(i);
            /* code */
        }
        return ans;
        
    }
};