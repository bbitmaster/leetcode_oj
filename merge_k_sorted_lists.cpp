//Author: Ben Goodrich
//
//From:
// https://oj.leetcode.com/problems/merge-k-sorted-lists/
//
//Problem:
// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;
class Solution {
public:
    //merge 2 sorted lists
    ListNode *merge2Lists(ListNode *a,ListNode *b){
        if(a == NULL)return b;
        if(b == NULL)return a;

        ListNode *root, *nonroot, *saved_root;
        if(a->val < b->val){
            saved_root = a;
            root = a;
            nonroot = b;
        }   else {
            saved_root = b;
            root = b;
            nonroot = a;
        }

        while(root->next != NULL){
            if(root->next->val >= nonroot->val){
                    ListNode *nonroot_prev=nonroot;
                    nonroot = nonroot->next;
                    nonroot_prev->next = root->next;
                    root->next = nonroot_prev;
                }
            if(nonroot == NULL)
                return saved_root;
            root = root->next;
        }

        root->next = nonroot;

        return saved_root;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *result=NULL;
        for(vector<ListNode *>::iterator it = lists.begin();
            it != lists.end();++it){
                result = merge2Lists(result,*it);
            }
        return result;
    }
};

int main(int argc,char *argv[]){
    Solution s;
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(6);

    ListNode *l2 = new ListNode(3);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(5);
    l2->next->next->next = new ListNode(6);

    ListNode *l3 = new ListNode(4);
    l3->next = new ListNode(5);
    l3->next->next = new ListNode(8);

    ListNode *l4 = new ListNode(8);
    
    vector<ListNode *> lists = {l1,l2,l3,l4};

    //this program will leak memory from result, we don't care.
    ListNode *result = s.mergeKLists(lists);
    //ListNode *result = s.merge2Lists(l1,l3);
    cout << "Result of merging 1 2 4 6, 3 4 5 6, 4 5 8, 8: " << endl;
    while(result != NULL){
        cout << to_string(result->val) << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}

