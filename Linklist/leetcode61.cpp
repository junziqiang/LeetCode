/***
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * **/

#include<iostream>
using namespace std;
  struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        int len = 1;
        ListNode* start = head;
        ListNode* newhead;
        ListNode* p = head;
        //此时start指向尾节点
        while(start->next != nullptr){
            start = start->next;
            len++;
        }
        //首先对k进行处理
        k = k%len;
        if(len == 1 || k ==0){
            return head;
        }else{
            for(int i = 0; i < len - k - 1;++i){
                p = p->next;
            }
            //保存新的头节点，尾节点指向旧的头节点
            newhead = p->next;
            start->next = head;
            p->next = NULL;
            return newhead;
        }
        
    }
};

int main(){
    ListNode p1(1);
    ListNode p2(2);
    ListNode p3(3);
    ListNode p4(4);
    ListNode p5(5);
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    p4.next = &p5;
    p5.next = nullptr;
    Solution* s = new Solution();
    ListNode* head = s->rotateRight(&p1,0);
    while(head != NULL){
        cout<<head->val<<endl;
        head = head->next;
    }
    return 0;
}