#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>



struct books {
	int bookID;
	char bookname[50];
	char pubdate[50];
	char pubname[50];
	int authorID;
} typedef books;
struct author {
	int ID;
	char authorname[50];
	char authoraddress[50];
	char authorphonenum[50];
	char email[50];
	char biography[50];
}typedef author;
int binaryID(books*, int*, int*);
int binaryauthor(author*, int*, int*);
void add_book(books*, author*);
void add_author(author*);
void sort();
void update_(books*, author*);
void delete_book(books*);
void delete_author(author*);
void search_(books*, author*);
void displaybook();
void author_display();
int program_();
void menu_();
int numofauthors = 0;
int numofbooks = 0;
books b[50] = { 0, };
author a[50] = { 0, };
books tempbook;
author tempauthor;
int main()
{
	FILE* booktxt;
	FILE* authortxt;
	FILE* numtxt;
	int bookerror = fopen_s(&booktxt, "C:\\Users\\Hellol\\Desktop\\clanguage\\book.txt", "r");
	int authorerror = fopen_s(&authortxt, "C:\\Users\\Hellol\\Desktop\\clanguage\\author.txt", "r");
	int numerror = fopen_s(&numtxt, "C:\\Users\\Hellol\\Desktop\\clanguage\\num.txt", "r");
	if (bookerror || authorerror || numerror != 0)
	{
		printf("Error! opening file");
		return 0;
	}
	fscanf(numtxt, "%d %d", &numofauthors, &numofbooks);
	fread(&b, sizeof(b), 1, booktxt);
	fread(&a, sizeof(a), 1, authortxt);
	program_();
	fclose(numtxt);
	fclose(booktxt);
	fclose(authortxt);
	bookerror = fopen_s(&booktxt, "C:\\Users\\Hellol\\Desktop\\clanguage\\book.txt", "w");
	authorerror = fopen_s(&authortxt, "C:\\Users\\Hellol\\Desktop\\clanguage\\author.txt", "w");
	numerror = fopen_s(&numtxt, "C:\\Users\\Hellol\\Desktop\\clanguage\\num.txt", "w");
	if (bookerror || authorerror || numerror != 0)
	{
		printf("Error! opening file");
		return 0;
	}
	fprintf(numtxt, "%d %d", numofauthors, numofbooks);
	fwrite(&b, sizeof(b), 1, booktxt);
	fwrite(&a, sizeof(a), 1, authortxt);
	fclose(numtxt);
	fclose(booktxt);
	fclose(authortxt);
	return 0;
}
void sort()
{
	books sorttemp1;
	for (int i = 0; i < numofbooks - 1; i++)
	{
		for (int j = 0; j < numofbooks - 1; j++)
		{
			if (b[j].bookID > b[j + 1].bookID)
			{
				sorttemp1 = b[j];
				b[j] = b[j + 1];
				b[j + 1] = sorttemp1;
			}
		}
	}




	author sorttemp2;
	for (int i = 0; i < numofauthors - 1; i++)
	{
		for (int j = 0; j < numofauthors - 1; j++)
		{
			if (a[j].ID > a[j + 1].ID)
			{
				sorttemp2 = a[j];
				a[j] = a[j + 1];
				a[j + 1] = sorttemp2;
			}
		}
	}

}
int binaryID(books* temp, int* low, int* high)
{
	if (*low > * high)
		return -1;
	int mid = (*low + *high) / 2;
	int midhigh = mid - 1;
	int midlow = mid + 1;
	if (b[mid].bookID == temp->bookID)
		return mid;
	else if (b[mid].bookID > temp->bookID)
		return binaryID(temp, low, &midhigh);
	else
		return binaryID(temp, &midlow, high);
}
int binaryauthor(author* temp, int* low, int* high)
{
	if (*low > * high)
		return -1;
	int mid = (*low + *high) / 2;
	int midhigh = mid - 1;
	int midlow = mid + 1;
	if (a[mid].ID == temp->ID)
		return mid;
	else if (a[mid].ID > temp->ID)
		return binaryauthor(temp, low, &midhigh);
	else
		return binaryauthor(temp, &midlow, high);
}
void author_display()
{
	{
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		printf("Author list\n");
		for (int i = 0; i < numofauthors; i++)
		{
			printf("\nAuthor ID : %d\nAuthorname : %s\nAuthor address : %s\nAuthor phone number : %s\nAuthor email : %s\nAuthor short biography : %s\n", a[i].ID, a[i].authorname, a[i].authoraddress, a[i].authorphonenum, a[i].email, a[i].biography);
			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		}
	}
}
void add_author(author* temp)
{
	int zero = 0;
	int p_numofauthors = numofauthors - 1;

	printf("\nEnter author ID : ");
	scanf("%d", &temp->ID);
	while (1)
	{
		if (temp->ID < 0)
		{
			printf("\nDo not enter negative number!\n\n");
			break;
		}
		else if (binaryauthor(temp, &zero, &p_numofauthors) != -1)
		{
			printf("\nThis author ID already exists in program\n");
			break;
		}
		else
		{
			a[numofauthors].ID = temp->ID;

			printf("Enter author name : ");
			scanf("%s", &a[numofauthors].authorname);
			printf("Enter author address : ");
			scanf("%s", &a[numofauthors].authoraddress);
			printf("Enter author phone number : ");
			scanf("%s", &a[numofauthors].authorphonenum);
			printf("Enter author email : ");
			scanf("%s", &a[numofauthors].email);
			printf("Enter author biography : ");
			scanf("%s", &a[numofauthors].biography);

			numofauthors += 1;
			printf("\nRecord save\n");
		}
		break;
	}
}
void add_book(books* temp1, author* temp2)

{
	int zero = 0;
	while (1)
	{
		if (numofauthors == 0)
		{

			printf("\nPlease add author first\n");
			break;
		}
		printf("\nEnter Book ID : ");
		scanf_s("%d", &temp1->bookID);
		int p_numofbooks = numofbooks - 1;
		if (temp1->bookID < 0)
		{
			printf("\nDo not enter negative number!\n\n");
			break;
		}
		else if (binaryID(temp1, &zero, &p_numofbooks) != -1)
		{
			printf("\nThis book ID already exists in program\n");
			break;
		}
		else
		{
			b[numofbooks].bookID = temp1->bookID;

			printf("Enter book name : ");
			scanf("%s", &b[numofbooks].bookname);
			printf("Enter publication date : ");
			scanf("%s", &b[numofbooks].pubdate);
			printf("Enter publisher name : ");
			scanf("%s", &b[numofbooks].pubname);
			printf("\n");
			author_display();
			while (1)
			{

				int p_numofauthors = numofauthors - 1;
				printf("\nSelect author by ID: ");
				scanf("%d", &temp2->ID);
				int index = binaryauthor(temp2, &zero, &p_numofauthors);
				if (index == -1)
				{
					printf("Cannot Find!\n");
				}
				else
				{
					b[numofbooks].authorID = temp2->ID;
					printf("\nRecord save\n");
					numofbooks += 1;
					break;
				}
			}


		}
		break;
	}
}
void update_(books* temp1, author* temp2)

{
	int zero = 0;
	int p_numofbooks = numofbooks - 1;

	int p_numofauthors = numofauthors - 1;
	while (1)
	{
		int updatetype;
		printf("\n1. book       \n2. author");
		printf("\nEnter number that you want to update : ");
		scanf_s("%d", &updatetype);

		if (updatetype == 1)
		{
			displaybook();
			int update = 0;
			printf("\nEnter bookID to update: ");
			scanf_s("%d", &temp1->bookID);
			int mid = binaryID(temp1, &zero, &p_numofbooks);
			if (mid != -1)
			{
				printf("-------------------------------------------------------------");
				printf("\n1. Update book Name\n");
				printf("2. Update publication Date\n");
				printf("3. Update publisher Name\n");
				printf("4. Update book's Author\n");
				printf("\nwhat do you want to update about book (book ID : %d)?\nEnter number 1~4 : ", temp1->bookID);
				scanf_s("%d", &update);
				if (update > 4 || update < 0)
				{
					printf("\nPlease enter 1~4\n");
					break;
				}
				switch (update)
				{
				case 1:
					printf("Enter updated book name : ");
					scanf("%s", temp1->bookname);
					if (strcmp(temp1->bookname, b[mid].bookname) == 0)
					{
						while (1)
						{
							printf("\nDon't enter same book name. Enter another name : ");
							scanf("%s", temp1->bookname);
							if (strcmp(temp1->bookname, b[mid].bookname) != 0)
							{
								break;
							}
						}
					}
					strcpy(b[mid].bookname, temp1->bookname);

					break;
				case 2:
					printf("Enter updated publication date : ");
					scanf("%s", temp1->pubdate);
					if (strcmp(temp1->pubdate, b[mid].pubdate) == 0)
					{
						while (1)
						{
							printf("\nDon't enter same publication date. Enter another name : ");
							scanf("%s", temp1->pubdate);
							if (strcmp(temp1->pubdate, b[mid].pubdate) != 0)
							{
								break;
							}
						}
					}
					strcpy(b[mid].pubdate, temp1->pubdate);
					break;

				case 3:
					printf("Enter updated publisher name : ");
					scanf("%s", temp1->pubname);
					if (strcmp(temp1->pubname, b[mid].pubname) == 0)
					{
						while (1)
						{
							printf("\nDon't enter same publisher name. Enter another name : ");
							scanf("%s", temp1->pubname);
							if (strcmp(temp1->pubname, b[mid].pubname) != 0)
							{
								break;
							}
						}
					}
					strcpy(b[mid].pubname, temp1->pubname);
					break;


				case 4:
					author_display();

					while (1)
					{
						if (a[0].ID == 0)
						{
							printf("\nPlease add any author before update\n");
							break;
						}
						int p_numofauthors = numofauthors - 1;
						printf("\nSelect author by ID: ");
						scanf("%d", &temp2->ID);
						int index = binaryauthor(temp2, &zero, &p_numofauthors);

						if (index == -1)
						{
							printf("Cannot Find!\n");
						}
						else
						{
							b[mid].authorID = temp2->ID;
							printf("\nUpdate!\n");
							break;
						}
					}
					break;

				}

			}
			else if (mid == -1)
			{
				printf("\nBook ID:%d doesn't exist\n", temp1->bookID);
				break;
			}
			break;
		}

		else if (updatetype == 2)
		{
			author_display();
			int update = 0;
			printf("\nEnter author ID to update:");
			scanf_s("%d", &temp2->ID);
			int mid = binaryauthor(temp2, &zero, &p_numofauthors);
			if (mid != -1)
			{
				printf("\n-------------------------------------------------------------");
				printf("\n1. Author Name\n");
				printf("2. Author address\n");
				printf("3. Author phone number\n");
				printf("4. Author email\n");
				printf("5. Author short biography");
				printf("\nwhat do you want to update? Enter number 1~5 : ");
				scanf_s("%d", &update);
				if (update > 5 || update < 0)
				{

					printf("\nPlease enter 1~5\n");
					break;
				}
				switch (update)
				{
				case 1:
					printf("Enter updated author name : ");
					scanf("%s", temp2->authorname);
					if (strcmp(temp2->authorname, a[mid].authorname) == 0)
					{
						while (1)
						{
							printf("\nDon't enter same author name. Enter another name : ");
							scanf("%s", temp2->authorname);
							if (strcmp(temp2->authorname, a[mid].authorname) != 0)
							{
								break;
							}
						}
					}
					strcpy(a[mid].authorname, temp2->authorname);
					break;
				case 2:
					printf("Enter updated author address : ");
					scanf("%s", temp2->authoraddress);
					if (strcmp(temp2->authoraddress, a[mid].authoraddress) == 0)
					{
						while (1)
						{
							printf("\nDon't enter same author address. Enter another author address : ");
							scanf("%s", temp2->authoraddress);
							if (strcmp(temp2->authoraddress, a[mid].authoraddress) != 0)
							{
								break;
							}
						}
					}
					strcpy(a[mid].authoraddress, temp2->authoraddress);
					break;
				case 3:
					printf("Enter updated author phone number : ");
					scanf("%s", temp2->authorphonenum);
					if (strcmp(temp2->authorphonenum, a[mid].authorphonenum) == 0)
					{
						while (1)
						{
							printf("\nDon't enter same author phone number. Enter another author phone number : ");
							scanf("%s", temp2->authorphonenum);
							if (strcmp(temp2->authorphonenum, a[mid].authorphonenum) != 0)
							{
								break;
							}
						}
					}
					strcpy(a[mid].authorphonenum, temp2->authorphonenum);
					break;
				case 4:
					printf("Enter updated author email : ");
					scanf("%s", temp2->email);
					if (strcmp(temp2->email, a[mid].email) == 0)
					{
						while (1)
						{
							printf("\nDon't enter same author email. Enter another author email : ");
							scanf("%s", temp2->email);
							if (strcmp(temp2->email, a[mid].email) != 0)
							{
								break;
							}
						}
					}
					strcpy(a[mid].email, temp2->email);

					break;

				case 5:
					printf("Enter updated author's short biography : ");
					scanf("%s", temp2->biography);
					if (strcmp(temp2->biography, a[mid].biography) == 0)
					{
						while (1)
						{
							printf("\nDon't enter same author's short biography. Enter another author's short biography: ");
							scanf("%s", temp2->biography);
							if (strcmp(temp2->biography, a[mid].biography) != 0)
							{
								break;
							}
						}
					}
					strcpy(a[mid].biography, temp2->biography);

					break;

				}
				printf("\nUpdate!\n");

			}
			else if (mid == -1)
			{
				printf("\nAuthor ID:%d doesn't exist\n", temp2->ID);
				break;
			}
			break;

		}
		else
		{
			printf("\nPlease enter 1~2\n");
			break;
		}
	}
}
void delete_book(books* temp)
{
	displaybook();
	printf("\nEnter book ID that you want to delete : ");
	scanf_s("%d", &temp->bookID);

	int zero = 0;
	int p_numofbooks = numofbooks - 1;
	while (1)
	{

		int mid = binaryID(temp, &zero, &p_numofbooks);
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
			printf("\nBook ID:%d doesn't exist", temp->bookID);
		}
		break;
	}
}
void delete_author(author* temp)
{
	author_display();
	printf("\nEnter author ID that you want to delete : ");
	scanf_s("%d", &temp->ID);
	int zero = 0;
	int p_numofauthors = numofauthors - 1;
	while (1)
	{
		int mid = binaryauthor(temp, &zero, &p_numofauthors);
		if (mid != -1)
		{
			for (int delete = mid; mid < numofauthors; mid++)
			{
				a[mid] = a[mid + 1];

			}
			printf("\nDelete!\n");
			numofauthors--;
			break;
		}

		if (mid == -1)
		{
			printf("\nAuthor ID:%d doesn't exist", temp->ID);
		}
		break;
	}
}
void search_(books* temp1, author* temp2)
{
	int type1;
	int type2;
	printf("-------------------------------------------------------------");
	printf("\n1. Search book information\n2. Search author information ");
	printf("\nEnter number : ");
	scanf("%d", &type1);
	if (type1 == 1) {
		printf("-------------------------------------------------------------");
		printf("\n1. Search book information by book ID\n2. Search book information by author ID");
		printf("\nEnter number : ");
		scanf("%d", &type2);
		if (type2 == 1)
		{
			if (numofbooks == 0)
			{
				printf("\nThere is no any book ID in this program\n");
				return 0;
			}


			printf("\nEnter book ID to search : ");
			scanf("%d", &temp1->bookID);
			int zero = 0;
			int p_numofbooks = numofbooks - 1;
			int p_numofauthors = numofauthors - 1;
			int mid = binaryID(temp1, &zero, &p_numofbooks);



			if (binaryID(temp1, &zero, &p_numofbooks) == -1)
			{
				printf("\nBook ID:%d doesn't exist\n", temp1->bookID);

			}
			else
			{
				printf("Book(ID:%d)'s information\n", temp1->bookID);
				printf("\nBookname : %s\n", b[mid].bookname);
				printf("Publication Date : %s\n", b[mid].pubdate);
				printf("publisher name: %s\n", b[mid].pubname);
				printf("Author name : %s\n", a[binaryauthor(&b[mid].authorID, &zero, &p_numofauthors)].authorname);
				printf("Author address : %s\n", a[binaryauthor(&b[mid].authorID, &zero, &p_numofauthors)].authoraddress);
				printf("Author phone number : %s\n", a[binaryauthor(&b[mid].authorID, &zero, &p_numofauthors)].authorphonenum);
				printf("Author email : %s\n", a[binaryauthor(&b[mid].authorID, &zero, &p_numofauthors)].email);
				printf("Author biography : %s\n", a[binaryauthor(&b[mid].authorID, &zero, &p_numofauthors)].biography);

			}

		}
		else if (type2 == 2)
		{
			if (numofauthors == 0)
			{
				printf("There is no any author ID in this program");
				return 0;
			}
			author_display();
			int p_numofauthors = numofauthors - 1;
			int zero = 0;
			int flag = 0;
			printf("\nEnter author ID: ");
			scanf("%d", &temp2->ID);

			if (binaryauthor(temp2, &zero, &p_numofauthors) == -1)
			{
				printf("\nNot exist\n");
				return 0;
			}
			else if(binaryauthor(temp2, &zero, &p_numofauthors) != -1)
			{
				printf("\nAuthor(ID : %d)'s book(s) information", temp2->ID);
				for (int i = 0; i < numofbooks; i++)
				{

					if (b[i].authorID == a[binaryauthor(temp2, &zero, &p_numofauthors)].ID)
					{
						flag++;
						printf("\nBook ID : %d", b[i].bookID);
						printf("\nBook name: %s", b[i].bookname);
						printf("\nBook publication date : %s", b[i].pubdate);
						printf("\nBook publisher name : %s", b[i].pubname);
						printf("\n-------------------------------------------------------------");
					}
				}
				if (flag != 0)
				{
					printf("\nTotal %d book(s)\n", flag);
				}
				
			}
			else if (flag == 0) {
				printf("\nNot exist\n");
			}
			
			
		}
		else
		{
			printf("\nPlease enter 1~2\n");
		}
	}
	else if (type1 == 2)
	{
		printf("-------------------------------------------------------------");
		printf("\n1. Search author information by book ID\n2. Search author information by author ID");
		printf("\nEnter number : ");
		scanf("%d", &type2);
		if (type2 == 1)
		{

			if (numofbooks == 0)
			{
				printf("\nThere is no any book ID in this program\n");
				return 0;
			}
			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			printf("\nBook List\n");
			for (int i = 0; i < numofbooks; i++)
			{

				printf("\nBook ID : %d\nBook name : %s\nBook publication date : %s\nBook publisher name : %s\n", b[i].bookID, b[i].bookname, b[i].pubdate, b[i].pubname);
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

			}
			printf("\nEnter book ID to search : ");
			scanf("%d", &temp1->bookID);
			int zero = 0;
			int p_numofbooks = numofbooks - 1;
			int p_numofauthors = numofauthors - 1;
			int mid = binaryID(temp1, &zero, &p_numofbooks);



			if (binaryID(temp1, &zero, &p_numofbooks) == -1)
			{
				printf("\nBook ID:%d doesn't exist\n", temp1->bookID);
			}
			else
			{
				printf("\nBook(ID: %d)'s author information\n", temp1->bookID);
				printf("Author name : %s\n", a[binaryauthor(&b[mid].authorID, &zero, &p_numofauthors)].authorname);
				printf("Author address : %s\n", a[binaryauthor(&b[mid].authorID, &zero, &p_numofauthors)].authoraddress);
				printf("Author phone number : %s\n", a[binaryauthor(&b[mid].authorID, &zero, &p_numofauthors)].authorphonenum);
				printf("Author email : %s\n", a[binaryauthor(&b[mid].authorID, &zero, &p_numofauthors)].email);
				printf("Author biography : %s\n", a[binaryauthor(&b[mid].authorID, &zero, &p_numofauthors)].biography);
			}
		}
		else if (type2 == 2)
		{
			int p_numofauthors = numofauthors - 1;
			int zero = 0;
			int flag = 0;
			if (numofauthors == 0)
			{
				printf("There is no any author ID in this program");
				return 0;
			}
			printf("-------------------------------------------------------------");
			printf("\nEnter author ID to search: ");
			scanf("%d", &temp2->ID);
			if (binaryauthor(temp2, &zero, &p_numofauthors) != -1)
			{
				printf("Author(ID : %d)'s information\n", temp2->ID);
				printf("Author name : %s\nAuthor address : %s\nAuthor phone number : %s\nAuthor email : %s\nAuthor's short biography : %s\n", a[binaryauthor(temp2, &zero, &p_numofauthors)].authorname, a[binaryauthor(temp2, &zero, &p_numofauthors)].authoraddress, a[binaryauthor(temp2, &zero, &p_numofauthors)].authorphonenum, a[binaryauthor(temp2, &zero, &p_numofauthors)].email, a[binaryauthor(temp2, &zero, &p_numofauthors)].biography);
			}
			else
			{
				printf("\nNot exist\n");
			}
		}
		else
		{
			printf("\nPlease enter 1~2\n");
		}
	}
	else
	{
		printf("\nPlease enter 1~2\n");

	}
}
void displaybook()
{
	int p_numofauthors = numofauthors - 1;
	int zero = 0;
	if (b[0].bookID == 0)
	{
		printf("\nNot exist\n");
		return 0;
	}
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\nBook List\n");
	for (int i = 0; i < numofbooks; i++)
	{

		printf("\nBook ID : %d\nBook name : %s\nBook publication date : %s\nBook publisher name : %s\nBook author name : %s\nBook author address : %s\nBook author phone number : %s\nBook author emali : %s\nBook author's short biography\n", b[i].bookID, b[i].bookname, b[i].pubdate, b[i].pubname, a[binaryauthor(&b[i].authorID, &zero, &p_numofauthors)].authorname, a[binaryauthor(&b[i].authorID, &zero, &p_numofauthors)].authoraddress, a[binaryauthor(&b[i].authorID, &zero, &p_numofauthors)].authorphonenum, a[binaryauthor(&b[i].authorID, &zero, &p_numofauthors)].email, a[binaryauthor(&b[i].authorID, &zero, &p_numofauthors)].biography);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	}
}
int program_()
{
	while (1)
	{

		author tempauthor = { 0, };
		books tempbook = { 0, };

		int num = 0;
		int tempnum = 0;
		menu_();
		scanf_s("%d", &num);
		switch (num)
		{
		case 1: //Add book information
			printf("\n1.Add book\n2.Add author\n");
			printf("Please Enter number you want : ");
			scanf_s("%d", &tempnum);
			if (tempnum == 1)
			{
				add_book(&tempbook, &tempauthor);
			}

			else if (tempnum == 2)
			{
				add_author(&tempauthor);
			}
			else
			{
				printf("\nPlease enter 1~2\n");
				break;
			}
			sort();
			break;
		case 2: //Update book information
			update_(&tempbook, &tempauthor);
			break;
		case 3: //Delete book information
			printf("\n1.Delete book\n2.Delete author\n");
			printf("Enter number : ");
			scanf_s("%d", &tempnum);
			if (tempnum == 1)
			{
				delete_book(&tempbook);
			}

			else if (tempnum == 2)
			{
				delete_author(&tempauthor);
			}
			else
			{
				printf("\nPlease enter 1~2\n");
			}
			break;

		case 4: //Search book information
			search_(&tempbook, &tempauthor);
			break;
		case 5://Display a list of all book			
			displaybook();
			break;
		case 6://display a list of all author
			author_display();
			break;
		case 0: //End program

			return 0;
		default:
			printf("\nPlease enter number 0~6\n");
			break;
		}
	}
}
void menu_()
{
	printf("\n=============================================================");
	printf("\nLibrary Management program\n");
	printf("1. Add information\n");
	printf("2. Update information\n");
	printf("3. Delete information\n");
	printf("4. Search information\n");
	printf("5. Display a list of all book\n");
	printf("6. Display a list of all author\n");
	printf("0. End program\n");
	printf("Enter number of the task (0~6) : ");
}
