#include "../include/flight.h"

int main(void) {
    FlightSystem system;
    int choice;
    int running = 1;

    init_system(&system);

    printf("\n");
    printf("欢迎使用航班信息管理系统\n");

    while (running) {
        show_menu();
        
        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("\n[错误] 请输入有效的数字选项！\n");
            continue;
        }
        clear_input_buffer();

        switch (choice) {
            case 1:
                display_all_flights(&system);
                break;
            case 2:
                add_flight(&system);
                break;
            case 3:
                delete_flight(&system);
                break;
            case 4:
                modify_flight(&system);
                break;
            case 5:
                search_flight(&system);
                break;
            case 0:
                printf("\n感谢使用航班信息管理系统,再见！\n");
                running = 0;
                break;
            default:
                printf("\n[错误] 无效选项，请重新选择！\n");
        }
    }

    return 0;
}