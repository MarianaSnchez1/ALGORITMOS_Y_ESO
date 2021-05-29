#include "simple_vector.hpp"

//---------------- CLASS BidirIterator METHODS ------------------
// Constructor
BidirIterator::BidirIterator(double *beg){
    ptr = beg;
}

// Copy constructor
BidirIterator::BidirIterator(const BidirIterator & it){
    ptr = it.ptr;
}

// deference operator
double &BidirIterator::operator*(){
    return  *ptr;
}

//////////////////////////////////////////////////////////////

//prefix/postfix operators
BidirIterator &BidirIterator::operator++(){ //operador it++
    ++ptr;
    return *this; 
}

BidirIterator BidirIterator::operator++(int){ //operador ++it
    BidirIterator tmp = *this;
    ptr++;
    return tmp;
}

BidirIterator &BidirIterator::operator--(){ //operador it--
    --ptr;
    return *this;
}

BidirIterator BidirIterator::operator--(int){ //operador --it
    BidirIterator tmp = *this;
    ptr--;
    return tmp;
}

////////////////////////////////////////////////////////////////

// assigment operator
void BidirIterator::operator=(BidirIterator it){
    ptr = it.ptr;
}

// comparison operators
bool BidirIterator::operator==(BidirIterator it){
    return (ptr == it.ptr);
}

bool BidirIterator::operator!=(BidirIterator it){
    return (ptr != it.ptr);
}

//------------CLASS SimpleVec METHODS -------------//
// Iterator and related methods

SimpleVec::iterator SimpleVec::begin(){
    return iterator(array); // primera posición.
}

SimpleVec::iterator SimpleVec::end(){
    return iterator(array + length); // última posición.
}

//-------------------------------------------------//
// Constructors
SimpleVec::SimpleVec() : capacity(INITIAL_CAPACITY), length(0) {
    array = new double[capacity];
}

SimpleVec::SimpleVec(const SimpleVec& rhs) {
    capacity = rhs.capacity;
    length = rhs.length;
    array = new double[capacity];
    for(int i = 0; i < length; ++i)
        array[i] = rhs.array[i];
}

// Destructor
SimpleVec::~SimpleVec() {
    delete[] array;
}

// Assignment operator
SimpleVec & SimpleVec::operator=(const SimpleVec& rhs) {
    delete[] array;
    capacity = rhs.capacity;
    length = rhs.length;
    array = new double[capacity];
    for(int i = 0; i < length; ++i)
        array[i] = rhs.array[i];

    return *this;
}

// Other SimpleVec methods
void SimpleVec::push(double value) {
    if(length == capacity) expandCapacity();
    array[length++] = value;
}

void SimpleVec::erase(int index) {
    for(int i = index; i < length-1; ++i)
        array[i] = array[i+1];
    length--;
}

void SimpleVec::insert(int index, double value) {
    if(length == capacity) expandCapacity();
    for(int i = length-1; i > index; --i)
        array[i] = array[i-1];
    array[index] = value;
    length++;
}

void SimpleVec::modify(int index, double value) {
    array[index] = value;
}

double SimpleVec::retrieve(int index) {
    return array[index];
}

void SimpleVec::expandCapacity() {
    double *oldArray = array;
    capacity *= 2;
    array = new double[capacity];
    for(int i = 0; i < length; ++i)
        array[i] = oldArray[i];
    delete[] oldArray;
}

void SimpleVec::clear() {
    length = 0;
}

bool SimpleVec::empty() {
    return length == 0;
}

int SimpleVec::size() {
    return length;
}
