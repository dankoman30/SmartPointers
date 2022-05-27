#include <iostream>
#include <string>

using namespace std;

void intro() {
    cout << endl << "Hi, welcome to SmartPointers.\nThis is a tutorial application in which you can learn about the different types of Smart Pointers used in C++.\n\n\n";
}

void exit() {
    cout << "\nPRESS ENTER TO EXIT THE PROGRAM\n";
    system("pause>0");
}

void talkAbout(string type) {
    string quality = "Awesome";
    if (type == "auto_ptr") { quality = "Bad"; } // auto pointers suck
    cout << endl << endl << "You've chosen to learn about " << type << " smart pointers. \n" << quality << " choice!\n\n";
}

void learnAuto() {
    talkAbout("auto_ptr");
    cout << "auto_ptr smart pointer type should not be used.\n";
}

void learnShared() {
    talkAbout("Shared_ptr");
    cout << "Let's learn about them!\n";
}

void learnUnique() {
    talkAbout("Unique_ptr");
    cout << "Let's learn about them!\n";
}

void learnWeak() {
    talkAbout("Weak_ptr");
    cout << "Let's learn about them!\n";
}

int main() {
    intro();

    for (;;) { // main loop
        int choice;

        cout << "\n\nWhich type of smart pointer would you like to learn about?" << endl << endl << "1. Auto pointer (auto_ptr)\n2. Shared pointer (Shared_ptr)\n3. Unique pointer (Unique_ptr)\n4. Weak pointer (Weak_ptr)\n5. Exit\n\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: // auto_ptr
            learnAuto();
            continue;
        case 2: // Shared_ptr
            learnShared();
            continue;
        case 3: // Unique_ptr
            learnUnique();
            continue;
        case 4: // Weak_ptr
            learnWeak();
            continue;
        case 5: // EXIT
            cout << "BYE!\n";
            break;
        }
        break; // exit loop if we've reached the end (other possibilities should have continued before here)
    }

    exit();
}