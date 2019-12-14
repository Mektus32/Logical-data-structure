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
    bool Available = false;
};

//---------------------------------------------//
void ClearObjectTStack(TObjectTStack& objectTStack);
//---------------------------------------------//

void BeginWorkTStack(TObjectTStack& objectTStack);
void ClearTStack(TObjectTStack &objectTStack, bool showMsg, size_t &size);
void StackIsEmpty(TObjectTStack& objectTStack);
void ShowTStackElem(TObjectTStack& objectTStack);
void DelTStackElem(TObjectTStack &objectTStack, bool showMsg, bool delNested, size_t &size);
void TakeTStackElem(TObjectTStack &objectTStack, size_t &size);
void ChangeTStackElem(TObjectTStack &objectTStack, size_t &size);
void AddTStackElem(TObjectTStack &objectTStack, size_t &size);
void PrintTStack(TObjectTStack& objectTStack);
void EndWorkTStack(TObjectTStack& objectTStack);

//---------------------------------------------//
int ChooseTStackOperation();
void MenuStack();
//---------------------------------------------//

#endif
