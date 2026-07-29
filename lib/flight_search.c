#include "../include/flight.h"

// 按航班号查找（返回指针）
Flight* find_flight(FlightSystem *sys,char *flight_id) {
    for (int i = 0; i < sys->count; i++) {
        if (strcmp(sys->flights[i].flight_id, flight_id) == 0) {
            return &sys->flights[i];
        }
    }
    return NULL;
}

// 搜索航班（按航班号或城市名）
void search_flight(FlightSystem *sys) {
    if (sys->count == 0) {
        printf("\n[提示] 当前没有航班信息！\n");
        return;
    }

    char keyword[FLIGHT_ID_LEN];
    printf("\n请输入航班号或城市名进行查找: ");
    scanf("%s", keyword);
    clear_input_buffer();

    int found = 0;
    printf("\n查找结果\n");
    
    for (int i = 0; i < sys->count; i++) {
        if (strcmp(sys->flights[i].flight_id, keyword) == 0 ||
            strcmp(sys->flights[i].start_city, keyword) == 0 ||
            strcmp(sys->flights[i].end_city, keyword) == 0) {
            display_flight(&sys->flights[i]);
            found++;
        }
    }

    if (found == 0) {
        printf("\n[提示] 未找到匹配的航班信息\n");
    } else {
        printf("\n共找到 %d 条匹配信息\n", found);
    }
}