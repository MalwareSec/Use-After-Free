#include <list>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>

/**
struct player {
	int32_t attack_pts;
    int32_t defense_pts;
    int32_t speed;
    int32_t precision;
    char *name;	
};
**/

struct Player {
	std::string name;
	long long player_num;
};

/**
class Player {
public:
	std::string name; 
	long long player_num;
};
**/

//No guard on purpose
// probably better to be a vector or list
std::map<int, Player> players;
std::list<Player*> team;
int next_idx = 1; 

int get_int() {
	char line[64] = {};
	fgets(line, 63, stdin);

	int output; 
	if (sscanf(line, "%i", &output) != 1) {
		puts("[*] Error! Protocol Error");
		exit(1);
	}

	return output;
}

long long get_ll() {
	char line[64] = {};
	fgets(line, 63, stdin);

	long long output; 
	if (sscanf(line, "%lli", &output) != 1) {
		puts("[*] Error! Protocol Error");
		exit(1);
	}

	return output;
}


void menu(void) {
	puts("Menu \n"
		"0. - Exit\n"
		"1. - Add Player \n"
		"2. - Remove Player\n"
		"3. - List Players\n"
		"4. - Add Player to Team\n"
		"5. - List Players on Team\n" 

		);
}

void add_player() {
	char buffer[1024];
	puts("Adding player....");
	printf("Name: ");

	fgets(buffer, 1023, stdin);
	sscanf(buffer, "%1023[^\n]", buffer);

	printf("Player Num: ");
	long long player_num = get_ll(); 

	
	Player temp1 = {buffer, player_num};
	players[next_idx] = temp1;
	

	printf("Added as %i\n", next_idx++);

}

void rem_player() {

	puts("[*] Removing Player... ");
	printf("Which Player ID? ");
	int player_id = get_int(); 

	if (players.find(player_id) != players.end()) {
		players.erase(player_id);
		puts("[*] Removed");
	} else {
		puts("[*] Error! Protocol Error");
		exit(1);
	}

}

void add_to_team() {

	puts("[*] Adding Player to Team...");
	printf("Which Player ID? ");

	int player_id = get_int(); 

	if (players.find(player_id) != players.end()) {
		team.push_back(&players[player_id]);
		puts("Added player to team!");
	} else {
		puts("[*] Error! Protocol Error");
		exit(1);
	}

}


void list_players(){
	puts("[*] Listing Players");
	for (const auto &player : players) {
		printf("%i. %s (%lli)\n", 
			player.first,
			player.second.name.c_str(),
			player.second.player_num);
	}
}

void list_team() {

	puts("[*] Listing Players on the Team");
	for (Player *player : team) {
		printf("%s (%lli)\n",
			player -> name.c_str(),
			player -> player_num);
	}

}

int main(void) {
	setbuf(stdout, NULL);
	//setlinebuf(stdin);
	puts("Welcome to the UAF game!");
	


	for (;;) {
		menu();
		printf("Choice: ");

		int choice = get_int(); 

		switch (choice) {
			
			case 1: add_player(); break;
			case 2: rem_player(); break;
			case 3: list_players(); break;
			case 4: add_to_team(); break;
			case 5: list_team(); break;

			case 0: puts("Bye!"); return 0;

			default:
				puts("Try Again!");
				continue;
		}

	}



	return 0;
}