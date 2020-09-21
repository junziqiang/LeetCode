/***
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * **/


/**
 * 代码模板
 * stack<int> st;
for(int i = 0; i < nums.size(); i++)
{
	while(!st.empty() && st.top() > nums[i])
	{
		st.pop();
	}
	st.push(nums[i]);
}
 * **/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stack;
        for (int i = 0; i < height.size(); i++)
        {
            while (!stack.empty()&&height[i]>height[stack.top()])
            {
                int index = stack.top();
                stack.pop();
                if(stack.empty())
                    break;
                int width = i - stack.top()-1;
                //最矮的墙减去底层墙的高度
                int hg = min(height[i],height[stack.top()])-height[index]; 
                ans+=width*hg;
                /* code */
            }
            stack.push(i);
            /* code */
        }
        return ans;
        
    }
};