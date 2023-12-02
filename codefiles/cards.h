#include <iostream>

using namespace std;

class card {
    public:
    
    card(int cval,int caltVal,string cname,string csuit) {
        val = cval;
        altVal = caltVal;
        name = cname;
        suit = csuit;
    }
    
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
    
    int val;
    int altVal;
    string name;
    string suit;
    
    private:
};

int main()
{
    /*card ace(1,11,"ace","clubs");
    cout<<ace.getAltVal();*/
}
