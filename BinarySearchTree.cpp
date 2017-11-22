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
void getpreorder(node* ptr);

void getinorder(node* ptr);

void getpostorder(node* ptr);

int selection();

void Log(char* text, int ending);

node* getbaseleft(node* ptr);

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
				getpreorder(top);
			break;
		case 5:
			if (left != nullptr)
				getinorder(left);
			break;
		case 6:
			if (right != nullptr)
				getpostorder(right);
			break;
		case 7:
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
	Log("inorder trav -------> 5", 1);
	Log("postorder trav -----> 6", 1);
	Log("exit ---------------> 7", 1);
	
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
		newnode -> top = nullptr;
		newnode -> left = nullptr;
		newnode -> right = nullptr;
	}
	else
	{
		node* ptr = top;
		int l = 0;
		int r = 0;
		while (true)
		{
			if (ptr == nullptr)
				break;
			else
				std::cout << ptr->info<<" ";
			if (info > ptr->info)
			{
				l = 1;
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
					if (l == 0)
						left = ptr;
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
		right = ptr;
	}
}

void getpreorder(node* ptr)
{
	//travers left
	Log("->", 0);
	node* temp = ptr;
	std::cout << ptr->info << " ";

	if (ptr->left != nullptr)
	{
		ptr = ptr->left;
		getpreorder(ptr);
	}
	ptr = temp;
	//travers right
	if (ptr->right != nullptr)
	{
		ptr = ptr->right;
		getpreorder(ptr);
	}

	
}
void getinorder(node* ptr)
{
	//travers right
	Log("->", 0);
	node* temp = ptr;
	std::cout << ptr->info << " ";
	int flag = 0;
	if (ptr->right != nullptr)
	{
		ptr = ptr->right;
		ptr = getbaseleft(ptr);	//this will return the left most element in the current branch
		getinorder(ptr);
		if (ptr->left == nullptr)
			flag = 1;
	}
	//travers top
	if (ptr->top != nullptr && flag == 0)
	{
		ptr = ptr->top;
		getinorder(ptr);
	}

}
void getpostorder(node* ptr)
{
	//travers right
	Log("->", 0);
	node* temp = ptr;
	std::cout << ptr->info << " ";

	if (ptr->right != nullptr)
	{
		ptr = ptr->right;
		getinorder(ptr);
	}
	ptr = temp;
	//travers top
	if (ptr->top != nullptr)
	{
		ptr = ptr->top;
		getinorder(ptr);
	}

}

node* getbaseleft(node* ptr)
{
	node* templeft = ptr;
	while (true)
	{
		if (templeft->left != nullptr)
		{
			templeft = templeft->left;
		}
		else
			return(templeft);
	}
}