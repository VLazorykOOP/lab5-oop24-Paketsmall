//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//
//class Animal {
//public:
//    string classification;
//    int limbs;
//    int posterity;
//public:
//    Animal()
//        :classification("Unknown"), limbs(0), posterity(0) {}
//    Animal(string cls, int limbsAmount, int posterityAmount)
//        :classification(cls), limbs(limbsAmount), posterity(posterityAmount) {}
//    ~Animal() {}
//    void print() {
//        cout << "Classification: " << this->classification << endl;
//        cout << "Number of Limbs: " << this->limbs << endl;
//        cout << "Number of Offspring: " << this->posterity << endl;
//    }
//    void setPost(int newPost) {
//        this->posterity = newPost;
//    }
//};
//
//class Pet : public Animal {
//private:
//    string name;
//public:
//    Pet()
//        :Animal(), name("Unknown") {}
//    Pet(string cls, int limbsAmount, int posterityAmount, string newName)
//        :Animal(cls, limbsAmount, posterityAmount), name(newName) {}
//    ~Pet() {}
//    void print() {
//        cout << "Pet Name: " << name << endl;
//        Animal::print();
//    }
//    void rename(string newName) {
//        this->name = newName;
//    }
//    void setNewPosterity(int newPost) {
//        Animal::setPost(newPost);
//    }
//};
//
//int main() {
//    Animal Lion("Mammal", 4, 3);
//    cout << "Animal:" << endl;
//    Lion.print();
//    cout << endl;
//
//    Pet Dog("Mammal", 4, 5, "Buddy");
//    cout << "Pet:" << endl;
//    Dog.print();
//    cout << endl;
//
//    Dog.rename("Max");
//    Dog.setNewPosterity(4);
//
//    cout << "After changes:" << endl;
//    Dog.print();
//
//    return 0;
//}
//
//  
//
//
//
//


//#include <iostream>
//#include <string>
//#include <map>
//#include <cstring>
//using namespace std;
//
//class Tail {
//private:
//    int length;
//public:
//    Tail() {}
//    Tail(int newLength)
//        :length(newLength) {}
//    int setLength(int newL) {
//        this->length = newL;
//    }
//    int getLength() const {
//        return length;
//    }
//};
//
//class Dog {
//private:
//    Tail tail;
//    char* color;
//    int age;
//public:
//    Dog(int tailLength, char* dogColor, int dogAge)
//        : age(dogAge) {
//        tail.setLength(tailLength);
//        this->color = new char[strlen(dogColor) + 1];
//        strcpy(color, dogColor);
//    }
//    ~Dog() {
//        delete[] color;
//    }
//    void print() const {
//        cout << "Dog details:" << endl;
//        cout << "Tail length: " << tail.getLength() << endl;
//        cout << "Color: " << color << endl;
//        cout << "Age: " << age << endl;
//    }
//};
//
//class PublicDog : public Dog {
//private:
//    char* name;
//public:
//    PublicDog(int tailLength, char* dogColor, int dogAge, const char* dogName)
//        : Dog(tailLength, dogColor, dogAge) {
//        this->name = new char[strlen(dogName) + 1];
//        strcpy(name, dogName);
//    }
//    ~PublicDog() {
//        delete[] name;
//    }
//    void print() const {
//        Dog::print();
//        cout << "Name: " << name << std::endl;
//    }
//};
//
//int main() {
//    PublicDog myDog(20, "Brown", 5, "Buddy");
//    myDog.print();
//
//    return 0;
//}






#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;

class Education {
private:
    string level;
public:
    Education(string lvl)
        :level(lvl) {}
    Education(const Education& other) : level(other.level) {}

    virtual ~Education() {}


    virtual void display() const {
        cout << "Level of Education: " << level << endl;
    }

    virtual void input(istream& is) {
        cout << "Enter level of education: ";
        is >> level;
    }
    Education& operator=(const Education& other) {
        if (this != &other) {
            level = other.level;
        }
        return *this;
    }


};

class HigherEducation : public Education {
private:
    string major;
public:
    HigherEducation(const string& lvl, const string& mjr) : Education(lvl), major(mjr) {}
    ~HigherEducation() {}
    HigherEducation(const HigherEducation& other) : Education(other), major(other.major) {}

    void display() const {
        Education::display();
        cout << "Major: " << major << endl;
    }

    void input(istream& is) {
        Education::input(is);
        cout << "Enter major: ";
        is >> major;
    }

    HigherEducation& operator=(const HigherEducation& other) {
        if (this != &other) {
            Education::operator=(other);
            major = other.major;
        }
        return *this;
    }
};

int main() {
    HigherEducation ipz("Bakalavr", "Computer Science");
    ipz.display();

    cout << "Enter new info:" << endl;
    ipz.input(cin);

    cout << "Updated info:" << endl;
    ipz.display();

    return 0;
}








