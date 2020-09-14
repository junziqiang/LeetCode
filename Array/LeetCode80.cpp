/**
 * 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 * **/


/**
 * 使用快慢指针
 * 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int i = 0;
        for(int j = 0; j<nums.size();j++){
            /**
             *  nums[i-2] < nums[j] 
                如果重复数字个数不大于2，那么这个判断肯定是成立的
                如果重复个数大于2，那么nums[i-2] < nums[j]就是不成立的
                即 多余重复项都被忽视了，直到遇到新的数字或者数字结束
            */
            if(i<2 || nums[i-2]<nums[j]){
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};