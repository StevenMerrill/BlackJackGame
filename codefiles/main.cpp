#include <iostream>
#include "class/cards.h"
#include "class/deck.h"
#include "class/player.h"

using namespace std;



//function check ace
    // compares val and alt val
    // if unequal returns true

int main()
{
    string p1Name="";
  //create player1
    player player1();
    player1.setPlaying(True);
  //create playerDealer
    player playerDealer();
    playerDealer.setPlaying(True);
  //set dealer name
    playerDealer.setName("Dealer");
  //ask name
    cout<<"What is your name?\n";
    cin>>p1Name;
  //set name
    player1.setName(p1Name);
  //welcome to blackjack
    cout<<"Welcome to Blackjack...\n";
  //while loop to play game
    while(player1.getPlaying()){
      //instantiate new deck
        deck Deck1();
        Deck1.shuffle();
      //deal initial cards
      // for 2
        for(int i=0;i<2;i++){
          //deal player and check ace
            player1.toHand(Deck1.draw());
          //deal dealer and check ace
            playerDealer.toHand(Deck1.draw());
      //reveal player
        for(int i=0;i<2;i++){
           cout<< (player1.getCardI(i)).getName()<<" ";
        }
        cout<<endl;
      //reveal dealer second card
      //if dealer has blackjack and player has balckjack
            //tie
      //elif player has balckjack and dealer does not
            //player wins
      //elif dealer has blackjack and player does not
            //dealer wins
      //else
          //while ask if player wants to draw
              //deal player and check ace
              //check for bust
          //end 
          //dealer draws if total is less than 16, stand on 17 or more
      //do you want to keep playing?
      
}
