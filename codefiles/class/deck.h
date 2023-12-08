#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;



class deck{
    public:
    
        deck() {
            string nameList[13] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
            int altValList[13] = {11,2,3,4,5,6,7,8,9,10,10,10,10};
            int valList[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
            string suitList[4] = {"Hearts","Clubs","Spades","Diamond"};
            int count=0;
            for(int i=0;i<4;i++) {
                for(int j=0;j<13;j++) {
                    cards[count] = card(valList[j],altValList[j],nameList[j],suitList[i]);
                    count++;
                }
            }
        }
        
        void shuffle(){
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            auto rng = default_random_engine(seed);
            ::shuffle(begin(cards),end(cards),rng);
        }
        
        card draw(){
            card out = cards[0];
            for (int i=1;i<=size-1;i++) {
                cards[i-1] = cards[i];
            }
            cards[size-1] = card();
            return out;
        }
        
        void discard(card dcd) {
            discardcards[discardSize] = dcd;
            discardSize++;
        }

    protected:
        int size=52;
        card cards[52];
        card discardcards[52];
        int discardSize = 0;

        
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
