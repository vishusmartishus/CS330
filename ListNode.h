/*
 *  ListNode.h
 *  Game
 *
 *  Created by Andrew Peddicord on 2/17/11.
 *  Copyright 2011 Capital University. All rights reserved.
 *
 */

#ifndef __LISTNODE_H__
#define __LISTNODE_H__

#include "Drawable.h";
#include "iostream"

class ListNode {
public:
	ListNode() { next_ = NULL; }
	~ListNode();
	Drawable *item_;
	ListNode *next_;
};

inline ListNode::~ListNode() {
	delete item_;
}

#endif