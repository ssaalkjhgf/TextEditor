//
//  ChunkNode.hpp
//  TextEditor
//
//  Created by QMZ on 2017/10/23.
//  Copyright © 2017年 QMZ. All rights reserved.
//

#ifndef _CHUNK_NODE_H_
#define _CHUNK_NODE_H_

#define BUFFER_SIZE 200

#include <iostream>
using namespace std;

//The chunk node implementation
class ChunkNode{
private:
    ChunkNode* prev;
    char* str;
    int length;
    ChunkNode* next;
    
public:
    //Constructors
    ChunkNode();
    ChunkNode(const char* str);
    ChunkNode(const char* str, ChunkNode* prev, ChunkNode* next);
    //Destructor
    ~ChunkNode();
    //Set the previous node
    void setPrev(ChunkNode* prev);
    //Set the next node
    void setNext(ChunkNode* next);
    //Set the string in the node
    void setStr(const char* str);
    //Get the length of the string in the node
    int getLength();
    //Get the string in the node
    char* getStr();
    //Get the pointer to the previous node
    ChunkNode* getPrev();
    //Get the pointer to the next node
    ChunkNode* getNext();
};

#endif /* ChunkNode_h */
