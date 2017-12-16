#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

template <typename T>
class linked;

class Car{
	private:
	string color;
	public:
	void setColor(const string a){
		//a = a+"hahahahahahah";
		color = a;
	}
	string getColor(){
		return color;
	}
};

template <typename T>
class node{
	private:
	T value;
	node<T> *next;
	friend class linked<T>;
};

template <typename T>
class linked{
	public:
	linked();
	~linked();
	bool empty() const;
	void addtolist(const T& e);
	T getElem(int i) const;   // first const used so return type is a constant reference, 2nd const means it can't modify any member of the class
	private:
	node<T> *head;
};

template <typename T>
linked<T>::linked(){
	head = NULL;
}

template <typename T>
linked<T>::~linked(){
	// WHAT TO DO HERE
}

template <typename T>
bool linked<T>::empty() const{
	if (head==NULL)
		return true;
}

template <typename T>
void linked<T>::addtolist(const T& e){
	node<T> *temp = new node<T>;
	temp->value = e;
	temp->next = head;
	head = temp;
}

template <typename T>
T linked<T>::getElem(int i) const{  // no need to put its return type as const because the next/urrent is private. btw it shows an error on assigning return type as constant.
	node<T> *current = head;
	int count = 1;
	while (current != NULL)
    {
       if (count == i)
          return current->value;
       count++;
       current = current->next;
    }
}

int main(){
	Car car1;
	car1.setColor("RED");
	linked<Car> list1;
	Car& car2 = car1;
	Car car3;
	car3.setColor("BLACK");
	Car& car4 = car3;
	list1.addtolist(car2);
	list1.addtolist(car4);
	cout << (list1.getElem(2)).getColor() << endl;
	return 0;
}
