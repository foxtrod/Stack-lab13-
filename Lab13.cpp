#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;



struct List
{
	int x;
	List *Next;
	List *Head;
}; 

void min(List *MyList)
{
	List *tmp = MyList->Head;  
	List *k = MyList;
	int min_index = 0;
	int current_index = 0;
	int min = tmp->x;
	while(tmp != NULL)
	{
		if (tmp->x < min)
		{
			min_index = current_index;
			min = tmp->x;
		}
		tmp = tmp->Next;
		current_index ++;
	}
	cout << min_index << endl;
	cout << min << endl;
}

void add(int x, List *&MyList)
{
	List *tmp = new List;
	tmp->x = x;
	tmp->Next = MyList->Head;
	MyList->Head = tmp;
}

void show(List *MyList)
{
	List *tmp = MyList->Head;
	while(tmp != NULL)
	{
		cout << tmp->x << " ";
		tmp=tmp->Next;
	}
	cout << endl;
}

int main()
{
	time_t q;
	srand(time(NULL));
	List *MyList = new List;
	MyList->Head = NULL;
	for (int i = 0; i < 10; i ++)
	{
		q = rand()% 100 - 50;
		add(q, MyList);
	}
	show(MyList);
	min(MyList);
	return 0;
}
