//programe to impliment binary sorted tree

#include<iostream>

struct node
{
	int info;
	node* left = nullptr;
	node* right = nullptr;
	node* top = nullptr;

	void getinfo()
	{
		std::cout << info;
	}
};

node *top = nullptr;
node *right = nullptr;
node *left = nullptr;

//all the funtion declarations are done here
void getpreorder(node* ptr, int i);

int selection();

void Log(char* text, int ending);

//void deletion();

void insert(int info);

//void search();

void main()
{
	int select;
	int exit = 0;

	while (!exit)
	{
		select = selection();
		switch (select)
		{
		case 1:
			int info;
			Log("enter the info:", 0);
			std::cin >> info;
			insert(info);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			if (top != nullptr)
				getpreorder(top, 1);
			break;
		case 5:
			exit = 1;
			break;
		default:
			Log("invalid entry.", 1);
			break;
		}
	}
}

int selection()
{
	int select;
	
	Log("Enter your choice:",1);
	Log("insert element -----> 1", 1);
	Log("search element -----> 2", 1);
	Log("delete element -----> 3", 1);
	Log("preorder trav ------> 4", 1);
	Log("exit ---------------> 5", 1);
	
	std::cin >> select;
	
	return(select);
}

void Log(char* text, int ending)
{
	if (ending == 1)
		std::cout << text << std::endl;
	else
		std::cout << text;
}

void insert(int info)
{
	bool L;
	node* newnode = new node;
	newnode->info = info;
	if (top == nullptr)
	{
		top = newnode;
		left = newnode;
		right = newnode;
		newnode->top = top;
	}
	else
	{
		node* ptr = top;
		while (true)
		{
			if (ptr == nullptr)
				break;
			else
				std::cout << ptr->info<<" ";
			if (info > ptr->info)
			{
				L = false;
				if (ptr->right == nullptr)
				{
					node* temp;
					temp = ptr->right;
					ptr->right = newnode;
					newnode->right = temp;
					newnode->top = ptr;
					break;
				}
				else
					ptr = ptr->right;
			}
			else if (info <= ptr->info)
			{
				L = true;
				if (ptr->left == nullptr)
				{
					node* temp;
					temp = ptr->left;
					ptr->left = newnode;
					newnode->left = temp;
					newnode->top = ptr;
					break;
				}
				else
					ptr = ptr->left;
			}
		}
	}
}

void getpreorder(node* ptr, int i)
{
	//left
	Log("->", 0);
	node* temp = ptr;
	std::cout << ptr->info << " ";

	if (ptr->left != nullptr && i == 1)
	{
		ptr = ptr->left;
		getpreorder(ptr, 1);
	}
	else
		i = 2;
	ptr = temp;
	//top
	if (ptr != top && i == 1)
	{
		ptr = ptr->top;
		if (ptr != nullptr)
			getpreorder(ptr, 0);
	}
	ptr = temp;
	//right
	if (ptr->right != nullptr && i != 2)
	{
		ptr = ptr->right;
		getpreorder(ptr,1);
	}
}