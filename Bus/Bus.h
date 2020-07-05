#pragma once
#include<iostream>
#include<string>
#include<list>

using namespace std;



class Bus {
	int numberBus;
	string nameDriver;
	int numberReis;

public:
    Bus() = default;
    Bus(const int& numberBus, const string& nameDriver, const int& numberReis) {
		setNumberBus(numberBus);
        setNameDriver(nameDriver);
		setNumberReis(numberReis);

	}
    void setNumberBus(const int& numberBus) {

		this->numberBus = numberBus;

	}

	void setNameDriver(const string& nameVodiy) {

		this->nameDriver = nameVodiy;

	}

	void setNumberReis(const int& numberReis) {

		this->numberReis = numberReis;

	}

	int getNumberBus() {

		return numberBus;

	}

	string getNameDriver() {

		return nameDriver;

	}

	int getNumberReis() {

		return numberReis;

	}

};
struct Node {
    Bus data;
	Node* next;

};

class BusList {

public:

	BusList() = default;
	BusList(const BusList& tmpp) :head(0), tail(0), size(0) {

		Node* tmp = tmpp.head;
		this->addBus(tmp->data.getNumberBus(), tmp->data.getNameDriver(), tmp->data.getNumberReis());

		tmp = tmp->next;

	}

	bool isEmpty()const;
    void addBus(const int& numberbus, const string& namevodiy, const int& numberReis);
    void print()const;
    Node* getNode(size_t number) {
        if (head->data.getNumberBus() == number) {

			Node* tmp = head;
			head = head->next;
            return tmp;

		}

		else {

			Node* tmp = head;
            Node* prev = head;
			while (tmp != nullptr && tmp->data.getNumberBus() != number)
			{
             	prev = tmp;
            	tmp = tmp->next;

			}
            prev->next = tmp->next;
            return tmp;

		}

	}

	void addNode(Node* node) {

		node->next = head;
		head = node;
	}

	void delHead() {

		if (isEmpty())
			return;

		auto del = head;
		head = head->next;
		if (head == nullptr) {

			tail = nullptr;

		}
       delete del;
	   --size;

	}

	void deleteAutoPark() {

		while (size) {
            delHead();

		}

	}
    void deleteIndex();
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	size_t size = 0;

};

class AutoPark
{
private:
	BusList route;
	BusList park;
public:
	void payBus(Bus& buss) {
		park.addBus(buss.getNumberBus(), buss.getNameDriver(), buss.getNumberReis());
	}
	void printRoute() {
		cout << "Bus route " << endl;
		route.print();
	}
	void printPark() {
		cout << "Bus park" << endl;
		park.print();
	}
	void goRoute() {
		if (park.isEmpty()) {
			return;
		}
		else {
			int numb;
			cout << "Enter number bus go to route" << endl;
			cin >> numb;
			Node* tmp = park.getNode(numb);
			route.addNode(tmp);

		}

	}

	void goPark() {

		if (route.isEmpty()) {
			return;
		}
		int numb;
		cout << "Enter numb bus go to park" << endl;
		cin >> numb;
		Node* tmp = route.getNode(numb);
		park.addNode(tmp);

	}

	void selBus() {
		park.deleteIndex();
	}



};
inline bool BusList::isEmpty() const
{
	return head == nullptr;
}
inline void BusList::addBus(const int& numberbus, const string& namevodiy, const int& numberReis)
{
	auto newNode = new Node{ Bus(numberbus,namevodiy,numberReis),nullptr };
	if (isEmpty()) {
		head = tail = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
	++size;

}
inline void BusList::print() const

{
	Node* tmp = head;

	while (tmp != nullptr) {
        cout << "Number bus >> " << tmp->data.getNumberBus() << endl;
		cout << "Name vodiy >>" << tmp->data.getNameDriver() << endl;
		cout << "Number reis >>" << tmp->data.getNumberReis() << endl;
		cout << "_________________" << endl;
		tmp = tmp->next;
	}
	cout << endl;



}
inline void BusList::deleteIndex()
{
	int index;
	cout << "enter index bus in delete" << endl;
	cin >> index;
	if (index == 0) {
		delHead();
	}
	else {
		Node* tmp = this->head;
		for (int i = 0; i < index - 1; i++) {
			tmp = tmp->next;
		}
		Node* dell = tmp->next;
		tmp->next = dell->next;
		delete dell;
		size--;
	}

}

