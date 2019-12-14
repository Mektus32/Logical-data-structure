#ifndef STACK_H
#define STACK_H

#include "Text.h"

//Type of stack element that contains the text element type
struct TStack {
    TObjectTText *objectTText = nullptr;
    TStack* Next = nullptr;
};

//The stack object type that contains the stack element type
struct TObjectTStack {
    TStack* FirstElem = nullptr;
    TStack* LastElem = nullptr;
    //The variable containing the last element taken
    TObjectTText* CurrentElem = nullptr;
    //Variable access permissions to work
    bool Available = false;
};

//Additional function
//---------------------------------------------//
void ClearObjectTStack(TObjectTStack& objectTStack);
//---------------------------------------------//

//The stack`s functions
void BeginWorkTStack(TObjectTStack& objectTStack);
void CleanTStack(TObjectTStack &objectTStack, bool showMsg, size_t &size);
void StackIsEmpty(TObjectTStack& objectTStack);
void ShowTStackElem(TObjectTStack& objectTStack);
void DelTStackElem(TObjectTStack &objectTStack, bool showMsg, bool delNested, size_t &size);
void TakeTStackElem(TObjectTStack &objectTStack, size_t &size);
void ChangeTStackElem(TObjectTStack &objectTStack, size_t &size);
void AddTStackElem(TObjectTStack &objectTStack, size_t &size);
void PrintTStack(TObjectTStack& objectTStack);
void EndWorkTStack(TObjectTStack& objectTStack);

//Menu stack`s functions
//---------------------------------------------//
int ChooseTStackOperation();
void MenuStack();
//---------------------------------------------//

#endif
