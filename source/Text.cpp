#include "Text.h"

#include <iostream>


//---------------------------------------------//
void ClearObjectTText(TObjectTText& objectTText) {
    objectTText.FirsElem = nullptr;
    objectTText.LastElem = nullptr;
    objectTText.Worked = nullptr;
    delete objectTText.CurrentElem;
}
//---------------------------------------------//
void BeginWorkTText(TObjectTText& objectTText) {
    std::cout << "Work with text is available" << std::endl;
}

void ClearTText(TObjectTText& objectTText, bool showMsg = true) {
    TText* del = nullptr;

    if (objectTText.FirsElem) {
        while (objectTText.FirsElem) {
            del = objectTText.FirsElem;
            objectTText.FirsElem = objectTText.FirsElem->Next;
            delete del;
        }
        showMsg ? std::cout << "Text has been cleared" << std::endl : std::cout << "";
    } else {
        showMsg ? std::cout << "Text is empty, can`t clear" : std::cout << "";
    }
    ClearObjectTText(objectTText);
}

void TextIsEmpty(TObjectTText& objectTText) {
    if (objectTText.FirsElem) {
        std::cout << "Text is not empty" << std::endl;
    } else {
        std::cout << "Text is empty" << std::endl;
        ClearTText(objectTText);
    }
}

void SetOnFirstElemTText(TObjectTText& objectTText) {
    if (objectTText.FirsElem) {
        objectTText.Worked = objectTText.FirsElem;
        std::cout << "Work pointer on first element" << std::endl;
    } else {
        std::cout << "Text is empty, can`t set work pointer on first element" << std::endl;
        ClearObjectTText(objectTText);
    }
}

void SetOnLastElemTText(TObjectTText& objectTText) {
    if (objectTText.FirsElem) {
        objectTText.Worked = objectTText.LastElem;
        std::cout << "Work pointer on last element" << std::endl;
    } else {
        std::cout << "Text is empty, can`t set work pointer on last element" << std::endl;
        ClearObjectTText(objectTText);
    }
}

void OnFirstElemTText(TObjectTText& objectTText) {
    if (objectTText.FirsElem) {
        if (objectTText.FirsElem == objectTText.Worked) {
            std::cout << "Work pointer on fist element" << std::endl;
        } else {
            std::cout << "Work pointer not on first element" << std::endl;
        }
    } else {
        std::cout << "Text is empty, can`t check position work pointer" << std::endl;
        ClearTText(objectTText);
    }
}

void OnLastElemTText(TObjectTText& objectTText) {
    if (objectTText.FirsElem) {
        if (objectTText.LastElem == objectTText.Worked) {
            std::cout << "Work pointer on last element" << std::endl;
        } else {
            std::cout << "Work pointer not on last element" << std::endl;
        }
    } else {
        std::cout << "Text is empty, can`t check position work pointer" << std::endl;
        ClearTText(objectTText);
    }
}

void MoveForwardTText(TObjectTText& objectTText) {
    if (objectTText.FirsElem) {
        if (!objectTText.Worked) {
            std::cout << "Work pointer invalid, can`t move forward" << std::endl;
        } else if (!objectTText.Worked->Next) {
            std::cout << "Work pointer on last element, can`t move forward" << std::endl;
        } else {
            objectTText.Worked = objectTText.Worked->Next;
            std::cout << "Work pointer moved on next element" << std::endl;
        }
    } else {
        std::cout << "Text is empty, can`t move work pointer" << std::endl;
        ClearTText(objectTText);
    }
}

void MoveBackTText(TObjectTText& objectTText) {
    if (objectTText.FirsElem) {
        if (!objectTText.Worked) {
            std::cout << "Work pointer invalid, can`t move back" << std::endl;
        } else if (!objectTText.Worked->Prev) {
            std::cout << "Work pointer on last element, can`t move back" << std::endl;
        } else {
            objectTText.Worked = objectTText.Worked->Prev;
            std::cout << "Work pointer moved on previous element" << std::endl;
        }
    } else {
        std::cout << "Text is empty, can`t move work pointer" << std::endl;
        ClearTText(objectTText);
    }
}

void ShowElemBeforeTText(TObjectTText& objectTText) {
    if (objectTText.FirsElem) {

    } else {
        std::cout << "Text is empty, can`t show element" << std::endl;
        ClearTText(objectTText);
    }
}