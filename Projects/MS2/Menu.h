#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>

namespace seneca {
    const int MAX_MENU_ITEMS = 20;

    class Menu;

    class MenuItem {
        char* m_menuItem{};
        MenuItem();
        MenuItem(const char* item);
        MenuItem(const MenuItem& other) = delete; // Delete copy constructor
        MenuItem& operator=(const MenuItem& other) = delete; // Delete copy assignment operator
        ~MenuItem();
        operator bool() const;
        operator const char* () const; // Convert to const char*
        void display(std::ostream& os = std::cout) const;
        friend class Menu; // Make Menu a friend class
    };

    class Menu {
        char* m_menuTitle{};
        MenuItem* m_items[MAX_MENU_ITEMS]{};
        int m_numOfMenu = 0;
    public:
        Menu();
        Menu(const char* title);
        Menu(const Menu& other) = delete; // Delete copy constructor
        Menu& operator=(const Menu& other) = delete; // Delete copy assignment operator
        ~Menu();
        int run();
        void display();
        char* operator[](int i) const;
        operator bool() const;
        int operator~();
        std::ostream& write(std::ostream& os = std::cout) const;
        Menu& operator<<(const char* menuContent);
        operator unsigned int() const;
    };

    std::ostream& operator<<(std::ostream& os, const Menu& m);
}

#endif // SENECA_MENU_H
