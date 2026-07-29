#include "../include/flight.h"

int delete_flight(FlightSystem *sys) {
    if (sys->count == 0) {
        printf("\n[提示] 当前没有航班可删除！\n");
        return 0;
    }

    char flight_id[FLIGHT_ID_LEN];
    printf("\n请输入要删除的航班号: ");
    scanf("%s", flight_id);
    clear_input_buffer();

    int index = -1;
    for (int i = 0; i < sys->count; i++) {
        if (strcmp(sys->flights[i].flight_id, flight_id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\n[错误] 未找到航班号 %s\n", flight_id);
        return 0;
    }

    printf("\n即将删除以下航班:\n");
    display_flight(&sys->flights[index]);

    char confirm;
    printf("确定删除? (y/n): ");
    scanf("%c", &confirm);
    clear_input_buffer();

    if (confirm != 'y' && confirm != 'Y') {
        printf("\n[提示] 已取消删除操作\n");
        return 0;
    }

    // 将后面的航班前移覆盖
    for (int i = index; i < sys->count - 1; i++) {
        sys->flights[i] = sys->flights[i + 1];
    }

    sys->count--;
    printf("\n[成功] 航班 %s 已删除，剩余 %d 条航班\n", 
           flight_id, sys->count);
    return 1;
}