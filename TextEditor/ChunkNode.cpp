//
//  ChunkNode.cpp
//  TextEditor
//
//  Created by QMZ on 2017/10/23.
//  Copyright © 2017年 QMZ. All rights reserved.
//

#include "ChunkNode.h"

#include <iostream>
#include <cstring>
using namespace std;

ChunkNode::ChunkNode(){
    prev=NULL;
    str=NULL;
    length=0;
    next=NULL;
}

ChunkNode::ChunkNode(const char* str){
    length=(int)strlen(str);
    this->str=new char[length+1];
    for(int i=0;i<length+1;i++)
        this->str[i]=str[i];
    prev=NULL;
    next=NULL;
}

ChunkNode::ChunkNode(const char* str, ChunkNode* prev, ChunkNode* next){
    length=(int)strlen(str);
    this->str=new char[length+1];
    for(int i=0;i<length+1;i++)
        this->str[i]=str[i];
    this->prev=prev;
    this->next=next;
}

ChunkNode::~ChunkNode(){
    delete[] str;
}

void ChunkNode::setPrev(ChunkNode* prev){
    this->prev=prev;
}

void ChunkNode::setNext(ChunkNode* next){
    this->next=next;
}

void ChunkNode::setStr(const char* str){
    length=(int)strlen(str);
    delete[] (this->str);
    this->str=new char[length+1];
    for(int i=0;i<length+1;i++)
        this->str[i]=str[i];
}

int ChunkNode::getLength(){
    return length;
}

char* ChunkNode::getStr(){
    return str;
}

ChunkNode* ChunkNode::getPrev(){
    return this->prev;
}

ChunkNode* ChunkNode::getNext(){
    return this->next;
}
