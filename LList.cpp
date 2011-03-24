/*
 *  LList.cpp
 *  Game
 *
 *  Created by Andrew Peddicord on 2/17/11.
 *  Copyright 2011 Capital University. All rights reserved.
 *
 */

#include "LList.h"
#include "LListIterator.h"
//------------------------------------------------------------
LList::LList() {
	this->size_ = 0;
	this->head_ = NULL;
	this->tail_ = NULL;
}

LList::~LList() {
    ListNode *node = this->head_;
	ListNode *temp;
	int i;
	for (i=0; i<this->size_; ++i) {
		temp = node->next_;
		delete[] node;
		node = temp;
	}
}
//------------------------------------------------------------

LList::LList(const LList& source) {
	LListIterator it;
	it.init(source);
	Drawable* item;
	while ((item = it.next())) {
		this->append(item);
	}
}

//------------------------------------------------------------
void LList::removeFirst(Drawable *&item) {
	ListNode *node;
	if (this->size_ > 0) {
		item = this->head_->item_;
		if (this->size_ > 1) {
			node = this->head_;
			head_ = this->head_->next_;
			delete node;
		} else {
			delete this->head_;
			this->head_ = NULL;
			this->tail_ = NULL;
		}
		size_--;
	}
}
//------------------------------------------------------------
void LList::append(Drawable *item){
	ListNode *temp = new ListNode();
	temp->item_ = item;
	
	if (this->size_ == 0) {
		this->head_ = temp;
		this->tail_ = temp;
	} else {
		tail_->next_ = temp;
	}
	size_++;
}
//------------------------------------------------------------
Drawable* LList::first() const {
	return head_->item_;
}
//------------------------------------------------------------
void LList::removeDrawable(Drawable *obj) {
	int i;
	Drawable *temp;
	ListNode *prenode;
	ListNode *node = this->head_;
	for (i = 0; i<(this->size_); i++) {
		if (node->item_ == obj) {
			break;
		}
		prenode = node;
		node = node->next_;
	}
	if (i == 0) {
		removeFirst(temp);
		return;
	} else if (i == ((this->size_) - 1)) {
		delete this->tail_;
		this->tail_ = prenode;
		prenode->next_ = NULL;
	} else {
		prenode->next_ = node->next_;
		delete node;
	}
	delete node;
	size_--;
}
//------------------------------------------------------------
LList& LList::operator=(const LList &list) {
	int i;
	LList *temp = new LList();
	ListNode *node = this->head_;
	for (i = 0; i<(this->size_); i++) {
		temp->append(node->item_);
		node = node->next_;
	}
	return *temp;
}