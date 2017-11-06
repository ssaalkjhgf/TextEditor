//
//  TextEditor.h
//  TextEditor
//
//  Created by QMZ on 2017/10/23.
//  Copyright © 2017年 QMZ. All rights reserved.
//

#ifndef _TEXTEDITOR_H_
#define _TEXTEDITOR_H_

#include <iostream>
#include <fstream>
#include "ChunkList.h"
using namespace std;

//A text editor implementation class
class TextEditor{
private:
    ChunkList list;
    char openFilePath[BUFFER_SIZE];
    char closeFilePath[BUFFER_SIZE];
    
private:
    //The main menu
    void mainMenu();
    //Insert a new line
    bool insertLine();
    //Delete the current line
    bool deleteLine();
    //Reload file
    bool reload();
    //Save file
    bool save();
    //Change the current line
    bool changeStr();
    //Show all the content of the file
    bool printContent();
    //Move to the first line
    bool moveToFirst();
    //Move to the last line
    bool moveToEnd();
    //Move to the previous line
    bool movePrev();
    //Move to the next line
    bool moveNext();
    //Jump to a special line
    bool jump();
    //Count the number of lines and characters
    bool count();
    //Find the special string in the line
    bool match();
    //Substitute the special string with a new string
    bool substitute();
    //Show help
    void help();
    
public:
    //Constructor: run the main menu
    TextEditor();
};

#endif /* TextEditor_h */
