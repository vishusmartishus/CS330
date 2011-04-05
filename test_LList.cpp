/*
 *  test_LList.cpp
 *  Game
 *  Blackbox testing of the LList
 *
 *  Created by David M. Reed and modified by Jamie Veals, Jay Bondzeleske, John (Jack) Johnson
 *
 */

#include<iostream>
#include<cassert>
#include "LList.h"
#include "Base.h"
#include "Coin.h"
#include "LListIterator.h"
using namespace std;
//------------------------------------------------------------
int main()
{
	// Creates four new coin pointers and two lists
    Coin *coin = new Coin();
	Coin *coin2 = new Coin();
	Coin *coin3 = new Coin();
    Coin *coin4 = new Coin();
    LList llist = new LList();
    LList llist2 = new LList();
	    
	// Sets the initial coordinates of the coins
    coin->setLeft(0);
    coin2->setLeft(16);
    coin3->setLeft(48);
    coin4->setLeft(32);
    
	// Checks the initial size of LList
	assert(llist.size() == 0);
	cout << "Size test passes" << endl;

	// Appends a coin to LList
	llist.append(coin);

	// Checks the size after the append
	assert(llist.size() == 1);
	cout << "Append test passes" << endl;

	// Removes the coin from LList and checks the size
	llist.removeDrawable(coin);
	assert(llist.size() == 0);
	cout << "Remove test passes" << endl;

	// Adds two coins to LList and checks the size
	llist.append(coin);
	llist.append(coin2);
	assert(llist.size() == 2);
	cout << "Append test 2 passes" << endl;

	// Removes the first coin in the list and checks the size
	llist.removeFirst();
	assert(llist.size() == 1);
	cout << "Remove first test passes" << endl;

    // Copies LList into LList2 and checks LList2 size
    llist2 = llist;
    assert(llist2.size() == 1);
    cout << "Copy constructer passes" << endl;
    
	// Appends a coin to LList2 and checks the size of both LLists
    llist2.append(coin2);
    assert(llist.size() == 2);
    assert(llist2.size() == 2);
    cout << "Correctly appends to both lists" << endl;
    
	// Checks to see if the first items in each LList are the same
    assert((llist.first() == llist2.first()));
    cout << "First test passes" << endl;
    
	// Checks to make sure that the first object is a coin in LList
    assert(llist.first().objectType() == coin_);
    cout << "First test 2 passes" << endl;
    
    // Appends a coin to LList and inserts another coin in sorted order according to coordinates
	llist.append(coin3);
    llist.insertInSortedOrder(coin4);
	
	/*
	//Use the iterator to test to see if the order is correct 
    // Should be coin, coin2, coin4, coin3
    LListIterator li;
    li.init(llist);
	Drawable *item;
	// Array of coins for testing in sorted order
	Drawable a[4];
	a[0] = coin;
	a[1] = coin2;
	a[2] = coin4;
	a[3] = coin3;
	// Checks if the order of coins is correct after calling in sorted order and the list itterator
	while ((item = li.next())) {
		// do something with item
		assert(item == a[i])
		i = i + 1;
	}*/
     
    
	return 0;
}
//------------------------------------------------------------
