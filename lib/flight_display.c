#include "../include/flight.h"

// 显示单个航班
void display_flight(Flight *f) {
    printf("航班号:  %-26s\n", f->flight_id);
    printf("出发地:  %-26s\n", f->start_city);
    printf("目的地:  %-26s\n", f->end_city);
    printf("起飞时间: %-25s\n", f->start_time);
    printf("落地时间: %-25s\n", f->end_time);
    printf("总座位:  %-3d  剩余: %-3d \n",  f->total_seats, f->available_seats);
    printf("价格: ￥%-26.2f\n", f->price);

}

// 显示所有航班
void display_all_flights(FlightSystem *sys) {
    if (sys->count == 0) {
        printf("\n[提示] 当前没有航班信息！\n");
        return;
    }
    
    printf("\n 所有航班信息 \n");
    for (int i = 0; i < sys->count; i++) {
        printf("\n【第 %d 条航班】\n", i + 1);
        display_flight(&sys->flights[i]);
    }
    printf("\n共 %d 条航班记录\n", sys->count);
}