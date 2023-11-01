#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "Player.h"
#define MAX_INPUT_SIZE 70

void* getInput(char* inputType);

int main ( int argc, char* argv[] ) {
	Player* player = createPlayer("NONE", 1000, 100);
	if (!player) return;

	char* input = (char*) getInput("string", "Enter your name: ");
	printf("%s", input);
	free(input);

	player->destroy(player);
	

	return 0;
}


void* getInput (char* inputType, char* prompt) {
	if (strncmp(inputType, "string", strlen(inputType)) == 0) {
		char input[MAX_INPUT_SIZE];

		printf("%s", prompt);
		scanf("%s", &input);

		return input;
	}

	return NULL;
}
