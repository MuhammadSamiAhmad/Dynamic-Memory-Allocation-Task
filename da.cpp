#include "da.h"
#include <iostream>
using namespace std;
//declaring array attributes in the constructor.
My_DA::My_DA() {
    size = 0; capacity = 1;
    data = new int[capacity];
}
//recieving array from user with it's size.
//optimizing the capacity according to the size
//saving the array in a new one that is accessible in the rest of the functions to operate on them without removing his original one.
My_DA::My_DA(int arr[], int arr_size) {
    size = arr_size;
    if(size ==0){
        capacity=1;
    }
    else if(size%2==0){
        capacity=size;
    }
    else{
        capacity=(size-1)*2;
    }
    data = new int[capacity];
    for (int i = 0; i < size; i++)
    {
        data[i] = arr[i];
    }
}
//returns the value corresponding to the index the user wants.
int My_DA::get(int index) {
    return data[index];
}
//placing elements in the array from the end.
//increase the capacity according to the size by a factor of 2 because the size keeps increasing by increasing the input elements
//creating a new temporary array storing the user array till we increase it's capacity then transfer the data again to it.
void My_DA::push(int element) {
    if (size < capacity) {
        data[size] = element;
        size++;
    }
    else {
        capacity *= 2;
        int* old_data = data;
        data = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = old_data[i];
        }
        delete[] old_data;
        data[size]=element;
        size++;
    }
}
//delete last element in the array by decreasing the size 
//if the size is already 0 return -1 as an invalid operation.
//storing the last element in a variable before deleting to return it.
int My_DA::pop() {
    if (size == 0){
        return -1;
    }
    else{
        int x=data[size-1];
        size--;
        return x;
    }
}
//deleting a specific element in the array ,store it in a varaible first to return it.
/*i will over write the element by the element preceding it in the array till we have the same value in the last two locations
 then i will delete the last one to keep the order of the elements in the array after deleting that specifc element */
int My_DA::remove(int index) {
    if(index>(size-1)){
    return -1;
    }
    else{
        int y=data[index];
    for (int i = index; i < (size-1); i++)
    {
        data[i]=data[i+1];
    }
    size--;
    return y;
    }
}
//return the size of the array
int My_DA::get_size() {
    return size;
}
//return the capacity according to the size conditions below
int My_DA::get_capacity() {
    if (size == 0)
    {
        return 1;
    }   
        else if(size%2==0){
       return capacity=size*2;
    }
    else{
       return capacity=(size-1)*2;
    }
}
//inserting an element in a specific place in the array
//we will start shifting the elements from the specified index then replace the element in the array by the new one 
//if the specified index is bigger than the array capacity we will double the capacity as mentioned before then shift and place the element.
void My_DA::insert(int index, int element) {
  if(index < capacity){
        for (int i = index; i <= size; i++)
        {
            data[i+1]=data[i];
        }
        data[index]=element;
    }
    else{
        capacity *= 2;
        int* old_data = data;
        data = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = old_data[i];
        }
        delete[] old_data;
                for (int i = index; i <= size; i++)
        {
            data[i+1]=data[i];
        }
        data[index]=element;
    }
}
//printing the whole array elements
void My_DA::print() {
    for (int i = 0; i <= size; i++)
        cout << data[i] << "";
}
//deleting the whole array 
void My_DA::clear() {
    delete[]data;
}
//returns the index of the element by comparing the element with the array elements.
int My_DA::find(int element) {
    for (int i = 0; i < size; i++) {
    if (data[i] == element)
        return i;
}
    return -1;
}

// implement all the methods in da.h
// feel free to add new helper methods whether private or public