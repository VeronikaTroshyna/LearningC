#include <stdio.h>
#include <limits.h>

#if _WIN64 || _WIN32
#include <windows.h>
#else 
#include <unistd.h>
#endif

#define ELEV_ERROR INT_MIN

void sleep_wrap(int ms) {
#if _WIN64 || _WIN32
    Sleep(ms);
#else 
    sleep(ms / 1000);
#endif
}

typedef struct Elevator{
    int min_floor;
    int max_floor;
    int current_floor;
    char elev_name[20];
} Elevator;

void simulate_person(Elevator *elevp);

int call_elevator(Elevator *elevp, int call_floor);
int go_up_elevator(Elevator *elevp);
int go_down_elevator(Elevator *elevp);

int main() {
    Elevator elev1 = {
        .min_floor = 1,
        .max_floor = 10,
        .current_floor = 1, 
        .elev_name = "Elevator 1"
    };

    simulate_person(&elev1);

    return 0;
}

void simulate_person(Elevator *elevp) {
    int person_floor = 0;
    char user_inp;

    while(1) {
        printf("-- Write floor where YOU are.\n> ");
        scanf("%d", &person_floor);
        printf("-- Call Elevator at floor %d\n", person_floor);
        if (call_elevator(elevp, person_floor) == ELEV_ERROR) {
            printf("-- Error in Elevator : %s\n", elevp->elev_name);
        }
        else {
            printf("-- Entering Lift. Write floor were to go\n> ");
            scanf("%d", &person_floor);
            printf("%s : Danger! Closing door.\n", elevp->elev_name);
            while (call_elevator(elevp, person_floor) == ELEV_ERROR) {
                printf("-- Choose floor again\n> ");    
                scanf("%d", &person_floor);
            }
            printf("-- Elevator reach needed floor. Exit Lift\n");
        }
        printf("Continue simulate ? y/n\n");
        scanf(" %c", &user_inp);
        if (user_inp != 'y')
            break;
    }
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
        sleep_wrap(1000);
    }
    printf("%s : Reach %d floor, Openning Door\n\n", elevp->elev_name, call_floor);
    return call_floor;
}