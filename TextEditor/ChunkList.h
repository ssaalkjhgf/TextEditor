//
//  ChunkList.hpp
//  TextEditor
//
//  Created by QMZ on 2017/10/23.
//  Copyright © 2017年 QMZ. All rights reserved.
//

#ifndef _CHUNK_LIST_H_
#define _CHUNK_LIST_H_

#define BUFFER_SIZE 200

#include <iostream>
#include "ChunkNode.h"
using namespace std;

//A chunk list implementation class
class ChunkList{
private:
    ChunkNode* head;
    ChunkNode* curr;
    ChunkNode* tail;
    int length;
    
private:
    //Set the current node
    bool setCurr(ChunkNode* node);
    
public:
    //Constructor
    ChunkList();
    //Destructor
    ~ChunkList();
    //Reinitialize the list
    void init();
    //Push a node at the end of the list
    void pushBack(ChunkNode* node);
    //Push a node of a string at the end of the list
    void pushBack(const char* str);
    //Push a node in the front of the list
    void pushFront(ChunkNode* node);
    //Push a node of a string in the front of the list
    void pushFront(const char* str);
    //Push a node after the curr node
    void pushCurr(ChunkNode* node);
    //Push a node of a string after the curr node
    void pushCurr(const char* str);
    //Push a node at a special position in the list
    void pushAtPos(ChunkNode* node, int pos);
    //Push a node of a string at a special position in the list
    void pushAtPos(const char* str, int pos);
    //Pop the last node in the list
    void popBack();
    //Pop the first node in the list
    void popFront();
    //Pop the current node in the list
    void popCurr();
    //Move the pointer curr forward
    bool movePrev();
    //Move the pointer curr backward
    bool moveNext();
    //Move the pointer curr to the front of the list
    bool moveToFirst();
    //Move the pointer curr to the end of the list
    bool moveToEnd();
    //Get the length of the list
    int getLength();
    //Get the pointer to the curr node in the list
    ChunkNode* getCurr();
    
    //Set the class TextEditor as the friend class
    friend class TextEditor;
};

#endif /* ChunkList_h */
