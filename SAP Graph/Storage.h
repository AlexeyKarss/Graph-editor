#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

template <class tmData>
class Node{
public:
	tmData* data;
	Node* next;
	Node* prev;

	Node(){
		data;
		next=prev=0;
	}
	Node(tmData* tmpd){
		data=tmpd;
		next=prev=0;
	}
	~Node(){}
};

template <class tmpData>
class Storage{
	Node<tmpData>* head;
	Node<tmpData>* tail;
	Node<tmpData>* current;
	int num;
	int cur_num;
public:
	tmpData* getObject(){
		//printf("Storage::getObject\n");
		if(current)
			return current->data;
		else
			return 0;
	}

	tmpData* getObject(int idx){
		if(idx<0) idx=0;		//Protection
		if(idx>=num) idx=num-1;	//Protection
		Node<tmpData>* cur=current; 
		int cur_i=cur_num;	

		first();
		for(int i=0; i<idx; ++i)
			next();
		Node<tmpData>* ret=current;

		current=cur;
		cur_num=cur_i;
		return ret->data;
	}

	int getIndex(tmpData* td){
		if(td==0)
			return -1;
		Node<tmpData>* cur=current; 
		int cur_i=cur_num;

		int idx=0;
		for(first();!eol();next())
			if(current->data==td)
				break;
			else
				++idx;

		current=cur;
		cur_num=cur_i;
		return idx;
	}

	void setObject(tmpData* td){
		current->data=td;
	}
	void first(){
		current=head;
		cur_num=0;
	}
	void last(){
		current=tail;
		cur_num=num;
	}
	bool eol(){
		//return current==tail;
		if(cur_num>=num)
			return true;
		return false;
	}
	void next(){
		if(current){
			current=current->next;
			cur_num++;
			if(cur_num>num) cur_num=0;
			//if(current==head) cur_num=0;
		}
	}
	void prev(){
		if(current){
		current=current->prev;
		cur_num--;
		if(cur_num<0) cur_num=num;
		}
	}
	int numOf(){
		return num;
	}
	bool isEmpty(){
		return num<=0?true:false;
	}
	int get_cur_i(){
		return cur_num;
	}

	void show(){
		if(num<=0){
			cout<<"Empty.";
			return;
		}
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		Node<tmpData>* tmp_cur = current;
		int tmp_i=cur_num;
		int idx=0;
		SetConsoleTextAttribute(handle, 7);
		for(first(); !eol(); next()){
			if(current==tmp_cur)
				SetConsoleTextAttribute(handle, 3);
			getObject()->Show(); cout<<" ";
			idx++;
			SetConsoleTextAttribute(handle, 7);
		}
	
		cur_num=tmp_i;
		current = tmp_cur;
	}


	void add(tmpData* tmd){ //Добавление элемента в конец
		//printf("Storage::add()\n");
		//printf("S:\nHead:%p\nTail:%p\n", head, tail);
		Node<tmpData>* tm=new Node<tmpData>(tmd);
		if(head==0){
			head=tail=tm;
			head->next=head->prev=tm;
			current=head;
			cur_num=0;
		}
		else{
			tm->prev=tail;
			tm->next=head;
			tail->next=tm;
			head->prev=tm;
			tail=tm;
			current=tail;
			cur_num=num;
		}
		//printf("E:\nHead:%p H>next:%p H>prev:%p\nTail:%p Tail>next:%p Tail>prev:%p\n\n", head, head->next, head->prev, tail, tail->next, tail->prev);

		num++;
	}
	void addTop(tmpData* tmd){ //Добавление в начало
		Node<tmpData>* tm=new Node<tmpData>(tmd);
		tail->next=tm;
		head->prev=tm;
		head=tm;
		if(tail==0)
			tail=tm;
		num++;
	}
	void insert(tmpData* tmd){ //Вставка на текущую позицию
		Node<tmpData>* tm=new Node<tmpData>(tmd);
		current->prev->next=tm;
		current->next->prev=tm;
		current=tm;
		if(head==0)
			head=tm;
		if(tail==0)
			tail=tm;
		num++;
	}
	void delCurrent(){ //Удаление текущего эл-та
		if(current){
			current->prev->next=current->next;
			current->next->prev=current->prev;
			Node<tmpData>* tm=current;
			current=tm->next;
			if(tm==head)
				head=tm->next;
			if(tm==tail)
				tail=tm->prev;
			delete tm;
			num--;
			if(num<=0)
				current=head=tail=0;
		}
	}

	Storage(){
		head=tail=current=0;
		num=0;
	}
};