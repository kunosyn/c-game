#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


typedef struct Player Player;

struct Player {
	char* name;

	unsigned int maxHealth, level;
	int health, money;

	bool isLiving;

	void (*takeDamage)(Player* player, int damage);
	void (*setAttribute)(Player* player, char* attribute, void* value);
	void (*destroy)(Player* player);
};


Player* createPlayer(char* name, int money, unsigned int maxHealth);
