/*
Задача:
Коэффициенты многочлена 𝑛-ой степени 𝑃 𝑥 = 𝑎(𝑛)*𝑥^𝑛 + 𝑎(𝑛−1)*𝑥^(𝑛−1) + ⋯ + 𝑎1𝑥 + 𝑎0 задаются парами (𝑖, 𝑎(𝑖)), 
где 𝑖 – показатель степени для коэффициента 𝑎(𝑖). Даны два многочлена P(x) и Q(x) степеней m и n соответственно. 
Найти коэффициенты многочлена, равного произведению многочленов P(x) и Q(x).


Автор: Нечунаева А.И.
Предмет: Практикум по программированию
Дата: 08.11.2021
Вариант: 11

*/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <locale.h>


using namespace std;

struct List {
	float coeff;
	int pow;
	struct List* next;
};


struct List* insert(struct List* head, float co, int pow)
{
	struct List* temp;
	struct List* newT = ( List*)malloc(sizeof(struct List));

	newT->coeff = co;
	newT->pow = pow;
	newT->next = NULL;

	if ( head==NULL || pow > head->pow)
	{
		newT->next = head;
		head = newT;
	}
	else
	{
		temp = head;

		while (temp->next != NULL && temp->next->pow >= pow)
			temp = temp->next;
		newT->next = temp->next;
		temp->next = newT;
	}
	return head;
}

struct List* create(struct List* head) 
{
	int n, i;
	float coeff;
	int power;

	cout << "Enter n ";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter coeff:  ";
		cin >> coeff;
		cout << endl;
		cout << "Enter pow:  " << endl;
		cin >> power;

		head = insert(head, coeff, power);
	}
	return head;
}

void print(struct List* head)
{
	if (head == NULL)
	{
		cout << "ERROR" << endl;
	}
	else
	{
		struct List* temp = head;
		while (temp != NULL)
		{
			cout << temp->coeff << "*x^" << temp->pow;
			temp = temp->next;
			if (temp != NULL)
			{
				cout << " + ";
			}
			else
			{
				cout << endl;
			}
		}
	}
}
void ProdPolynomials(List* head1, List* head2) {

	List* ptr1 = head1;
	List* ptr2 = head2;
	List* head3 = NULL;


	if (head1 == NULL || head2 == NULL)
	{
		return;
	}

	while (ptr1 != NULL)
	{
		while (ptr2 != NULL)
		{
			head3 = insert(head3, ptr1->coeff * ptr2->coeff, ptr1->pow + ptr2->pow);
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
		ptr2 = head2;
	}

	print(head3);
}


int main() 
{
	List* head1 =NULL;
	List* head2 = NULL;
	cout << "Enter head1 : " << endl;
	head1 = create(head1);
	cout << "Enter head2 : " << endl;
	head2 = create(head2);

	ProdPolynomials(head1, head2);
	return 0;
}
