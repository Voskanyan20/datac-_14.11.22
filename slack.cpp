#include <iostream>
using namespace std;
#define SIZE 16
template <class T>
class stack{
	private:
		int capacity;
		int size;
		T arr[SIZE];
	public:
		stack();
		~stack();
		stack(const stack&);
		void push(T);
		void pop();
		T top();
		bool isEmpty() const;
		bool isFull() const;
};
template <class T>
stack<T>::stack(){
	capacity = SIZE;
	size = 0;
}
template <class T>
stack<T>::~stack()
{
    // delete [] arr;
}
template <class T>
void stack<T>::push(T value){
	arr[size] = value;
	size++;
}
template <class T>
void stack<T>::pop(){
	size--;	
}
template <class T>
T stack<T>::top(){
	return arr[size - 1];	
}
template <class T>
bool stack<T>::isEmpty() const 
{
	return size == 0;
}
template <class T>
bool stack<T>::isFull() const 
{
	return size == capacity;
}

int main (){
	stack<int> s;
	for (int i = 0;i < 16 ;i++){
		s.push(i);
        //cout << "push count = " << i << endl;
	} 
	 while (!s.isEmpty()){
	 	cout << s.top() << endl;
	 	s.pop();
	 }
    return 0;
}
