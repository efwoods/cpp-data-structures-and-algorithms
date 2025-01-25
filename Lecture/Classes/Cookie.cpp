#include <iostream>

using namespace std;

class Cookie {
    private: // attributes
        string color;

    public: 
        Cookie (string color) { //constructor: a member function that has the same name as the class
            this->color = color; // changes the private string color;
        }
        string getColor(){
            return this->color;
        }
        void setColor(string color) {
            this->color = color;
        }
};

int main(){
    Cookie* cookieOne = new Cookie("green");
    Cookie* cookieTwo = new Cookie("blue");

    cookieOne->setColor("yellow");

    cout << "cookieOne = " << cookieOne->getColor() << endl;
    cout << "cookieTwo = " << cookieTwo->getColor() << endl;
}