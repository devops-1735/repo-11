#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node(int data1)
	{
		data = data1;
		next = nullptr;
	}
	Node(int data1, Node *next1)
	{
		data = data1;
		next = next1;
	}
};

Node *convertarrtoLL(vector<int> &arr)
{
	Node *head = new Node(arr[0]);
	Node *mover = head;
	for (int i = 1; i < arr.size(); i++)
	{
		Node *temp = new Node(arr[i]);
		mover->next = temp;
		mover = temp;
	}
	return head;
}

int lengthofll(Node *head)
{
	int cnt = 0;
	Node *temp = head;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
		cnt++;
	}
	return cnt;
}

void checkvalue(Node *head, int val)
{
	Node *temp = head;
	while (temp)
	{
		if (temp->data == val)
		{
			cout << "yes present";
		}
		temp = temp->next;
	}
	cout << "no";
}

Node *removeshead(Node *head)
{
	if (head == NULL)
		return head;
	Node *temp = head;
	head = head->next;
	delete temp;
	return head;
}

Node *removestail(Node *head)
{
	if (head == NULL || head->next == NULL)
		return NULL;
	Node *temp = head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	delete temp->next;
	temp->next = nullptr;
	return head;
}

Node *removeK(Node *head, int k)
{
	if (k == 1)
	{
		Node *temp = head;
		head = head->next;
		delete temp;
		return head;
	}
	int cnt = 0;
	Node *temp = head;
	Node *prev = NULL;
	while (temp != NULL)
	{
		cnt++;
		if (cnt == k)
		{
			prev->next = prev->next->next;
			delete temp;
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	return head;
}

Node *removeelement(Node *head, int el)
{
	if (head->data == el)
	{
		Node *temp = head;
		head = head->next;
		delete temp;
		return head;
	}

	Node *temp = head;
	Node *prev = NULL;
	while (temp != NULL)
	{

		if (temp->data == el)
		{
			prev->next = prev->next->next;
			delete temp;
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	return head;
}

Node *insertnewhead(Node *head)
{
	Node *temp = new Node(1, head);
	return temp;
}

Node *insertlast(Node *head)
{

	Node *temp = head;
	if (head == NULL)
	{
		return new Node(45);
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	Node *last = new Node(45);
	temp->next = last;
	return head;
}

Node *insertposition(Node *head, int el, int k)
{
	if (head == NULL)
	{
		if (k == 1)
		{
			return new Node(el);
		}
		else
		{
			return head;
		}
	}
	int cnt = 0;
	Node *temp = head;

	while (temp != NULL)
	{
		cnt++;
		if (cnt == k - 1)
		{
			Node *x = new Node(el, temp->next);
			temp->next = x;
			break;
		}
		temp = temp->next;
	}
	return head;
}

Node *insertbeforevalue(Node *head, int el, int k)
{
	if (head == NULL)
	{
		return NULL;
	}

	Node *temp = head;

	while (temp->next != NULL)
	{

		if (temp->next->data == k)
		{
			Node *x = new Node(el, temp->next);
			temp->next = x;
			break;
		}
		temp = temp->next;
	}
	return head;
}

int main()
{
	vector<int> arr = {2, 5, 8, 7};
	Node *y = convertarrtoLL(arr);
	// cout << y->data;
	// y = removeshead(y);
	// y = removestail(y);
	// y = removeK(y , 3);
	// y = removeelement(y, 2);
	// y = insertnewhead(y);
	// y = insertlast(y);
	// y = insertposition(y, 36, 4);
	y = insertbeforevalue(y, 34, 8);

	while (y)
	{
		cout << y->data << " ";
		y = y->next;
	}
	// cout<<lengthofll(y);
	// checkvalue(y , 35);

	return 0;
}
