#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iomanip>

using namespace std;

// Book Structure
struct Book {
    string title;
    string author;
    string isbn;
    bool is_available;

    Book(string t, string a, string i)
        : title(t), author(a), isbn(i), is_available(true) {}
};

// Patron Structure
struct Patron {
    string name;
    string id;
    vector<Book> borrowed_books;

    Patron(string n, string i) : name(n), id(i) {}
};

// Library Class
class Library {
private:
    vector<Book> books;
    unordered_map<string, Patron> patrons;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book '" << book.title << "' added to the library." << endl;
    }

    void removeBook(const string& isbn) {
        auto it = remove_if(books.begin(), books.end(),
                            [&isbn](const Book& b) { return b.isbn == isbn; });
        if (it != books.end()) {
            books.erase(it, books.end());
            cout << "Book with ISBN '" << isbn << "' removed from the library." << endl;
        } else {
            cout << "Book with ISBN '" << isbn << "' not found." << endl;
        }
    }

    void searchBook(const string& title) {
        cout << "Searching for book titled: '" << title << "'" << endl;
        for (const auto& book : books) {
            if (book.title.find(title) != string::npos) {
                cout << "Found: " << book.title << " by " << book.author << " (ISBN: " << book.isbn << ")" 
                     << (book.is_available ? " - Available" : " - Not Available") << endl;
            }
        }
    }

    void addPatron(const string& name, const string& id) {
        patrons.emplace(id, Patron(name, id));
        cout << "Patron '" << name << "' added to the library." << endl;
    }

    void borrowBook(const string& isbn, const string& patron_id) {
        auto book_it = find_if(books.begin(), books.end(),
                                [&isbn](const Book& b) { return b.isbn == isbn && b.is_available; });

        auto patron_it = patrons.find(patron_id);
        
        if (book_it != books.end() && patron_it != patrons.end()) {
            patron_it->second.borrowed_books.push_back(*book_it);
            book_it->is_available = false;
            cout << "Book '" << book_it->title << "' borrowed by patron '" << patron_it->second.name << "'." << endl;
        } else {
            cout << "Book not available or Patron ID not found." << endl;
        }
    }

    void returnBook(const string& isbn, const string& patron_id) {
        auto patron_it = patrons.find(patron_id);
        if (patron_it != patrons.end()) {
            auto& borrowed_books = patron_it->second.borrowed_books;
            auto book_it = find_if(borrowed_books.begin(), borrowed_books.end(),
                                    [&isbn](const Book& b) { return b.isbn == isbn; });

            if (book_it != borrowed_books.end()) {
                borrowed_books.erase(book_it);
                auto library_book_it = find_if(books.begin(), books.end(),
                                                [&isbn](const Book& b) { return b.isbn == isbn; });
                library_book_it->is_available = true;
                cout << "Book '" << library_book_it->title << "' returned by patron '" << patron_it->second.name << "'." << endl;
            } else {
                cout << "This book was not borrowed by the patron." << endl;
            }
        } else {
            cout << "Patron ID not found." << endl;
        }
    }

    void listPatrons() {
        cout << "List of Patrons:" << endl;
        for (const auto& pair : patrons) {
            cout << "- " << pair.second.name << " (ID: " << pair.second.id << ")" << endl;
        }
    }

    void listBooks() {
        cout << "List of Books:" << endl;
        for (const auto& book : books) {
            cout << "- " << book.title << " by " << book.author 
                 << " (ISBN: " << book.isbn << ")" 
                 << (book.is_available ? " - Available" : " - Not Available") << endl;
        }
    }

    void showBorrowedBooks(const string& patron_id) {
        auto patron_it = patrons.find(patron_id);
        if (patron_it != patrons.end()) {
            cout << "Books borrowed by '" << patron_it->second.name << "':" << endl;
            for (const auto& book : patron_it->second.borrowed_books) {
                cout << "- " << book.title << " by " << book.author << " (ISBN: " << book.isbn << ")" << endl;
            }
        } else {
            cout << "Patron ID not found." << endl;
        }
    }
};

// Function to display the menu
void displayMenu() {
    cout << "\nLibrary Management System" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Remove Book" << endl;
    cout << "3. Search Book" << endl;
    cout << "4. Add Patron" << endl;
    cout << "5. Borrow Book" << endl;
    cout << "6. Return Book" << endl;
    cout << "7. List Patrons" << endl;
    cout << "8. List Books" << endl;
    cout << "9. Show Borrowed Books" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    Library library;
    int choice;

    // Initial Setup
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", "9780060935467"));
    library.addBook(Book("1984", "George Orwell", "9780451524935"));
    library.addPatron("John Doe", "P001");
    library.addPatron("Jane Smith", "P002");

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, author, isbn;
                cout << "Enter Book Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                getline(cin, isbn);
                library.addBook(Book(title, author, isbn));
                break;
            }
            case 2: {
                string isbn;
                cout << "Enter ISBN of Book to Remove: ";
                cin >> isbn;
                library.removeBook(isbn);
                break;
            }
            case 3: {
                string title;
                cout << "Enter Title to Search: ";
                cin.ignore();
                getline(cin, title);
                library.searchBook(title);
                break;
            }
            case 4: {
                string name, id;
                cout << "Enter Patron Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Patron ID: ";
                getline(cin, id);
                library.addPatron(name, id);
                break;
            }
            case 5: {
                string isbn, patron_id;
                cout << "Enter ISBN of Book to Borrow: ";
                cin >> isbn;
                cout << "Enter Patron ID: ";
                cin >> patron_id;
                library.borrowBook(isbn, patron_id);
                break;
            }
            case 6: {
                string isbn, patron_id;
                cout << "Enter ISBN of Book to Return: ";
                cin >> isbn;
                cout << "Enter Patron ID: ";
                cin >> patron_id;
                library.returnBook(isbn, patron_id);
                break;
            }
            case 7:
                library.listPatrons();
                break;
            case 8:
                library.listBooks();
                break;
            case 9: {
                string patron_id;
                cout << "Enter Patron ID to Show Borrowed Books: ";
                cin >> patron_id;
                library.showBorrowedBooks(patron_id);
                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}