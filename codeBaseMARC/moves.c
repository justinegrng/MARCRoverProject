//
// Created by flasque on 19/10/2024.
//

#include "moves.h"
#include <string.h>
#include <stdio.h>
#include "map.h"
#include <stdlib.h>

/* prototypes of local functions */
/* local functions are used only in this file, as helper functions */

/**
 * @brief Function to rotate the robot according to a move and its actual orientation
 * @param ori : the actual orientation of the robot
 * @param move : the move to do
 * @return the new orientation of the robot
 */
t_orientation rotate(t_orientation, t_move );

/**
 * @brief function to translate the robot according to a move and its actual position
 * @param loc : the actual localisation of the robot
 * @param move : the move to do
 * @return the new localisation of the robot
 */
t_localisation translate(t_localisation , t_move);

/* definition of local functions */

t_orientation rotate(t_orientation ori, t_move move)
{
    int rst;
    switch (move)
    {
        case T_LEFT:
            rst=3;
            break;
        case T_RIGHT:
            rst=1;
            break;
        case U_TURN:
            rst=2;
            break;
        default:
            break;
    }
    return (ori+rst)%4;
}

t_localisation translate(t_localisation loc, t_move move)
{
    /** rules for coordinates:
     *  - x grows to the right with step of +1
     *  - y grows to the bottom with step of +1
     *  - the origin (x=0, y=0) is at the top left corner
     */
    t_position res = loc.pos;
    switch (move) {
        case F_10:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y - 1;
                    break;
                case EAST:
                    res.x = loc.pos.x + 1;
                    break;
                case SOUTH:
                    res.y = loc.pos.y + 1;
                    break;
                case WEST:
                    res.x = loc.pos.x - 1;
                    break;
                default:
                    break;
            }
            break;
        case F_20:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y - 2;
                    break;
                case EAST:
                    res.x = loc.pos.x + 2;
                    break;
                case SOUTH:
                    res.y = loc.pos.y + 2;
                    break;
                case WEST:
                    res.x = loc.pos.x - 2;
                    break;
                default:
                    break;
            }
            break;
        case F_30:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y - 3;
                    break;
                case EAST:
                    res.x = loc.pos.x + 3;
                    break;
                case SOUTH:
                    res.y = loc.pos.y + 3;
                    break;
                case WEST:
                    res.x = loc.pos.x - 3;
                    break;
                default:
                    break;
            }
            break;
        case B_10:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y + 1;
                    break;
                case EAST:
                    res.x = loc.pos.x - 1;
                    break;
                case SOUTH:
                    res.y = loc.pos.y - 1;
                    break;
                case WEST:
                    res.x = loc.pos.x + 1;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
        return loc_init(res.x, res.y, loc.ori);

}

/* definitions of exported functions */

char *getMoveAsString(t_move move)
{
    return _moves[move];
}

t_localisation move(t_localisation loc, t_move move)
{
    t_localisation new_loc;
    new_loc.ori = rotate(loc.ori, move);
    new_loc = translate(loc, move);
    return new_loc;
}

void updateLocalisation(t_localisation *p_loc, t_move m)
{
    *p_loc = move(*p_loc, m);
    return;
}

void displayMapWithRover(t_map map, t_localisation loc) {
    for (int i = 0; i < map.y_max; i++) {
        for (int rep = 0; rep < 3; rep++) {
            for (int j = 0; j < map.x_max; j++) {
                if (i == loc.pos.y && j == loc.pos.x && rep == 1) {
                    printf(" R ");
                } else {
                    char c[4];
                    switch (map.soils[i][j]) {
                        case BASE_STATION:
                            if (rep == 1) {
                                strcpy(c, " B ");
                            } else {
                                strcpy(c, "   ");
                            }
                            break;
                        case PLAIN:
                            strcpy(c, "---");
                            break;
                        case ERG:
                            strcpy(c, "~~~");
                            break;
                        case REG:
                            strcpy(c, "^^^");
                            break;
                        case CREVASSE:
                            sprintf(c, "%c%c%c", 219, 219, 219);
                            break;
                        default:
                            strcpy(c, "???");
                            break;
                    }
                    printf("%s", c);
                }
            }
            printf("\n");
        }
    }
}

int isAtBaseStation(t_map map, t_localisation loc)
{
    return map.soils[loc.pos.y][loc.pos.x] == BASE_STATION;
}

int isOutOfMap(t_map map, t_localisation loc)
{
    return loc.pos.x < 0 || loc.pos.x >= map.x_max || loc.pos.y < 0 || loc.pos.y >= map.y_max;
}

int isOnCrevasse(t_map map, t_localisation loc)
{
    return map.soils[loc.pos.y][loc.pos.x] == CREVASSE;
}

t_move getRandomMove()
{
    return (t_move)(rand()%7);
}


void applyOptimalSequence(t_localisation* loc, t_move* sequence, int length) {
    for (int i = 0; i < length; i++) {
        updateLocalisation(loc, sequence[i]);
    }
}