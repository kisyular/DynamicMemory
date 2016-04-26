#include<iostream>
using std::cout; using std::endl;
#include "class-10.h"

/*
 Edge cases we test here:

Cursor:
  Moving too far right
  Moving too far left
  Copying buffer when cursor is not on edge of buffer
Delete:
  Deleting when buffer is empty
  Deleting when too far left
Insert:
  Inserting when full
Left:
  All the way left
Right:
  All the way right
*/


int main(){
  TextBuffer tb(5);
  tb.insert('c');
  cout << "First c: "<< tb << endl<<endl;
  tb.insert('a');
  tb.insert('t');
  
  // This might cause some users to lose data depending on how they implemented the rule of 3.
 tb = tb;

  cout << "Cat: "<< tb << endl<<endl;
  tb.del();
  cout << "Del: " << tb << endl<<endl;
  tb.left();
  cout << "left 1: "<<tb << endl<<endl;
  tb.insert('r');
  cout << "add r: "<<tb << endl<<endl;
  tb.right();
  cout << "right 1: "<<tb << endl<<endl;
  tb.insert('t');
  cout << "insert t: "<<tb << endl<<endl;
  tb.left();
  tb.left();
  cout << "left 2: "<<tb << endl<<endl;
  tb.insert('e');
  cout << "grow: "<<tb << endl<<endl;
  tb.right();
  tb.right();
  tb.insert('e');
  cout << "Final: "<<tb << endl<<endl;   

  cout << "\nSTART new tests______\n\n" << endl;

  cout << "moving tb left 3 times. will print tb each time so you can see the cursor and back interacting" << endl;
  for (int i = 0; i < 3; i++){
    tb.left();
    cout << tb << endl;
  } cout << "DONE MOVING LEFT 3 times" << endl;
  cout << "tb after moving left 3 times: " << tb << endl;

  cout << "\nCopy tb and print the copy" << endl;
  TextBuffer one_copy(tb);
  cout << "carbon copy: " << one_copy << endl;

  cout << "\n inserting 6 i's" << endl;
  for (int i = 0; i < 6; i++) {
    tb.insert('i');
  }
  cout << "insert 6 i's: " << tb << endl;

  cout << "\ntesting copy constructor/ operator=/ swap/ chain assign " << endl;
  TextBuffer test, test2;
  test = test2 = tb;
  cout << test << endl;

  cout << "\ntesting direct copy constructor" << endl;
	TextBuffer new_guy(test);
	cout << "Copied new_guy: " << new_guy << endl;

  cout << "\nInsert 12 r's into new_guy" << endl;
	TextBuffer new_guy2(new_guy);
	for (int i = 0; i < 12; i++) {
		new_guy2.insert('r');
	}
	cout << "Afterinserting 12 r's: " << new_guy2 << endl;

  cout << "\nGo waaay left" << endl;
  for (int i = 0; i < 100; i++)
  	new_guy2.left();
	cout << "way Left: " << new_guy2 << endl;
	
  cout << "\nAttempting delete 10 times" << endl;
  for (int i = 0; i < 10; i++) 
    new_guy2.del();
  cout << "new_guy2 after 10 del's: " << new_guy2 << endl;

  cout << "\nGo waaaay right" << endl;
  for (int i = 0; i < 100; i++)
    new_guy2.right();
  cout << "new_guy2 after 100 right's: " << new_guy2 << endl;

  cout << "\n1000 del's" << endl;
  for (int i = 0; i < 1000; i++)
    new_guy2.del();
  cout << "new_guy2 after 1000 del's: " << new_guy2 << endl; 

  cout << "\nYou made it this far :D, good job\n " << endl;
  cout << "Go waaay left" << endl;
  for (int i = 0; i < 100; i++)
    new_guy2.left();
  cout << "way Left: " << new_guy2 << endl;  

  cout << "\nGo waaaay right" << endl;
  for (int i = 0; i < 100; i++)
    new_guy2.right();
  cout << "new_guy2 after 100 right's: " << new_guy2 << endl;


	cout << "\nReached end of code" << endl;

}
