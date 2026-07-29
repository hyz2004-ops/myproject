#include "../include/flight.h"

int add_flight(FlightSystem *sys) {
    if (sys->count >= MAX_FLIGHTS) {
        printf("\n[错误] 航班数已达上限 %d,无法添加！\n", MAX_FLIGHTS);
        return 0;
    }

    Flight *new_flight = &sys->flights[sys->count];
    
    printf("\n添加新航班\n");

    printf("请输入航班号: ");
    scanf("%s", new_flight->flight_id);
    clear_input_buffer();

    // 检查航班号是否已存在
    if (find_flight(sys, new_flight->flight_id) != NULL) {
        printf("\n[错误] 航班号 %s 已存在！\n", new_flight->flight_id);
        return 0;
    }

    printf("请输入出发城市: ");
    scanf("%s", new_flight->start_city);
    clear_input_buffer();

    printf("请输入目的地: ");
    scanf("%s", new_flight->end_city);
    clear_input_buffer();

    printf("请输入起飞时间: ");
    scanf("%s", new_flight->start_time);
    clear_input_buffer();

    printf("请输入落地时间: ");
    scanf("%s", new_flight->end_time);
    clear_input_buffer();

    printf("请输入总座位数: ");
    scanf("%d", &new_flight->total_seats);
    clear_input_buffer();

    printf("请输入剩余座位数: ");
    scanf("%d", &new_flight->available_seats);
    clear_input_buffer();

    printf("请输入价格: ");
    scanf("%f", &new_flight->price);
    clear_input_buffer();

    sys->count++;
    printf("\n[成功] 航班 %s 添加成功，当前共 %d 条航班\n", 
           new_flight->flight_id, sys->count);
    return 1;
}