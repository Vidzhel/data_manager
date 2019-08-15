//#include "pch.h" 
#include <iostream> 
#include <stdio.h> 
#include <Windows.h> 
#include <conio.h> 
#define N 100 
#define COLS 9 

const char* column(int col)
{
	const char* columns[] = {
	"NUM",
	"Name of Country",
	"Capital",
	"Official lenguage",
	"Population",
	"Area territory",
	"Currency",
	"Political system",
	"President",
	"National symbols"
	};
	return columns[col];
}

struct state {
	char nameOfCountry[N];
	char capital[N];
	char officialLenguage[N];
	char population[N];
	char areaTerritory[N];
	char currency[N];
	char politicalSystem[N];
	char president[N];
	char nationalSymbols[N];
}*list;

int i = 0;

int orderA(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c - 64;
	else if (c >= 'a' && c <= 'z')
		return c - 96;
	else if (c >= '0' && c <= '9')
		return c - 48;
	return 0;
}

char* field(int col, int row) {
	char* fields[] = {
	(list + row)->capital,
	(list + row)->nameOfCountry,
	(list + row)->officialLenguage,
	(list + row)->population,
	(list + row)->areaTerritory,
	(list + row)->currency,
	(list + row)->politicalSystem,
	(list + row)->president,
	(list + row)->nationalSymbols
	};
	return fields[col];
}

int getNum(int min, int max) {
	int ch;
	do
	{
		ch = _getch() - 48;
		if (ch >= min && ch <= max)
			return ch;
		else if (ch == 0) {
			return 0;
		}
		else
			printf(" Error, try again...\n\n");
	} while (true);
}

int menu(void) {
	printf("+-------------MENU-------------+\n");
	printf("\nChoose one of folowing options:\n");
	printf(" 1- Create new note;\n");
	printf(" 2- Change note;\n");
	printf(" 3- Print ...;\n");
	printf(" 4- Search by ...\n");
	printf(" 5- Delete element\n");
	printf(" 6- Sort ...\n");
	printf(" 7- Save\n");
	printf(" 8- Open;\n");
	printf(" 9- Quit.\n");
	printf(" ->\n");
	return getNum(1, 9);
}

void scan(char* path, int start) {
	int k = start, c;
	do
	{
		c = _getch();
		if (c == '.')
			break;
		else if (c == 8) {
			printf("\b");
			path[k] = '\0';
			k > start ? k-- : 0;
			path[k] = '\0';
		}
		else {
			printf("%c", c);
			path[k] = c;
			k++;
		}
	} while (k < N - 1);
	path[k] = '\0';
}

void createNew(void) {
	int c, k;
	list = (state*)realloc(list, sizeof(state) * (i + 2));
	for (int j = 1; j < COLS + 1; j++)
	{
		printf("\n Enter %s: ", column(j));
		scan(field(j - 1, i), 0);
	}
	i++;
	printf("\n");
}

int nums(int num) {
	int k = 0;
	for (int temp = num; temp >= 1; k++) {
		temp /= 10;
	}
	return k;
}

int colSize(int col) {
	int size = 0;
	size = strlen(column(col));
	if (col == 0) {
		int temp;
		nums(i) > 3 ? temp = nums(i) + 1 : temp = 4;
		return temp;
	}
	for (int j = 0; j < i; j++)
		strlen(field(col - 1, j)) > size ? size = strlen(field(col - 1, j)) : 0;
	return size;
}

void print(const char* row, const char* col) {
	int rows, cols, allCols = 0, allRows = 0;
	(strcmp("all", row)) == 0 ? rows = i, allRows = 1 : rows = strlen(row);
	(strcmp("all", col)) == 0 ? cols = COLS + 1, allCols = 1 : cols = strlen(col);
	printf("\n\n+");
	for (int i = 0, tempCol; i < cols; i++) {
		allCols ? tempCol = i : tempCol = col[i] - 48;
		if (tempCol == 0) {
			for (int j = 0; j < colSize(tempCol); j++)
				printf("-");
		}
		else {
			for (int j = 0; j < colSize(tempCol); j++)
				printf("-");
		}
		printf("+");
	}
	printf("\n");
	for (int i = 0, tempCol; i < cols; i++)
	{
		allCols ? tempCol = i : tempCol = col[i] - 48;
		printf("|%s", column(tempCol));
		if (tempCol == 0) {
			for (int j = 0; j < (colSize(0) - strlen(column(tempCol)) - 1); j++)
				printf(" ");
		}
		for (int j = 0; j < (colSize(tempCol) - strlen(column(tempCol))); j++)
			printf(" ");
	}
	printf("|");
	printf("\n+");
	for (int i = 0, tempCol; i < cols; i++) {
		allCols ? tempCol = i : tempCol = col[i] - 48;
		if (tempCol == 0) {
			for (int j = 0; j < colSize(tempCol); j++)
				printf("-");
		}
		else {
			for (int j = 0; j < colSize(tempCol); j++)
				printf("-");
		}
		printf("+");
	}
	for (int j = 0, tempRow, tempCol; j < rows; j++)
	{
		allRows ? tempRow = j : tempRow = row[j] - 49;
		if (tempRow > i) {
			printf("\n\nWrong row\n");
			return;
		}
		printf("\n| %d", j + 1);
		for (int k = 0; k < (colSize(0) - nums(j + 1) - 1); k++)
			printf(" ");
		printf("|");
		for (int k = 0, is = 0; k < cols - 1; k++)
		{
			allCols ? tempCol = k : (tempCol = col[k + 1] - 49) == -1 ? is = 1 : 0;
			if (is)
			{
				printf("\n\n Error, there is not 0 column\n");
				break;
			}
			colSize(tempCol + 1) == strlen(field(tempCol, tempRow)) ? 0 : printf(" ");
			printf("%s", field(tempCol, tempRow));
			for (int i = 1; i < (colSize(tempCol + 1) - strlen(field(tempCol, tempRow))); i++)
				printf(" ");
			printf("|");
		}
	}
	printf("\n+");
	for (int i = 0, tempCol; i < cols; i++) {
		allCols ? tempCol = i : tempCol = col[i] - 48;
		if (tempCol == 0) {
			for (int j = 0; j < colSize(tempCol); j++)
				printf("-");
		}
		else {
			for (int j = 0; j < colSize(tempCol); j++)
				printf("-");
		}
		printf("+");
	}
	printf("\n\n");
}

void printChoose() {
	printf("\n Print columns you want to display in table [1; %d] or 'all':\n\n", COLS);
	for (int i = 1; i < COLS + 1; i++)
		printf("  %d- %s;\n", i, column(i));
	char* col = (char*)calloc(1, 1);
	char* row = (char*)calloc(1, 1);
	col[0] = '0';
	printf("\n");
	scan(col, 1);
	printf("\n");
	printf("\n Print rows you want to display in table (0; %d) or 'all':\n\n", i + 1);
	scan(row, 0);
	printf("\n");
	print(row, col);
}

void printTable() {
	printf("\n Choose one of the following options:\n\n");
	printf("  0- ...\n");
	printf("  1- Print whole table;\n");
	printf("  2- Print certain rows and columns;\n");
	int ch = getNum(1, 2);
	if (ch == 0)
		return;
	ch == 1 ? print("all", "all") : printChoose();
}

void search(void) {
	printf("\n Choose one of folowing options:\n\n");
	printf("  0- ...\n");
	for (int i = 1; i < COLS + 1; i++)
		printf("  %d- Search by %s\n", i, column(i));
	int ch = getNum(1, COLS);
	if (ch == 0)
		return;
	ch--;
	char* target = (char*)calloc(1, 1), c;
	char* resultOfSearch = (char*)calloc(1, 1);
	int k = 0;
	printf("\n Enter word or part of it:\n");
	scan(target, 0);
	printf("\n\n");
	int is;
	for (int j = 0, n = 0; j < i; j++)
	{
		is = 1;
		for (int k = 0; field(ch, j)[k] != '\0' && target[k] != '\0'; k++)
		{
			if (field(ch, j)[k] != target[k])
			{
				is = 0;
				break;
			}
		}
		if (is)
		{
			resultOfSearch[n] = j + 49, n++;
			resultOfSearch[n] = '\0';
		}
	}
	print(resultOfSearch, "all");
	printf("\n\n");
}

void del(void) {
	print("all", "all");
	printf("\n Enter number for delete (0; %d) or 0 to leave:\n", i + 1);
	int ch = getNum(1, i);
	if (ch == 0)
		return;
	ch--;
	for (int m = ch; m < i - 1; m++)
		list[m] = list[m + 1];
	i--;
	list = (state*)realloc(list, sizeof(state) * i + 1);
}

void quit() {
	printf("\n Quit...");
	exit(0);
}

void sortAlphabet(void) {
	print("all", "all");
	printf("\n Choose one of folowing options:\n\n");
	printf("  0- ...\n");
	for (int i = 1; i < COLS + 1; i++)
		printf("  %d- Sort by %s;\n", i, column(i));
	int ch = getNum(1, COLS);
	if (ch == 0)
		return;
	ch--;
	char* order = (char*)calloc(i + 1, 1);
	for (int j = 0, pos; j < i; j++)
	{
		pos = 1;
		for (int n = 0; n < i; n++)
			for (int k = 0; ; k++)
			{
				if (field(ch, j)[k] == '\0' || field(ch, n)[k] == '\0')
					break;
				if (j == n)
					continue;
				int o1, o2;
				o1 = orderA(field(ch, j)[k]);
				o2 = orderA(field(ch, n)[k]);
				if (o1 < o2)
				{
					break;
				}
				else if (o1 > o2)
				{
					pos++;
					break;
				}
			}
		order[pos - 1] = j + 49;
	}
	order[i + 1] = '\0';
	print(order, "all");
}

void clear() {
	system("@cls||clear");
}

void sort() {
	printf("\n Choose one of folowing options:\n\n");
	printf("  0- ...\n");
	printf("  1- Sort by fall;\n");
	printf("  2- Sort alphabetically;\n");
	int ch = getNum(1, 2);
	if (ch == 0)
		return;
	if (ch == 1) {
		char* order = (char*)calloc(i + 1, 1);
		for (int j = i, k = 0; k < i; j--, k++) {
			order[k] = j + 48;
		}
		order[i] = '\0';
		print(order, "all");
	}
	else if (ch = 2)
		sortAlphabet();
}

void save() {
	FILE* myfile;
	fopen_s(&myfile, "dataTable.txt", "w") == 0 ? printf("\nFile opened\n") : printf("\nFile did not open\n");
	for (int row = 0; row < i; row++) {
		for (int col = 0; col < COLS; col++) {
			for (int sumb = 0; field(col, row)[sumb] != '\0'; sumb++)
				fputc(field(col, row)[sumb], myfile);
			fputs(".", myfile);
		}
	}
	fclose(myfile) == 0 ? printf("\nChanges successfully saved(%d)\n\n", i) : printf("\nSave failed\n\n");
}

void open() {
	FILE* myfile;
	char ch;
	i = 0;
	list = (state*)realloc(list, sizeof(state) * i);
	fopen_s(&myfile, "dataTable.txt", "r") == 0 ? printf("\nFile opened\n") : printf("\nFile did not opened\n");
	int changes = 0;
	for (int ch; !feof(myfile);) {
		if ((ch = fgetc(myfile)) == '.')
			changes++;
	}
	changes /= COLS;
	fseek(myfile, 0L, 0);
	list = (state*)realloc(list, sizeof(state) * changes);
	for (int row = 0, col = 0, sumb = 0; !feof(myfile);) {
		ch = fgetc(myfile);
		if (ch == '.') {
			field(col, row)[sumb] = '\0';
			++col > COLS - 1 ? col = 0, row++, i++ : 0;
			sumb = 0;
			continue;
		}
		field(col, row)[sumb] = ch;
		sumb++;
	}
	i != changes ? printf("File load error") : 0;
	fclose(myfile) == 0 ? printf("\nData successfully added (%d)\n\n", i) : printf("\nError\n\n");
}

void change() {
	print("all", "all");
	printf("\n Enter row or 0 to leave:\n\n");
	int row = getNum(1, i);
	if (row == 0)
		return;
	row--;
	printf("\n Choose one of folowing options:\n\n");
	for (int i = 1; i < COLS + 1; i++)
		printf("  %d- Change %s;\n", i, column(i));
	int col = getNum(1, COLS);
	col--;
	printf("\n Enter %s: ", column(col + 1));
	scan(field(col, row), 0);
	printf("\n");
}

void(*options[])() = {
createNew,
change,
printTable,
search,
del,
sort,
save,
open,
quit
};

int main(void)
{
	list = (state*)calloc(1, sizeof(state));
	system("color F0");
	do
	{
		printf("\nPress any button...\n\n");
		_getch();
		clear();
		(*options[menu() - 1])();
	} while (true);
}