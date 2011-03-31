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
    Coin *coin = new Coin();
	Coin *coin2 = new Coin();
	Coin *coin3 = new Coin();
    Coin *coin4 = new Coin();
    LList *llist = new LList();
    LList *llist2 = new LList();
	    
    coin->setLeft(0);
    coin2->setLeft(16);
    coin3->setLeft(48);
    coin4->setLeft(32);
    
	assert(llist->size() == 0);
	cout << "Size test passes" << endl;

	llist->append(coin);

	assert(llist->size() == 1);
	cout << "Append test passes" << endl;

	llist->removeDrawable(coin);
	assert(llist->size() == 0);
	cout << "Remove test passes" << endl;

	llist->append(coin);
	llist->append(coin2);
	assert(llist->size() == 2);
	cout << "Append test 2 passes" << endl;

	llist->removeFirst();
	assert(llist->size() == 1);
	cout << "Remove first test passes" << endl;

    
    llist2 = llist;
    assert(llist2->size() == 1);
    cout << "Copy constructer passes" << endl;
    
    llist2->append(coin2);
    assert(llist->size() == 2);
    assert(llist2->size() == 2);
    cout << "Correctly appends to both lists" << endl;
    
    assert((llist->first() == llist2->first()));
    cout << "First test passes" << endl;
    
    assert(llist->first()->objectType() == coin_);
    cout << "First test 2 passes" << endl;
    
    llist->append(coin3);
    llist->insertInSortedOrder(coin4);
    //Use the iterator to test to see if the order is correct 
    // Should be coin, coin2, coin4, coin3
    /*LListIterator li;
    li.init(llist);
	Drawable *item;
	while ((item = li.next())) {
		// do something with item
	}
     */
    
	return 0;
}
//------------------------------------------------------------
