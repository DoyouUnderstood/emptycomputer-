#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{
    // the X position of the light of power
    int light_x;
    // the Y position of the light of power
    int light_y;
    // Thor's starting X position
    int initial_tx;
    // Thor's starting Y position
    int initial_ty;
    scanf("%d%d%d%d", &light_x, &light_y, &initial_tx, &initial_ty);

    // game loop
    while (1) {
        // The remaining amount of turns Thor can move. Do not remove this line.
        int remaining_turns;
        scanf("%d", &remaining_turns);
        char direction_X = ' ';
        char direction_Y = ' ';

        if(initial_tx < light_x)
        {
            initial_tx++;
            direction_X = 'E';
        }
        if(initial_tx > light_x)
        {
            initial_tx--;
            direction_X = 'W';
        }
        if(initial_ty < light_y)
        {
            initial_ty++;
            direction_Y = 'N';
        }
        if(initial_ty > light_y)
        {
            initial_ty++;
            direction_Y = 'S';
        }
        printf("%c%c\n", direction_X,direction_Y);
    }

    return 0;
}