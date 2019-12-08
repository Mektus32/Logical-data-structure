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
		if (callNotCurrent) {
			delete objectTText->CurrentElem;
		}
        while (objectTText->FirstElem) {
            del = objectTText->FirstElem;
            objectTText->FirstElem = objectTText->FirstElem->Next;
            //Clear nested struct
            if (delNested) {
            	delete del->objectTWordsList;
            }
            delete del;
        }
        showMsg ? std::cout << "Text has been cleared" << std::endl : std::cout << "";
    } else {
        showMsg ? std::cout << "Text is empty, can`t clear" : std::cout << "";
    }
    ClearObjectTText(objectTText);
}

void TextIsEmpty(TObjectTText *objectTText) {
    if (objectTText->FirstElem) {
        std::cout << "Text is not empty" << std::endl;
    } else {
        std::cout << "Text is empty" << std::endl;
        ClearTText(objectTText);
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
        ClearTText(objectTText);
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
        ClearTText(objectTText);
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
        ClearTText(objectTText);
    }
}

void MoveBackTText(TObjectTText* objectTText) {
    if (objectTText->FirstElem) {
        if (!objectTText->Worked) {
            std::cout << "Work pointer invalid, can`t move back" << std::endl;
        } else if (!objectTText->Worked->Prev) {
            std::cout << "Work pointer on last element, can`t move back" << std::endl;
        } else {
            objectTText->Worked = objectTText->Worked->Prev;
            std::cout << "Work pointer moved on previous element" << std::endl;
        }
    } else {
        std::cout << "Text is empty, can`t move work pointer" << std::endl;
        ClearTText(objectTText);
    }
}

void ShowElemBeforeTText(TObjectTText* objectTText) {
    if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << "Work pointer invalid, can`t show before" << std::endl;
		} else if (!objectTText->Worked->Prev) {
			std::cout << "Work pointer on last element, can`t show before" << std::endl;
		} else {
			std::cout << "Element:" << std::endl;
			//Print nested struct
		}
    } else {
        std::cout << "Text is empty, can`t show element" << std::endl;
        ClearTText(objectTText);
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
			//Print nested struct
		}
	} else {
		std::cout << "Text is empty, can`t show element" << std::endl;
		ClearTText(objectTText);
	}
}

void DelElemBeforeTText(TObjectTText *objectTText, bool showMsg = true, bool delNested = true) {
	TText* del = nullptr;

	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << (showMsg ? "Work pointer invalid, can`t delete element before\n" : "");
		} else if (!objectTText->Worked->Prev) {
			std::cout << (showMsg ? "Work pointer on last element, can`t delete element before\n" : "");
		} else {
			del = objectTText->Worked->Prev;
			objectTText->Worked->Prev = objectTText->Worked->Prev->Prev;
			objectTText->Worked->Prev->Next = objectTText->Worked;
			//delete nested struct
			if (delNested) {
				delete del->objectTWordsList;
			}
			delete del;
			std::cout << (showMsg ? "Element has been deleted\n" : "");
		}
	} else {
		std::cout << (showMsg ? "Text is empty, can`t delete element\n" : "");
		ClearTText(objectTText);
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
			objectTText->Worked->Next->Prev = objectTText->Worked;
			//delete nested struct
			if (delNested) {
				delete del->objectTWordsList;
			}
			delete del;
			std::cout << (showMsg ? "Element has been deleted\n" : "");
		}
	} else {
		std::cout << (showMsg ? "Text is empty, can`t delete element\n" : "");
		ClearTText(objectTText);
	}
}

void TakeElemBeforeTText(TObjectTText* objectTText) {
	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << "Work pointer invalid, can`t take before" << std::endl;
		} else if (!objectTText->Worked->Prev) {
			std::cout << "Work pointer on last element, can`t take before" << std::endl;
		} else {
			if (objectTText->CurrentElem) {
				//Clear nested struct
				delete objectTText->CurrentElem;
			}
			objectTText->CurrentElem = objectTText->Worked->Prev->objectTWordsList;
			std::cout << "Element:" << std::endl;
			//Print nested struct
			DelElemBeforeTText(objectTText, false, false);
		}
	} else {
		std::cout << "Text is empty, can`t take element" << std::endl;
		ClearTText(objectTText);
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
				//Clear nested struct
				delete objectTText->CurrentElem;
			}
			objectTText->CurrentElem = objectTText->Worked->Prev->objectTWordsList;
			std::cout << "Element:" << std::endl;
			//Print nested struct
			DelElemAfterTText(objectTText, false, false);
		}
	} else {
		std::cout << "Text is empty, can`t take element" << std::endl;
		ClearTText(objectTText);
	}
}

void ChangeElemBeforeTText(TObjectTText* objectTText) {
	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << "Work pointer invalid, can`t change before" << std::endl;
		} else if (!objectTText->Worked->Prev) {
			std::cout << "Work pointer on last element, can`t change before" << std::endl;
		} else {
			//Menu nested struct
		}
	} else {
		std::cout << "Text is empty, can`t change before" << std::endl;
		ClearTText(objectTText);
	}
}

void ChangeElemAfterTText(TObjectTText* objectTText) {
	if (objectTText->FirstElem) {
		if (!objectTText->Worked) {
			std::cout << "Work pointer invalid, can`t change after" << std::endl;
		} else if (!objectTText->Worked->Next) {
			std::cout << "Work pointer on last element, can`t change after" << std::endl;
		} else {
			//Menu nested struct
		}
	} else {
		std::cout << "Text is empty, can`t change after" << std::endl;
		ClearTText(objectTText);
	}
}

void AddElemBeforeTText(TObjectTText* objectTText) {
	auto newElem = new TObjectTWordsList;
	//Menu nested struct
	if (!objectTText->FirstElem) {
		objectTText->FirstElem = new TText;
		objectTText->FirstElem->objectTWordsList = newElem;
		objectTText->LastElem = objectTText->FirstElem;
		objectTText->Worked = objectTText->FirstElem;
	} else if (!objectTText->Worked) {
		std::cout << "Work pointer invalid, can`t add before" << std::endl;
		//Clear nested struct
		delete newElem;
	} else if (!objectTText->Worked->Prev) {
		std::cout << "Work pointer om first element, can`t add before" << std::endl;
		//Clear nested struct
		delete newElem;
	} else {
		auto* tmp = new TText;
		tmp->Next = objectTText->Worked;
		tmp->Prev = objectTText->Worked->Prev;
		tmp->Next->Prev = tmp;
		tmp->Prev->Next = tmp;
		std::cout << "Element has been added" << std::endl;
	}
}

void AddElemAfterTText(TObjectTText* objectTText) {
	auto newElem = new TObjectTWordsList;
	//Menu nested struct
	if (!objectTText->FirstElem) {
		objectTText->FirstElem = new TText;
		objectTText->FirstElem->objectTWordsList = newElem;
		objectTText->LastElem = objectTText->FirstElem;
		objectTText->Worked = objectTText->FirstElem;
	} else if (!objectTText->Worked) {
		std::cout << "Work pointer invalid, can`t add after" << std::endl;
		//Clear nested struct
		delete newElem;
	} else if (!objectTText->Worked->Next) {
		std::cout << "Work pointer om first element, can`t add after" << std::endl;
		//Clear nested struct
		delete newElem;
	} else {
		auto tmp = new TText;
		tmp->Next = objectTText->Worked->Next;
		tmp->Prev = objectTText->Worked;
		tmp->Next->Prev = tmp;
		tmp->Prev->Next = tmp;
		std::cout << "Element has been added" << std::endl;
	}
}

void PrintText(TObjectTText* objectTText) {
	if (objectTText->FirstElem) {
		int i = 0;
		for (auto tmp = objectTText->FirstElem; tmp != nullptr; tmp = tmp->Next) {
			std::cout << (tmp == objectTText->Worked ? "-->" : "   ");
			//Print nested struct
			std::cout << std::endl;
		}
	} else {
		std::cout << "Text is empty, can`t print" << std::endl;
		ClearTText(objectTText);
	}
}

void EndWorkTText(TObjectTText* objectTText) {
	objectTText->Available = false;
	std::cout << "Work with text is forbidden" << std::endl;
}

//---------------------------------------------//

int ChooseTTextOperation() {
	//system("pause");
	//system("cls");
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
			std::cout << "Choose first operation" << std::endl;
		} else {
			std::cout << "Choose right operation" << std::endl;
		};
	}
	return objectTText->FirstElem;
}