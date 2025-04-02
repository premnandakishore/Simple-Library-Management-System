#include <iostream> 
#include <string> 
 
using namespace std; 
 
struct Book { 
    int id; 
    string title; 
    string author; 
    bool isIssued; 
    Book* next; 
 
   
    Book(int id, string title, string author) { 
        this->id = id; 
        this->title = title; 
        this->author = author; 
        this->isIssued = false; 
        this->next = 0; 
    } 
}; 
 
class Library { 
private: 
    Book* head; 
 
public: 
    Library() : head(0) {} 
 
    void addBook(int id, string title, string author) { 
        Book* newBook = new Book(id, title, author); 
        if (head == 0) { 
            head = newBook; 
        } else { 
            Book* temp = head; 
            while (temp->next != 0) { 
                temp = temp->next; 
            } 
            temp->next = newBook; 
        } 
        cout << "Book added successfully!" << endl; 
    } 
 
    Book* searchBook(int id) { 
        Book* temp = head; 
        while (temp != 0) { 
            if (temp->id == id) { 
                return temp; 
            } 
            temp = temp->next; 
        } 
        return 0; 
    } 
 
    void issueBook(int id, string studentName) { 
        Book* book = searchBook(id); 
        if (book != 0) { 
            if (!book->isIssued) { 
                book->isIssued = true; 
                cout << "Book issued to " << studentName << endl; 
            } else { 
                cout << "Book is already issued!" << endl; 
            } 
        } else { 
            cout << "Book not found!" << endl; 
        } 
    } 
 
    void returnBook(int id) { 
        Book* book = searchBook(id); 
        if (book != 0) { 
            if (book->isIssued) { 
                book->isIssued = false; 
                cout << "Book returned successfully!" << endl; 
            } else { 
                cout << "Book was not issued!" << endl; 
            } 
        } else { 
            cout << "Book not found!" << endl; 
        } 
    } 
 
    void listBooks() { 
        if (head == 0) { 
            cout << "No books in the library." << endl; 
        } else { 
            Book* temp = head; 
            while (temp != 0) { 
                cout << "ID: " << temp->id << ", Title: " << temp->title << ", Author: " << temp->author 
                     << ", Status: " << (temp->isIssued ? "Issued" : "Available") << endl; 
                temp = temp->next; 
            } 
        } 
    } 
 
    void deleteBook(int id) { 
        if (head == 0) { 
            cout << "No books in the library." << endl; 
            return; 
        } 
 
        if (head->id == id) { 
            Book* temp = head; 
            head = head->next; 
            delete temp; 
            cout << "Book deleted successfully!" << endl; 
            return; 
        } 
 
        Book* temp = head; 
        while (temp->next != 0 && temp->next->id != id) { 
            temp = temp->next; 
        } 
 
        if (temp->next != 0 && temp->next->id == id) { 
            Book* toDelete = temp->next; 
            temp->next = temp->next->next; 
            delete toDelete; 
            cout << "Book deleted successfully!" << endl; 
        } else { 
            cout << "Book not found!" << endl; 
        } 
    } 
 
    ~Library() { 
        Book* temp = head; 
        while (temp != 0) { 
            Book* toDelete = temp; 
            temp = temp->next; 
            delete toDelete; 
        } 
    } 
}; 
 
int main() { 
    Library lib; 
    int choice, id; 
    string title, author, studentName; 
 
    while (true) { 
        cout << "\nLibrary Management System\n"; 
        cout << "1. Add New Book\n"; 
        cout << "2. Search for a Book\n"; 
        cout << "3. Issue a Book\n"; 
        cout << "4. Return a Book\n"; 
        cout << "5. List All Books\n"; 
        cout << "6. Delete a Book\n"; 
        cout << "7. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                cout << "Enter Book ID: "; 
                cin >> id; 
                cin.ignore(); 
                cout << "Enter Book Title: "; 
                getline(cin, title); 
                cout << "Enter Book Author: "; 
                getline(cin, author); 
                lib.addBook(id, title, author); 
                break; 
            case 2: 
                cout << "Enter Book ID to search: "; 
                cin >> id; 
                { 
                    Book* book = lib.searchBook(id); 
                    if (book != 0) { 
                        cout << "Book found! ID: " << book->id << ", Title: " << book->title 
                             << ", Author: " << book->author << ", Status: " 
                             << (book->isIssued ? "Issued" : "Available") << endl; 
                    } else { 
                        cout << "Book not found!" << endl; 
                    } 
                } 
                break; 
            case 3: 
                cout << "Enter Book ID to issue: "; 
                cin >> id; 
                cin.ignore(); 
                cout << "Enter Student Name: "; 
                getline(cin, studentName); 
                lib.issueBook(id, studentName); 
                break; 
            case 4: 
                cout << "Enter Book ID to return: "; 
                cin >> id; 
                lib.returnBook(id); 
                break; 
            case 5: 
                lib.listBooks(); 
                break; 
            case 6: 
                cout << "Enter Book ID to delete: "; 
                cin >> id; 
                lib.deleteBook(id); 
                break; 
            case 7: 
                return 0; 
            default: 
                cout << "Invalid choice!" << endl; 
        } 
    } 
 
    return 0; 
}
