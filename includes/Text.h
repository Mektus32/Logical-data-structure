#ifndef TEXT_H
#define TEXT_H

#include "WordsList.h"

struct TText {
    TObjectTWordsList* objectTWordsList = nullptr;
    TText* Next = nullptr;
    TText* Prev = nullptr;
};

struct TObjectTText {
    TText* FirstElem = nullptr;
    TText* LastElem = nullptr;
	TObjectTWordsList* CurrentElem = nullptr;
    TText* Worked = nullptr;
    bool Available = false;
};

//---------------------------------------------//
void ClearObjectTText(TObjectTText *objectTText);
//---------------------------------------------//

void BeginWorkTText(TObjectTText* objectTText);
void ClearTText(TObjectTText* objectTText, bool showMsg, bool delNested, bool callNotCurrent);
void TextIsEmpty(TObjectTText* objectTText);
void SetOnFirstElemTText(TObjectTText* objectTText);
void SetOnLastElemTText(TObjectTText* objectTText);
void OnFirstElemTText(TObjectTText* objectTText);
void OnLastElemTText(TObjectTText* objectTText);
void MoveForwardTText(TObjectTText* objectTText);
void MoveBackTText(TObjectTText* objectTText);
void ShowElemBeforeTText(TObjectTText* objectTText);
void ShowElemAfterTText(TObjectTText* objectTText);
void DelElemBeforeTText(TObjectTText* objectTText, bool showMsg, bool delNested);
void DelElemAfterTText(TObjectTText* objectTText, bool showMsg, bool delNested);
void TakeElemBeforeTText(TObjectTText* objectTText);
void TakeElemAfterTText(TObjectTText* objectTText);
void ChangeElemBeforeTText(TObjectTText* objectTText);
void ChangeElemAfterTText(TObjectTText* objectTText);
void AddElemBeforeTText(TObjectTText* objectTText);
void AddElemAfterTText(TObjectTText* objectTText);
void PrintText(TObjectTText* objectTText);
void EndWorkTText(TObjectTText* objectTText);

//---------------------------------------------//

int ChooseTTextOperation();
bool MenuText(TObjectTText* objectTText);

//---------------------------------------------//
#endif
