#include <iostream>
#include <string>

class Login {
public:
    virtual bool login(int logID, std::string logName) = 0;
    virtual ~Login() {}
};

class User : public Login {
private:
    int id;
    std::string name;

public:
    User(int id, std::string name) : id(id), name(name) {

    }

    bool login(int inputID, std::string inputName) override {
        return (this->id == inputID && this->name == inputName);
    }

    int getID() {
        return id;
    }

    std::string getName() {
        return name;
    }

    virtual void displayInfo() {
        std::cout << "Id: " << id << " | Name: " << name << std::endl;
    }

    virtual void displayRole() = 0;

    virtual ~User() {}
};

class Student : public User {
private:
    int booksBorrowed;
public:
    Student(int id, std::string name, int books) : User(id, name), booksBorrowed(books) {
    }

    void displayRole() override {
        std::cout << "Role: Student (Borrow maximum 10 books at a time)" << std::endl;
    }

    void displayInfo() override {
        std::cout << "|Student Profile|" << std::endl;
        User::displayInfo();
    }
};

class Librarian : public User {
private:
    std::string shift;
public:
    Librarian(int id, std::string name, std::string shift) : User(id, name), shift(shift) {

    }

    void displayRole() override {
        std::cout << "Role: Librarian | Shift: " << shift << std::endl;
    }
    
    void displayInfo() override {
        std::cout << "| Librarian Profile |" << std::endl;
        User::displayInfo();
    }
};

class Book {
private:
    std::string title;
    std::string author;
public:
    Book() : title(""), author("") {

    }

    Book(std::string title, std::string author) : title(title), author(author) {

    }

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }
};

class Library {
private:
    std::string name;
    Book books[36];
    int bookCount = 0;
public:
    Library(std::string name) : name(name) {

    }

    void addBook(Book b) {
        books[bookCount] = b;
        bookCount++;
    }

    void displayBook() {
        for (int i = 0; i < bookCount; i++) {
            std::cout << "Book: " << books[i].getTitle() << ". Author: " << books[i].getAuthor() << std::endl;
        }
    }
};

int main() {
    User* users1;
    User* users2;
    Library lib("City Library");

    lib.addBook(Book("Khong Gia Dinh", "Victor Hugo"));
    lib.addBook(Book("Dac Nhan Tam", "Nguyen Hien Le"));

    Student hy(201, "Ngo Gia Hy", 9);
    Librarian admin(101, "Le Thanks Wuang Min", "Morning");

    users1 = &hy;
    users2 = &admin;

    int inputID;
    std::string inputName;

    std::cout << "---Welcome to the City Library Service---" << std::endl;
    std::cout << "Please login to access to the service center" << std::endl;
    std::cout << "Enter ID: ";
    std::cin >> inputID;
    std::cout << "Enter Name: ";
    std::cin.ignore();
    std::getline(std::cin, inputName);

    if (users1->login(inputID, inputName) || users2->login(inputID, inputName)) {
        int choice;
        bool running = true;

        while (running) {
            std::cout << "---Welcome to the City Library Service---" << std::endl;
            std::cout << "Please choose the service you want to do: " << std::endl;
            std::cout << "1. Show all books" << std::endl;
            std::cout << "2. Show student information" << std::endl;
            std::cout << "3. Show librarian information" << std::endl;
            std::cout << "0. Exit" << std::endl;
            std::cout << "Please enter your choice: ";
            std::cin >> choice;
            std::cout << " " << std::endl;

            switch (choice) {
            case 1:
                lib.displayBook();
                std::cout << std::endl;
                break;
            case 2:
                users1->displayRole();
                users1->displayInfo();
                std::cout << std::endl;
                break;
            case 3:
                users2->displayRole();
                users2->displayInfo();
                std::cout << std::endl;
                break;
            case 0:
                running = false;
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid input, please try again!!!" << std::endl;
            }
        }
    }
    else {
        std::cout << "Login Fail" << std::endl;
    }
    
    return 0;
}