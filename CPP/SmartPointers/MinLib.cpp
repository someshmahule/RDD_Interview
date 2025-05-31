#include<iostream>
#include<vector>
#include<memory>

using namespace std;

class Book{

    public:
    string title;
    Book(){}
    Book(string t):title(t){cout<<"Book "<<title<<" created\n";}
    ~Book(){cout<<"Book Destroyed\n";}

};

class Library;

class Member{

    public:
    string name;
    vector<shared_ptr<Book>> bBook;
    weak_ptr<Library> lib;
    Member(string n): name(n) {}
    ~Member(){}
    void borrowBook(shared_ptr<Book>);
    void printLibraryName();
};

class Library : public enable_shared_from_this<Library>{
    public:
    string name;
    vector<unique_ptr<Book>> oBook;
    vector<shared_ptr<Member>> mems;
    Library(){}
    ~Library(){}
    Library(string n): name(n) {}

    void addBook(string t) {
        oBook.push_back(make_unique<Book>(t));
    }

    shared_ptr<Book> getBook(string t) {
        // Search for the book by title in oBook
        for (auto it = oBook.begin(); it != oBook.end(); ++it) {
            if ((*it)->title == t) {
                // Transfer ownership from unique_ptr to shared_ptr
                shared_ptr<Book> sp = move(*it);
                oBook.erase(it);
                return sp;
            }
        }
        // If not found, return nullptr
        return nullptr;
    }

    void addMember(shared_ptr<Member> m){
        mems.push_back(m);
        m->lib = shared_from_this();
    }

    string getLibraryName(){
        return name;
    }
};

void Member::borrowBook(shared_ptr<Book> b){

    bBook.push_back(b);

}

void Member::printLibraryName(){
    if(lib.lock()){
        cout<<"Library exist"<<lib.lock()->name<<"\n";
    }
    else{
        cout<<"Library doesnt exist\n";
    }
}

int main(){

    shared_ptr<Library> l1 = make_shared<Library>("Walchand");
    l1->addBook("CPP");
    l1->addBook("Java");
    l1->addBook("Python");
    shared_ptr<Member> m1 = make_shared<Member>("somesh");
    l1->addMember(m1);
    m1->borrowBook(l1->getBook("CPP"));
    m1->borrowBook(l1->getBook("Python"));
    m1->borrowBook(l1->getBook("Java"));
    m1->printLibraryName();
    cout<<m1->lib.use_count()<<"\n";
    m1->lib.reset();
    cout<<m1->lib.use_count()<<"\n";
    return 0;
}