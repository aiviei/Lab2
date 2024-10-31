#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <unordered_map>

void processing(char * array, int len) {
	std::unordered_map <char, int> letters = { {'a', 1}, {'e', 1}, {'y', 1}, {'u', 1}, {'i', 1}, {'o', 1},
	{'A', 1}, {'E', 1}, {'Y', 1}, {'U', 1}, {'I', 1}, {'O', 1} };

	for (int ask = 65; ask < 91; ask++) {
		if (letters[(char)ask] != 1)
			letters[(char)ask] = 2;
	}
	for (int ask = 97; ask < 123; ask++) {
		if (letters[(char)ask] != 1)
			letters[(char)ask] = 2;
	}
	int i = 0;

	for (int i = 1; array[i + 1] != '0'; i++) {
		if (array[i] == '.') {
			if (letters[array[i - 1]] == 1 and letters[array[i + 1]] == 2) {
				array[i] = '.';

				for (int j = len + 2; j > i; j--) {
					array[j] = array[j - 2];
				}
				array[i + 1] = '.';
				array[i + 2] = '.';
				i += 2;
				len += 2;
			}
			else {
				for (int j = i; j < len; j++) {
					array[j] = array[j + 1];
				}
				i--;
				len--;
			}
		}
	}
}

void first() {
	char *string, *string2, *last_string;
	string = (char*)malloc(1 * sizeof(char));
	char letter;
	int count = 0;
	std::cin >> letter;
	string[0] = letter;
	while (letter != '0') {
		count++;
		string2 = (char*)malloc((count + 1) * sizeof(char));
		for (int i = 0; i < count; i++) {
			string2[i] = string[i];
		}
		string2[count - 1] = letter;
		std::cin >> letter;
		free(string);
		string = string2;
	}
	string[count] = '0';

	processing(string, count + 2);

	for (int d = 0; string[d] != '0'; d++) {
		std::cout << string[d] << " ";
	}
}

void second() {
	char* string3;
	string3 = (char*)calloc(5, sizeof(char));
	char letter;
	int count = 0;
	int mem = 5;
	std::cin >> letter;
	while (letter != '0') {
		if (count >= mem) {
			string3 = (char*)realloc(string3, mem + 5);
			mem += 5;
		}
		string3[count] = letter;
		std::cin >> letter;
		count++;
	}
	string3[count] = '0';

	processing(string3, count + 1);

	for (int d = 0; string3[d] != '0'; d++) {
		std::cout << string3[d] << " ";
	}
}

void third() {
	char* string4;
	string4 = (char*)calloc(5, sizeof(char));
	char letter;
	int count = 0;
	int mem = 5;
	std::cin >> letter;
	while (letter != '0') {
		if (count >= mem) {
			string4 = (char*)realloc(string4, mem + 5);
			mem += 5;
		}
		string4[count] = letter;
		std::cin >> letter;
		count++;
	}
	string4[count] = '0';

	FILE* f1 = fopen("1.txt", "w");

	int count2 = 0;
	while (string4[count2] != '0') {
		fputc(string4[count2], f1);
		count2++;
	}
	fclose(f1);

	char* string5;
	string5 = (char*)calloc(5, sizeof(char));
	count = 0;
	mem = 5;
	FILE* f1_1 = fopen("1.txt", "r");
	while ((letter = fgetc(f1_1)) != EOF) {
		if (count >= mem) {
			string5 = (char*)realloc(string5, mem + 5);
			mem += 5;
		}
		string5[count] = letter;
		count++;
	}
	string5[count] = '0';
	fclose(f1);

	processing(string5, count + 1);
	
	FILE* f1_2 = fopen("1.txt", "r+");
	count2 = 0;
	while (string5[count2] != '0') {
		fputc(string5[count2], f1_2);
		count2++;
	}
}

void main(){
	first();
	second();
	third();
}