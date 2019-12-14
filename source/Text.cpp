#include "Text.h"

#include <iostream>

//---------------------------------------------//
void ClearObjectTText(TObjectTText *objectTText) {
    objectTText->FirstElem = nullptr;
    objectTText->LastElem = nullptr;
    objectTText->Worked = nullptr;
}
//---------------------------------------------//

void BeginWorkTText(TObjectTText *objectTText) {
	objectTText->Available = true;
    std::cout << "Work with text is available" << std::endl;
}

void ClearTText(TObjectTText* objectTText, bool showMsg = true, bool delNested = true, bool callNotCurrent = true) {
    TText* del = nullptr;

    if (objectTText->FirstElem) {
		if (callNotCurrent && objectTText->CurrentElem) {
			ClearTWordsList(objectTText->CurrentElem, false, true);
			free(objectTText->CurrentElem);
		}
        while (objectTText->FirstElem) {
            del = objectTText->FirstElem;
            objectTText->FirstElem = objectTText->FirstElem->Next;
            if (delNested) {
                ClearTWordsList(del->objectTWordsList, false, true);
            	free(del->objectTWordsList);
            }
            free(del);
        }
        showMsg ? std::cout << "Text has been cleared\n" << std::endl : std::cout << "";
    } else {
        showMsg ? std::cout << "Text is empty, can`t clear\n" : std::cout << "";
    }
    ClearObjectTText(objectTText);
}

void TextIsEmpty(TObjectTText *objectTText) {
    if (objectTText->FirstElem) {
        std::cout << "Text is not empty" << std::endl;
    } else {
        std::cout << "Text is empty" << std::endl;
        ClearObjectTText(objectTText);
    }
}

void SetOnFirstElemTText(TObjectTText* objectTText) {
    if (objectTText->FirstElem) {
        objectTText->Worked = objectTText->FirstElem;
        std::cout << "Work pointer on first element" << std::endl;
    } else {
        std::cout << "Text is empty, can`t set work pointer on first element" << std::endl;
        ClearObjectTText(objectTText);
    }
}

void SetOnLastElemTText(TObjectTText* objectTText) {
    if (objectTText->FirstElem) {
        objectTText->Worked = objectTText->LastElem;
        std::cout << "Work pointer on last element" << std::endl;
    } else {
        std::cout << "Text is empty, can`t set work pointer on last element" << std::endl;
        ClearObjectTText(objectTText);
    }
}

void OnFirstElemTText(TObjectTText* objectTText) {
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

void OnLastElemTText(TObjectTText* objectTText) {
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

void MoveForwardTText(TObjectTText* objectTText) {
    if (objectTText->FirstElem) {
        if (!objectTText->Worked) {
            std::cout << "Work pointer invalid, can`t move forward" << std::endl;
        } else if (!objectTText->Worked->Next) {
            std::cout << "Work pointer on last element, can`t move forward" << std::endl;
        } else {
            objectTText->Worked = objectTText->Worked->Next;
            std::cout << "Work pointer moved on next element" << std::endl;
        }
    } else {
        std::cout << "Text is empty, can`t move work pointer" << std::endl;
        ClearObjectTText(objectTText);
    }
}

void MoveBackTText(TObjectTText* objectTText) {
    if (objectTText->FirstElem) {
        if (!objectTText->Worked) {
            std::cout << "Work pointer invalid, can`t move back" << std::endl;
        } else if (!objectTText->Worked->Prev) {
            std::cout << "Work pointer on first element, can`t move back" << std::endl;
        } else {
            objectTText->Worked = objectTText->Worked->Prev;
            std::cout << "Work pointer moved on previous element" << std::endl;
        }
    } else {
        std::cout << "Text is empty, can`t move work pointer" << std::endl;
        ClearObjectTText(objectTText);
    }
}

void ShowElemBeforeTText(TObjectTText* objectTText) {
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

void ShowElemAfterTText(TObjectTText* objectTText) {
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

void DelElemBeforeTText(TObjectTText *objectTText, bool showMsg = true, bool delNested = true) {
	TText* del = nullptr;

	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << (showMsg ? "Work pointer invalid, can`t delete element before\n" : "");
		} else if (!objectTText->Worked->Prev) {
			std::cout << (showMsg ? "Work pointer on first element, can`t delete element before\n" : "");
		} else {
			del = objectTText->Worked->Prev;
			objectTText->Worked->Prev = objectTText->Worked->Prev->Prev;
			if (objectTText->Worked->Prev) {
                objectTText->Worked->Prev->Next = objectTText->Worked;
            } else {
			    objectTText->FirstElem = objectTText->Worked;
			}
			if (delNested) {
                ClearTWordsList(del->objectTWordsList, false, true);
				free(del->objectTWordsList);
			}
			free(del);
			std::cout << (showMsg ? "Element has been deleted\n" : "");
		}
	} else {
		std::cout << (showMsg ? "Text is empty, can`t delete element\n" : "");
		ClearObjectTText(objectTText);
	}
}

void DelElemAfterTText(TObjectTText *objectTText, bool showMsg = true, bool delNested = true) {
	TText* del = nullptr;

	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << (showMsg ? "Work pointer invalid, can`t delete element after\n" : "");
		} else if (!objectTText->Worked->Next) {
			std::cout << (showMsg ? "Work pointer on last element, can`t delete element after\n" : "");
		} else {
			del = objectTText->Worked->Next;
			objectTText->Worked->Next = objectTText->Worked->Next->Next;
			if (objectTText->Worked->Next) {
                objectTText->Worked->Next->Prev = objectTText->Worked;
            } else {
			    objectTText->LastElem = objectTText->Worked;
			}
            if (delNested) {
                ClearTWordsList(del->objectTWordsList, false, true);
				free(del->objectTWordsList);
			}
			free(del);
			std::cout << (showMsg ? "Element has been deleted\n" : "");
		}
	} else {
		std::cout << (showMsg ? "Text is empty, can`t delete element\n" : "");
		ClearObjectTText(objectTText);
	}
}

void TakeElemBeforeTText(TObjectTText* objectTText) {
	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << "Work pointer invalid, can`t take before" << std::endl;
		} else if (!objectTText->Worked->Prev) {
			std::cout << "Work pointer on first element, can`t take before" << std::endl;
		} else {
			if (objectTText->CurrentElem) {
				ClearTWordsList(objectTText->CurrentElem, false, true);
				free(objectTText->CurrentElem);
			}
			objectTText->CurrentElem = objectTText->Worked->Prev->objectTWordsList;
			std::cout << "Taken element:" << std::endl;
			PrintTWordsList(objectTText->CurrentElem, false);
			std::cout << std::endl;
			DelElemBeforeTText(objectTText, false, false);
		}
	} else {
		std::cout << "Text is empty, can`t take element" << std::endl;
		ClearObjectTText(objectTText);
	}
}

void TakeElemAfterTText(TObjectTText* objectTText) {
	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << "Work pointer invalid, can`t take after" << std::endl;
		} else if (!objectTText->Worked->Next) {
			std::cout << "Work pointer on last element, can`t take after" << std::endl;
		} else {
			if (objectTText->CurrentElem) {
                ClearTWordsList(objectTText->CurrentElem, false, true);
				free(objectTText->CurrentElem);
			}
			objectTText->CurrentElem = objectTText->Worked->Next->objectTWordsList;
			std::cout << "Taken element:" << std::endl;
            PrintTWordsList(objectTText->CurrentElem, false);
            std::cout << std::endl;
			DelElemAfterTText(objectTText, false, false);
		}
	} else {
		std::cout << "Text is empty, can`t take element" << std::endl;
		ClearObjectTText(objectTText);
	}
}

void ChangeElemBeforeTText(TObjectTText* objectTText) {
	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << "Work pointer invalid, can`t change before" << std::endl;
		} else if (!objectTText->Worked->Prev) {
			std::cout << "Work pointer on first element, can`t change before" << std::endl;
		} else {
		    if (!MenuList(objectTText->Worked->Prev->objectTWordsList)) {
		        DelElemBeforeTText(objectTText, false);
		        std::cout << "Nested struct is empty, element has been removed" << std::endl;
		    }
		}
	} else {
		std::cout << "Text is empty, can`t change element" << std::endl;
		ClearObjectTText(objectTText);
	}
}

void ChangeElemAfterTText(TObjectTText* objectTText) {
	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << "Work pointer invalid, can`t change after" << std::endl;
		} else if (!objectTText->Worked->Next) {
			std::cout << "Work pointer on last element, can`t change after" << std::endl;
		} else {
            if (!MenuList(objectTText->Worked->Next->objectTWordsList)) {
                DelElemAfterTText(objectTText, false);
                std::cout << "Nested struct is empty, element has been removed" << std::endl;
            }
		}
	} else {
		std::cout << "Text is empty, can`t change element" << std::endl;
		ClearObjectTText(objectTText);
	}
}

void AddElemBeforeTText(TObjectTText* objectTText) {
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
	    ClearTWordsList(newElem, false, true);
	    free(newElem);
	    free(tmpText);
	    std::cout << "Nested struct is empty, can`t add new element" << std::endl;
	    return;
	}
	if (!objectTText->FirstElem) {
		objectTText->FirstElem = tmpText;
		objectTText->FirstElem->objectTWordsList = newElem;
		objectTText->LastElem = objectTText->FirstElem;
		objectTText->Worked = objectTText->FirstElem;
	} else if (!objectTText->Worked) {
		std::cout << "Work pointer invalid, can`t add before" << std::endl;
		ClearTWordsList(newElem, false, true);
		free(newElem);
		free(tmpText);
		return;
	} else if (!objectTText->Worked->Prev) {
		objectTText->Worked->Prev = tmpText;
		objectTText->FirstElem = objectTText->Worked->Prev;
		objectTText->FirstElem->Next = objectTText->Worked;
		objectTText->FirstElem->objectTWordsList = newElem;
	} else {
		tmpText->objectTWordsList = newElem;
		tmpText->Next = objectTText->Worked;
		tmpText->Prev = objectTText->Worked->Prev;
		tmpText->Next->Prev = tmpText;
		tmpText->Prev->Next = tmpText;
	}
    std::cout << "Element has been added" << std::endl;
}

void AddElemAfterTText(TObjectTText* objectTText) {
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
        ClearTWordsList(newElem, false, true);
        free(newElem);
        free(tmpText);
        std::cout << "Nested struct is empty, can`t add new element" << std::endl;
        return;
    }
	if (!objectTText->FirstElem) {
		objectTText->FirstElem = tmpText;
		objectTText->FirstElem->objectTWordsList = newElem;
		objectTText->LastElem = objectTText->FirstElem;
		objectTText->Worked = objectTText->FirstElem;
	} else if (!objectTText->Worked) {
		std::cout << "Work pointer invalid, can`t add after" << std::endl;
		ClearTWordsList(newElem, false, true);
		free(newElem);
		free(tmpText);
		return;
	} else if (!objectTText->Worked->Next) {
	    objectTText->Worked->Next = tmpText;
	    objectTText->LastElem = objectTText->Worked->Next;
	    objectTText->LastElem->Prev = objectTText->Worked;
	    objectTText->LastElem->objectTWordsList = newElem;
	} else {
		tmpText->objectTWordsList = newElem;
		tmpText->Next = objectTText->Worked->Next;
		tmpText->Prev = objectTText->Worked;
		tmpText->Next->Prev = tmpText;
		tmpText->Prev->Next = tmpText;
	}
    std::cout << "Element has been added" << std::endl;
}

void PrintText(TObjectTText* objectTText) {
	if (objectTText->FirstElem) {
		for (auto tmp = objectTText->FirstElem; tmp != nullptr; tmp = tmp->Next) {
			std::cout << (tmp == objectTText->Worked ? "-->" : "   ");
			PrintTWordsList(tmp->objectTWordsList, true);
			std::cout << std::endl;
		}
		std::cout << "revers print:" << std::endl;
        for (auto tmp = objectTText->LastElem; tmp != nullptr; tmp = tmp->Prev) {
            std::cout << (tmp == objectTText->Worked ? "-->" : "   ");
            PrintTWordsList(tmp->objectTWordsList, true);
            std::cout << std::endl;
        }
	} else {
		std::cout << "Text is empty, can`t print" << std::endl;
		ClearObjectTText(objectTText);
	}
}

void EndWorkTText(TObjectTText* objectTText) {
	objectTText->Available = false;
	std::cout << "Work with text is forbidden" << std::endl;
}

//---------------------------------------------//
int ChooseTTextOperation() {
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
		operation = ChooseTTextOperation();
        std::cout << "////////////////////////////////////////////////////////////////////////" << std::endl;
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
    std::cout << "////////////////////////////////////////////////////////////////////////" << std::endl;
	return objectTText->FirstElem;
}
//---------------------------------------------//