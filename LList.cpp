/*
 *  LList.cpp
 *  Game
 *
 *  Created by Andrew Peddicord on 2/17/11.
 *  Copyright 2011 Capital University. All rights reserved.
 *
 */

#include "LList.h"
//------------------------------------------------------------
LList::LList() {
	this->size = 0;
}
//------------------------------------------------------------
void LList::removeFirst(Drawable *&item) {
	if (this->size > 0) {
		item = this->head->item_;
		if (this->size > 1) {
			head = this->head->next_;
		} else {
			delete this->head;
		}
		size --;
	}
}
//------------------------------------------------------------
void LList::append(Drawable *&item){
	ListNode *temp = new ListNode();
	temp->item_ = item;
	
	if (this->size == 0) {
		this->head = temp;
		this->tail = temp;
	} else {
		tail->next_ = temp;
	}
	size++;
}
//------------------------------------------------------------
void LList::first(Drawable *&item){
	item = head->item_;
}
//------------------------------------------------------------
void LList::removeDrawable(Drawable *obj) {
	int i;
	ListNode *prenode;
	ListNode *node = this->head;
	for (i = 0; i<(this->size); i++) {
		if (node->item_ == obj) {
			break;
		}
		prenode = node;
		node = node->next_;
	}
	
	size--;
}
//------------------------------------------------------------
LList& LList::operator=(const LList &list) {
	int i;
	LList *temp = new LList();
	ListNode *node = this->head;
	for (i = 0; i<(this->size); i++) {
		temp->append(node->item_);
		node = node->next_;
	}
	return *temp;
}