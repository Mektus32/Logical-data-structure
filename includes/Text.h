#ifndef TEXT_H
#define TEXT_H

#include "WordsList.h"

//Type of text element that contains the list element type
struct TText {
    TObjectTWordsList* objectTWordsList = nullptr;
    TText* Next = nullptr;
    TText* Prev = nullptr;
};

//The text object type that contains the text element type
struct TObjectTText {
    TText* FirstElem = nullptr;
    TText* LastElem = nullptr;
	//The variable containing the last element taken
	TObjectTWordsList* CurrentElem = nullptr;
	//Work pointer
    TText* Worked = nullptr;
    //Variable access permissions to work
    bool Available = false;
};

//Additional function
//---------------------------------------------//
void ClearObjectTText(TObjectTText *objectTText);
//---------------------------------------------//

//The text functions
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

//Menu text functions
//---------------------------------------------//
int ChooseTTextOperation();
bool MenuText(TObjectTText* objectTText);
//---------------------------------------------//
#endif
