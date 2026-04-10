#include "header.h"

int main()
{
    bool running = true;
    while (running)
    {
        int result = interface();
        switch (result)
        {
        case 1:
            add_book();
            break;
        case 2:
            edit_book();
            break;
        case 3:
            search_book();
            break;
        case 4:
            delete_book();
            break;
        case 5:
            borrow_book();
            break;
        case 6:
            restore_book();
            break;
        case 7:
            display_books();
            break;
        case 8:
            display_total_copies();
            break;
        case 9:
            display_borrowed_copies();
            break;
        case 10:
            display_unique_copies();
            break;
        case 11:
            display_shelves();
            break;
        case 12:
            cout << "You are out of the system!!" << endl;
            running = false;
            break;
        default:
            cout << "Please enter a valid number (1-12)." << endl;
            break;
        }
    }
    return 0;
}



