#include <stdio.h>
#include <limits.h>

#define ELEV_ERROR INT_MIN
#define ELEV_NAME_SIZE 64

typedef struct Elevator{
    int min_floor;
    int max_floor;
    int current_floor;
    char elev_name[ELEV_NAME_SIZE];
} Elevator;

int call_elevator(Elevator *elevp, int call_floor);
int go_up_elevator(Elevator *elevp);
int go_down_elevator(Elevator *elevp);

int main() {
    Elevator elev1 = {1, 10, 1, "Elevator 1"};
    //Elevator elev2 = {-3, 5, 0, "Elevator with 3 basements"};
    call_elevator(&elev1, 10);
    call_elevator(&elev1, 10);

    call_elevator(&elev1, 4);
    call_elevator(&elev1, 100);
    return 0;
}

int go_up_elevator(Elevator *elevp) {
    if (elevp->current_floor >= elevp->max_floor) {
        printf("Can't go upper, max floor was reached\n");
        return elevp->max_floor;
    }
    printf("%s : Floor %d, going up...\n", elevp->elev_name, elevp->current_floor);
    return ++elevp->current_floor;
}

int go_down_elevator(Elevator *elevp) {
    if (elevp->current_floor <= elevp->min_floor) {
        printf("Can't go lower, min floor was reached\n");
        return elevp->min_floor;
    }
    printf("%s : Floor %d, going down...\n", elevp->elev_name, elevp->current_floor);
    return --elevp->current_floor;
}

int call_elevator(Elevator *elevp, int call_floor) {
    if (call_floor < elevp->min_floor || call_floor > elevp->max_floor) {
        printf("Non correct floor, %s can't reach %d floor\n", elevp->elev_name, call_floor);       
        return ELEV_ERROR;
    }
    else if (call_floor == elevp->current_floor) {
        printf("%s : Already at %d floor, Openning Door\n\n", elevp->elev_name, call_floor);
        return call_floor;
    }
    for (int floor = elevp->current_floor; floor != call_floor; ) {
        if (floor < call_floor) {
            floor = go_up_elevator(elevp);
        }
        else {
            floor = go_down_elevator(elevp);
        }
        //sleep(1);
    }
    printf("%s : Reach %d floor, Openning Door\n\n", elevp->elev_name, call_floor);
    return call_floor;
}