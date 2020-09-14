/**
 * 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
 * **/

/**
 * 数组完成排序后，我们可以放置两个指针 i 和 j，其中i是慢指针，而j是快指针。只要 nums[i] = nums[j]，我们就增加j以跳过重复项。

当我们遇到 nums[j] != nums[i]nums[j] 跳过重复项的运行已经结束，因此我们必须把它（nums[j]）的值复制到 nums[i + 1]。然后递增i，接着我们将再次重复相同的过程，直到j到达数组的末尾为止。
 * 
 * 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int i = 0;
        for(int j=1; j<nums.size();j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
        }
    }
    return i+1;
    }

};