/*
 *  LList.h
 *  Game
 *
 *  Created by Andrew Peddicord on 2/17/11.
 *  Copyright 2011 Capital University. All rights reserved.
 *
 */

#ifndef __LLIST_H__
#define __LLIST_H__

#include "ListNode.h"
#include "Drawable.h"

class LListIterator;

class LList {

	friend class LListIterator;
	
public:
	LList();
	~LList();
	//Copy methods
	LList(const LList& source);
	LList& operator=(const LList &list);
	
	Drawable* removeFirst();
	
	void append(Drawable *item);
	
	Drawable* first() const;
	
	void removeDrawable(Drawable *obj);
	
	int size() const { return size_; }
	
	void insertInSortedOrder(Drawable *item);
	
private:
	
	void copy(const LList &source);
	
	ListNode *head_;
	ListNode *tail_;
	int size_;
	
};

#endif
	
