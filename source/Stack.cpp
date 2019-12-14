#include "Stack.h"

#include <iostream>

//---------------------------------------------//
void ClearObjectTStack(TObjectTStack& objectTStack) {
    objectTStack.FirstElem = nullptr;
    objectTStack.LastElem = nullptr;
}
//---------------------------------------------//

void BeginWorkTStack(TObjectTStack& objectTStack) {
	objectTStack.Available = true;
    std::cout << "Work with stack is available" << std::endl;
}

void ClearTStack(TObjectTStack &objectTStack, bool showMsg, size_t &size) {
    TStack* del = nullptr;

    if (objectTStack.FirstElem) {
        while (objectTStack.FirstElem) {
            del = objectTStack.FirstElem;
            objectTStack.FirstElem = objectTStack.FirstElem->Next;
            ClearTText(del->objectTText, false, true,true);
            free(del->objectTText);
            free(del);
        }
        size = 0;
        std::cout << (showMsg ? "Stack has been cleared\n" : "");
    } else {
        std::cout << (showMsg ? "Stack is empty, can`t clear\n" : "");
    }
    ClearObjectTStack(objectTStack);
}

void StackIsEmpty(TObjectTStack& objectTStack) {
    if (objectTStack.FirstElem) {
        std::cout << "Stack is not empty" << std::endl;
    } else {
        std::cout << "Stack is empty" << std::endl;
        ClearObjectTStack(objectTStack);
    }
}

void ShowTStackElem(TObjectTStack& objectTStack) {
    if (objectTStack.FirstElem) {
    	std::cout << "Element:" << std::endl;
        PrintText(objectTStack.LastElem->objectTText);
    } else {
        std::cout << "Stack is empty, can`t show value" << std::endl;
        ClearObjectTStack(objectTStack);
    }
}

void DelTStackElem(TObjectTStack &objectTStack, bool showMsg, bool delNested, size_t &size) {
    TStack* tmp = nullptr;

    if (objectTStack.FirstElem) {
        tmp = objectTStack.FirstElem;
        while (tmp != objectTStack.LastElem && tmp->Next != objectTStack.LastElem) {
            tmp = tmp->Next;
        }
        if (delNested) {
            ClearTText(objectTStack.LastElem->objectTText, false, delNested, true);
            free(objectTStack.LastElem->objectTText);
        }
        if (objectTStack.LastElem != objectTStack.FirstElem) {
			free(objectTStack.LastElem);
			objectTStack.LastElem = tmp;
			objectTStack.LastElem->Next = nullptr;
		} else {
			free(objectTStack.LastElem);
			objectTStack.FirstElem = nullptr;
        }
        --size;
        std::cout << (showMsg ? "Element has been deleted\n" : "");
    } else {
        std::cout << (showMsg ? "Stack is empty, can`t delete element\n" : "");
        ClearObjectTStack(objectTStack);
    }
}

void TakeTStackElem(TObjectTStack &objectTStack, size_t &size) {
    if (objectTStack.FirstElem) {
		if (objectTStack.CurrentElem) {
			ClearTText(objectTStack.CurrentElem, false, true, true);
			free(objectTStack.CurrentElem);
		}
		objectTStack.CurrentElem = objectTStack.LastElem->objectTText;
        std::cout << "Taken element:" << std::endl;
        PrintText(objectTStack.LastElem->objectTText);
		DelTStackElem(objectTStack, false, false, size);

    } else {
        std::cout << "Stack is empty, can`t take element" << std::endl;
        ClearObjectTStack(objectTStack);
    }
}

void ChangeTStackElem(TObjectTStack &objectTStack, size_t &size) {
    if (objectTStack.FirstElem) {
        if (!MenuText(objectTStack.LastElem->objectTText)) {
			DelTStackElem(objectTStack, false, false, size);
        	std::cout << "Nested structure is empty, element has been deleted" << std::endl;
        	return;
        }
        std::cout << "Element has been changed" << std::endl;
    } else {
        std::cout << "Stack is empty, can`t change element" << std::endl;
        ClearObjectTStack(objectTStack);
    }
}

void AddTStackElem(TObjectTStack &objectTStack, size_t &size) {
	if (size >= 10) {
		std::cout << "Size limit" << std::endl;
		return;
	}
    auto newElem = (TObjectTText*)calloc(sizeof(TObjectTText), 1);
    auto tmpStack = (TStack*)calloc(sizeof(TStack), 1);

    if (!newElem || !tmpStack) {
        std::cout << "Error allocate memory, element does not add" << std::endl;
        if (newElem) {
            free(newElem);
        }
        if (tmpStack) {
            free(tmpStack);
        }
        return;
    }
    if (!MenuText(newElem)) {
		free(newElem);
		free(tmpStack);
		std::cout << "Nested structure is empty, element does not add" << std::endl;
		return;
    }
    if (objectTStack.FirstElem) {
        objectTStack.LastElem->Next = tmpStack;
        objectTStack.LastElem = objectTStack.LastElem->Next;
        objectTStack.LastElem->objectTText = newElem;
    } else {
        objectTStack.FirstElem =  tmpStack;
        objectTStack.FirstElem->objectTText = newElem;
        objectTStack.LastElem = objectTStack.FirstElem;
    }
    ++size;
    std::cout << "Element has been added" << std::endl;
}

void PrintTStack(TObjectTStack& objectTStack) {
    TStack* tmp = nullptr;

    if (objectTStack.FirstElem) {
        tmp = objectTStack.FirstElem;
        for (int i = 1; tmp != nullptr; ++i, tmp = tmp->Next) {
            std::cout << i << ".Elem." << std::endl;
            PrintText(tmp->objectTText);
        }
    } else {
        std::cout << "Stack is empty, can`t print stack" << std::endl;
        ClearObjectTStack(objectTStack);
    }
}

void EndWorkTStack(TObjectTStack& objectTStack) {
	objectTStack.Available = false;
    std::cout << "Work with stack is end" << std::endl;
}

//---------------------------------------------//
int ChooseTStackOperation() {
    std::cout << "////////////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << "Stack menu" << std::endl;
    std::cout << "1.Begin work with stack" << std::endl;
    std::cout << "2.To clear the stack" << std::endl;
    std::cout << "3.To check the emptiness of the stack" << std::endl;
    std::cout << "4.Show stack element" << std::endl;
    std::cout << "5.Delete stack element" << std::endl;
    std::cout << "6.Take stack element" << std::endl;
    std::cout << "7.Change stack element" << std::endl;
    std::cout << "8.Add stack element" << std::endl;
    std::cout << "9.Print stack" << std::endl;
    std::cout << "10.End work with stack" << std::endl;
    std::cout << "11.End program" << std::endl;
    std::cout << "Input number operation: ";
    return InputManager(false);
}

void MenuStack() {
    TObjectTStack stack;
	size_t size = 0;
    bool loop = true;
    int operation;

    while (loop) {
        operation = ChooseTStackOperation();
        std::cout << "////////////////////////////////////////////////////////////////////////" << std::endl;
        if (stack.Available) {
            switch (operation) {
                case 1: BeginWorkTStack(stack); break;
                case 2: ClearTStack(stack, false, size); break;
                case 3: StackIsEmpty(stack); break;
                case 4: ShowTStackElem(stack); break;
                case 5: DelTStackElem(stack, false, false, size); break;
                case 6: TakeTStackElem(stack, size); break;
                case 7: ChangeTStackElem(stack, size); break;
                case 8: AddTStackElem(stack, size); break;
                case 9: PrintTStack(stack); break;
                case 10 : EndWorkTStack(stack); break;
                case 11 : loop = false; break;
                default: std::cout << "Choose right operation" << std::endl;
            }
            if (operation != 9 && operation != 11) {
            	if (stack.FirstElem) {
            		PrintTStack(stack);
            	}
            }
        } else if (operation == 1) {
            BeginWorkTStack(stack);
        } else if (operation == 11) {
            loop = false;
			ClearTStack(stack, false, size);
            if (stack.CurrentElem) {
            	ClearTText(stack.CurrentElem, false, true, true);
            	free(stack.CurrentElem);
            }
        } else if (operation > 1 && operation < 11) {
            std::cout << "Work is prohibited" << std::endl;
        } else {
        	std::cout << "Choose right operation" << std::endl;
        }
    }
}
//---------------------------------------------//