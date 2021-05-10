#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

struct books {
	int bookID;
	char bookname[50];
	char pubdate[20];
	char pubname[50];
	int pubphonenum;
	char authorname[20];
	char email[30];
} typedef books;


books b[50];
int numofbooks = 0;
void sort();
int binaryID(books b[], books, int, int);
int program_();
void menu_();
void add_(books);
void update_(books);
void delete_(books);
void search_(books);
void display_entered_author(books);
void display_entered_publisher(books);
void display();


int main()
{
	program_();
}
void sort()
{
	books sorttemp;
	for (int i = 0; i < numofbooks - 1; i++)
	{
		for (int j = 0; j < numofbooks - 1; j++)
		{
			if (b[j].bookID > b[j + 1].bookID)
			{
				sorttemp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = sorttemp;
			}
		}
	}
}
int binaryID(books b[], books temp, int low, int high)
{
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (b[mid].bookID == temp.bookID)
		return mid;
	else if (b[mid].bookID > temp.bookID)
		return binaryID(b, temp, low, mid - 1);
	else
		return binaryID(b, temp, mid + 1, high);
}
int program_()
{
	books temp;
	while (1)
	{
		int num = 0;
		menu_();
		scanf_s("%d", &num);
		switch (num)
		{
		case 1: //Add book information
			printf("\nEnter Book ID : ");
			scanf_s("%d", &temp.bookID);
			add_(temp);
			sort();
			break;
		case 2: //Update book information
			printf("\nEnter book ID that you want to update : ");
			scanf_s("%d", &temp.bookID);
			update_(temp);
			break;
		case 3: //Delete book information
			printf("\nEnter book ID that you want to delete : ");
			scanf_s("%d", &temp.bookID);
			delete_(temp);
			break;
		case 4: //Search book information
			printf("\nEnter book ID to search : ");
			scanf_s("%d", &temp.bookID);
			search_(temp);
			sort();
			break;
		case 5: //Display a list of book(s) published by an entered author
			printf("Enter author : ");
			scanf("%s", temp.authorname);
			display_entered_author(temp);
			break;
		case 6: //Display a list of book(s) published by an entered publisher
			printf("Enter publisher : ");
			scanf("%s", temp.pubname);
			display_entered_publisher(temp);
			break;
		case 7://Display a list of all book			
			display();
			break;
		case 0: //End program
			return 0;
		default:
			printf("\nPlease enter number 0~7\n");
			break;
		}
	}
}
void add_(books temp)

{
	while (1)
	{
		if (temp.bookID < 0)
		{
			printf("\nDo not enter negative number!\n\n");
			break;
		}
		else if (binaryID(b, temp, 0, numofbooks - 1) != -1)
		{
			printf("\nThis book ID already exists in program\n");
			break;
		}
		else

		{
			b[numofbooks].bookID = temp.bookID;

			printf("Enter book name : ");
			scanf("%s", b[numofbooks].bookname);
			printf("Enter publication date : ");
			scanf("%s", b[numofbooks].pubdate);
			printf("Enter publisher name : ");
			scanf("%s", b[numofbooks].pubname);
			printf("Enter publisher phone number : ");
			scanf_s("%d", &b[numofbooks].pubphonenum);
			printf("Enter author name : ");
			scanf("%s", b[numofbooks].authorname);
			printf("Enter author email address : ");
			scanf("%s", b[numofbooks].email);
			numofbooks += 1;
			printf("\nRecord save\n\n");
		}

		break;
	}
}
void update_(books temp)


{
	while (1)
	{
		int update = 0;
		int mid = binaryID(b, temp, 0, numofbooks - 1);
		if (mid != -1)
		{

			printf("1. Book Name\n");
			printf("2. Publication Date\n");
			printf("3. Publisher Name\n");
			printf("4. Publisher Phone Number\n");
			printf("5. Author Name\n");
			printf("6. Author Email Address\n");
			printf("\nwhat do you want to update? Enter number 0~6 : ");

			scanf_s("%d", &update);
			if (update > 6 || update < 0)
			{

				printf("\nPlease enter 0~6\n");
				break;
			}
			switch (update)
			{
			case 1:
				printf("Enter updated book name : ");
				scanf("%s", temp.bookname);
				if (strcmp(temp.bookname, b[mid].bookname) == 0)
				{
					while (1)
					{
						printf("\nDon't enter same book name. Enter another name : ");
						scanf("%s", temp.bookname);
						if (strcmp(temp.bookname, b[mid].bookname) != 0)
						{
							break;
						}
					}
				}
				strcpy(b[mid].bookname, temp.bookname);
				break;
			case 2:
				printf("Enter updated publication date : ");
				scanf("%s", temp.pubdate);
				if (strcmp(temp.pubdate, b[mid].pubdate) == 0)
				{
					while (1)
					{
						printf("\nDon't enter same publication date. Enter another name : ");
						scanf("%s", temp.pubdate);
						if (strcmp(temp.pubdate, b[mid].pubdate) != 0)
						{
							break;
						}
					}
				}
				strcpy(b[mid].pubdate, temp.pubdate);
				break;
			case 3:
				printf("Enter updated publisher name : ");
				scanf("%s", temp.pubname);
				if (strcmp(temp.pubname, b[mid].pubname) == 0)
				{
					while (1)
					{
						printf("\nDon't enter same publisher name. Enter another name : ");
						scanf("%s", temp.pubname);
						if (strcmp(temp.pubname, b[mid].pubname) != 0)
						{
							break;
						}
					}
				}
				strcpy(b[mid].pubname, temp.pubname);
				break;
			case 4:
				printf("Enter updated publisher phone number : ");
				scanf_s("%d", &temp.pubphonenum);
				if (temp.pubphonenum == b[mid].pubphonenum)
				{
					while (1)
					{
						printf("\nDon't enter same phone number. Enter another phone number : ");
						scanf_s("%d", &temp.pubphonenum);
						if (temp.pubphonenum != b[mid].pubphonenum)
						{
							break;
						}
					}
				}
				b[mid].pubphonenum = temp.pubphonenum;
				break;
			case 5:
				printf("Enter updated author name : ");
				scanf("%s", temp.authorname);
				if (strcmp(temp.authorname, b[mid].authorname) == 0)
				{
					while (1)
					{
						printf("\nDon't enter same authorname. Enter another name : ");
						scanf("%s", temp.authorname);
						if (strcmp(temp.authorname, b[mid].authorname) != 0)
						{
							break;
						}
					}
				}
				strcpy(b[mid].authorname, temp.authorname);
				break;
			case 6:
				printf("Enter updated author email address : ");
				scanf("%s", temp.email);
				if (strcmp(temp.email, b[mid].email) == 0)
				{
					while (1)
					{
						printf("\nDon't enter same email. Enter another email : ");
						scanf("%s", temp.email);
						if (strcmp(temp.email, b[mid].email) != 0)
						{
							break;
						}
					}
				}
				strcpy(b[mid].email, temp.email);
				break;
			}
			printf("\nUpdate!\n");
		}

		if (mid == -1)
		{
			printf("\nBook ID:%d doesn't exist\n", temp.bookID);
			break;
		}
		break;
	}
}
void delete_(books temp)


{
	while (1)
	{
		int mid = binaryID(b, temp, 0, numofbooks - 1);
		if (mid != -1)
		{


			for (int delete = mid; mid < numofbooks; mid++)
			{
				b[mid] = b[mid + 1];

			}

			printf("\nDelete!\n");
			numofbooks--;
			break;
		}

		if (mid == -1)
		{
			printf("\nBook ID:%d doesn't exist", temp.bookID);

		}
		break;
	}
}
void search_(books temp)


{
	while (1)
	{

		int mid = binaryID(b, temp, 0, numofbooks - 1);

		if (numofbooks == 0)
		{
			printf("\nThere is no book ID in this program\n");
			break;
		}

		if (binaryID(b, temp, 0, numofbooks - 1) == -1)
		{
			printf("\nBook ID:%d doesn't exist\n", temp.bookID);
			break;
		}
		else
		{
			printf("\nBookname : %s\n", b[mid].bookname);
			printf("Publication Date : %s\n", b[mid].pubdate);
			printf("Publisher Name : %s\n", b[mid].pubname);
			printf("Publisher Phone Number : %d\n", b[mid].pubphonenum);
			printf("Author Name : %s\n", b[mid].authorname);
			printf("Author Email Address : %s\n", b[mid].email);
			break;
		}
	}
}
void display_entered_author(books temp)

{
	int flag = 0;
	for (int i = 0; i < numofbooks; i++)
	{
		if (strcmp(temp.authorname, b[i].authorname) == 0)
		{
			flag = 1;
			printf("\nBook ID : %d	Bookname : %s", b[i].bookID, b[i].bookname);
		}
	}

	if (flag == 0)
	{
		printf("Book published by Author %s doesn't exist in this program\n", temp.authorname);
	}
}
void display_entered_publisher(struct books temp)

{
	int flag = 0;
	for (int i = 0; i < numofbooks; i++)
	{
		if (strcmp(temp.pubname, b[i].pubname) == 0)
		{
			flag = 1;
			printf("\nBook ID : %d	Bookname : %s", b[i].bookID, b[i].bookname);
		}
	}

	if (flag == 0)
	{
		printf("\nBook published by %s doesn't exist in this program\n", temp.pubname);
	}
}
void display()
{
	for (int i = 0; i < numofbooks; i++)
	{
		printf("\nBook ID : %d	Bookname : %s", b[i].bookID, b[i].bookname);
	}
}
void menu_()
{
	printf("\nLibrary Management program\n");
	printf("1. Add book information\n");
	printf("2. Update book information\n");
	printf("3. Delete book information\n");
	printf("4. Search book information\n");
	printf("5. Display a list of book(s) published by an entered author\n");
	printf("6. Display a list of book(s) published by an entered publisher\n");
	printf("7. Display a list of all book\n");
	printf("0. End program\n");
	printf("Enter number of the task (0~7) : ");
}
