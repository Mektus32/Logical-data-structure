#include "WordsList.h"

#include <iostream>

//Additional functions
//---------------------------------------------//
//The function text the text parameters
void ClearObjectTWordsList(TObjectTWordsList* objectTWordsList) {
	objectTWordsList->FirstElem = nullptr;
	objectTWordsList->LastElem = nullptr;
	objectTWordsList->Worked = nullptr;
}

//The function that give character or digit
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

//Function creating string
char* CreateString() {
    char* str = nullptr;
    size_t size = 1;
    char c = ' ';
    size_t i;

    if (!(str = (char*)malloc(sizeof(char) * size + 1))) {
        std::cout << "Error allocate memory, element does not add" << std::endl;
        return nullptr;
    }
    while (c == ' ' || c == '\n') {
        c = (char)getchar();
    }
    for (i = 0; c != ' ' && c != '\n'; ++i) {
        str[i] = c;
        if (i == size) {
            size += 4;
            if (!(str = (char*)realloc(str, size + 1))) {
                std::cout << "Error allocate memory, element does not add" << std::endl;
                return nullptr;
            }
        }
        c = (char)getchar();
    }
    str[i] = '\0';
    while (c != '\n') {
        c = (char)getchar();
    }
    return str;
}
//---------------------------------------------//
//The list`s functions

//A function to start working
void BeginWorkTWordsList(TObjectTWordsList* objectTWordsList) {
	objectTWordsList->Available = true;
	std::cout << "Work with words list is available" << std::endl;
}

//A function to clean list
void ClearTWordsList(TObjectTWordsList* objectTWordsList, bool showMsg = true, bool callNotCurrent = true) {
	TWordsList* del = nullptr;
	//Checking pointers
	if (objectTWordsList->FirstElem) {
		//If calling not current level structure we should freed memory in variable currentElement
		if (callNotCurrent && objectTWordsList->CurrentElem) {
			free(objectTWordsList->CurrentElem);
		}
		//Iterating over text elements
		while (objectTWordsList->FirstElem) {
			del = objectTWordsList->FirstElem;
			objectTWordsList->FirstElem = objectTWordsList->FirstElem->Next;
			free(del->Word);
			free(del);
		}
		//When deleting, you do not always need to show messages, they are shown in the calling function
		std::cout << (showMsg ? "Words list has been cleared\n" : "");
	} else {
		std::cout << (showMsg ? "Words list is empty, can`t clear list\n" : "");
		ClearObjectTWordsList(objectTWordsList);
	}
}

//A function to check emptiness list
void ListIsEmpty(TObjectTWordsList* objectTWordsList) {
	if (!objectTWordsList->FirstElem) {
		std::cout << "Words list is empty" << std::endl;
		ClearObjectTWordsList(objectTWordsList);
	} else {
		std::cout << "Words list is not empty" << std::endl;
	}
}

//The function setting working pointer on the first element
void SetOnFirstElemTWordsList(TObjectTWordsList* objectTWordsList) {
	//Checking pointers
	if (objectTWordsList->FirstElem) {
		objectTWordsList->Worked = objectTWordsList->FirstElem;
		std::cout << "Work pointer on first element" << std::endl;
	} else {
		std::cout << "Words list is empty, can`t set work pointer on first element" << std::endl;
		ClearObjectTWordsList(objectTWordsList);
	}
}

//The function checks that the working pointer is on the last element
void OnLastElemTWordsList(TObjectTWordsList* objectTWordsList) {
	//Checking pointers
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

//A function to moving work pointer forward
void MoveForwardTWordsList(TObjectTWordsList* objectTWordsList) {
	//Checking pointers
	if (objectTWordsList->FirstElem) {
		if (!objectTWordsList->Worked) {
			std::cout << "Work pointer is nullptr.., can`t move forward" << std::endl;
		} else if (!objectTWordsList->Worked->Next) {
			std::cout << "Work pointer on last element, can`t move forward" << std::endl;
		} else {
			//Move work pointer forward
			objectTWordsList->Worked = objectTWordsList->Worked->Next;
			std::cout << "Work pointer moved on one element" << std::endl;
		}
	} else {
		std::cout << "Words list is empty, can`t move work pointer" << std::endl;
		ClearObjectTWordsList(objectTWordsList);
	}
}

//A function to show list`s element after work pointer
void ShowElemAfterTWordsList(TObjectTWordsList* objectTWordsList) {
	//Checking pointers
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

//A function to deleting list`s element after work pointer
void DelElemAfterTWordsList(TObjectTWordsList* objectTWordsList, bool showMsg = true) {
	TWordsList* del = nullptr;
	//Checking pointers
	if (objectTWordsList->FirstElem) {
		if (!objectTWordsList->Worked) {
			std::cout << (showMsg ? "Work pointer is nullptr.., can`t delete\n" : "");
		} else if (!objectTWordsList->Worked->Next) {
			std::cout << (showMsg ? "Work pointer on last element, can`t delete\n" : "");
		} else {
			del = objectTWordsList->Worked->Next;
			//Building links
			objectTWordsList->Worked->Next = objectTWordsList->Worked->Next->Next;
			free(del->Word);
			free(del);
			//When deleting, you do not always need to show messages, they are shown in the calling function
			std::cout << (showMsg ? "Element has been deleted\n" : "");
		}
	} else {
		std::cout << (showMsg ? "Words list is empty, can`t delete next element\n" : "");
		ClearObjectTWordsList(objectTWordsList);
	}
}

//A function to taking list`s element after work pointer
void TakeElemAfterTWordsList(TObjectTWordsList* objectTWordsList) {
	//Checking pointers
	if (objectTWordsList->FirstElem) {
		if (!objectTWordsList->Worked) {
			std::cout << "Work pointer is nullptr.., can`t take next element" << std::endl;
		} else if (!objectTWordsList->Worked->Next) {
			std::cout << "Work pointer on last element, can`t take next element" << std::endl;
		} else {
			std::cout << "Taken element: " << objectTWordsList->Worked->Next->Word << std::endl;
			//Clearing memory if there is something in the taken element
			if (objectTWordsList->CurrentElem) {
			    free(objectTWordsList->CurrentElem);
			}
			//Pass the value to a separate variable
			objectTWordsList->CurrentElem = strdup(objectTWordsList->Worked->Next->Word);
			//We delete the element without messages about deletion
			DelElemAfterTWordsList(objectTWordsList, false);
		}
	} else {
		std::cout << "Words list is empty, can`t take next element" << std::endl;
		ClearObjectTWordsList(objectTWordsList);
	}
}

//A function to changing list`s element after work pointer
void ChangeElemAfterTWordsList(TObjectTWordsList* objectTWordsList) {
	char* newString = nullptr;
	//Checking pointers
	if (objectTWordsList->FirstElem) {
		if (!objectTWordsList->Worked) {
			std::cout << "Work pointer is nullptr.., can`t change next element" << std::endl;
		} else if (!objectTWordsList->Worked->Next) {
			std::cout << "Work pointer on last element, can`t change next element" << std::endl;
		} else {
			std::cout << "Input new word: ";
			//If error creating string, element does not changed
			if (!(newString = CreateString())) {
				return;
			}
			//Freed old memory
			free(objectTWordsList->Worked->Next->Word);
			//Changing element
			objectTWordsList->Worked->Next->Word = newString;
		}
	} else {
		std::cout << "Words list is empty, can`t change next element" << std::endl;
		ClearObjectTWordsList(objectTWordsList);
	}
}

//A function to add list`s element after work pointer
void AddElemAfterTWordsList(TObjectTWordsList* objectTWordsList) {
	//Creating a list object
	auto newElem = (TWordsList*)calloc(sizeof(TWordsList), 1);

	if (!newElem) {
	    std::cout << "Error allocate memory, element does not add" << std::endl;
	    return;
	}
	std::cout << "Input new word: ";
	//If error creating string, element does not add and freed memory
	if (!(newElem->Word = CreateString())) {
	    free(newElem);
	    return;
	}
	if (!objectTWordsList->FirstElem) {
		//Building links if the list is empty
		objectTWordsList->FirstElem = newElem;
		objectTWordsList->LastElem = newElem;
		objectTWordsList->Worked = newElem;
	} else if (!objectTWordsList->Worked) {
		std::cout << "Work pointer is nullptr.., can`t add new element" << std::endl;
		//If work pointer is nullptr, all memory is freed without messages
		free(newElem->Word);
		free(newElem);
		return;
	} else if (!objectTWordsList->Worked->Next) {
		//Building links if the is not empty and work pointer has not next element
		objectTWordsList->Worked->Next = newElem;
		objectTWordsList->LastElem = newElem;
	} else {
		//Building links if the is not empty and work pointer has next element
		newElem->Next = objectTWordsList->Worked->Next;
		objectTWordsList->Worked->Next = newElem;
	}
	std::cout << "New element has been added" << std::endl;
}

//A function to printing list`s elements
void PrintTWordsList(TObjectTWordsList* objectTWordsList, bool callNoCurrent = false) {
	size_t beginStr = 0;
	size_t endStr = 0;
	bool whileNotWork = true;
	//Checking pointers
	if (objectTWordsList->FirstElem) {
		//Data output and length calculation for working pointer output
		for (auto tmp = objectTWordsList->FirstElem; tmp != nullptr; tmp = tmp->Next) {
			if (tmp == objectTWordsList->Worked) {
				whileNotWork = false;
				endStr = beginStr + strlen(tmp->Word);
			}
			if (whileNotWork) {
				beginStr += strlen(tmp->Word) + 1;
			}
			std::cout << tmp->Word << " ";
		}
		std::cout << std::endl;
		//Alignment if the call is not from the current structure
		if (callNoCurrent) {
			std::cout << "   ";
		}
		//The output working pointer
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

//A function to finish working
void EndWorkTWordsList(TObjectTWordsList* objectTWordsList) {
	objectTWordsList->Available = false;
	std::cout << "Work with words list is forbidden" << std::endl;
}

//---------------------------------------------//
int ChooseTWordsListOperation() {
	//The divider output
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
		//Calling a list function that selects an operation
		operation = ChooseTWordsListOperation();
		//The divider output
		std::cout << "////////////////////////////////////////////////////////////////////////" << std::endl;
		//Select an action relative to the operation number
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
			//Print list after operations
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
			std::cout << "Work is prohibited" << std::endl;
		} else {
			std::cout << "Choose right operation" << std::endl;
		}
	}
	//The divider output
	std::cout << "////////////////////////////////////////////////////////////////////////" << std::endl;
	//Determines whether the list is empty after working with it
	return objectTWordsList->FirstElem;
}
//---------------------------------------------//