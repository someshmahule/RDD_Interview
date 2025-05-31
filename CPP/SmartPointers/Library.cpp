#include<iostream>
#include<memory>
#include<vector>

using namespace std;

class Library
{
    public:
    Library() {}
    ~Library() {}
    vector<unique_ptr<Book>> books;
    void addBooks( unique_ptr<Book> b);

};

class Book{

    public:
    string title;
    weak_ptr<Members> last_borrowed;
    Book(string t) : title(t) { cout<<title<<" Book created\n";}
    ~Book() { cout<<title<<" Book Destroyed\n"; }

};

void Library::addBooks( unique_ptr<Book> b) {

    books.push_back(b);

}

class Members : public enable_shared_from_this<Members> {

    public:
    string name;
    vector<shared_ptr<Book>> borrowedBooks ;
    Members(string n): name(n){ cout<<"Member created\n";}
    ~Members() { cout<<"Member destroyed\n";}
    void borrowBook(shared_ptr<Book> book);
};

void Members::borrowBook(shared_ptr<Book> b){

        borrowedBooks.push_back(b);
        b->last_borrowed = shared_from_this();
}


int main(){

    unique_ptr<Library> l = make_unique<Library>();
    l->addBooks(make_unique<Book>("CPP"));
    l->addBooks(make_unique<Book>("Java"));
    l->addBooks(make_unique<Book>("Python"));

    unique_ptr<Members> m1 = make_unique<Members>("somesh");
    unique_ptr<Members> m2 = make_unique<Members>("ramesh");
    unique_ptr<Members> m3 = make_unique<Members>("rakesh");

    m1->borrowBook();
    return 0;

}