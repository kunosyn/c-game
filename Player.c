#include "Player.h"

void takeDamage ( Player* player, int damage ) {
	player->health -= damage;
	if (player->health > 0) return;

	player->health = 0;
	player->isLiving = false;
}


void setAttribute ( Player* player, char* attribute, void* value ) {
	if (strncmp(attribute, "name", strlen(attribute)) == 0) {
		char* buffer = (char*) value;

		strncpy(player->name, buffer, sizeof buffer);
		player->name[strlen(buffer)] = '\0'; // Make sure that player->name is terminated with a null character.
	} else if (strncmp(attribute, "money", strlen(attribute)) == 0) {
		player->money = *((int*)value);
	} else if (strncmp(attribute, "level", strlen(attribute)) == 0) {
		player->level = *((unsigned int*)value);
	}
}


void destroy ( Player* player ) {
	if (!player) return;

	free(player);
	free(player->name);

	player = NULL;
}


Player* createPlayer ( char* name, int money, unsigned int maxHealth ) {
	Player* player = (Player*) malloc(sizeof(Player));
	if (!player) return NULL; // malloc wasn't successful.

	player->name = (char*) malloc(sizeof(char) * (strlen(name) + 1));

	if (!player->name) {
		free(player);
		return NULL;
	}


	strncpy(player->name, name, strlen(name));
	player->name[strlen(name)] = '\0';

	player->money = money;
	player->maxHealth = maxHealth;


	player->destroy = &destroy;
	player->setAttribute = &setAttribute;
	player->takeDamage = &takeDamage;


	return player;
}
