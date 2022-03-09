    /**
               .•° ✿ °•.
         created on 19-mar-2021
            @author: andreea
               °•. ✿ .•°
    */

#ifndef A45_912_BUIGA_ANDREEA_DYNAMIC_ARRAY_H
#define A45_912_BUIGA_ANDREEA_DYNAMIC_ARRAY_H

#include <cstdlib>

template<class TElem>
class DynamicArray {
private:
    TElem *elems;
    int size{};
    int max_capacity{};
public:
    /*
     * Dynamic array constructor
     */
    explicit DynamicArray(int max_capacity = 10);
    /*
     * Dynamic array copy-constructor
     */
    DynamicArray(const DynamicArray<TElem> &dyn_array);
    /*
     * Dynamic array destructor
     */
    ~DynamicArray();

    /*
     * getter for the size of the dynamic array
     */
    int get_size();
    /*
     * overwriting the = operator
     */
    DynamicArray &operator=(const DynamicArray<TElem> &dyn_array);
    /*
     * overwriting the [] operator
     * getting an item from a certain position
     */
    TElem &operator[](int position);
    /*
     * adding a new element to the dynamic array
     */
    void add_element(const TElem &element);
    /*
     * removing an element from the dynamic array
     */
    void remove_element(int position);
private:
    /*
     * resizing the dynamic array (when the size gets to the max capacity)
     */
    void resize(double factor = 2);
};

template<class TElem>
DynamicArray<TElem>::DynamicArray(int max_capacity) {
    /*
     * Dynamic array constructor
     */
    this->size = 0;
    this->max_capacity = max_capacity;
    this->elems = new TElem[max_capacity];
}

template<class TElem>
DynamicArray<TElem>::DynamicArray(const DynamicArray<TElem> &dyn_array) {
    /*
     * Dynamic array copy-constructor
     */
    this->size = dyn_array.size;
    this->max_capacity = dyn_array.max_capacity;
    this->elems = new TElem[this->max_capacity];
    int i;
    for(i = 0; i < this->size; i++)
        this->elems[i] = dyn_array.elems[i];
}

template<class TElem>
DynamicArray<TElem>::~DynamicArray() {
    /*
     * Dynamic array destructor
     */
    delete[] this->elems;
}

template<class TElem>
int DynamicArray<TElem>::get_size() {
    /*
     * getter for the size of the dynamic array
     */
    return this->size;
}

template<class TElem>
DynamicArray<TElem>&DynamicArray<TElem>::operator=(const DynamicArray &dyn_array) {
    /*
     * overwriting the = operator
     */
    /*if(this == &dyn_array)
        return *this;*/

    this->size = dyn_array.size;
    this->max_capacity = dyn_array.max_capacity;
    delete[] this->elems;
    this->elems = new TElem[this->max_capacity];
    int i;
    for(i = 0; i < this->size; i++)
        this->elems[i] = dyn_array.elems[i];

    return *this;
}

template<class TElem>
TElem& DynamicArray<TElem>::operator[](int position) {
    /*
     * overwriting the [] operator
     * getting an item from a certain position
     */
    return this->elems[position];
}

template<class TElem>
void DynamicArray<TElem>::resize(double factor) {
    /*
     * resizing the dynamic array (when the size gets to the max capacity)
     */
    this->max_capacity = this->max_capacity * factor;
    auto *new_elems = new TElem[this->max_capacity];
    int i;
    for(i = 0; i < this->size; i++)
        new_elems[i] = this->elems[i];
    delete[] this->elems;
    this->elems = new_elems;
}

template<class TElem>
void DynamicArray<TElem>::add_element(const TElem &element) {
    /*
     * adding a new element to the dynamic array
     */
    if(this->size == this->max_capacity)
        this->resize();
    this->elems[this->size] = element;
    this->size = this->size + 1;
}

template<class TElem>
void DynamicArray<TElem>::remove_element(int position) {
    /*
     * removing an element from the dynamic array
     */
    int i;
    for(i = position; i < this->size - 1; i++)
        this->elems[i] = this->elems[i + 1];
    this->size = this->size - 1;
}

#endif //A45_912_BUIGA_ANDREEA_DYNAMIC_ARRAY_H
