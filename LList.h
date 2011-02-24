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

#include "ListNode.h";
#include "Drawable.h";

class LList {
public:
	LList();
	
	void removeFirst(Drawable *&item);
	
	void append(Drawable *&item);
	
	void first(Drawable *&item);
	
	void removeDrawable(Drawable *obj);
	
	LList& operator=(const LList &list);
	
private:
	ListNode *head;
	ListNode *tail;
	int size;
	
};

#endif
	
