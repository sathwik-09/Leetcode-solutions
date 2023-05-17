/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        int n = v.size();
        int i=0, j=n-i-1;
        int sum = 0;
        int maxSum = INT_MIN;
        while(i<j){
            sum = v[i++] + v[j--];
            if(sum>maxSum){
                maxSum = sum;
            }
        }
        return maxSum;
    }
};