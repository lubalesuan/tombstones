/////////////////////////////////////////////////////////////////////////////
// tombstones.h, expected interface for CS254 assignment 5
/////////////////////////////////////////////////////////////////////////////

#if !defined(__TOMBSTONES_H__)
#define __TOMBSTONES_H__
 #include "myTombstone.h"
template <class T> class Pointer;
template <class T> void free(Pointer<T>& obj);

template <class T>
class Pointer {
public:
    Pointer<T>();
         // default constructor
        //init self???
                                 
    // Pointer<T>(Pointer<T>& otherPointer);
    Pointer<T>(Pointer<T>& otherPointer) {
        t = otherPointer.t;
        t.incrementRefCount();
    }
    Pointer<T>(T* object) {// bootstrapping constructor, argument should always be a call to new
        t.setMyTombstone(object, 1);
    }
        //if pointer was pointed to some object x2 before, and x2 wasn't deleted
        //do I throw error here???
                              
    ~Pointer<T>();                              // destructor
    T& operator*() const; 
       // return (t->pointerToObj)&; //CHECK
                  // deferencing
    T* operator->() const ;
      //  return t->pointerToObj; //CHECK
                      // field dereferencing
    Pointer<T>& operator=(const Pointer<T>& otherPointer) { // assignment
        t = otherPointer.t;
        t.incrementRefCount();
    }       
    friend void free<T>(Pointer<T>&);           // delete pointed-at object
    T& operator*() const {
        return (t->pointerToObj)&; //CHECK
    }                // deferencing
    T* operator->() const {
        return t->pointerToObj; //CHECK
    }                  // field dereferencing
    Pointer<T>& operator=(const Pointer<T>& otherPointer) {
        this->t = otherPointer->t; //does it assign same object to this pointer?
    }       // assignment
    friend void free<T>(Pointer<T>&)
    {
        this->t = NULL;
        ~Pointer<T>();  
    }           // delete pointed-at object
        // This is essentially the inverse of the new inside the call to
        // the bootstrapping constructor.
    //free deletes the tombstone and object and pointer
    // equality comparisons:
    bool operator==(const Pointer<T>& otherPointer) const;
    //     if (t == otherPointer->t) return true;
    //     else return false;
    // }
    bool operator!=(const Pointer<T>& otherPointer) const;
    //     if (t == otherPointer->t) return false;
    //     else return true;
    // }
    bool operator==(const int refInt) const;
    //     if (this->t == NULL && refInt == 0) return true;
    //     else return false;
    // }
    //     // true iff Pointer is null and int is zero
    bool operator!=(const int refInt) const;
    //     if (this->t == NULL && refInt == 0) return false;
    //     else return true;
    // }
    //     // false iff Pointer is null and int is zero
private:
MyTombstone <T> t;
};
#endif // __TOMBSTONES_H__