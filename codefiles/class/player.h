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

    bool checkBust(bool ace) {
        //logic for ace
        if (ace) {
            
        }
        //compare cards to 21
        else if (cards>21) {
            cout<< "You have busted!"<<endl;
            return True;
        } else return False;
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
