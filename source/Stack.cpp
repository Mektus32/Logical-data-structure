#include "Stack.h"

#include <iostream>

//---------------------------------------------//
void ClearObjectTStack(TObjectTStack& objectTStack) {
    objectTStack.FirstElem = nullptr;
    objectTStack.LastElem = nullptr;
    delete objectTStack.CurrentElem;
}

int InputManager(bool value = false) {
    char c = '\0';
    char clear = '\0';
    int count = 0;
    bool flag = true;
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

void BeginWorkTStack(TObjectTStack& objectTStack) {
    std::cout << "Work with stack is available" << std::endl;
}

void ClearTStack(TObjectTStack& objectTStack, bool showMsg = true) {
    TStack* del = nullptr;

    if (objectTStack.FirstElem) {
        while (objectTStack.FirstElem) {
            del = objectTStack.FirstElem;
            objectTStack.FirstElem = objectTStack.FirstElem->Next;
            //clear nested struct del
            delete del;
        }
        showMsg ? std::cout << "Stack has been cleared" << std::endl : std::cout << "";
    } else {
        showMsg ? std::cout << "Stack is empty, can`t clear" << std::endl : std::cout << "";
    }
    ClearObjectTStack(objectTStack);
}

void StackIsEmpty(TObjectTStack& objectTStack) {
    if (objectTStack.FirstElem) {
        std::cout << "Stack is not empty" << std::endl;
    } else {
        std::cout << "Stack is empty" << std::endl;
    }
}

void ShowTStackElem(TObjectTStack& objectTStack) {
    if (objectTStack.FirstElem) {
        //print nested struct objectTStack.LastElem
    } else {
        std::cout << "Stack is empty, can`t show value" << std::endl;
        ClearObjectTStack(objectTStack);
    }
}

void DelTStackElem(TObjectTStack& objectTStack, bool showMsg = true) {
    TStack* tmp = nullptr;

    if (objectTStack.FirstElem) {
        //clear nested struct objectTStack.LastElem
        tmp = objectTStack.FirstElem;
        while (tmp->Next != objectTStack.LastElem) {
            tmp = tmp->Next;
        }
        delete objectTStack.LastElem;
        objectTStack.LastElem = tmp;
        objectTStack.LastElem->Next = nullptr;
        showMsg ? std::cout << "Element has been deleted" << std::endl : std::cout << "";
    } else {
        showMsg ? std::cout << "Stack is empty, can`t delete element" << std::endl : std::cout << "";
        ClearObjectTStack(objectTStack);
    }
}

void TakeTStackElem(TObjectTStack& objectTStack) {
    TStack *tmp = nullptr;

    if (objectTStack.FirstElem) {
        delete objectTStack.CurrentElem;
        objectTStack.CurrentElem = objectTStack.LastElem->objectTText;
        tmp = objectTStack.FirstElem;
        while (tmp->Next != objectTStack.LastElem) {
            tmp = tmp->Next;
        }
        delete objectTStack.LastElem;
        objectTStack.LastElem = tmp;
        objectTStack.LastElem->Next = nullptr;
        std::cout << "Element has been taken" << std::endl;
    } else {
        std::cout << "Stack is empty, can`t take element" << std::endl;
        ClearObjectTStack(objectTStack);
    }
}

void ChangeTStackElem(TObjectTStack& objectTStack) {
    if (objectTStack.FirstElem) {
        //Menu nested struct objectTStack.LastElem
    } else {
        std::cout << "Stack is empty, can`t change element" << std::endl;
        ClearObjectTStack(objectTStack);
    }
}

void AddTStackElem(TObjectTStack& objectTStack) {
    TObjectTText* newElem = new TObjectTText;
    //Menu nested struct
    if (objectTStack.FirstElem) {
        objectTStack.LastElem->Next = new TStack;
        objectTStack.LastElem = objectTStack.LastElem->Next;
        objectTStack.LastElem->objectTText = newElem;
    } else {
        objectTStack.FirstElem = new TStack;
        objectTStack.FirstElem->objectTText = newElem;
        objectTStack.LastElem = objectTStack.FirstElem;
    }
    std::cout << "Element has been added" << std::endl;
}

void PrintTStack(TObjectTStack& objectTStack) {
    TStack* tmp = nullptr;

    if (objectTStack.FirstElem) {
        tmp = objectTStack.FirstElem;
        for (int i = 0; tmp != nullptr; ++i, tmp = tmp->Next) {
            std::cout << i << ".Elem." << std::endl;
            //print nested struct tmp
        }
    } else {
        std::cout << "Stack is empty, can`t print stack" << std::endl;
        ClearObjectTStack(objectTStack);
    }
}

void EndWorkTStack(TObjectTStack& objectTStack) {
    std::cout << "Work with list is end" << std::endl;
}

int ChooseTStackOperation() {
    system("pause");
    system("cls");
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
    std::cout << "Input number operation: ";
    return InputManager();
}

void MenuStack() {
    TObjectTStack stack;
    bool loop = true;
    bool available = false;
    int operation;

    while (loop) {
        operation = ChooseTStackOperation();
        if (available) {
            switch (operation) {
                case 1: BeginWorkTStack(stack); break;
                case 2: ClearTStack(stack); break;
                case 3: StackIsEmpty(stack); break;
                case 4: ShowTStackElem(stack); break;
                case 5: DelTStackElem(stack); break;
                case 6: TakeTStackElem(stack); break;
                case 7: ChangeTStackElem(stack); break;
                case 8: AddTStackElem(stack); break;
                case 9: PrintTStack(stack); break;
                case 10: {
                    EndWorkTStack(stack);
                    loop = false;
                } break;
                default: std::cout << "Choose right operation" << std::endl;
            }
        } else if (operation == 1) {
            available = true;
            BeginWorkTStack(stack);
        } else if (operation == 10) {
            loop = false;
            ClearTStack(stack, false);
        } else {
            std::cout << "Choose right operation" << std::endl;
        }
    }
}