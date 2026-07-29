#include "../include/flight.h"

// 初始化系统（预置示例数据）
void init_system(FlightSystem *sys) {
    sys->count = 0;

    strcpy(sys->flights[0].flight_id, "CC123");
    strcpy(sys->flights[0].start_city, "重庆");
    strcpy(sys->flights[0].end_city, "成都");
    strcpy(sys->flights[0].start_time, "8:30");
    strcpy(sys->flights[0].end_time, "13:00");
    sys->flights[0].total_seats = 200;
    sys->flights[0].available_seats = 50;
    sys->flights[0].price = 300;

    strcpy(sys->flights[1].flight_id, "CS456");
    strcpy(sys->flights[1].start_city, "重庆");
    strcpy(sys->flights[1].end_city, "上海");
    strcpy(sys->flights[1].start_time, "9:30");
    strcpy(sys->flights[1].end_time, "15:00");
    sys->flights[1].total_seats = 200;
    sys->flights[1].available_seats = 60;
    sys->flights[1].price = 500;

    strcpy(sys->flights[2].flight_id, "CB789");
    strcpy(sys->flights[2].start_city, "重庆");
    strcpy(sys->flights[2].end_city, "北京");
    strcpy(sys->flights[2].start_time, "7:30");
    strcpy(sys->flights[2].end_time, "19:00");
    sys->flights[2].total_seats = 200;
    sys->flights[2].available_seats = 20;
    sys->flights[2].price = 800;

    sys->count = 3;
}

// 显示菜单
void show_menu(void) {
    printf("\n");
    printf("航班信息管理系统:\n");
    printf("1. 查看所有航班信息\n");
    printf("2. 增加航班\n");
    printf("3. 删除航班\n");
    printf("4. 修改航班信息\n");
    printf("5. 查找航班\n");
    printf("0. 退出系统\n");
    printf("请选择操作: ");
}