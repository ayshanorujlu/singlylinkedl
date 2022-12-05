#include<iostream>
using namespace std;

class Node {
public:
	string data;
	Node* next;
	Node(const string& data) : data(data), next(nullptr) {}
};

class SinglyLinkedList {
	Node* head = nullptr;
public:
	void AddBegin(const string& val) {
		Node* newNode = new Node(val);
		newNode->next = head;
		head = newNode;
	}
	void AddEnd(const string& val) {
		Node* newNode = new Node(val);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
		temp = nullptr;
	}
	void DeleteBegin() {
		if (head != nullptr) {
			Node*temp = head;
			while (temp->next->next != nullptr) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = nullptr;
		}
	}

	void Print() {
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void AddBefore(const string& x, const string& val) {
		Node* newNode = new Node(val);
		if (head != nullptr) {
			Node* temp = head;
			if (x == head->data)
			{
				AddBegin(val);
				return;
			}
			while (temp->next->data != x) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
	void AddAfter(const string& x, const string& val) {
		Node* newNode = new Node(val);
		if (head != nullptr) {
			Node* temp = head;
			while (temp->data != x) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
		void DeleteByvalue(const string & val) {
			Node* temp = head;
			Node* prev = nullptr;
			if (head->data == val) {
				head = temp->next;
				delete temp;
				return;
			}
			while (temp->data != val) {
				prev = temp;
				temp = temp->next;
			}
			prev->next = temp->next;
			delete temp;
		}
};
//Elnura,Ayshan,Sarxan,Elchin
void main() {
	SinglyLinkedList s;
	s.AddBegin("Elchin");
	s.AddBegin("Sarxan");
	s.AddBegin("Ayshan");
	s.AddBegin("Elnura");
	s.DeleteByvalue("Elchin");
	s.Print();
}