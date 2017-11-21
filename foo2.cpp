/////////////////////////////////////////////////////////////////////////////
// foo2.cpp, test file for CS254, assignment 5
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include "tombstones.h"

using namespace std;

void error(const char *text)
{
    cout << "error: " << text << endl;
    exit(-1);
}

int main(int argc, char **argv)
{
    Pointer<int> foo;
    cout << "befor = \n";
    foo = new int(12);
    cout << "after = \n";
    Pointer<int> bar(foo);

<<<<<<< HEAD
 //    if (bar == 0)
	// Error("Bar should not be null!");
 //    if (*bar != 12)
	// Error("Bar got the wrong value!");
 //    if (foo != bar)
	// Error("Foo and bar are NOT distinct pointers!");
 //    if (*foo != *bar)
	// Error("Foo and bar should have the same value here!");
 //    *foo = 15;
 //    if (*bar != 15)
	// Error("Bar should still match foo!");

 //    free(foo);
 //    free(bar);
 //    Error("Attempt to double-delete pointer not flagged!");
=======
    if (bar == 0)
	error("Bar should not be null!");
    if (*bar != 12)
	error("Bar got the wrong value!");
    if (foo != bar)
	error("Foo and bar are NOT distinct pointers!");
    if (*foo != *bar)
	error("Foo and bar should have the same value here!");
    *foo = 15;
    if (*bar != 15)
	error("Bar should still match foo!");

    free(foo);
    free(bar);
    error("Attempt to double-delete pointer not flagged!");
>>>>>>> 5b475a6a26ae1d84c49e9187265c8a2f97c80d98

    return 0;
    
}
