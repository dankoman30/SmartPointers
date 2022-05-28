#include <iostream>
#include <string>
#include <memory>

using namespace std;

void intro() {
    cout << endl << "Hi, welcome to SmartPointers.\nThis is a tutorial application in which you can learn about the different types of Smart Pointers used in C++.\n\n\n";
}

void exit() {
    cout << "\nPRESS ENTER TO EXIT THE PROGRAM\n";
    system("pause>0");
}

class Talker { // create talker class, responsible for communicating with the user
    public: // these methods are public
        void talkAbout(string type) { // pass type to function to save some extra typing
            string quality = "Awesome";
            if (type == "auto_ptr") { quality = "Bad"; } // auto pointers suck
            cout << endl << endl << "You've chosen to learn about " << type << " smart pointers. \n" << quality << " choice!\n\n";
        }

        void learnAuto() {
            talkAbout("auto_ptr");
            cout << "auto_ptr smart pointer type should not be used. Its disadvantages outweigh its advantages, and there are more suitable options.\n";
            cout << "auto_ptr is a smart pointer that assumes or transfers ownership.  Althoguh it auto-initiates to null and auto-deletes when out of\n";
            cout << "scope, the ownership is transferred when passed as a parameter. It does not work with containers, and does not work with anything\n";
            cout << "that requires 'new.' It should probably be avoided for these reasons.\n\n";
        }

        void learnShared() {
            talkAbout("Shared_ptr");
            cout << "Let's learn about them!\n";
            cout << "USE THIS SMART POINTER TYPE WHEN SHARED OWNERSHIP IS NECESSARY!\n";
            cout << "Shared_ptr smart pointer type is a smart pointer that shares ownership with any other smart pointer types. Auto-deletion takes place\n";
            cout << "once out of scope for all smart pointers that have some ownership. Initiation to null is also automatic. A disadvantage of this smart\n";
            cout << "pointer type is that in order to delete, all smart pointers must be out of scope.\n\n";
        }

        void learnUnique() {
            talkAbout("Unique_ptr");
            cout << "Let's learn about them!\n";
            cout << "USE THIS SMART POINTER TYPE WHEN OWNERSHIP IS NOT SHARED!\n";
            cout << "Unique_ptr smart pointer type is a smart pointer that has EXCLUSIVE ownership. It auto-deletes once out of scope, and auto-initiates\n";
            cout << "to null. Additionally, ownership can be transferred to another Unique_ptr. The only disadvantage of this smart pointer type is that\n";
            cout << "inherently, ownership cannot be shared (hence its unique name).\n\n";
            cout << "In fact, A UNIQUE POINTER WAS USED AND INSTANTIATED IN THIS VERY PROGRAM! Would you like to know the memory address of the pointer used?\n";
            cout << "Here it is:\n";
        }

        void learnWeak() {
            talkAbout("Weak_ptr");
            cout << "Let's learn about them!\n";
            cout << "USE THIS SMART POINTER TYPE WHEN A POINTER IS NEEDED, BUT YOU DON'T WANT IT IN THE REFERENCE LIST FOR AUTO-DELETION DUE TO\n";
            cout << "OUT OF SCOPE!\n";
            cout << "Weak_ptr smart pointer type is a smart pointer that is not included in the reference list that determines if out-of-scope. Its advantages\n";
            cout << "include auto-initiation to null and its absence from the auto-deletion decision. Additionally, weak_ptr smart pointer type NEVER has ownership,\n";
            cout << "which could be considered an advantage or a disadvantage, depending on use case. This pointer type cannot ever assume any ownership.\n\n";
        }
};

unique_ptr<Talker> demoUnique(unique_ptr<Talker> pTalkerTemp) {
    pTalkerTemp->learnUnique(); // call learnunique function (this time from the new temp pointer created
    cout << endl << pTalkerTemp.get() << endl << endl << "Pretty cool, huh?\n\n"; // output the memory address of the unique pointer
    return move(pTalkerTemp); // return the pointer back to the caller
}

int main() {
    intro();
    unique_ptr<Talker> pTalker(new Talker); // instantiate Talker class as new pointer

    for (;;) { // main loop
        int choice;

        cout << "\n\nWhich type of smart pointer would you like to learn about?" << endl << endl << "1. Auto pointer (auto_ptr)\n2. Shared pointer (Shared_ptr)\n3. Unique pointer (Unique_ptr)\n4. Weak pointer (Weak_ptr)\n5. Exit\n\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: // auto_ptr
            pTalker->learnAuto(); // call learnauto function
            continue;
        case 2: // Shared_ptr
            pTalker->learnShared(); // call learnshared function
            continue;
        case 3: // Unique_ptr
            pTalker = demoUnique(move(pTalker)); // basically sets pTalker equal to itself, because demoUnique is type unique_ptr<Talker>,
                                                 // and coded to return ownership of the passed pointer parameter. In essence, we're transferring
                                                 // ownership to the parameter, then receiving it back.
            continue;
        case 4: // Weak_ptr
            pTalker->learnWeak(); // call learnunique function
            continue;
        case 5: // EXIT
            cout << "BYE!\n";
            break; // break the switch
        }
        break; // exit loop if we've reached the end (other possibilities should have continued before here)
    }

    exit();
}