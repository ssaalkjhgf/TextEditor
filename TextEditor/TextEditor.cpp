//
//  TextEditor.cpp
//  TextEditor
//
//  Created by QMZ on 2017/10/23.
//  Copyright © 2017年 QMZ. All rights reserved.
//

#include "TextEditor.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

TextEditor::TextEditor(){
    char buffer[BUFFER_SIZE]={'\0'};
    cout<<"<Enter the open file path:>\n";
    cin>>openFilePath;
    cout<<"<Enter the save file path:>\n";
    cin>>closeFilePath;
    cin.get();
    fstream file(openFilePath, ios::in);
    if(file.fail())
        cout<<"fail!\n";
    while(file.getline(buffer, BUFFER_SIZE)){
        list.pushBack(buffer);
        for(int i=0;i<BUFFER_SIZE;i++)
            buffer[i]='\0';
    }
    file.close();
    mainMenu();
}

void TextEditor::mainMenu(){
    char ins='\0';
    for(;;){
        if(list.getLength()!=0){
            cout<<"<Current Line>";
            cout<<list.getCurr()->getStr()<<endl;
        }
        else
            cout<<"<Caution: The file is empty!>\n";
        cout<<"<Enter your instruction:>";
        cin>>ins;
        switch(ins){
            case 'a':
                printContent();
                break;
            case 'c':
                changeStr();
                break;
            case 'd':
                deleteLine();
                break;
            case 'e':
                moveToEnd();
                break;
            case 'f':
                moveToFirst();
                break;
            case 'h':
                help();
                break;
            case 'i':
                insertLine();
                break;
            case 'j':
                jump();
                break;
            case 'm':
                match();
                break;
            case 'n':
                moveNext();
                break;
            case 'p':
                movePrev();
                break;
            case 'q':
                return;
            case 'r':
                reload();
                break;
            case 's':
                save();
                break;
            case 't':
                substitute();
                break;
            case 'z':
                count();
                break;
            default:
                cout<<"Invalid instruction!\n";
                break;
        }
    }
}

void TextEditor::help(){
    cout<<"<a: show all contents in the file>\n";
    cout<<"<c: substitute the whole line with a new string>\n";
    cout<<"<d: delete the current line>\n";
    cout<<"<e: move to the last line of the file>\n";
    cout<<"<f: move to the first line of the file>\n";
    cout<<"<h: show all instructions>\n";
    cout<<"<i: insert a new line>\n";
    cout<<"<j: jump to a line>\n";
    cout<<"<m: find>\n";
    cout<<"<n: move to the next line>\n";
    cout<<"<p: move to the previous line>\n";
    cout<<"<q: quit (without saving the file)>\n";
    cout<<"<r: reload the input file>\n";
    cout<<"<s: save the file>\n";
    cout<<"<t: replace>\n";
    cout<<"<z: show the total number of lines and characters>\n";
}

bool TextEditor::insertLine(){
    int line=0;
    cout<<"<Enter line number:>";
    cin>>line;
    cin.get();
    cout<<"<Enter the content:>\n";
    if(line>(list.getLength()+1) || line<=0){
        cout<<"Insert failed!\n";
        return false;
    }
    char buffer[BUFFER_SIZE]={'\0'};
    cin.getline(buffer,BUFFER_SIZE);
    list.pushAtPos(buffer, line);
    return true;
}

bool TextEditor::deleteLine(){
    if(list.getLength()==0)
        return false;
    else{
        list.popCurr();
        return true;
    }
}

bool TextEditor::reload(){
    list.init();
    char buffer[BUFFER_SIZE]={'\0'};
    fstream file(openFilePath, ios::in);
    if(file.fail()){
        cout<<"fail!\n";
        return false;
    }
    while(file.getline(buffer, BUFFER_SIZE)){
        list.pushBack(buffer);
        for(int i=0;i<BUFFER_SIZE;i++)
            buffer[i]='\0';
    }
    return true;
}

bool TextEditor::save(){
    fstream file(closeFilePath, ios::out);
    if(file.fail()){
        cout<<"fail!\n";
        return false;
    }
    ChunkNode* temp=list.getCurr();
    list.moveToFirst();
    if(list.getLength()==0)
        return true;
    else{
        for(;;){
            file<<list.getCurr()->getStr()<<endl;
            if(!list.moveNext())
                break;
        }
    }
    list.setCurr(temp);
    file.close();
    cout<<"<Save succeed!>\n";
    return true;
}

bool TextEditor::changeStr(){
    char buffer[BUFFER_SIZE]={'\0'};
    cin.get();
    cout<<"<Enter the content of the new line:>\n";
    cin.getline(buffer,BUFFER_SIZE);
    list.getCurr()->setStr(buffer);
    return true;
}

bool TextEditor::printContent(){
    if(list.getLength()==0)
        return false;
    ChunkNode* temp=list.getCurr();
    list.moveToFirst();
    for(;;){
        cout<<list.getCurr()->getStr()<<endl;
        if(!list.moveNext())
            break;
    }
    list.setCurr(temp);
    return true;
}

bool TextEditor::moveToFirst(){
    if(list.getLength()==0)
        return false;
    list.moveToFirst();
    return true;
}

bool TextEditor::moveToEnd(){
    if(list.getLength()==0)
        return false;
    list.moveToEnd();
    return true;
}

bool TextEditor::movePrev(){
    return list.movePrev();
}

bool TextEditor::moveNext(){
    return list.moveNext();
}

bool TextEditor::jump(){
    int line;
    cout<<"<Enter the line number:>";
    cin>>line;
    cin.get();
    if(line>list.getLength() || line<0){
        cout<<"<Invalid line number!>\n";
        return false;
    }
    if(list.getLength()!=0){
        list.moveToFirst();
        for(int i=1;i<line;i++)
            list.moveNext();
        return true;
    }
    else
        return false;
}

bool TextEditor::count(){
    cout<<"<Total number of lines:"<<list.getLength()<<">\n";
    int sum=0;
    if(list.getLength()!=0){
        ChunkNode* temp=list.getCurr();
        list.moveToFirst();
        for(;;){
            sum+=list.getCurr()->getLength();
            if(!list.moveNext())
                break;
        }
        list.setCurr(temp);
    }
    cout<<"<Total number of characters:"<<sum<<">\n";
    return true;
}

bool TextEditor::match(){
    char str[BUFFER_SIZE]={'\0'};
    int length=(int)strlen(list.getCurr()->getStr());
    for(int i=0;i<length;i++){
        str[i]=(list.getCurr()->getStr())[i];
    }
    char buffer[BUFFER_SIZE]={'\0'};
    cin.get();
    cout<<"<Enter the content you want to find:>\n";
    cin.getline(buffer, BUFFER_SIZE);
    int destLength=(int)strlen(buffer);
    bool match[BUFFER_SIZE]={false};
    bool matchFlag=true;
    for(int i=0;i<length-destLength+1;i++){
        matchFlag=true;
        for(int k=0;k<destLength;k++){
            if(buffer[k]!=str[k+i])
                matchFlag=false;
        }
        if(matchFlag){
            match[i]=true;
        }
    }
    cout<<"<The result is as follows:>\n";
    cout<<str<<endl;
    for(int i=0;i<length;i++){
        cout<<(match[i]?'^':' ');
    }
    cout<<endl;
    return true;
}

bool TextEditor::substitute(){
    char str[BUFFER_SIZE]={'\0'};
    int length=(int)strlen(list.getCurr()->getStr());
    for(int i=0;i<length;i++){
        str[i]=(list.getCurr()->getStr())[i];
    }
    char buffer[BUFFER_SIZE]={'\0'};
    char substitute[BUFFER_SIZE]={'\0'};
    char result[BUFFER_SIZE]={'\0'};
    cin.get();
    cout<<"<Enter the content you want to replace:>\n";
    cin.getline(buffer, BUFFER_SIZE);
    cout<<"<Enter the new content:>\n";
    cin.getline(substitute,BUFFER_SIZE);
    int destLength=(int)strlen(buffer);
    bool match[BUFFER_SIZE]={false};
    bool matchFlag=true;
    for(int i=0;i<length-destLength+1;i++){
        matchFlag=true;
        for(int k=0;k<destLength;k++){
            if(buffer[k]!=str[k+i])
                matchFlag=false;
        }
        if(matchFlag){
            match[i]=true;
        }
    }
    int resultIndex=0,strIndex=0;
    int substituteLength=(int)strlen(substitute);
    for(;;){
        if(!match[strIndex]){
            result[resultIndex]=str[strIndex];
            resultIndex++;
            strIndex++;
        }
        else{
            for(int k=0;k<substituteLength;k++)
                result[resultIndex+k]=substitute[k];
            resultIndex+=substituteLength;
            strIndex+=destLength;
        }
        if(strIndex>=length)
            break;
    }
    list.getCurr()->setStr(result);
    return true;
}
