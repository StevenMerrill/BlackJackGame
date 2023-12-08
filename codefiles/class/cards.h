#include <iostream>

using namespace std;
class player {
    public: 
    player(int cardsC, int orderC, string nameC, bool playingC, bool bustC){
        cards=cardsC;
        order=orderC;
        pName=nameC;
        playing=playingC;
        bust=bustC;
    }
    player(){}
    string getPlayerName(){
        return pName;
    }
    int getOrder(){
        return order;
    }
    int getCardsNum(){
        return cards;
    }
    bool getPlaying(){
        return playing;
    }
    bool getBust(){
        return bust;
    }
    card getCardI(int i){
        return playerCards[i];
    }
        
    void setOrder(int orderSet){
        order=orderSet;
    }
    void setName(string nameSet){
        pName=nameSet;
    }
    void setCards(int cardsSet){
        cards=cardsSet;
    }
    void setPlaying(bool playingSet){
        playing=playingSet;
    }
    void setBust(bool bustSet){
        bust=bustSet;
    }
    void setCardI(int i, card toSet){
        playerCards[i]=toSet;
    }
    protected:
    
    int cards;
    int order;
    string pName;
    bool playing=false;
    bool bust=false;
    card playerCards[11];
    
    
    private:
};

class card {
    public:
    
    card(int cval,int caltVal,string cname,string csuit) {
        val = cval;
        altVal = caltVal;
        name = cname;
        suit = csuit;
    }
    card(){
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
