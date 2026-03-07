#include "header.h"

book library[100] ;
int book_counter = 0, finder = 0 ;
string name, author ;
int number, year, copies ;
double price ;

// what appear to user
int interface ()
{
    cout << "..........................................................................\n" ;
    cout << "......<<<.....<<<.....<<< WELCOME TO OUR LIBRARY >>>.....>>>.....>>>......\n" ;
    cout << "..........................................................................\n" ;
    cout << ".. 1) Add book                                                          ..\n" ;
    cout << ".. 2) Edit book                                                         ..\n" ;
    cout << ".. 3) Search book                                                       ..\n" ;
    cout << ".. 4) Delete book                                                       ..\n" ;
    cout << ".. 5) Borrow book                                                       ..\n" ;
    cout << ".. 6) Restore book                                                      ..\n" ;
    cout << ".. 7) Display books                                                     ..\n" ;
    cout << ".. 8) Total books counter                                               ..\n" ;
    cout << ".. 9) Borrowed books counter                                            ..\n" ;
    cout << ".. 10) Unique books counter                                             ..\n" ;
    cout << ".. 11) Shelves counter                                                  ..\n" ;
    cout << ".. 12) Exit from the library                                            ..\n" ;
    cout << "..........................................................................\n" ;
    cout << "   Enter command number : ";
    cin >> number;
    return number;
}

// check if book exist or not
bool find_book(string name)
{
    for (int i = 0; i < book_counter ; i++)
    {
        if (library[i].book_name == name && library[i].available && library[i].shelf_occupy)
        {
            finder = i ;
            return true ;
        }
    }
    return false ;
}

// check if there is an empty place in the library or not
bool check_place_in_library()
{
    if (book_counter == 100)
    {
        cout << "Sorry, the library is full. You can't add more books.\n" ;
        return false ;
    }
    else
    {
        return true ;
    }
}

// add a book to the library
void add_book()
{
    cout << "... Enter the book name: " ;
    cin.ignore() ;
    getline(cin, name) ;
    cout << "... Enter the book author name: " ;
    getline(cin, author) ;
    cout << "... Enter the book price: LE " ;
    cin >> price ;
    cout << "... Enter the number of copies: " ;
    cin >> copies ;
    cout << "... Enter the publication year: " ;
    cin >> year ;

    if (check_place_in_library() && !(find_book(name)))
    {
        library[book_counter].book_name = name ;
        library[book_counter].book_author = author ;
        library[book_counter].book_price = price ;
        library[book_counter].total_copies = copies ;
        library[book_counter].borrowed_copies = 0 ;
        library[book_counter].available_copies = copies ;
        library[book_counter].year = year ;
        library[book_counter].available = true ;
        library[book_counter].shelf_occupy = true ;

        cout << library[book_counter].book_name << " book is entered successfully at shelf " << book_counter + 1 << endl ;
        cout << "and now the existing total copies is " << library[book_counter].total_copies << endl ;
        book_counter++ ;
    }
    else if (find_book(name))
    {
        cout << "Sorry, the book is already existing in the library.\n" ;
        cout << "If you want to edit its data please choose \"edit\".\n" ;
    }
}

// edit a book in the library
void edit_book()
{
    cout << "Please enter the name of book that you want to edit: " ;
    cin.ignore ();
    getline(cin, name) ;
    if (find_book(name))
    {
        cout << "..... The Book Information .....\n" ;
        cout << "1) Book name: " << library[finder].book_name << endl ;
        cout << "2) Author name: " << library[finder].book_author << endl ;
        cout << "3) Book price: LE " << library[finder].book_price << endl ;
        cout << "4) Book total copies: " << library[finder].total_copies << endl ;
        cout << "5) Book borrowed copies: " << library[finder].borrowed_copies << endl ;
        cout << "6) Book available copies: " << library[finder].available_copies << endl ;
        cout << "7) Book publication year: " << library[finder].year << endl ;
        cout << "8) Book at shelf: " << finder + 1 << endl ;
        cout << "Enter the command number (1:7) of what you want to edit: " ;
        cin >> number ;
        switch (number)
        {
        case 1:
            cout << "The current book name: " << library[finder].book_name << endl ;
            cout << "Enter the New book name: " ;
            cin.ignore ();
            getline(cin, name) ;
            library[finder].book_name = name ;
            cout << "The book name is changed successfully to be \"" << library[finder].book_name << "\".\n" ;
            break ;
        case 2:
            cout << "The current author name: " << library[finder].book_author << endl ;
            cout << "Enter the New author name: " ;
            cin.ignore ();
            getline(cin, author) ;
            library[finder].book_author = author ;
            cout << "The author name is changed successfully to be \"" << library[finder].book_author << "\".\n" ;
            break ;
        case 3:
            cout << "The current book price: LE " << library[finder].book_price << endl ;
            cout << "Enter the New book price: " ;
            cin >> price ;
            library[finder].book_price = price ;
            cout << "The book price is changed successfully to be LE " << library[finder].book_price << ".\n" ;
            break ;
        case 4:
            cout << "The current book total copies: " << library[finder].total_copies << endl ;
            cout << "Enter the New book total copies (the number will add to the current total copies): " ;
            cin >> copies ;
            library[finder].total_copies += copies ;
            cout << "The book total copies is changed successfully to be \"" << library[finder].total_copies << " copy\".\n" ;
            break ;
        case 5:
            cout << "The current book borrowed copies: " << library[finder].borrowed_copies << endl ;
            cout << "Enter the New book borrowed copies (the number will add to the current borrowed copies): " ;
            cin >> copies ;
            library[finder].borrowed_copies += copies ;
            cout << "The book borrowed copies is changed successfully to be \"" << library[finder].borrowed_copies << " copy\".\n" ;
            break ;
        case 6:
            cout << "The current book available copies: " << library[finder].available_copies << endl ;
            cout << "Enter the New book available copies (the number will add to the current available copies): " ;
            cin >> copies ;
            library[finder].available_copies += copies ;
            cout << "The book available copies is changed successfully to be \"" << library[finder].available_copies << " copy\".\n" ;
            break ;
        case 7:
            cout << "The current book publication year: " << library[finder].year << endl ;
            cout << "Enter the New book publication year: " ;
            cin >> year ;
            library[finder].year = year ;
            cout << "The book publication year is changed successfully to be \"" << library[finder].year << "\".\n" ;
            break;
        case 8:
            cout << "Sorry, you can't change the shelf!!!\n" ;
            break ;
        default:
            cout << "Please enter a valid number (1:7).\n" ;
            break ;
        }
    }
    else
    {
        cout << "Sorry, the book isn't existing in the library.\n" ;
    }
}

// borrow a book from the library
void borrow_book()
{
    cout << "Enter the book name you want to borrow: " ;
    cin.ignore ();
    getline(cin, name) ;
    if (find_book(name))
    {
        cout << "How many copies you want to borrow: " ;
        cin >> number ;
        if (number <= library[finder].available_copies && number > 0)
        {
            library[finder].available_copies -= number ;
            library[finder].borrowed_copies += number ;
            cout << "The book \"" << library[finder].book_name << "\"\nTotal copies: " << library[finder].total_copies << endl ;
            cout << "Available copies: " << library[finder].available_copies << "\nBorrowed copies: " << library[finder].borrowed_copies << endl ;
        }
        else
        {
            cout << "Invalid number of copies to borrow.\n"  ;
        }
    }
    else
    {
        cout << "Sorry, the book isn't existing in the library." << endl ;
    }
}

// restore a book to the library
void restore_book()
{
    cout << "Enter the book name you want to restore: " ;
    cin.ignore ();
    getline(cin, name) ;
    if (find_book(name))
    {
        cout << "How many copies you want to restore: " ;
        cin >> number ;
        if (number <= library[finder].borrowed_copies && number > 0)
        {
            library[finder].available_copies += number ;
            library[finder].borrowed_copies -= number ;
            cout << "The book \"" << library[finder].book_name << "\"\nTotal copies: " << library[finder].total_copies << endl ;
            cout << "Available copies: " << library[finder].available_copies << "\nBorrowed copies: " << library[finder].borrowed_copies << endl ;
        }
        else
        {
            cout << "Invalid number of copies to restore.\n" ;
        }
    }
    else
    {
        cout << "Sorry, the book isn't existing in the library." << endl ;
    }
}

// search on a book in the library
void search_book()
{
    cout << "Enter the book name you search on: " ;
    cin.ignore ();
    getline(cin, name) ;
    if (find_book(name))
    {
        cout << "..... The Book Information .....\n" ;
        cout << " Book name: " << library[finder].book_name << endl ;
        cout << " Author name: " << library[finder].book_author << endl ;
        cout << " Book price: LE " << library[finder].book_price << endl ;
        cout << " Book total copies: " << library[finder].total_copies << endl ;
        cout << " Book borrowed copies: " << library[finder].borrowed_copies << endl ;
        cout << " Book available copies: " << library[finder].available_copies << endl ;
        cout << " Book publication year: " << library[finder].year << endl ;
        cout << " Book at shelf: " << finder + 1 << endl ;
    }
    else
    {
        cout << "Sorry, the book isn't existing in the library.\n" ;
    }
}

// delete a book from the library
void delete_book()
{
    cout << "Enter the book name you want to delete: " ;
    cin.ignore ();
    getline(cin, name) ;
    if (find_book(name))
    {
        cout << "..... The Book Information .....\n" ;
        cout << " Book name: " << library[finder].book_name << endl ;
        cout << " Author name: " << library[finder].book_author << endl ;
        cout << " Book price: LE " << library[finder].book_price << endl ;
        cout << " Book total copies: " << library[finder].total_copies << endl ;
        cout << " Book borrowed copies: " << library[finder].borrowed_copies << endl ;
        cout << " Book available copies: " << library[finder].available_copies << endl ;
        cout << " Book publication year: " << library[finder].year << endl ;
        cout << " Book at shelf: " << finder + 1 << endl ;
        cout << " Are you really want to delete this book?\n 1) Yes\t 2) No\n Enter the command: " ;
        cin >> number ;
        switch (number)
        {
        case 1:                                                // 5 books  book counter 4
            for (int i = finder; i < book_counter - 1; i++)  // index 2 ... i 2 ... i stop 3
            {
                library[i] = library[i + 1];   // shift the books up
            }
            // Clear the last book slot after shifting
            library[book_counter - 1].book_name.clear();
            library[book_counter - 1].book_author.clear();
            library[book_counter - 1].book_price = 0.0;
            library[book_counter - 1].total_copies = 0;
            library[book_counter - 1].borrowed_copies = 0;
            library[book_counter - 1].available_copies = 0;
            library[book_counter - 1].year = 0;
            library[book_counter - 1].shelf_occupy = false;
            library[book_counter - 1].available = false;
            book_counter--;
            cout << "The book information is deleted.\n" ;
            break ;
        case 2:
            cout << "There is no changes happen!!\n" ;
            break ;
        default:
            cout << "Please enter a valid number.\n" ;
            break ;
        }
    }
    else
    {
        cout << "Sorry, the book isn't existing in the library." << endl ;
    }
}

// display books
void display_books()
{
    for (int i = 0; i < book_counter ; i++)
    {
        if (library[i].shelf_occupy && library[i].available)
        {
            cout << "The book at shelf "<<i + 1<<" :\n" ;
            cout << "..Book name: " << library[i].book_name << endl ;
            cout << "..Author name: " << library[i].book_author << endl ;
            cout << "..Book price: LE " << library[i].book_price << endl ;
            cout << "..Book total copies: " << library[i].total_copies << endl ;
            cout << "..Book borrowed copies: " << library[i].borrowed_copies << endl ;
            cout << "..Book available copies: " << library[i].available_copies << endl ;
            cout << "..Book publication year: " << library[i].year << endl ;
            cout << "......................................................................\n" ;
        }
    }
}

// display total books counter
void display_total_copies()
{
    for (int i = 0; i < book_counter ; i++)
    {

        cout << "The "<<library[i].book_name <<" book at shelf "<<i + 1<<" :\n" ;
        cout << "..Book total copies: " << library[i].total_copies << endl ;
        cout << "......................................................................\n" ;
    }
}

// display borrowed books counter
void display_borrowed_copies()
{
    for (int i = 0; i < book_counter ; i++)
    {
        cout << "The "<<library[i].book_name <<" book at shelf "<<i + 1<<" :\n" ;
        cout << "..Book borrowed copies: " << library[i].borrowed_copies << endl ;
        cout << "..Book available copies: " << library[i].available_copies << endl ;
        cout << "......................................................................\n" ;
    }
}

// display unique books counter
void display_unique_copies()
{
    cout << "Total unique books in the library: " << book_counter << endl ;
}

// display shelves counter
void display_shelves()
{
    int shelf_counter =0 ;
    for (int i = 0; i < book_counter ; i++)
    {
        if (library[i].shelf_occupy)
        {
            shelf_counter++;
        }
    }
    cout << "..... Shelves information.....\n" ;
    cout << ".. Empty shelves: " << 100-shelf_counter << "\n.. Occupied shelves: " << shelf_counter << endl;
}
