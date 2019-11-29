#ifndef TEXT_H
#define TEXT_H

#include "WordsList.h"

struct TText {
    TObjectTWordsList* objectTWordsList = nullptr;
    TText* Next = nullptr;
    TText* Prev = nullptr;
};

struct TObjectTText {
    TText* FirsElem = nullptr;
    TText* LastElem = nullptr;
    TText* CurrentElem = nullptr;
    TText* Worked = nullptr;
};

//---------------------------------------------//
void ClearObjectTText(TObjectTText& objectTText);
//---------------------------------------------//

void BeginWorkTText(TObjectTText& objectTText);
void ClearTText(TObjectTText& objectTText, bool showMsg);
void TextIsEmpty(TObjectTText& objectTText);
void SetOnFirstElemTText(TObjectTText& objectTText);
void SetOnLastElemTText(TObjectTText& objectTText);
void OnFirstElemTText(TObjectTText& objectTText);
void OnLastElemTText(TObjectTText& objectTText);
void MoveForwardTText(TObjectTText& objectTText);
void MoveBackTText(TObjectTText& objectTText);
void ShowElemBeforeTText(TObjectTText& objectTText);
void ShowElemAfterTText(TObjectTText& objectTText);
void DelElemBeforeTText(TObjectTText& objectTText, bool showMsg);
void DelElemAfterTText(TObjectTText& objectTText, bool showMsg);
void TakeElemBeforeTText(TObjectTText& objectTText);
void TakeElemAfterTText(TObjectTText& objectTText);
void ChangeElemBeforeTText(TObjectTText& objectTText);
void ChangeElemAfterTText(TObjectTText& objectTText);
void AddElemBeforeTText(TObjectTText& objectTText);
void AddElemAfterTText(TObjectTText& objectTText);
void PrintText(TObjectTText& objectTText);
void EndWorkTText(TObjectTText& objectTText);

//---------------------------------------------//

int ChooseTTextOperation();
void MenuText();

//---------------------------------------------//
#endif
