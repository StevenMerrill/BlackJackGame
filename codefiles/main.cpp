#include <iostream>
#include "class/cards.h"
#include "class/deck.h"
#include "class/player.h"

using namespace std;



//function check ace
    // compares val and alt val
    // if unequal returns true

int main(){
    string p1Name="";
    string continuePlaying;
    string drawing;
    bool invalid=true;
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
                cout<<"You both drew Blackjack and have tied. This is the end of the hand.";
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
            cout<<"You drew a blackjack and have won this hand. This is the end of the hand.";
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
            cout<<"\nthe dealer has drawn a blackjack and has won this hand. This is the end of the hand.";
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
                    if(player1.checkBust()){
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
            //check for bust
          //end 
          //dealer draws if total is less than 16, stand on 17 or more
      //do you want to keep playing?
        player1.setPlaying(false);
            }
        }
    }


