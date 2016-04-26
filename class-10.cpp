/*
2016-04-10
class-10.cpp
Your Comments
*/
#include <iostream>
using std::cout; using std::endl; using std::ostream; using std::stol;
#include <vector>
using std::vector;
#include <algorithm>
using std::transform; using std:: copy;
#include <iterator>
using std::ostream_iterator;
#include <sstream>
using std::ostringstream;
#include <string>
using std::string;
#include<random>
using std::default_random_engine;
using std::uniform_int_distribution;
#include "class-10.h"
#include <map>
using std ::map; using std::make_pair; using std:: pair;

//constructor
TextBuffer::TextBuffer(size_t size){
	size_ = 0;
	capacity_ = size;
	back_ = capacity_-1;
	cursor_ = 0;
	buf_=new char[capacity_];
	}
TextBuffer::TextBuffer(TextBuffer& buffer_){
	size_ = buffer_.size_;
	capacity_ = buffer_.capacity_;
	back_ = buffer_.back_;
	cursor_ = buffer_.cursor_;
	buf_=new char[capacity_];
	copy(buffer_.buf_, buffer_.buf_+buffer_.capacity_, buf_);
}
//Destructor - delete the buf_ memory
TextBuffer:: ~TextBuffer(){
		delete [] buf_;
}
TextBuffer& TextBuffer::operator=(TextBuffer s){
	swap(s);
    return *this;
}

void TextBuffer::grow(){
	//create new buffer with capacity * 2
	char  *bufNew;
	bufNew = new char [capacity_ * 2];
	size_t off_set = (capacity_ -back_); //the value of capacity minus the back
	size_t backNew = capacity_*2-off_set;//create new back
	
	//copy everything from buffer to position of cursor
	copy(buf_, buf_+cursor_, bufNew);
	
	//copy from back to the end of the buffer, this will take care of the gap
	copy( buf_ + back_ +1, buf_+capacity_ , bufNew+backNew +1 );
	
	//swap  buf_ with bufNew
    std::swap(buf_, bufNew);
	capacity_ =(capacity_ * 2);
	//assign the back_ to backNew and then delete the new buffer
	back_ =backNew;
	delete [] bufNew;
}
void TextBuffer::swap(TextBuffer& bufSwap){
	//swap data member of buf_ with bufSwap
    std::swap (size_, bufSwap.size_);
    std::swap (capacity_, bufSwap.capacity_);
    std::swap (back_, bufSwap.back_);
    std::swap (cursor_, bufSwap.cursor_);
}

bool TextBuffer:: isfull(){
	//the buffer is full if cursor is at the back position
	if( cursor_==back_){
		return true;
	}else{
		return false;
	}
}

bool TextBuffer:: isempty(){
	//if buffer is empty, the size is 0
	if (size_ == 0){
		return true;
	}else{
		return false;
	}
}

void TextBuffer:: insert(char chr){
	//check if the buffer is full, if so call grow function and then insert the character
	if (isfull()){
		cout<<"buf_ full calling the grow() function"<<endl;
		grow();
		buf_[cursor_] = chr;
		cursor_ +=1;
		size_+=1;
	}else{
		buf_[cursor_] = chr;
		cursor_ +=1;
		size_+=1;
	}
}

bool TextBuffer:: del(){
	//delete the character by moving cursor backwards one position
	if (cursor_==0){
		return false;
	}else{
		cursor_-=1;
		buf_[cursor_] = buf_[cursor_];
		size_--;
		return true;
	}
}
bool TextBuffer:: left(){
	//move cursor one position backwards by subtractiiong one to cursor_
	if (cursor_==0){
		return false;
	}else{
		cursor_ -=1;
		buf_[back_] = buf_[cursor_];
		back_ -=1;
		return true;
	}
}

bool TextBuffer:: right(){
	//move cursor one position forward by adding one to cursor_
	if (cursor_==capacity_){
		return false;
	}else{
		back_ +=1;
		buf_[cursor_] = buf_[back_];
		cursor_ +=1;		
		return true;
	}
}

ostream& operator<<(ostream& out, TextBuffer &tb){
	//first print the size, capaciity, cursor and back position
		out<<"sz:"<<tb.size_<<", "<<"cap:"<<tb.capacity_<<", "<<"cur:"<<tb.cursor_<<
		", "<<"bac:"<<tb.back_<<endl;
		
	//print everything in  the buffer separated by comma
	for (unsigned j =0;  j< tb.capacity_ ; j++){
		out<<tb.buf_[j] <<", ";
		}
		out<<endl;
	//print everything in  the buffer till the cursor_ position
	for (unsigned k = 0; k <tb.cursor_ ; k++){
		out<<tb.buf_[k];
	}
	out<<"|";
	//print everything in  the buffer after the cursor_ position till the end
	for (unsigned k = tb.back_+1; k <tb.capacity_ +1; k++){
		out<<tb.buf_[k];
	}
	return out;
}


