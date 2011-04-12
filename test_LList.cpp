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

    //------------------------------------------------------------
    // Test removeFirst()

	// Removes the first coin in the list and checks the size
	llist.removeFirst();
	assert(llist.size() == 1);
	cout << "Remove first test passes" << endl;

    //------------------------------------------------------------
    // Test copy constructor

    // Copies LList into LList2 and checks LList2 size
    llist2 = llist;
    assert(llist2.size() == 1);
    cout << "Copy constructer passes test - fixed error" << endl;
    
    // Test that the elements from llist was copied to llist2
    assert(llist2.first() == llist.first());
    cout << "Copying elements test fails currently" << endl;
    
    //------------------------------------------------------------
    // Test append again

	// Appends a coin to LList2 and checks the size of both LLists
    llist2.append(coin2);
    assert (llist.size() == 1);
    assert(llist2.size() == 2);
    cout << "Correctly appends to second list - pass" << endl;
    
    //------------------------------------------------------------
    // Test first()
    
	// Checks to see if the first items in each LList are the same
    assert((llist.first() == llist2.first()));
    cout << "First test passes" << endl;
    
	// Checks to make sure that the first object is a coin in llist
    assert(llist.first()->objectType() == COIN);
    cout << "First test 2 passes" << endl;
    
    // Checks to make sure that the first object is a coin in llist2
    assert(llist2.first()->objectType() == COIN);
    cout << "First test 3 passes" << endl;

    //------------------------------------------------------------
    // Tests the iterator and insertInSortedOrder
    // Appends a coin to LList and inserts another coin in sorted order according to coordinates
    llist3.append(coin);
    llist3.append(coin2);
	llist3.append(coin3);
    llist3.insertInSortedOrder(coin4);
	
	
	//Use the iterator to test to see if the order is correct 
    // Should be coin, coin2, coin4, coin3
    LListIterator li;
    li.init(llist3);
	Drawable *item;
	// Array of coins for testing in sorted order
	Coin *a[4];
	a[0] = coin;
	a[1] = coin2;
	a[2] = coin4;
	a[3] = coin3;
	// Checks if the order of coins is correct after calling in sorted order and the list itterator
    int i = 0;
    cout << "test append with last insertInSortedOrder" << endl;
	while ((item = li.next())) {
		// do something with item
        cout << "a[i] "  << a[i] << " item " << item << " " << i << endl; 
		/*assert(item == a[i]);
        cout << "SortedOrder test for position " << i << "is correct" << endl;
         */
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
    cout << "Just test appends." << endl;
    while ((item = li2.next())) {
		// do something with item
        cout << "a[i] "  << a[i] << " item " << item << " " << i << endl; 
		/*assert(item == a[i]);
         cout << "SortedOrder test for position " << i << "is correct" << endl;
         */
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
    cout << "Just test insertInSortedOrder." << endl;
    while ((item = li3.next())) {
		// do something with item
        cout << "a[i] "  << a[i] << " item " << item << " " << i << endl; 
		/*assert(item == a[i]);
         cout << "SortedOrder test for position " << i << "is correct" << endl;
         */
		i++;
	}
	return 0;
}
//------------------------------------------------------------
