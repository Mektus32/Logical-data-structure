#ifndef WORDSLIST_H
#define WORDSLIST_H

#include <string>

struct TWordsList {
	std::string Word;
	TWordsList* Next = nullptr;
};

struct TObjectTWordsList {
	TWordsList* FirstElem = nullptr;
	TWordsList* LastElem = nullptr;
	std::string CurrentElem;
	TWordsList* Worked = nullptr;
	bool Available = false;
};

//---------------------------------------------//
void ClearObjectTWordsList(TObjectTWordsList* objectTWordsList);
int InputManager(bool value);
//---------------------------------------------//

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

//---------------------------------------------//
int ChooseTWordsListOperation();
bool MenuList(TObjectTWordsList* objectTWordsList);
//---------------------------------------------//

#endif
