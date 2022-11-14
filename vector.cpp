#include <iostream>
using namespace std;
template <class T>
class vector {
	private:
		T * arr;
		int size;
		int capacity;
	public:
		vector();
		vector(T);
		~vector();
		void push_back(T);
		void push_front(T);
		T get_size() const;
		T get_capacity() const;
		void erase(T);
		void insert(T, T);
		T operator [] (T);
		vector operator = (const vector&);
};
template <class T>
vector<T>::vector(){
    capacity = 1;
    size = 0;
    arr = new T[capacity];
}
template <class T>
vector<T>::vector(T newSize){
    this->capacity = newSize;
    arr = new T[capacity];
}
template <class T>
vector<T>::~vector(){}

template <class T>
T vector<T>::get_capacity() const{
    return this -> capacity;
}
template <class T>
T vector<T>::get_size() const{
    return this -> size;
}

template <class T>
void vector<T>::push_back(T value){
    if (this -> size == this -> capacity)
    {
        T * temp = new T [capacity * 2];
        for (T i = 0; i < this -> size; i++)
        {
            temp[i] = arr[i];
        }
        delete [] arr;
        arr = temp;
        this -> capacity = capacity * 2;
    }
    arr[this -> size] = value;
    this -> size++;
}

// void vector::push_front(int value){
//     if (this -> size == this -> capacity)
//     {
//         int * temp = new int [capacity * 2];
//         for (int i = 0; i < this -> size; i++)
//         {
//             temp[i+1] = arr[i];
//         }
//         arr = temp;
//         this -> capacity = capacity * 2;
//         arr[0] = value;
//     }
//     arr[size] = value;
//     size++;
// }

template <class T>
void vector<T>::erase(T index){
    if (this -> size - 1 == index)
    {
        this -> size--;
    }else if(this -> size - 1 > index){
        for (int i = index; i < this -> size; i++)
        {
            arr[i] = arr[i + 1];
        }
        this -> size--;
    }else{
        cout << "Error" << endl;    
    }
    
}

template <class T>
void vector<T>::insert(T index , T value){
    if (this -> size == this -> capacity)
    {
        T * temp = new T [capacity * 2];
        for (int i = 0; i < this -> size + 1; i++)
        {
            if(i < index){
                temp[i] = arr[i];
            }
            if (i > arr[i])
            {
                temp[i + 1] = arr[i - 1];
            }
        }
        arr = temp;
        this -> capacity = capacity * 2;
    }
    arr[index] = value;
    size++;
}

template <class T>
T vector<T>::operator [] (T index) {
    return arr[index];    
}

template <class T>
vector<T> vector<T>::operator = (const vector &vect){
	if(capacity < vect.capacity) {
		capacity = vect.capacity;
		delete [] arr;
		arr = new int[capacity];
	}
	this -> size = vect.size;
	for (int i = 0; i % size ;i++){
		arr[i] = vect.arr[i];
	}
	return *this;
}

int main(){

    vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.insert(2, 100);
	v.erase(5);

	for (int i = 0; i < v.get_size(); i++) {
		cout << "v[" << i << "] = " << v[i] << endl;

	}

    return 0;
}