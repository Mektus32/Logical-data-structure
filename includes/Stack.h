#ifndef STACK_H
#define STACK_H

#include "Text.h"

struct TStack {
    TObjectTText *objectTText = nullptr;
    TStack* Next = nullptr;
};

struct TObjectTStack {
    TStack* FirstElem = nullptr;
    TStack* LastElem = nullptr;
    TObjectTText* CurrentElem = nullptr;
    bool Available;
};

//---------------------------------------------//
void ClearObjectTStack(TObjectTStack& objectTStack);
//---------------------------------------------//

void BeginWorkTStack(TObjectTStack& objectTStack);
void ClearTStack(TObjectTStack& objectTStack, bool showMsg);
void StackIsEmpty(TObjectTStack& objectTStack);
void ShowTStackElem(TObjectTStack& objectTStack);
void DelTStackElem(TObjectTStack& objectTStack, bool showMsg, bool delNested);
void TakeTStackElem(TObjectTStack& objectTStack);
void ChangeTStackElem(TObjectTStack& objectTStack);
void AddTStackElem(TObjectTStack& objectTStack);
void PrintTStack(TObjectTStack& objectTStack);
void EndWorkTStack(TObjectTStack& objectTStack);

//---------------------------------------------//
int ChooseTStackOperation();
void MenuStack();
//---------------------------------------------//

#endif
