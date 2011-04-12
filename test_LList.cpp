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
    LList llist = LList();
    LList llist2 = LList();
    LList llist3 = LList();
    
    //------------------------------------------------------------
	// Sets the initial coordinates of the coins
    coin->setLeft(0);
    coin2->setLeft(16);
    coin3->setLeft(48);
    coin4->setLeft(32);
    //------------------------------------------------------------
    // Test size() and append()
    
	// Checks the initial size of llist
	assert(llist.size() == 0);

	// Appends a coin to llist and checks that the size = 1
	llist.append(coin);
    assert(llist.size() == 1);

	// Removes the coin from llist and checks the size = 0
	llist.removeDrawable(coin);
	assert(llist.size() == 0);

	// Adds two coins to llist and checks the size = 2
	llist.append(coin);
	llist.append(coin2);
	assert(llist.size() == 2);

    //------------------------------------------------------------
    // Test removeFirst()

	// Removes the first coin in the list and checks the size = 1
	llist.removeFirst();
	assert(llist.size() == 1);

    //------------------------------------------------------------
    // Test copy constructor

    // Copies llist into llist2 and checks llist2 size = 1
    llist2 = llist;
    assert(llist2.size() == 1);
    
    // Test that the elements from llist was copied to llist2
    assert(llist2.first() == llist.first());
    
    //------------------------------------------------------------
    // Test append again with copied list

	// Appends a coin to llist2 and checks the size of both lists
    llist2.append(coin2);
    assert (llist.size() == 1);
    assert(llist2.size() == 2);
    
    //------------------------------------------------------------
    // Test first()
    
	// Checks to see if the first items in each LList are the same
    assert((llist.first() == llist2.first()));
    
	// Checks to make sure that the first object is a coin in llist
    assert(llist.first()->objectType() == COIN);
    
    // Checks to make sure that the first object is a coin in llist2
    assert(llist2.first()->objectType() == COIN);

    //------------------------------------------------------------
    // Tests the iterator and insertInSortedOrder()
    
    // Appends a coin to llist and inserts another coin in sorted order according to coordinates
    llist3.append(coin);
    llist3.append(coin2);
	llist3.append(coin3);
    llist3.insertInSortedOrder(coin4);
	
	
	//Use the iterator to test to see if the order is correct 
    // Should be coin, coin2, coin4, coin3
    LListIterator li;
    li.init(llist3);
	Drawable *item;
	// Array of coins for testing insertInSortedOrder
	Coin *a[4];
	a[0] = coin;
	a[1] = coin2;
	a[2] = coin4;
	a[3] = coin3;
	// Checks if the order of coins is correct after calling in sorted order and the list itterator
    int i = 0;
	while ((item = li.next())) {
		assert(item == a[i]);         
		i++;
	}
    
    LList llist4 = LList();
    llist4.append(coin);
    llist4.append(coin2);
    llist4.append(coin4);
    llist4.append(coin3);
    
    LListIterator li2;
    li2.init(llist4);
    i = 0;
    while ((item = li2.next())) {
		assert(item == a[i]);        
		i++;
	}
    
    
    LList llist5 = LList();
    llist5.insertInSortedOrder(coin);
    llist5.insertInSortedOrder(coin2);
    llist5.insertInSortedOrder(coin3);
    llist5.insertInSortedOrder(coin4);
    
    LListIterator li3;
    li3.init(llist5);
    i = 0;
    while ((item = li3.next())) {
		assert(item == a[i]);        
		i++;
	}
    
    cout << "tests successfully completed" << endl;
	return 0;
}
//------------------------------------------------------------
