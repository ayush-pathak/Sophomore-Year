#include <stdexcept>
#include <iostream>
using namespace std;

/** The vector class
 * based on implementation from chapter 6 of textbook
 */
template <typename Object>
class Vector {
  
private:
  


  int _capacity;	//current maximum capacity
  int _size;		//number of elements in vector currently
  Object * _data;	//array to store the vector
   
public:
  
  //constructor
  Vector(int cap=100) : _capacity(cap), _size(0), _data(new Object[_capacity]) {}
  
  //destructor
  ~Vector() {
    delete[] _data;
  }

  /* function to insert and shift the rest of the list down
  *  input: an int which is the index of where to insert
            the data to insert into the vector */  
  void insert(int index, const Object& element) {
    //check if out of bounds and throw an error
    if ((index < 0) || (index > _size))
      throw domain_error("index is out of bounds");
    
    //check if full, and expand the array if so, inserting the new element
    if (_size==_capacity) {
      //cout << "resizing array" << endl;
      Object* temp = new Object[2*_capacity];
      for (int i=0; i<index; i++)
	temp[i] = _data[i];
      temp[index] = element;
      for (int i = index+1; i <= _size; i++)
	temp[i] = _data[i-1];
      delete[] _data;
      _size++;
      _capacity*=2;
      _data = temp;
    } //end if
    
    else {
      //there is room, so insert the new element
      for (int i = _size; i > index; i--)
	_data[i] = _data[i-1];
      _data[index]=element;
      _size++;
    }
    
  } //end of insert function

  /*  function to return the current size of the vector */  
  int size() const {
   return _size; 
  }
  
  /*  function to return true if the vector is empty (regardless of capacity) */
  bool empty() const {
    return _size == 0;
  }
  
  /*  function to allow access to arbitrary elements in the vector
   *  input: an index of an element in the array
   *  output: a reference to that object  */
  Object& operator[](int index) {
    if ((index >= _size) || (index < 0))
      throw domain_error("index is out of bounds");
    
    return _data[index];
  }
  
  /* function to delete an element of the vector, and shift the rest down
   * input: a valid index of an element in the vector */
  void erase(int index) {
    
    //check index is valid
    if ((index >= _size) || (index < 0))
      throw domain_error("index out of bounds");
    
    for (int i = index; i < _size-1; i++)
      _data[i]=_data[i+1];
    _size--;
    
    //Homework: shrink if less than half full
    if(_size < _capacity/4){
      Object* temp = new Object[_capacity/2];   //allocate a new array
      for(int i=0; i!=_size; i++){
	temp[i]=_data[i];                       //populate the temp array with data
      }
      _capacity= _capacity/2;                   //upadate the capacity variable
      delete[] _data;                           //deallocate the old array
      _data = temp;                             //set _data equal to the new array
    }
  }

  void remove(Object val){
    int i =0;                                  //start looking at the beginning of vector
    while(_data[i]!=val && i!= _size){         //and make sure i never goes above size
      i++;
    }
    if(i==_size){			       //if i is the same as size then val is not in vector
      cout<<"value not found"<<endl;
    }
    else{
      erase(i);                                //otherwise i is the index where val is and use erase to remove and reduce the size
    }
  }

  void replace(Object val1, Object val2){      
    for( int i =0; i!=_size; i++){             //loop through the whole vector 
      if(_data[i]==val1){                      //if the index has val1 then replace it with val2
	_data[i]=val2;
       }
     }
  }  
  
  void reverse(){
    Object* temp = new Object[_capacity];      //allocate a new array
    int j = 0;                                 //holder for the index of the new array
    for(int i= _size-1; i!=-1;i--){            //start from the end of the current array
       temp[j]=_data[i];                       //end of the current array is the start of new array
       j++;                                    //move the index over
    }
    delete[] _data;                            //deallocate the current array
    _data = temp;
  }

  void push_back(Object e) {
    insert(_size,e);
  }
  
  void pop_back() {
    erase(_size-1);
  }  

  
  //copy constructor
  Vector(const Vector& other) {
    _capacity = other._capacity;
    _size = other._size;
    
    //make a deep copy of the data in array
    _data = new Object[_capacity];
    for (int i =0; i<_size; i++)
      _data[i] = other._data[i];
  }
  
  //operator=
  Vector& operator=(const Vector& other) {
    if (this != &other) {
      
      //deallocate my array
      delete[] _data;

      //make a deep copy of other
      _capacity = other._capacity;
      _size = other._size;
      
      _data = new Object[_capacity];
      for (int i = 0; i < _size; i++)
	_data[i] = other._data[i];
      
    }
    return *this;
  }
  
  
};
