#include "../include/flight.h"

int modify_flight(FlightSystem *sys) {
    if (sys->count == 0) {
        printf("\n[提示] 当前没有航班可修改！\n");
        return 0;
    }

    char flight_id[FLIGHT_ID_LEN];
    printf("\n请输入要修改的航班号: ");
    scanf("%s", flight_id);
    clear_input_buffer();

    Flight *flight = find_flight(sys, flight_id);
    if (flight == NULL) {
        printf("\n[错误] 未找到航班号 %s\n", flight_id);
        return 0;
    }

    printf("\n修改航班信息\n");
    printf("当前航班信息:\n");
    display_flight(flight);

    int choice;
    while (1) {
        printf("\n请选择要修改的字段:\n");
        printf("1. 出发城市 (当前: %s)\n", flight->start_city);
        printf("2. 目的城市 (当前: %s)\n", flight->end_city);
        printf("3. 起飞时间 (当前: %s)\n", flight->start_time);
        printf("4. 到达时间 (当前: %s)\n", flight->end_time);
        printf("5. 总座位数 (当前: %d)\n", flight->total_seats);
        printf("6. 剩余座位数 (当前: %d)\n", flight->available_seats);
        printf("7. 票价 (当前: %.2f)\n", flight->price);
        printf("0. 保存并退出修改\n");
        printf("请选择: ");
        
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                printf("请输入新的出发城市: ");
                scanf("%s", flight->start_city);
                clear_input_buffer();
                printf("[已更新] 出发城市\n");
                break;
            case 2:
                printf("请输入新的目的城市: ");
                scanf("%s", flight->end_city);
                clear_input_buffer();
                printf("[已更新] 目的城市\n");
                break;
            case 3:
                printf("请输入新的起飞时间: ");
                scanf("%s", flight->start_time);
                clear_input_buffer();
                printf("[已更新] 起飞时间\n");
                break;
            case 4:
                printf("请输入新的到达时间: ");
                scanf("%s", flight->end_time);
                clear_input_buffer();
                printf("[已更新] 到达时间\n");
                break;
            case 5:
                printf("请输入新的总座位数: ");
                scanf("%d", &flight->total_seats);
                clear_input_buffer();
                printf("[已更新] 总座位数\n");
                break;
            case 6:
                printf("请输入新的剩余座位数: ");
                scanf("%d", &flight->available_seats);
                clear_input_buffer();
                printf("[已更新] 剩余座位数\n");
                break;
            case 7:
                printf("请输入新的票价: ");
                scanf("%f", &flight->price);
                clear_input_buffer();
                printf("[已更新] 票价\n");
                break;
            case 0:
                printf("\n[成功] 航班 %s 修改完成！\n", flight_id);
                return 1;
            default:
                printf("\n[提示] 无效选择，请重新输入\n");
        }
    }
}