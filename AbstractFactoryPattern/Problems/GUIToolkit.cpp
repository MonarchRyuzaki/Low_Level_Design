/*
Problem Statement:

Design a cross-platform GUI Toolkit using the Abstract Factory pattern to support Windows and MacOS. 
The toolkit should allow for the creation of various UI components such as Buttons, Checkboxes, and TextFields. 
Each of these components should have different implementations for Windows and MacOS platforms. 

Components:
1. Button:
   - Methods:
     - render(): Renders the button on the screen.
     - onClick(): Defines the behavior when the button is clicked.

2. Checkbox:
   - Methods:
     - render(): Renders the checkbox on the screen.
     - isChecked(): Returns the current state (checked/unchecked) of the checkbox.
     - toggle(): Toggles the checkbox state between checked and unchecked.

3. TextField: // This to be done in future
   - Methods:
     - render(): Renders the text field on the screen.
     - getText(): Returns the current text in the text field.
     - setText(string text): Sets the text in the text field to the specified value.

Abstract Factory:
- GUIFactory: An abstract class that defines methods to create instances of the above components.
   - Methods:
     - createButton(): Returns a Button object.
     - createCheckbox(): Returns a Checkbox object.
     - createTextField(): Returns a TextField object.

Concrete Factories:
1. WindowsGUIFactory: Implements the GUIFactory to create Windows-specific components.
   - Methods:
     - createButton(): Returns a WindowsButton object.
     - createCheckbox(): Returns a WindowsCheckbox object.
     - createTextField(): Returns a WindowsTextField object.

2. MacOSGUIFactory: Implements the GUIFactory to create MacOS-specific components.
   - Methods:
     - createButton(): Returns a MacOSButton object.
     - createCheckbox(): Returns a MacOSCheckbox object.
     - createTextField(): Returns a MacOSTextField object.

Implement the Abstract Factory pattern by creating concrete classes for each platform-specific component (e.g., WindowsButton, MacOSButton) that override the methods defined in their respective interfaces.

The client code should be able to switch between different platforms (Windows and MacOS) by selecting the appropriate factory, allowing for consistent creation of platform-specific components without modifying the client code.
*/
#include <bits/stdc++.h>
using namespace std;

class Button{
public:
    virtual ~Button() {};
    virtual void render() const = 0;
    virtual void onClick() const = 0;
};
class WindowsButton : public Button{
public:
    void render() const  {
        cout << "Rendering Windows Button on screen" << endl;
    }
    void onClick() const {
        cout << "Clicking the Windows Button" << endl;
    }
};
class MacOSButton : public Button{
public:
    void render() const  {
        cout << "Rendering MacOS Button on screen" << endl;
    }
    void onClick() const {
        cout << "Clicking the MacOS Button" << endl;
    }
};

class Checkbox{
public:
    virtual ~Checkbox() {};
    virtual void render() const = 0;
    virtual void isChecked() = 0;
    virtual void toggle() = 0;
};
class WindowsCheckbox : public Checkbox {
public:
    void render() const {
        cout << "Rendering Windows Checkbox on screen" << endl;
    }
    void isChecked() {
        cout << "Checking if Windows Checkbox is Checked" << endl;
    }
    void toggle() {
        cout << "Toggling Windows Checkbox" << endl;
    }
};
class MacOSCheckbox : public Checkbox {
public:
    void render() const {
        cout << "Rendering MacOS Checkbox on screen" << endl;
    }
    void isChecked() {
        cout << "Checking if MacOS Checkbox is Checked" << endl;
    }
    void toggle() {
        cout << "Toggling MacOS Checkbox" << endl;
    }
};

class GUIFactory{
public:
    virtual Button* createButton() const = 0;
    virtual Checkbox* createCheckbox() const = 0;
};
class WindowsFactory : public GUIFactory{
public:
    Button* createButton() {
        cout << "Creating Windows Button" << endl;
        return new WindowsButton();
    }
    Checkbox* createCheckbox() {
        cout << "Creating Windows Checkbox" << endl;
        return new WindowsCheckbox();
    }
};
class MacOSFactory : public GUIFactory{
public:
    Button* createButton() const {
        cout << "Creating MacOS Button" << endl;
        return new MacOSButton();
    }
    Checkbox* createCheckbox() const {
        cout << "Creating MacOS Checkbox" << endl;
        return new MacOSCheckbox();
    }
};

int main() {
    // Select the appropriate factory based on the platform
    GUIFactory* factory;
    #ifdef _WIN32
        factory = new WindowsFactory();
    #else
        factory = new MacOSFactory();
    #endif

    // Create UI components using the factory
    Button* button = factory->createButton();
    Checkbox* checkbox = factory->createCheckbox();

    // Use the created components
    button->render();
    button->onClick();

    checkbox->render();
    checkbox->isChecked();
    checkbox->toggle();

    // Clean up
    delete button;
    delete checkbox;
    delete factory;

    return 0;
}