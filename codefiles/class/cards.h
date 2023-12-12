#include <iostream>

include namespace std;

class card {
    public:

    //constructor
    card(int cval,int caltVal,string cname,string csuit) {
        val = cval;
        altVal = caltVal;
        name = cname;
        suit = csuit;
    }

    //blank constructor
    card(){
        name = "null";
    }

//getter functions
    string getName() {
        return name;
    }
    
    string getSuit() {
        return suit;
    }
    
    int getVal() {
        return val;
    }
    
    int getAltVal() {
        return altVal;
    }
    
    
    
    protected:
    
    int val; //value
    int altVal; //alternate value
    string name; //card name
    string suit; // suit if the card
    
    private:
};

