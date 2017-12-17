/*************************************************************************
> File Name: main.cpp
> Author: Triose
> Mail: Triose@163.com
> Created Time: 2016/3/30 星期三 下午 1:37:53
************************************************************************/


#include<iostream>
#include<string>
#include<fstream>
using namespace std;

/* Define of ListElmt. */
template<class T>
class ListElmt {
public:
	T data;
	ListElmt * next;
	ListElmt * prev;
	ListElmt(T data_) {
		this->data = data_;
		next = NULL;
		prev = NULL;
	}
};

template<class T> T Max(T a, T b) { return a > b ? a : b; }

/* Public Interface. */
#define List_size(l) ((l)->size)
#define List_head(l) ((l)->head)
#define List_tail(l) ((l)->tail)


/* Define of My_list. */
template<class T>
class My_list {
public:
	ListElmt<T> *head;
	ListElmt<T> *tail;
	int size;
	double max_price;
};

/* List_init. */
template<class T>
void List_init(My_list<T> *l) {
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	l->max_price = -1.0;
	return;
}

/* List_destroy. */
template<class T>
void List_destroy(My_list<T> *l) {
	while (List_size(l)) {
		List_rem(l, 0);
	}
	return;
}

/* List_ins. */
template<class T>
int List_ins(My_list<T> * l, int pos, ListElmt<T> *newelement) {
    pos--;
    if(!(l->size) && pos) {
        return -1;
    }
    if(!pos) {
        newelement->next = l->head;
        if(l->size) {
            l->head->prev = newelement;
        }
        l->head = newelement;
        if(pos == l->size) {
            l->tail = newelement;
        }
        l->size++;
        l->max_price = Max(l->max_price, newelement->data->price);
        return 0;
    }
    ListElmt<T> *current_elmt = l->head;
    int count = 0;
    while(count < pos - 1 && current_elmt->next) {
        count++;
        current_elmt = current_elmt->next;
    }
    if(count == pos - 1) {
        newelement->next = current_elmt->next;
        newelement->prev = current_elmt;
        if(current_elmt->next) {
            current_elmt->next->prev = newelement;
        }
        current_elmt->next = newelement;
        if(pos == l->size) {
            l->tail = newelement;
        }
        l->size++;
        l->max_price = Max(l->max_price, newelement->data->price);
        return 0;
    }
    return -1;
}

/* List_rem. */
template<class T>
int List_rem(My_list<T> *l, int pos) {
    pos--;
    if(!l->size || pos >= l->size) {
        return -1;
    }
    if(!pos) {
        ListElmt<T> *delete_elmt = l->head;
        double max_ = delete_elmt->data->price;
        l->head = l->head->next;
        l->head->prev = NULL;
        delete delete_elmt;
        l->size--;
        if(max_ == l->max_price) {
            l->max_price = l->head->data->price;
            ListElmt<T> *current_elmt = l->head;
            while(current_elmt->next) {
                current_elmt = current_elmt->next;
                l->max_price = Max(current_elmt->data->price, l->max_price);
            }
        }
        return 0;
    }
    ListElmt<T> *current_elmt = l->head;
    int count = 0;
    while(count < pos - 1 && current_elmt->next) {
        count++;
        current_elmt = current_elmt->next;
    }
    if(count == pos - 1) {
        ListElmt<T> *delete_elmt = current_elmt->next;
        current_elmt->next = current_elmt->next->next;
        if(current_elmt->next) {
            current_elmt->next->prev = current_elmt;
        }
        else {
            l->tail = current_elmt;
        }
        double max_ = delete_elmt->data->price;
        delete delete_elmt;
        if(max_ == l->max_price) {
            current_elmt = l->head;
            l->max_price = l->head->data->price;
            while(current_elmt->next) {
                current_elmt = current_elmt->next;
                l->max_price = Max(l->max_price, current_elmt->data->price);
            }
        }
        l->size--;
        return 0;
    }
    return -1;
}



class Book {
public:
	string ISBN;
	string name;
	double price;
	Book(string isbn_ = "", string name_ = "", double price_ = -1.0) {
		this->ISBN = isbn_;
		this->name = name_;
		this->price = price_;
	}
	friend istream & operator >> (istream & is, Book & book) {
		is >> book.ISBN >> book.name >> book.price;
		return is;
	}
	friend ostream & operator << (ostream & os, const Book & book) {
		os << book.ISBN << book.name << book.price << endl;
		return os;
	}
	void operator = (Book * book) {
		this->ISBN = book->ISBN;
		this->name = book->name;
		this->price = book->price;
	}
};

#define MAX_LEN 1000
char title[MAX_LEN], unit[MAX_LEN];

template<class T>
void Input(My_list<T> *l) {
	fstream fptr_in("book.txt", ios::in);
	fptr_in.getline(title, MAX_LEN);
	fptr_in.getline(unit, MAX_LEN);
	string isbn_, name_; double price_;
	while (!fptr_in.eof()) {
		fptr_in >> isbn_ >> name_ >> price_;
		List_ins(l, 1, new ListElmt<Book>(*(new Book(isbn_,name_,price_))));
	}
	fptr_in.close();
}


template<class T>
void Output(My_list<T> *l) {
	fstream fptr_out("new_Book.txt", ios::out);
	fptr_out << title << endl << unit << endl;
	ListElmt<T> * current_elmt = l->head;
	while (current_elmt) {
		cout << current_elmt->data << endl;
		current_elmt = current_elmt->next;
	}
	fptr_out.close();
}


int main() {
	My_list<Book> l;
	List_init(&l);
	Input(&l);
	Output(&l);
	cout << "Done" << endl;
	return 0;
}


