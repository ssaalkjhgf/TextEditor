//
//  ChunkList.cpp
//  TextEditor
//
//  Created by QMZ on 2017/10/23.
//  Copyright © 2017年 QMZ. All rights reserved.
//

#include "ChunkList.h"

ChunkList::ChunkList(){
    head=new ChunkNode;
    curr=head;
    tail=head;
    length=0;
}

ChunkList::~ChunkList(){
    ChunkNode* temp=NULL;
    for(int i=0;i<length;i++){
        temp=tail->getPrev();
        delete tail;
        tail=temp;
    }
}

void ChunkList::init(){
    ChunkNode* temp=NULL;
    for(int i=0;i<length;i++){
        temp=tail->getPrev();
        delete tail;
        tail=temp;
    }
    length=0;
    curr=head;
    tail=head;
}

void ChunkList::pushBack(ChunkNode* node){
    tail->setNext(node);
    node->setPrev(tail);
    tail=node;
    curr=node;
    length++;
}

void ChunkList::pushBack(const char* str){
    ChunkNode* temp=new ChunkNode(str);
    pushBack(temp);
}

void ChunkList::pushFront(ChunkNode* node){
    if(length!=0){
        node->setNext(head->getNext());
        head->getNext()->setPrev(node);
        head->setNext(node);
        node->setPrev(head);
    }
    else{
        node->setNext(NULL);
        head->setNext(node);
        tail=node;
        node->setPrev(head);
    }
    length++;
    curr=node;
}

void ChunkList::pushFront(const char* str){
    ChunkNode* temp=new ChunkNode(str);
    pushFront(temp);
}

void ChunkList::pushCurr(ChunkNode* node){
    if(curr==tail){
        pushBack(node);
    }
    else if(curr==head){
        pushFront(node);
    }
    else{
        node->setNext(curr->getNext());
        curr->setNext(node);
        node->setPrev(curr);
        node->getNext()->setPrev(node);
    }
    length++;
    curr=node;
}

void ChunkList::pushCurr(const char* str){
    ChunkNode* temp=new ChunkNode(str);
    pushCurr(temp);
}

void ChunkList::pushAtPos(ChunkNode* node, int pos){
    curr=head;
    for(int i=1;i<pos;i++){
        curr=curr->getNext();
    }
    pushCurr(node);
}

void ChunkList::pushAtPos(const char* str, int pos){
    curr=head;
    for(int i=1;i<pos;i++){
        curr=curr->getNext();
    }
    pushCurr(str);
}

void ChunkList::popBack(){
    if(head==tail)
        return;
    ChunkNode* temp=tail->getPrev();
    if(tail==curr)
        curr=temp;
    delete tail;
    tail=temp;
    tail->setNext(NULL);
    length--;
}

void ChunkList::popFront(){
    if(head==tail)
        return;
    ChunkNode* temp=head->getNext()->getNext();
    if(curr==head->getNext()){
        if(temp==NULL)
            curr=head;
        else
            curr=temp;
    }
    delete head->getNext();
    head->setNext(temp);
    if(temp!=NULL)
        temp->setPrev(head);
    length--;
}

void ChunkList::popCurr(){
    if(curr==tail){
        popBack();
        return;
    }
    if(curr==head->getNext()){
        popFront();
        return;
    }
    ChunkNode* temp=curr->getPrev();
    curr->getNext()->setPrev(curr->getPrev());
    curr->getPrev()->setNext(curr->getNext());
    delete curr;
    if(temp!=head)
        curr=temp;
    else if(temp->getNext()!=NULL)
        curr=temp->getNext();
    else
        curr=temp;
    length--;
}

bool ChunkList::moveNext(){
    if(curr!=tail){
        curr=curr->getNext();
        return true;
    }
    else{
        return false;
    }
}

bool ChunkList::movePrev(){
    if(head->getNext()==curr)
        return false;
    else{
        curr=curr->getPrev();
        return true;
    }
}

ChunkNode* ChunkList::getCurr(){
    return curr;
}

bool ChunkList::moveToFirst(){
    if(length==0)
        return false;
    else{
        curr=head->getNext();
        return true;
    }
}

bool ChunkList::moveToEnd(){
    if(length==0)
        return false;
    else{
        curr=tail;
        return true;
    }
}

bool ChunkList::setCurr(ChunkNode* node){
    curr=node;
    return true;
}

int ChunkList::getLength(){
    return length;
}

