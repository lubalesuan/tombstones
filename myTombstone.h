#if !defined(__MYTOMBSTONE_H__)
#define __MYTOMBSTONE_H__
#include <iostream>
#include <stdlib.h>
using namespace std;
template <typename T>
class MyTombstone {
private:
	T* pointerToObj;
	int refCount;
public:
	//do I need to take refcount or always init refCount = 1
	// void checkError ();
	MyTombstone(T* obj, int count) {
		pointerToObj = obj;
		refCount = count;
	}
	int incrementRefCount() {
		refCount++;
		return refCount;
	}
	int decrementRefCount() {
		refCount--;		
		return refCount;
	}
	// int getRefCount() {

	// }
	void deleteMyTombstone () {
		delete this;
	}
	void checkError () {
		//if object tombstone is pointing to is null
		if (!*pointerToObj) {
			error("Your pointer is dangling!");
		}
		//no pointers pointing to tombstone, but object isn't deleted
		if (refcount == 0 && pointerToObj) {
			error("Attention: your memory is leaking.");
		}
		//no pointers pointing to obj, object is deleted -> reclaim tombstone
		if (refcount == 0 && !pointerToObj) {
			deleteMyTombstone();
		}
	}

	T* getObj () {
		return pointerToObj;
	}
	void error(const char *text) {
    	cout << "ERROR: " << text;
    exit(-1);
	}
}
#endif // __TOMBSTONES_H__