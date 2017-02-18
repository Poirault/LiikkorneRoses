
#include <influence-client.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void attak(x,y,a_x,a_y){
	infl_client_attack(client, x, y, a_x, a_y);
	printf("Attaque (%d, %d) -> (%d, %d)\n", x, y, a_x, a_y);
}
