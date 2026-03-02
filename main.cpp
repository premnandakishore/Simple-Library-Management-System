#include <iostream>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
    Book* next;

    Book(int id, string title, string author)
        : id(id), title(title), author(author), isIssued(false), next(nullptr) {}
};

class Library {
private:
    Book* head;
    int totalBooks;

public:
    Library() : head(nullptr), totalBooks(0) {}

    // Check if Book ID already exists
    bool isDuplicate(int id) {
        Book* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void addBook(int id, string title, string author) {
        if (isDuplicate(id)) {
            cout << "Book with this ID already exists!\n";
            return;
        }

        Book* newBook = new Book(id, title, author);

        if (head == nullptr) {
            head = newBook;
        } else {
            Book* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newBook;
        }

        totalBooks++;
        cout << "Book added successfully!\n";
    }

    Book* searchBook(int id) {
        Book* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void issueBook(int id, string studentName) {
        Book* book = searchBook(id);

        if (book == nullptr) {
            cout << "Book not found!\n";
            return;
        }

        if (book->isIssued) {
            cout << "Book is already issued!\n";
        } else {
            book->isIssued = true;
            cout << "Book issued to " << studentName << endl;
        }
    }

    void returnBook(int id) {
        Book* book = searchBook(id);

        if (book == nullptr) {
            cout << "Book not found!\n";
            return;
        }

        if (!book->isIssued) {
            cout << "Book was not issued!\n";
        } else {
            book->isIssued = false;
            cout << "Book returned successfully!\n";
        }
    }

    void listBooks() {
        if (head == nullptr) {
            cout << "No books in the library.\n";
            return;
        }

        Book* temp = head;

        cout << "\n--- Library Book List ---\n";

        while (temp != nullptr) {
            cout << "ID: " << temp->id
                 << " | Title: " << temp->title
                 << " | Author: " << temp->author
                 << " | Status: "
                 << (temp->isIssued ? "Issued" : "Available")
                 << endl;

            temp = temp->next;
        }

        cout << "Total Books: " << totalBooks << endl;
    }

    void deleteBook(int id) {
        if (head == nullptr) {
            cout << "No books in the library.\n";
            return;
        }

        if (head->id == id) {
            Book* temp = head;
            head = head->next;
            delete temp;
            totalBooks--;
            cout << "Book deleted successfully!\n";
            return;
        }

        Book* temp = head;
        while (temp->next != nullptr && temp->next->id != id) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Book not found!\n";
        } else {
            Book* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            totalBooks--;
            cout << "Book deleted successfully!\n";
        }
    }

    ~Library() {
        Book* temp = head;
        while (temp != nullptr) {
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
        cout << "\n====== Library Management System ======\n";
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
                    if (book != nullptr) {
                        cout << "Book found!\n";
                        cout << "ID: " << book->id
                             << " | Title: " << book->title
                             << " | Author: " << book->author
                             << " | Status: "
                             << (book->isIssued ? "Issued" : "Available")
                             << endl;
                    } else {
                        cout << "Book not found!\n";
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
                cout << "Exiting system...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}