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

    //puts a card into a hand
    void toHand(card x) {
        if (x.getVal() == x.getAltVal()) {
            hasAce=True;
        }
        playerCards[cards] = x;
        cards++;
        checkBust();
        value += x.getVal();
    }

    //checks for a bust
    bool checkBust() {
        if (value>21) {
            cout<< "You have busted!"<<endl;
            return True;
        } else {
            return False;
        }
    }

    //returns the greatest value under 21
    int checkValue() {
        if (!hasAce) {
            return value;
        } else if (value + 10 <= 21) {
            return value +10;
        } else {
            return value;
        }
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
    
    int value; //value of total cards
    int cards; //number of cards
    int order; //order the player goes in; does not matter for 1 player
    string pName; //name of player
    bool playing=false; //if player is playing or not
    bool bust=false; //if player has bust or not
    card playerCards[11]; //array for the players hand
    bool hasAce=false; //determines if player has an ace
    
    
    private:
};
