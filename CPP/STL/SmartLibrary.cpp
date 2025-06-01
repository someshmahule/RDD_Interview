#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <tuple>
#include <optional>
#include <variant>

using namespace std;

// ---------- Book Struct and Comparator ----------
struct Book {
    int id;
    string title;
    string author;
    int year;
    double rating;

    bool operator<(const Book& other) const {
        return rating < other.rating;
    }
};

// ---------- User Struct ----------
struct User {
    int id;
    string name;
    unordered_set<int> borrowedBooks;
};

// ---------- Library Class ----------
class Library {
    multimap<string, Book> booksByTitle;
    multiset<string> genres;
    unordered_map<int, User> users;
    unordered_map<int, vector<int>> borrowingHistory;
    priority_queue<Book> topBooks;
    stack<string> operationLog;
    queue<int> waitlist;

public:
    void addBook(const Book& book, const string& genre) {
        booksByTitle.insert({book.title, book});
        genres.insert(genre);
        topBooks.push(book);
        operationLog.push("Added book: " + book.title);
    }

    void addUser(const User& user) {
        users[user.id] = user;
        operationLog.push("Added user: " + user.name);
    }

    optional<Book> findBook(const string& title) {
        auto it = booksByTitle.find(title);
        if (it != booksByTitle.end()) {
            return it->second;
        }
        return nullopt;
    }

    void borrowBook(int userId, const string& title) {
        auto userIt = users.find(userId);
        if (userIt == users.end()) return;
        auto bookOpt = findBook(title);
        if (bookOpt) {
            userIt->second.borrowedBooks.insert(bookOpt->id);
            borrowingHistory[userId].push_back(bookOpt->id);
            operationLog.push("User " + userIt->second.name + " borrowed book: " + title);
        } else {
            waitlist.push(userId);
            operationLog.push("Book not found. User added to waitlist.");
        }
    }

    void printTopRated() {
        cout << "Top rated book: " << topBooks.top().title << " with rating: " << topBooks.top().rating << endl;
    }

    void undoLastAction() {
        if (!operationLog.empty()) {
            cout << "Undo: " << operationLog.top() << endl;
            operationLog.pop();
        }
    }

    void printBorrowingHistory(int userId) {
        cout << "Borrowing history of user " << userId << ": ";
        for (int id : borrowingHistory[userId]) {
            cout << id << " ";
        }
        cout << endl;
    }
};

// ---------- Main ----------
int main() {
    Library lib;

    Book b1{1, "1984", "Orwell", 1949, 4.8};
    Book b2{2, "Dune", "Herbert", 1965, 4.7};
    Book b3{3, "Foundation", "Asimov", 1951, 4.6};

    User u1{101, "Alice"};
    User u2{102, "Bob"};

    lib.addUser(u1);
    lib.addUser(u2);

    lib.addBook(b1, "Dystopia");
    lib.addBook(b2, "Sci-Fi");
    lib.addBook(b3, "Sci-Fi");

    lib.borrowBook(101, "1984");
    lib.borrowBook(102, "Dune");

    lib.printTopRated();
    lib.printBorrowingHistory(101);
    lib.undoLastAction();

    return 0;
}
