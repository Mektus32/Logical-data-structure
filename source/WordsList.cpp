#include "WordsList.h"

#include <iostream>

//---------------------------------------------//
void ClearObjectTWordsList(TObjectTWordsList* objectTWordsList) {
	objectTWordsList->FirstElem = nullptr;
	objectTWordsList->LastElem = nullptr;
	objectTWordsList->Worked = nullptr;
}

int InputManager(bool value = false) {
	char c = '\0';
	char clear = '\0';
	int count = 0;
	std::string buffer;

	if (value) {
		while (c <= ' ' || c > '~') {
			count ? (std::cout << "Input right character: ") : std::cout << "";
			c = (char)getchar();
			while ((clear = (char)getchar()) != '\n') {
			}
			++count;
		}
		return c;
	}
	else {
		while ((c = (char)getchar()) != '\n') {
			buffer += c;
		}
		return atoi(buffer.c_str());
	}
}
//---------------------------------------------//

void BeginWorkTWordsList(TObjectTWordsList* objectTWordsList) {
	objectTWordsList->Available = true;
	std::cout << "Work with words list is available" << std::endl;
}

void ClearTWordsList(TObjectTWordsList* objectTWordsList, bool showMsg = true, bool callNotCurrent = true) {
	TWordsList* del = nullptr;

	if (objectTWordsList->FirstElem) {
		if (callNotCurrent) {
			objectTWordsList->CurrentElem.clear();
		}
		while (objectTWordsList->FirstElem) {
			del = objectTWordsList->FirstElem;
			objectTWordsList->FirstElem = objectTWordsList->FirstElem->Next;
			delete del;
		}
		std::cout << (showMsg ? "Words list has been cleared\n" : "");
	} else {
		std::cout << (showMsg ? "Words list is empty, can`t clear list\n" : "");
		ClearObjectTWordsList(objectTWordsList);
	}
}

void ListIsEmpty(TObjectTWordsList* objectTWordsList) {
	if (!objectTWordsList->FirstElem) {
		std::cout << "Words list is empty" << std::endl;
		ClearObjectTWordsList(objectTWordsList);
	} else {
		std::cout << "Words list is not empty" << std::endl;
	}
}

void SetOnFirstElemTWordsList(TObjectTWordsList* objectTWordsList) {
	if (objectTWordsList->FirstElem) {
		objectTWordsList->Worked = objectTWordsList->FirstElem;
		std::cout << "Work pointer on first element" << std::endl;
	} else {
		std::cout << "Words list is empty, can`t set work pointer on first element" << std::endl;
		ClearObjectTWordsList(objectTWordsList);
	}
}

void OnLastElemTWordsList(TObjectTWordsList* objectTWordsList) {
	if (objectTWordsList->FirstElem) {
		if (objectTWordsList->Worked == objectTWordsList->LastElem) {
			std::cout << "Work pointer on last element" << std::endl;
		} else {
			std::cout << "Work pointer not on last element" << std::endl;
		}
	} else {
		std::cout << "Words list is empty, can`t check on last element work pointer" << std::endl;
		ClearObjectTWordsList(objectTWordsList);
	}
}

void MoveForwardTWordsList(TObjectTWordsList* objectTWordsList) {
	if (objectTWordsList->FirstElem) {
		if (!objectTWordsList->Worked) {
			std::cout << "Work pointer is nullptr.., can`t move forward" << std::endl;
		} else if (!objectTWordsList->Worked->Next) {
			std::cout << "Work pointer on last element, can`t move forward" << std::endl;
		} else {
			objectTWordsList->Worked = objectTWordsList->Worked->Next;
			std::cout << "Work pointer moved on one element" << std::endl;
		}
	} else {
		std::cout << "Words list is empty, can`t move work pointer" << std::endl;
		ClearObjectTWordsList(objectTWordsList);
	}
}

void ShowElemAfterTWordsList(TObjectTWordsList* objectTWordsList) {
	if (objectTWordsList->FirstElem) {
		if (!objectTWordsList->Worked) {
			std::cout << "Work pointer is nullptr.., can`t show next element" << std::endl;
		} else if (!objectTWordsList->Worked->Next) {
			std::cout << "Work pointer on last element, can`t show next element" << std::endl;
		} else {
			std::cout << "Element: " << objectTWordsList->Worked->Next->Word << std::endl;
		}
	} else {
		std::cout << "Words list is empty, can`t show next element" << std::endl;
		ClearObjectTWordsList(objectTWordsList);
	}
}

void DelElemAfterTWordsList(TObjectTWordsList* objectTWordsList, bool showMsg = true) {
	TWordsList* del = nullptr;

	if (objectTWordsList->FirstElem) {
		if (!objectTWordsList->Worked) {
			std::cout << (showMsg ? "Work pointer is nullptr.., can`t delete\n" : "");
		} else if (!objectTWordsList->Worked->Next) {
			std::cout << (showMsg ? "Work pointer on last element, can`t delete\n" : "");
		} else {
			del = objectTWordsList->Worked->Next;
			objectTWordsList->Worked->Next = objectTWordsList->Worked->Next->Next;
			delete del;
			std::cout << (showMsg ? "Element has been deleted\n" : "");
		}
	} else {
		std::cout << (showMsg ? "Words list is empty, can`t delete next element\n" : "");
		ClearObjectTWordsList(objectTWordsList);
	}
}

void TakeElemAfterTWordsList(TObjectTWordsList* objectTWordsList) {
	if (objectTWordsList->FirstElem) {
		if (!objectTWordsList->Worked) {
			std::cout << "Work pointer is nullptr.., can`t take next element" << std::endl;
		} else if (!objectTWordsList->Worked->Next) {
			std::cout << "Work pointer on last element, can`t take next element" << std::endl;
		} else {
			std::cout << "Taken element: " << objectTWordsList->Worked->Next->Word << std::endl;
			objectTWordsList->CurrentElem = objectTWordsList->Worked->Next->Word;
			DelElemAfterTWordsList(objectTWordsList, false);
		}
	} else {
		std::cout << "Words list is empty, can`t take next element" << std::endl;
		ClearObjectTWordsList(objectTWordsList);
	}
}

void ChangeElemAfterTWordsList(TObjectTWordsList* objectTWordsList) {
	char clear = '\0';

	if (objectTWordsList->FirstElem) {
		if (!objectTWordsList->Worked) {
			std::cout << "Work pointer is nullptr.., can`t change next element" << std::endl;
		} else if (!objectTWordsList->Worked->Next) {
			std::cout << "Work pointer on last element, can`t change next element" << std::endl;
		} else {
			std::cout << "Input new word: ";
			std::cin >> objectTWordsList->Worked->Next->Word;
			while ((clear = (char)getchar()) != '\n') {
			}
		}
	} else {
		std::cout << "Words list is empty, can`t change next element" << std::endl;
		ClearObjectTWordsList(objectTWordsList);
	}
}

void AddElemAfterTWordsList(TObjectTWordsList* objectTWordsList) {
	auto newElem = new TWordsList;
	char clear = '\0';

	std::cout << "Input new word: ";
	std::cin >> newElem->Word;
	while ((clear = (char)getchar()) != '\n') {
	}
	if (!objectTWordsList->FirstElem) {
		objectTWordsList->FirstElem = newElem;
		objectTWordsList->LastElem = newElem;
		objectTWordsList->Worked = newElem;
	} else if (!objectTWordsList->Worked) {
		std::cout << "Work pointer is nullptr.., can`t add new element" << std::endl;
		return;
	} else if (!objectTWordsList->Worked->Next) {
		objectTWordsList->Worked->Next = newElem;
		objectTWordsList->LastElem = newElem;
	} else {
		newElem->Next = objectTWordsList->Worked->Next;
		objectTWordsList->Worked->Next = newElem;
	}
	std::cout << "New element has been added" << std::endl;
}

void PrintTWordsList(TObjectTWordsList* objectTWordsList, bool callNoCurrent = false) {
	size_t beginStr = 0;
	size_t endStr = 0;
	bool whileNotWork = true;

	if (objectTWordsList->FirstElem) {
		for (auto tmp = objectTWordsList->FirstElem; tmp != nullptr; tmp = tmp->Next) {
			if (tmp == objectTWordsList->Worked) {
				whileNotWork = false;
				endStr = beginStr + tmp->Word.size();
			}
			if (whileNotWork) {
				beginStr += tmp->Word.size() + 1;
			}
			std::cout << tmp->Word << " ";
		}
		std::cout << std::endl;
		if (callNoCurrent) {
			std::cout << "   ";
		}
		for (size_t i = 0; i < endStr; ++i) {
			if (i == beginStr || i == endStr - 1) {
				std::cout << '|';
			} else {
				std::cout << ' ';
			}
		}
	} else {
		std::cout << "Words list is empty, can`t print list" << std::endl;
		ClearObjectTWordsList(objectTWordsList);
	}
}

void EndWorkTWordsList(TObjectTWordsList* objectTWordsList) {
	objectTWordsList->Available = false;
	std::cout << "Work with words list is forbidden" << std::endl;
}

//---------------------------------------------//
int ChooseTWordsListOperation() {
	//system("pause");
	//system("cls");
	std::cout << "////////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "Words list menu" << std::endl;
	std::cout << "1.Begin work with words list" << std::endl;
	std::cout << "2.To clear the words list" << std::endl;
	std::cout << "3.To check the emptiness of the  words list" << std::endl;
	std::cout << "4.To set work pointer on first element" << std::endl;
	std::cout << "5.To check work pointer on last element" << std::endl;
	std::cout << "6.To move work pointer forward" << std::endl;
	std::cout << "7.To show element after work pointer" << std::endl;
	std::cout << "8.To delete element after work pointer" << std::endl;
	std::cout << "9.To take element after work pointer" << std::endl;
	std::cout << "10.To change element after work pointer" << std::endl;
	std::cout << "11.To add element after work pointer" << std::endl;
	std::cout << "12.To print words list" << std::endl;
	std::cout << "13.End work with words list" << std::endl;
	std::cout << "14.Return to up struct" << std::endl;
	std::cout << "15.End program" << std::endl;
	std::cout << "Input number operation: ";
	return InputManager(false);
}

bool MenuList(TObjectTWordsList* objectTWordsList) {
	objectTWordsList->Available = false;
	bool loop = true;
	int operation;

	while (loop) {
		operation = ChooseTWordsListOperation();
		std::cout << "////////////////////////////////////////////////////////////////////////" << std::endl;
		if (objectTWordsList->Available) {
			switch (operation) {
				case 1: BeginWorkTWordsList(objectTWordsList); break;
				case 2: ClearTWordsList(objectTWordsList); break;
				case 3: ListIsEmpty(objectTWordsList); break;
				case 4: SetOnFirstElemTWordsList(objectTWordsList); break;
				case 5: OnLastElemTWordsList(objectTWordsList); break;
				case 6: MoveForwardTWordsList(objectTWordsList); break;
				case 7: ShowElemAfterTWordsList(objectTWordsList); break;
				case 8: DelElemAfterTWordsList(objectTWordsList); break;
				case 9: TakeElemAfterTWordsList(objectTWordsList); break;
				case 10: ChangeElemAfterTWordsList(objectTWordsList); break;
				case 11: AddElemAfterTWordsList(objectTWordsList); break;
				case 12: PrintTWordsList(objectTWordsList); std::cout << std::endl; break;
				case 13: EndWorkTWordsList(objectTWordsList); break;
				case 14: loop = false; break;
				case 15: exit(0);
				default: std::cout << "Choose right operation" << std::endl;
			}
			if (operation != 12 && operation != 14) {
				if (objectTWordsList->FirstElem) {
					PrintTWordsList(objectTWordsList);
					std::cout << std::endl;
				}
			}
		} else if (operation == 1) {
			BeginWorkTWordsList(objectTWordsList);
		} else if (operation == 14 || operation == 15) {
			if(operation == 14) {
				loop = false;
			} else {
				exit(0);
			}
		} else if (operation > 1 && operation < 14) {
			std::cout << "Use operation begin work" << std::endl;
		} else {
			std::cout << "Choose right operation" << std::endl;
		}
	}
	std::cout << "////////////////////////////////////////////////////////////////////////1" << std::endl;
	return objectTWordsList->FirstElem;
}
//---------------------------------------------//