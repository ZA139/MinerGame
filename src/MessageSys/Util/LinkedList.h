#pragma once
#ifndef __LINKEDLIST
#define __LINKEDLIST
#include "./ListNode.h"
template <class classType>
class LinkedList{
    private:
        ListNode<classType>* head,*tail;
        void deleteNode(ListNode<classType> * target){
            if(target->next){
                deleteNode(target->next);
            }
            delete target;
        }
    public:
        LinkedList(){
            head=new ListNode<classType>();
            tail=head;
        }
        ~LinkedList(){
            deleteNode(head);
        }
        void add(classType* tar){
            tail->next=new ListNode<classType>(tail,tar);
            tail->pre=tail;
            tail=tail->next;
        }
        void remove(ListNode<classType>* tar){
            if(tar->next){
                tar->pre->next=tar->next;
                tar->next->pre=tar->pre;
            }
            else{
                tar->pre->next=nullptr;
                tail=tar->pre;
            }
            delete tar;
        }
        ListNode<classType> * getHead(){
            return head;
        }
};
#endif