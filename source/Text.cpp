#include "Text.h"

#include <iostream>

//Additional function
//---------------------------------------------//
//The function clears the text parameters
void ClearObjectTText(TObjectTText *objectTText) {
    objectTText->FirstElem = nullptr;
    objectTText->LastElem = nullptr;
    objectTText->Worked = nullptr;
}
//---------------------------------------------//
//The text`s functions

//A function to start working
void BeginWorkTText(TObjectTText *objectTText) {
	objectTText->Available = true;
    std::cout << "Work with text is available" << std::endl;
}

//A function to clean text
void ClearTText(TObjectTText* objectTText, bool showMsg = true, bool delNested = true, bool callNotCurrent = true) {
    TText* del = nullptr;
	//Checking pointers
    if (objectTText->FirstElem) {
    	//If calling not current level structure we should freed memory in variable currentElement
		if (callNotCurrent && objectTText->CurrentElem) {
			ClearTWordsList(objectTText->CurrentElem, false, true);
			free(objectTText->CurrentElem);
		}
		//Iterating over text elements
        while (objectTText->FirstElem) {
            del = objectTText->FirstElem;
            objectTText->FirstElem = objectTText->FirstElem->Next;
			//Removing a nested structure defined in the calling function, without messages
            if (delNested) {
                ClearTWordsList(del->objectTWordsList, false, true);
            	free(del->objectTWordsList);
            }
            free(del);
        }
		//When deleting, you do not always need to show messages, they are shown in the calling function
        std::cout << (showMsg ? "Text has been cleared\n" : "");
    } else {
        std::cout << (showMsg ? "Text is empty, can`t clear\n" : "");
    }
    ClearObjectTText(objectTText);
}

//A function to check emptiness text
void TextIsEmpty(TObjectTText *objectTText) {
    if (objectTText->FirstElem) {
        std::cout << "Text is not empty" << std::endl;
    } else {
        std::cout << "Text is empty" << std::endl;
        ClearObjectTText(objectTText);
    }
}

//The function setting working pointer on the first element
void SetOnFirstElemTText(TObjectTText* objectTText) {
	//Checking pointers
    if (objectTText->FirstElem) {
        objectTText->Worked = objectTText->FirstElem;
        std::cout << "Work pointer on first element" << std::endl;
    } else {
        std::cout << "Text is empty, can`t set work pointer on first element" << std::endl;
        ClearObjectTText(objectTText);
    }
}

//The function setting working pointer on the last element
void SetOnLastElemTText(TObjectTText* objectTText) {
	//Checking pointers
    if (objectTText->FirstElem) {
        objectTText->Worked = objectTText->LastElem;
        std::cout << "Work pointer on last element" << std::endl;
    } else {
        std::cout << "Text is empty, can`t set work pointer on last element" << std::endl;
        ClearObjectTText(objectTText);
    }
}

//The function checks that the working pointer is on the first element
void OnFirstElemTText(TObjectTText* objectTText) {
	//Checking pointers
    if (objectTText->FirstElem) {
        if (objectTText->FirstElem == objectTText->Worked) {
            std::cout << "Work pointer on fist element" << std::endl;
        } else {
            std::cout << "Work pointer not on first element" << std::endl;
        }
    } else {
        std::cout << "Text is empty, can`t check position work pointer" << std::endl;
        ClearObjectTText(objectTText);
    }
}

//The function checks that the working pointer is on the last element
void OnLastElemTText(TObjectTText* objectTText) {
	//Checking pointers
    if (objectTText->FirstElem) {
        if (objectTText->LastElem == objectTText->Worked) {
            std::cout << "Work pointer on last element" << std::endl;
        } else {
            std::cout << "Work pointer not on last element" << std::endl;
        }
    } else {
        std::cout << "Text is empty, can`t check position work pointer" << std::endl;
        ClearObjectTText(objectTText);
    }
}

//A function to moving work pointer forward
void MoveForwardTText(TObjectTText* objectTText) {
	//Checking pointers
    if (objectTText->FirstElem) {
        if (!objectTText->Worked) {
            std::cout << "Work pointer invalid, can`t move forward" << std::endl;
        } else if (!objectTText->Worked->Next) {
            std::cout << "Work pointer on last element, can`t move forward" << std::endl;
        } else {
			//Move work pointer forward
            objectTText->Worked = objectTText->Worked->Next;
            std::cout << "Work pointer moved on next element" << std::endl;
        }
    } else {
        std::cout << "Text is empty, can`t move work pointer" << std::endl;
        ClearObjectTText(objectTText);
    }
}

//A function to moving work pointer back
void MoveBackTText(TObjectTText* objectTText) {
	//Checking pointers
    if (objectTText->FirstElem) {
        if (!objectTText->Worked) {
            std::cout << "Work pointer invalid, can`t move back" << std::endl;
        } else if (!objectTText->Worked->Prev) {
            std::cout << "Work pointer on first element, can`t move back" << std::endl;
        } else {
        	//Move work pointer back
            objectTText->Worked = objectTText->Worked->Prev;
            std::cout << "Work pointer moved on previous element" << std::endl;
        }
    } else {
        std::cout << "Text is empty, can`t move work pointer" << std::endl;
        ClearObjectTText(objectTText);
    }
}

//A function to show text`s element before work pointer
void ShowElemBeforeTText(TObjectTText* objectTText) {
	//Checking pointers
    if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << "Work pointer invalid, can`t show before" << std::endl;
		} else if (!objectTText->Worked->Prev) {
			std::cout << "Work pointer on first element, can`t show before" << std::endl;
		} else {
			std::cout << "Element:" << std::endl;
			PrintTWordsList(objectTText->Worked->Prev->objectTWordsList, false);
			std::cout << std::endl;
		}
    } else {
        std::cout << "Text is empty, can`t show element" << std::endl;
        ClearObjectTText(objectTText);
    }
}

//A function to show text`s element after work pointer
void ShowElemAfterTText(TObjectTText* objectTText) {
	//Checking pointers
	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << "Work pointer invalid, can`t show after" << std::endl;
		} else if (!objectTText->Worked->Next) {
			std::cout << "Work pointer on last element, can`t show after" << std::endl;
		} else {
			std::cout << "Element:" << std::endl;
            PrintTWordsList(objectTText->Worked->Next->objectTWordsList, false);
            std::cout << std::endl;
		}
	} else {
		std::cout << "Text is empty, can`t show element" << std::endl;
		ClearObjectTText(objectTText);
	}
}

//A function to deleting text`s element before work pointer
void DelElemBeforeTText(TObjectTText *objectTText, bool showMsg = true, bool delNested = true) {
	TText* del = nullptr;
	//Checking pointers
	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << (showMsg ? "Work pointer invalid, can`t delete element before\n" : "");
		} else if (!objectTText->Worked->Prev) {
			std::cout << (showMsg ? "Work pointer on first element, can`t delete element before\n" : "");
		} else {
			del = objectTText->Worked->Prev;
			//Building links
			objectTText->Worked->Prev = objectTText->Worked->Prev->Prev;
			if (objectTText->Worked->Prev) {
                objectTText->Worked->Prev->Next = objectTText->Worked;
            } else {
			    objectTText->FirstElem = objectTText->Worked;
			}
			//Removing a nested structure defined in the calling function
			if (delNested) {
                ClearTWordsList(del->objectTWordsList, false, true);
				free(del->objectTWordsList);
			}
			free(del);
			//When deleting, you do not always need to show messages, they are shown in the calling function
			std::cout << (showMsg ? "Element has been deleted\n" : "");
		}
	} else {
		std::cout << (showMsg ? "Text is empty, can`t delete element\n" : "");
		ClearObjectTText(objectTText);
	}
}

//A function to deleting text`s element after work pointer
void DelElemAfterTText(TObjectTText *objectTText, bool showMsg = true, bool delNested = true) {
	TText* del = nullptr;
	//Checking pointers
	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << (showMsg ? "Work pointer invalid, can`t delete element after\n" : "");
		} else if (!objectTText->Worked->Next) {
			std::cout << (showMsg ? "Work pointer on last element, can`t delete element after\n" : "");
		} else {
			del = objectTText->Worked->Next;
			//Building links
			objectTText->Worked->Next = objectTText->Worked->Next->Next;
			if (objectTText->Worked->Next) {
                objectTText->Worked->Next->Prev = objectTText->Worked;
            } else {
			    objectTText->LastElem = objectTText->Worked;
			}
			//Removing a nested structure defined in the calling function
            if (delNested) {
                ClearTWordsList(del->objectTWordsList, false, true);
				free(del->objectTWordsList);
			}
			free(del);
			//When deleting, you do not always need to show messages, they are shown in the calling function
			std::cout << (showMsg ? "Element has been deleted\n" : "");
		}
	} else {
		std::cout << (showMsg ? "Text is empty, can`t delete element\n" : "");
		ClearObjectTText(objectTText);
	}
}

//A function to taking text`s element before work pointer
void TakeElemBeforeTText(TObjectTText* objectTText) {
	//Checking pointers
	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << "Work pointer invalid, can`t take before" << std::endl;
		} else if (!objectTText->Worked->Prev) {
			std::cout << "Work pointer on first element, can`t take before" << std::endl;
		} else {
			//Clearing memory if there is something in the taken element
			if (objectTText->CurrentElem) {
				ClearTWordsList(objectTText->CurrentElem, false, true);
				free(objectTText->CurrentElem);
			}
			//Pass the value to a separate variable
			objectTText->CurrentElem = objectTText->Worked->Prev->objectTWordsList;
			std::cout << "Taken element:" << std::endl;
			PrintTWordsList(objectTText->CurrentElem, false);
			std::cout << std::endl;
			//We delete the element without messages about deletion and without deleting the nested structure,
			//since we need it in the new variable
			DelElemBeforeTText(objectTText, false, false);
		}
	} else {
		std::cout << "Text is empty, can`t take element" << std::endl;
		ClearObjectTText(objectTText);
	}
}

//A function to taking text`s element after work pointer
void TakeElemAfterTText(TObjectTText* objectTText) {
	//Checking pointers
	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << "Work pointer invalid, can`t take after" << std::endl;
		} else if (!objectTText->Worked->Next) {
			std::cout << "Work pointer on last element, can`t take after" << std::endl;
		} else {
			//Clearing memory if there is something in the taken element
			if (objectTText->CurrentElem) {
                ClearTWordsList(objectTText->CurrentElem, false, true);
				free(objectTText->CurrentElem);
			}
			//Pass the value to a separate variable
			objectTText->CurrentElem = objectTText->Worked->Next->objectTWordsList;
			std::cout << "Taken element:" << std::endl;
            PrintTWordsList(objectTText->CurrentElem, false);
            std::cout << std::endl;
			//We delete the element without messages about deletion and without deleting the nested structure,
			//since we need it in the new variable
			DelElemAfterTText(objectTText, false, false);
		}
	} else {
		std::cout << "Text is empty, can`t take element" << std::endl;
		ClearObjectTText(objectTText);
	}
}

//A function to changing text`s element before work pointer
void ChangeElemBeforeTText(TObjectTText* objectTText) {
	//Checking pointers
	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << "Work pointer invalid, can`t change before" << std::endl;
		} else if (!objectTText->Worked->Prev) {
			std::cout << "Work pointer on first element, can`t change before" << std::endl;
		} else {
			//Go to the list menu
		    if (!MenuList(objectTText->Worked->Prev->objectTWordsList)) {
				//If the object is empty after the change, the item is removed from the text and all memory is freed,
				//without displaying messages
		        DelElemBeforeTText(objectTText, false);
		        std::cout << "Nested struct is empty, element has been removed" << std::endl;
		    }
		}
	} else {
		std::cout << "Text is empty, can`t change element" << std::endl;
		ClearObjectTText(objectTText);
	}
}

//A function to changing text`s element after work pointer
void ChangeElemAfterTText(TObjectTText* objectTText) {
	//Checking pointers
	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << "Work pointer invalid, can`t change after" << std::endl;
		} else if (!objectTText->Worked->Next) {
			std::cout << "Work pointer on last element, can`t change after" << std::endl;
		} else {
			//Go to the list menu
            if (!MenuList(objectTText->Worked->Next->objectTWordsList)) {
				//If the object is empty after the change, the item is removed from the text and all memory is freed,
				//without displaying messages
                DelElemAfterTText(objectTText, false);
                std::cout << "Nested struct is empty, element has been removed" << std::endl;
            }
		}
	} else {
		std::cout << "Text is empty, can`t change element" << std::endl;
		ClearObjectTText(objectTText);
	}
}

//A function to add text`s element before work pointer
void AddElemBeforeTText(TObjectTText* objectTText) {
	//Creating a text object and list
	auto newElem = (TObjectTWordsList*)calloc(sizeof(TObjectTWordsList), 1);
	auto tmpText = (TText*)calloc(sizeof(TText), 1);

	if (!newElem || !tmpText) {
	    std::cout << "Error allocate memory, element does not add" << std::endl;
	    if (newElem) {
	        free(newElem);
	    }
	    if (tmpText) {
	        free(tmpText);
	    }
	    return;
	}
	if (!MenuList(newElem)) {
		//If the object is empty after the creating, the item is does not add in the text and all memory is freed,
		//without messages
	    ClearTWordsList(newElem, false, true);
	    free(newElem);
	    free(tmpText);
	    std::cout << "Nested struct is empty, can`t add new element" << std::endl;
	    return;
	}
	if (!objectTText->FirstElem) {
		//Building links if the text is empty
		objectTText->FirstElem = tmpText;
		objectTText->FirstElem->objectTWordsList = newElem;
		objectTText->LastElem = objectTText->FirstElem;
		objectTText->Worked = objectTText->FirstElem;
	} else if (!objectTText->Worked) {
		std::cout << "Work pointer invalid, can`t add before" << std::endl;
		//If work pointer is nullptr, all memory is freed without messages
		ClearTWordsList(newElem, false, true);
		free(newElem);
		free(tmpText);
		return;
	} else if (!objectTText->Worked->Prev) {
		//Building links if the is not empty and work pointer has not previous element
		objectTText->Worked->Prev = tmpText;
		objectTText->FirstElem = objectTText->Worked->Prev;
		objectTText->FirstElem->Next = objectTText->Worked;
		objectTText->FirstElem->objectTWordsList = newElem;
	} else {
		//Building links if the is not empty and work pointer has previous element
		tmpText->objectTWordsList = newElem;
		tmpText->Next = objectTText->Worked;
		tmpText->Prev = objectTText->Worked->Prev;
		tmpText->Next->Prev = tmpText;
		tmpText->Prev->Next = tmpText;
	}
    std::cout << "Element has been added" << std::endl;
}

//A function to add text`s element after work pointer
void AddElemAfterTText(TObjectTText* objectTText) {
	//Creating a text object and list
	auto newElem = (TObjectTWordsList*)calloc(sizeof(TObjectTWordsList), 1);
	auto tmpText = (TText*)calloc(sizeof(TText), 1);

    if (!newElem || !tmpText) {
        std::cout << "Error allocate memory, element does not add" << std::endl;
        if (newElem) {
            free(newElem);
        }
        if (tmpText) {
            free(tmpText);
        }
        return;
    }
    if (!MenuList(newElem)) {
		//If the object is empty after the creating, the item is does not add in the text and all memory is freed,
		//without messages
        ClearTWordsList(newElem, false, true);
        free(newElem);
        free(tmpText);
        std::cout << "Nested struct is empty, can`t add new element" << std::endl;
        return;
    }
	if (!objectTText->FirstElem) {
		//Building links if the text is empty
		objectTText->FirstElem = tmpText;
		objectTText->FirstElem->objectTWordsList = newElem;
		objectTText->LastElem = objectTText->FirstElem;
		objectTText->Worked = objectTText->FirstElem;
	} else if (!objectTText->Worked) {
		std::cout << "Work pointer invalid, can`t add after" << std::endl;
		//If work pointer is nullptr, all memory is freed without messages
		ClearTWordsList(newElem, false, true);
		free(newElem);
		free(tmpText);
		return;
	} else if (!objectTText->Worked->Next) {
		//Building links if the is not empty and work pointer has not next element
	    objectTText->Worked->Next = tmpText;
	    objectTText->LastElem = objectTText->Worked->Next;
	    objectTText->LastElem->Prev = objectTText->Worked;
	    objectTText->LastElem->objectTWordsList = newElem;
	} else {
		//Building links if the is not empty and work pointer has next element
		tmpText->objectTWordsList = newElem;
		tmpText->Next = objectTText->Worked->Next;
		tmpText->Prev = objectTText->Worked;
		tmpText->Next->Prev = tmpText;
		tmpText->Prev->Next = tmpText;
	}
    std::cout << "Element has been added" << std::endl;
}

//A function to printing text`s elements
void PrintText(TObjectTText* objectTText) {
	//Checking pointers
	if (objectTText->FirstElem) {
		for (auto tmp = objectTText->FirstElem; tmp != nullptr; tmp = tmp->Next) {
			//Align the output and output of the working pointer
			std::cout << (tmp == objectTText->Worked ? "-->" : "   ");
			PrintTWordsList(tmp->objectTWordsList, true);
			std::cout << std::endl;
		}
		//Output in reverse order
		std::cout << "revers print:" << std::endl;
        for (auto tmp = objectTText->LastElem; tmp != nullptr; tmp = tmp->Prev) {
        	//Align the output and output of the working pointer
            std::cout << (tmp == objectTText->Worked ? "-->" : "   ");
            PrintTWordsList(tmp->objectTWordsList, true);
            std::cout << std::endl;
        }
	} else {
		std::cout << "Text is empty, can`t print" << std::endl;
		ClearObjectTText(objectTText);
	}
}

//A function to finish working
void EndWorkTText(TObjectTText* objectTText) {
	objectTText->Available = false;
	std::cout << "Work with text is forbidden" << std::endl;
}

//---------------------------------------------//
int ChooseTTextOperation() {
	//The divider output
    std::cout << "////////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "Text menu" << std::endl;
	std::cout << "1.Begin work with text" << std::endl;
	std::cout << "2.To clear the text" << std::endl;
	std::cout << "3.To check the emptiness of the text" << std::endl;
	std::cout << "4.To set work pointer on first element" << std::endl;
	std::cout << "5.To set work pointer on last element" << std::endl;
	std::cout << "6.To check work pointer on first element" << std::endl;
	std::cout << "7.To check work pointer on last element" << std::endl;
	std::cout << "8.To move work pointer forward" << std::endl;
	std::cout << "9.To move work pointer back" << std::endl;
	std::cout << "10.To show element before work pointer" << std::endl;
	std::cout << "11.To show element after work pointer" << std::endl;
	std::cout << "12.To delete element before work pointer" << std::endl;
	std::cout << "13.To delete element after work pointer" << std::endl;
	std::cout << "14.To take element before work pointer" << std::endl;
	std::cout << "15.To take element after work pointer" << std::endl;
	std::cout << "16.To change element before work pointer" << std::endl;
	std::cout << "17.To change element after work pointer" << std::endl;
	std::cout << "18.To add element before work pointer" << std::endl;
	std::cout << "19.To add element after work pointer" << std::endl;
	std::cout << "20.To print text" << std::endl;
	std::cout << "21.End work with text" << std::endl;
	std::cout << "22.Return to up struct" << std::endl;
	std::cout << "23.End program" << std::endl;
	std::cout << "Input number operation: ";
	return InputManager(false);
}

bool MenuText(TObjectTText* objectTText) {
	objectTText->Available = false;
	bool loop = true;
	int operation;

	while (loop) {
		//Calling a text function that selects an operation
		operation = ChooseTTextOperation();
		//The divider output
        std::cout << "////////////////////////////////////////////////////////////////////////" << std::endl;
		//Select an action relative to the operation number
        if (objectTText->Available) {
			switch (operation) {
				case 1: BeginWorkTText(objectTText); break;
				case 2: ClearTText(objectTText, true, true, false); break;
				case 3: TextIsEmpty(objectTText); break;
				case 4: SetOnFirstElemTText(objectTText); break;
				case 5: SetOnLastElemTText(objectTText); break;
				case 6: OnFirstElemTText(objectTText); break;
				case 7: OnLastElemTText(objectTText); break;
				case 8: MoveForwardTText(objectTText); break;
				case 9: MoveBackTText(objectTText); break;
				case 10: ShowElemBeforeTText(objectTText); break;
				case 11: ShowElemAfterTText(objectTText); break;
				case 12: DelElemBeforeTText(objectTText); break;
				case 13: DelElemAfterTText(objectTText); break;
				case 14: TakeElemBeforeTText(objectTText); break;
				case 15: TakeElemAfterTText(objectTText); break;
				case 16: ChangeElemBeforeTText(objectTText); break;
				case 17: ChangeElemAfterTText(objectTText); break;
				case 18: AddElemBeforeTText(objectTText); break;
				case 19: AddElemAfterTText(objectTText); break;
				case 20: PrintText(objectTText); break;
				case 21: EndWorkTText(objectTText); break;
				case 22: loop = false; break;
				case 23: exit(0);
				default: std::cout << "Choose right operation" << std::endl;
			}
			//Print text after operations
			if (operation != 20 && operation != 22) {
				if (objectTText->FirstElem) {
					PrintText(objectTText);
				}
			}
		} else if (operation == 1) {
			BeginWorkTText(objectTText);
		} else if (operation == 22) {
			loop = false;
		} else if (operation == 23) {
			exit(0);
		} else if (operation > 1 && operation < 22) {
			std::cout << "Work is prohibited" << std::endl;
		} else {
			std::cout << "Choose right operation" << std::endl;
		};
	}
	//The divider output
    std::cout << "////////////////////////////////////////////////////////////////////////" << std::endl;
	//Determines whether the text is empty after working with it
	return objectTText->FirstElem;
}
//---------------------------------------------//