#ifndef WORDSLIST_H
#define WORDSLIST_H

#include <cstring>

//Type of list element
struct TWordsList {
	char* Word = nullptr;
	TWordsList* Next = nullptr;
};

//The list object type that contains the list element type
struct TObjectTWordsList {
	TWordsList* FirstElem = nullptr;
	TWordsList* LastElem = nullptr;
	//The variable containing the last element taken
	char* CurrentElem = nullptr;
	//Work pointer
	TWordsList* Worked = nullptr;
	//Variable access permissions to work
	bool Available = false;
};

//Additional functions
//---------------------------------------------//
void ClearObjectTWordsList(TObjectTWordsList* objectTWordsList);
int InputManager(bool value);
char* CreateString();
//---------------------------------------------//

//The list`s functions
void BeginWorkTWordsList(TObjectTWordsList* objectTWordsList);
void ClearTWordsList(TObjectTWordsList* objectTWordsList, bool showMsg, bool callNotCurrent);
void ListIsEmpty(TObjectTWordsList* objectTWordsList);
void SetOnFirstElemTWordsList(TObjectTWordsList* objectTWordsList);
void OnLastElemTWordsList(TObjectTWordsList* objectTWordsList);
void MoveForwardTWordsList(TObjectTWordsList* objectTWordsList);
void ShowElemAfterTWordsList(TObjectTWordsList* objectTWordsList);
void DelElemAfterTWordsList(TObjectTWordsList* objectTWordsList, bool showMsg);
void TakeElemAfterTWordsList(TObjectTWordsList* objectTWordsList);
void ChangeElemAfterTWordsList(TObjectTWordsList* objectTWordsList);
void AddElemAfterTWordsList(TObjectTWordsList* objectTWordsList);
void PrintTWordsList(TObjectTWordsList* objectTWordsList, bool callNotCurrent);
void EndWorkTWordsList(TObjectTWordsList* objectTWordsList);

//Menu list`s functions
//---------------------------------------------//
int ChooseTWordsListOperation();
bool MenuList(TObjectTWordsList* objectTWordsList);
//---------------------------------------------//

#endif
