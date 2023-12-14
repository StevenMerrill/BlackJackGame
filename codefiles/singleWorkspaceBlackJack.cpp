#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
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


class deck{
    public:
        //constructor
        deck() {
            //Local variable with card data
            string nameList[13] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
            int altValList[13] = {11,2,3,4,5,6,7,8,9,10,10,10,10};
            int valList[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
            string suitList[4] = {"Hearts","Clubs","Spades","Diamonds"};
            int count=0;
            //makes a 52 card deck
            for(int i=0;i<4;i++) {
                for(int j=0;j<13;j++) {
                    //puts in a unique card selected using the above matrices
                    cards[count] = card(valList[j],altValList[j],nameList[j],suitList[i]);
                    //increment count to move onto the next card
                    count++;
                }
            }
        }

        //function for shuffling the deck
        void shuffle(){
            //gets a random seed from system clock
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            //generates random number from seed
            auto rng = default_random_engine(seed);
            //shuffles array using built in matrix function
            ::shuffle(begin(cards),end(cards),rng);
        }

        //function for drawing card
        card draw(){
            //pick the card you draw
            card out = cards[0];
            //replace with next in slot
            for (int i=1;i<=size-1;i++) {
                cards[i-1] = cards[i];
            }
            //empty the last card
            cards[size-1] = card();
            return out;
        }

        //function to discard a card
        void discard(card dcd) {
            //[puts the card in the discard pile
            discardcards[discardSize] = dcd;
            //increases size of the discard pile
            discardSize++;
        }

    protected:
        int size=52; //deck size
        card cards[52]; //deck container
        card discardcards[52]; //discard pile
        int discardSize = 0; //discard pile size

        
    private:    
    
};
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
        if (x.getVal() != x.getAltVal()) {
            hasAce=true;
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
            return true;
        } else {
            return false;
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
    void resetCards(){
        value = 0;
        cards=0;
        hasAce = false;
        bust=false;

        for (int i = 0; i < 11; ++i) {
            playerCards[i] = card(); 
        }
        
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

int main(){
    string p1Name="";
    string continuePlaying;
    string drawing;
    bool invalid;
  //create player1
    player player1;
    player1.setPlaying(true);
  //create playerDealer
    player playerDealer;
    playerDealer.setPlaying(true);
  //set dealer name
    playerDealer.setName("Dealer");
  //ask name
    cout<<"What is your name?\n";
    cin>>p1Name;
  //set name
    player1.setName(p1Name);
  //welcome to blackjack
    cout<<"Welcome to Blackjack "<<player1.getPlayerName()<<"... Good Luck.\n";
  //while loop to play game
    while(player1.getPlaying()){
        invalid=true;
        player1.resetCards();
        playerDealer.resetCards();
      //instantiate new deck
        deck Deck1;
        Deck1.shuffle();
        cout<<"The dealer will now shuffle the cards.\n";
        cout<<"Shuffling..."<<endl<<"Shuffling..."<<endl<<"Shuffling..."<<endl;
      //deal initial cards
      // for 2
        for(int i=0;i<2;i++){
          //deal player and check ace
            player1.toHand((Deck1.draw()));
          //deal dealer and check ace
            playerDealer.toHand(Deck1.draw());
        }
      //reveal player
        cout<< "Your cards are the ";
        for(int i=0;i<2;i++){
           cout<<(player1.getCardI(i)).getName()<<" of "<<(player1.getCardI(i)).getSuit();
            if(i==0){
                cout<<" and the ";
            }
        }
        cout<<endl;
        cout<<player1.getPlayerName()<<", the value of your cards is "<<to_string(player1.checkValue());
         //reveal dealer second card
        cout<<"\nThe dealer's second card is the "<<(playerDealer.getCardI(1)).getName()<<" of "<<(playerDealer.getCardI(1)).getSuit();
        //if dealer has blackjack and player has balckjack
        if(player1.checkValue()==21&&playerDealer.checkValue()==21){
                cout<<"\nYou both drew Blackjack and have tied. This is the end of the hand.";
            while(invalid){
                cout<<"Do you want to play again?(Y/N)"<<endl;
                cin>>continuePlaying;
                if(continuePlaying=="Y"){
                    invalid=false;
                }
                else if(continuePlaying=="N"){
                    invalid=false;
                    player1.setPlaying(false);
                }
                else{
                    cout<<"invalid selection... please try again.";
                }
            }
            continue;
        }//tie
      //elif player has blackjack and dealer does not
        else if(player1.checkValue()==21){
            cout<<"\nYou drew a blackjack and have won this hand. This is the end of the hand.";
            while(invalid){
                cout<<"Do you want to play again?(Y/N)"<<endl;
                cin>>continuePlaying;
                if(continuePlaying=="Y"){
                    invalid=false;
                }
                else if(continuePlaying=="N"){
                    invalid=false;
                    player1.setPlaying(false);
                }
                else{
                    cout<<"invalid selection... please try again.";
                }
            }
            continue;
        }
                
            //player wins
      //elif dealer has blackjack and player does not
        else if(playerDealer.checkValue()==21){
            cout<<"\nThe dealer has drawn a blackjack and has won this hand. This is the end of the hand.";
            while(invalid){
                cout<<"do you want to continue playing?\n";
                cin>>continuePlaying;
                if(continuePlaying=="Y"){
                    invalid=false;
                }
                else if(continuePlaying=="N"){
                    invalid=false;
                    player1.setPlaying(false);
                }
                else{
                    cout<<"invalid selection... please try again.";
                    continue;
                }
            }
            continue;
        }
            
            //dealer wins
      //else
        else{
            
          //while ask if player wants to draw
            bool wantDraw=true;
            cout<<"\nDo you want to draw another card?(Y/N)"<<endl;
            cin>>drawing;
            while(wantDraw){
                if(drawing=="Y"){
                    //deal player and check ace
                    player1.toHand((Deck1.draw()));
                    cout<<"You drew a "<<(player1.getCardI(player1.getCardsNum()-1)).getName()<<" of "<<(player1.getCardI(player1.getCardsNum()-1)).getSuit()<<" with a value of "<<(player1.getCardI(player1.getCardsNum()-1)).getVal()<<endl;
                    cout<<"Your new value is "<<to_string(player1.checkValue())<<endl;
                    if(player1.checkValue())==21){
                        cout<<"\nThats Blackjack! Time to see what the dealer drew!");
                        break;
                    if(player1.checkBust()){
                        player1.setBust(true);
                        break;
                    }
                    cout<<"\nDo you want to draw another card?(Y/N)"<<endl;
                    cin>>drawing;
                    continue;
                    
                    
                }
                else if(drawing=="N"){
                    wantDraw=false;
                    continue;
                }
                else{
                    cout<<"invalid selection... please try again.";
                    continue;
                } 
              
              }
              if(player1.getBust()){
                  cout<<"\nThis is the end of the hand.";
                   while(invalid){
                        cout<<"\nDo you want to continue playing?\n";
                        cin>>continuePlaying;
                        if(continuePlaying=="Y"){
                            invalid=false;
                     }
                        else if(continuePlaying=="N"){
                         invalid=false;
                         player1.setPlaying(false);
                     }
                     else{
                    cout<<"invalid selection... please try again.";
                    continue;}
                   }
                   continue;
                   
                }
              }
              //dealer draws if total is less than 16, stand on 17 or more
              cout<<"\nThe dealer's first card is now revealed to be the "<<(playerDealer.getCardI(0)).getName()<<" of "<<(playerDealer.getCardI(0)).getSuit()<<" with a value of "<<to_string((playerDealer.getCardI(0)).getVal())<<" giving the dealer a total value of "<<to_string(playerDealer.checkValue())<<endl;
              while(playerDealer.checkValue()<17){
                  cout<<"\nThe dealer is drawing another card...";
                  playerDealer.toHand((Deck1.draw()));
                  cout<<"\nThe dealer drew the "<<(playerDealer.getCardI(playerDealer.getCardsNum()-1)).getName()<<" of "<<(playerDealer.getCardI(playerDealer.getCardsNum()-1)).getSuit()<<" with a value of "<<to_string((playerDealer.getCardI(playerDealer.getCardsNum()-1)).getVal())<<endl;
              }
              cout<<"\nThe value of your cards is "<<to_string(player1.checkValue())<<" and the value of the dealer's cards is " <<to_string(playerDealer.checkValue());
              if (playerDealer.checkValue()>21){
                  cout<<"\nThe dealer busted, you win!";
              }
              else if(player1.checkValue()<playerDealer.checkValue()){
                  if(playerDealer.checkValue()==21){
                      cout<<"\nThe dealer had blackjack. The dealer wins.";
                      break;
                  }
                  cout<<"\nThe dealer had a greater total than you... the dealer won.";
              }
              else if(player1.checkValue()>playerDealer.checkValue()){
                  if(player1.checkValue()==21){
                      cout<<"\nYou had blackjack! You won!";
                      break;
                  }
                  cout<<"\nYou had a greater total than the dealer... you won!";
              }
              else{
                  if(player1.checkValue()==playerDealer.checkValue()&&player1.checkValue()==21){
                      cout<<"\nYou both have blackjack... it's a tie.";
                      break;
                  }
                  cout<<"\nYou and the dealer had the same total... it's a tie.";
              }
              while(invalid){
                cout<<"\nDo you want to continue playing?\n";
                cin>>continuePlaying;
                if(continuePlaying=="Y"){
                    invalid=false;
                }
                else if(continuePlaying=="N"){
                    invalid=false;
                    player1.setPlaying(false);
                }
                else{
                    cout<<"invalid selection... please try again.";
                    continue;
                }
            }
            continue;
        }
         cout<<"Thank you for playing. Goodbye."; 
      //do you want to keep playing?
}
