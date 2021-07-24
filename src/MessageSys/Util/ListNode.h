#pragma once
#ifndef __LISTNODE
#define __LISTNODE
#include "../Message.h"
template<class classType> 
struct ListNode{
    ListNode(){
        pre=nullptr;
        next=nullptr;
        entity=nullptr;
    }
    ListNode(ListNode<classType>* _pre,classType* _enitty){
        next=nullptr;
        pre=_pre;
        entity=_enitty;
    }
    ListNode(classType* _enitty){
        next=nullptr;
        pre=nullptr;
        entity=_enitty;
    }
    ListNode* pre;
    ListNode* next;
    classType* entity;
};
#endif
