//https://practice.geeksforgeeks.org/problems/identical-linked-lists/1
#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *n){
  while (n != nullptr)
  {
     cout<<n->val<<' ';
     n = n->next;
  }
}

bool areIdentical(ListNode *a, ListNode *b){
    while(a != nullptr && b != nullptr){
        if(a->val != b->val){
            return false;
        }else{
            a = a->next;
            b = b->next;
        }
    }
    return (a == nullptr && b == nullptr);
}


int main(){
    ListNode *L1 = new ListNode(1);
    ListNode *ls_1 = new ListNode(2);  L1->next = ls_1;
    ListNode *ls_2 = new ListNode(3);  ls_1->next = ls_2;
    ListNode *ls_3 = new ListNode(4); ls_2->next = ls_3;
//    ListNode *ls_4 = new ListNode(5); ls_3->next = ls_4;

    ListNode *L2 = new ListNode(1);
    ListNode *ls_5 = new ListNode(2);  L2->next = ls_5;
    ListNode *ls_6 = new ListNode(3);  ls_5->next = ls_6;
    ListNode *ls_7 = new ListNode(4); ls_6->next = ls_7;


    cout<<"Created Linked List L1: "<<endl;
    printList(L1);cout<<endl;
    cout<<"Created Linked List L2: "<<endl;
    printList(L2);cout<<endl;

    cout<<areIdentical(L1,L2);
}
