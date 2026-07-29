#ifndef FLIGHT_H
#define FLIGHT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 100
#define FLIGHT_ID_LEN 20
#define CITY_LEN 20
#define TIME_LEN 20

typedef struct {
    char flight_id[FLIGHT_ID_LEN];
    char start_city[CITY_LEN];
    char end_city[CITY_LEN];
    char start_time[TIME_LEN];
    char end_time[TIME_LEN];
    int total_seats;
    int available_seats;
    float price;
} Flight;


typedef struct {
    Flight flights[MAX_FLIGHTS];
    int count;
} FlightSystem;

void clear_input_buffer(void);
void init_system(FlightSystem *sys);
void show_menu(void);
void display_flight(Flight *f);
void display_all_flights(FlightSystem *sys);
Flight* find_flight(FlightSystem *sys,char *flight_id);
void search_flight(FlightSystem *sys);
int add_flight(FlightSystem *sys);
int delete_flight(FlightSystem *sys);
int modify_flight(FlightSystem *sys);

#endif