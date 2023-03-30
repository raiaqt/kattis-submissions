#include <cstdio>

const int LET = 0;
const int IF = 1;
const int PRINT = 2;
const int PRINTLN = 3;

struct Line {
	int id;
	int command;
	char* statement;

	Line(int i, int c, char* s) {
		id = i;
		command = c;
		statement = s;
	}
};

struct Line** list;
int size;
int values[30];

int getNum(char* statement, int &end) {
	// can be a value from a variable or an actual number
	end--;

	if (statement[end] >= 'A' && statement[end] <= 'Z') {
		return values[statement[end--] - 'A'];
	}

	int num = 0;
	int base = 10;
	int mult = 1;

	while (statement[end] != ' ') {
		num += (statement[end] - '0') * mult;
		mult *= base;
		end--;
	}
	return num;
}

int getResult(int A, int B, char op) {
	switch (op) {
	case '+':
		return A + B;
	case '-':
		return A - B;
	case '*':
		return A * B;
	case '/':
		return A / B;
	default:
		return 0;
	}
}

void executeLet(char* statement) {
	int variable = statement[1] - 'A';

	int i = 0;
	while (statement[i] != '\0') {
		i++;
	}

	int B = getNum(statement, i);

	int result;
	i--;

	if (statement[i] == '=') {
		result = B;
	} else {
		char op = statement[i--];
		int A = getNum(statement, i);

		printf("A %d\n", A);
		result = getResult(A, B, op);
	}
	printf("storing %d in %c\n", result, variable + 'A');
	values[variable] = result;
}

void executeIf(char* statement) {
	printf("executing if\n");
}

void executePrint(char* statement, bool ln) {
	printf("executing print\n");

	if (ln) {

		printf("executing printLn\n");
	}
}

int main() {
	int id;
	char* commandIn;
	char* statement;
	int command;
	list = new Line*[100000];
	size = 0;

	// initialize values of variables
	for (int i = 0; i < 30; i++) {
		values[i] = 0;
	}

	while (scanf("%d", &id) == 1) {

		if (id == -1) break;

		commandIn = new char[10];
		statement = new char[100000];
		scanf("%s", commandIn);
		scanf("%[^\n]\n", statement);

		if (commandIn[0] == 'L') {
			command = LET;
		} else if (commandIn[0] == 'I') {
			command = IF;
		} else if (commandIn[5] == '\0') {
			command = PRINT;
		} else {
			command = PRINTLN;
		}

		// store all lines in list
		struct Line* l = new Line(id, command, statement);
		list[size++] = l;
	}

	// sort the list according to increasing ID
	// TO DO: change to merge sort
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (list[i]->id > list[j]->id) {
				struct Line* temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		switch (list[i]->command) {
		case LET:
			executeLet(list[i]->statement);
			break;
		case IF:
			executeIf(list[i]->statement);
			break;
		case PRINT:
			executePrint(list[i]->statement, false);
			break;
		case PRINTLN:
			executePrint(list[i]->statement, true);
			break;
		default:
			break;
		}
	}

	printf("done\n");
	return 0;
}
