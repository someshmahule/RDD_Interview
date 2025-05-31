#include<iostream>
#include<memory>
#include<vector>

using namespace std;

class Members;

class Library : public enable_shared_from_this<Library> {

    public:
        string name;
        vector<shared_ptr<Members>> mems;

        Library() {}
        Library(string n):name(n) {}
        ~Library() {}
        void addMember(shared_ptr<Members> m);
        string getName();
        //void removeMember(shared_ptr<Members> m);
};


class Members{

    public:
        string name;
        weak_ptr<Library> lib;

        Members(){}
        Members(string n, weak_ptr<Library> l) : name(n), lib(l) {}
        ~Members(){}
        void printLib();

};

void Library::addMember(shared_ptr<Members> m){
    mems.push_back(m);
    m->lib = shared_from_this();
}

string Library::getName(){
    return name;
}

void Members::printLib(){
    if(lib.lock()){
        cout<< lib.lock()->getName();
    }
    else{
        cout<<"Library no longer exists";
    }
}

/*void Library::removeMember(shared_ptr<Members> m ){
    mems.pop_back()
}*/

int main(){


    shared_ptr<Library> l1 = make_shared<Library>("Walchand");
    shared_ptr<Members> m1 = make_shared<Members>("Somesh", l1 );
    shared_ptr<Members> m2 = make_shared<Members>("ramesh", l1);
    shared_ptr<Members> m3 = make_shared<Members>("rakesh", l1);
    l1->addMember(m1);
    l1->addMember(m2);
    l1->addMember(m3);
    m1->printLib();
    m2->printLib();
    l1.reset();
    m1->printLib();
    return 0;
}


