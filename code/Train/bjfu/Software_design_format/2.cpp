/*************************************************************************
    > File Name: 2.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年09月18日 星期日 20时51分10秒
 ************************************************************************/
#include<iostream>
#include<string>
using namespace std;

struct Student {
    int sex;
    int age;
    string ID;
    Student(int sex_ = 0, int age_ = 0, string id = ""):sex(sex_), age(age), ID(id) {}
    friend ostream & operator << (ostream & os, const Student & stu) {
	os << stu.sex << " " << stu.age << " " << stu.ID;
	return os;
    }
};

bool stucmp(Student a, Student b) {
    if(a.sex < b.sex) return true;
    else if(a.sex == b.sex && a.age < b.age) return true;
    else if(a.sex == b.sex && a.age == b.age && a.ID < b.ID) return true;
    return false;
}

template<class T>
void msort(T * arr, int l, int r, bool (*cmp)(T , T )) {
    if(l >= r) return ;
    T value = arr[l];
    int i = l, j = r;
    while(i < j) {
	for(; i < j; j--)
	    if(cmp(arr[j], value)) {
		arr[i++] = arr[j]; break;
	    }
	for(; i < j; i++)
	    if(cmp(value, arr[i])) {
		arr[j--] = arr[i]; break;
	    }
    }
    arr[i] = value;
    msort(arr, l, i - 1, cmp);
    msort(arr, i + 1, r, cmp);
}



int main() {
    Student a[10];
    a[0].sex = 0; a[0].age = 19; a[0].ID = "1247438";
    a[1].sex = 0; a[1].age = 17; a[1].ID = "4834954";
    a[2].sex = 1; a[2].age = 20; a[2].ID = "1230000";
    a[3].sex = 1; a[3].age = 20; a[3].ID = "0000001";
    a[4].sex = 0; a[4].age = 16; a[4].ID = "9999999";
    msort(a, 0, 4, stucmp);
    for(int i = 0; i < 5; i++) {
	cout << a[i] << endl;
    }
    return 0;
}
