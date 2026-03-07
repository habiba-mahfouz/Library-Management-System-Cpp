#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;

struct book
{
    string book_name = "" ;
    string book_author = "" ;
    double book_price = 0.0 ;
    int total_copies = 0 ;
    int borrowed_copies = 0 ;
    int available_copies = 0 ;
    int year = 0 ;
    bool available = false ;
    bool shelf_occupy = false ;
};
extern book library[100];

int interface ();
bool find_book(string name);
bool check_place_in_library();
void add_book();
void edit_book();
void borrow_book();
void restore_book();
void search_book();
void delete_book();
void display_books();
void display_total_copies();
void display_borrowed_copies();
void display_unique_copies();
void display_shelves();


#endif
