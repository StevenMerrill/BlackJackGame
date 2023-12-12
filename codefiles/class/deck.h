#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;



class deck{
    public:
        //constructor
        deck() {
            //Local variable with card data
            string nameList[13] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
            int altValList[13] = {11,2,3,4,5,6,7,8,9,10,10,10,10};
            int valList[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
            string suitList[4] = {"Hearts","Clubs","Spades","Diamond"};
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



int main()
{
    /*deck test;
    test.shuffle();
    for (int i=0; i<52; i++) {
        cout<< (test.draw()).getName() <<endl;
    }*/
}
