/*
 *  LListIterator.h
 *  Game
 *
 *  Created by Andrew Peddicord on 2/17/11.
 *  Copyright 2011 Capital University. All rights reserved.
 *
 */

#ifndef __LLISTITERATOR_H__
#define __LLISTITERATOR_H__

#include "LList.h"

/*
	LListIterator li;
    li.init(llist);
	Drawable *item;
	while ((item = li.next())) {
		// do something with item
		item = li.next();
	}
*/ 

class LListIterator {
	
public:
	LListIterator() {}
	
	void init(LList &list);
	Drawable* next();

private:
	LListIterator(const LListIterator&);
	ListNode *node;
};

inline LListIterator::init(LList &list) 
{
	node = list.head_;
}

inline Drawable* LListIterator::next()
{
	Drawable *item;
	if (node) {
		item = node->item_;
		node = node->next_;
		return item;
	}
	return NULL;
}


#endif