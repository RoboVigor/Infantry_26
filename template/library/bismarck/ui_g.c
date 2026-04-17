//
// Created by RM UI Designer
// Static Edition
//

#include <string.h>

#include "ui_interface.h"

ui_7_frame_t ui_g_Assault_0;

ui_interface_line_t *ui_g_Assault_line6 = (ui_interface_line_t*)&(ui_g_Assault_0.data[0]);
ui_interface_line_t *ui_g_Assault_Line1 = (ui_interface_line_t*)&(ui_g_Assault_0.data[1]);
ui_interface_line_t *ui_g_Assault_Line2 = (ui_interface_line_t*)&(ui_g_Assault_0.data[2]);
ui_interface_line_t *ui_g_Assault_Line0 = (ui_interface_line_t*)&(ui_g_Assault_0.data[3]);
ui_interface_line_t *ui_g_Assault_Line3 = (ui_interface_line_t*)&(ui_g_Assault_0.data[4]);
ui_interface_line_t *ui_g_Assault_line4 = (ui_interface_line_t*)&(ui_g_Assault_0.data[5]);
ui_interface_line_t *ui_g_Assault_line5 = (ui_interface_line_t*)&(ui_g_Assault_0.data[6]);

void _ui_init_g_Assault_0() {
    for (int i = 0; i < 7; i++) {
        ui_g_Assault_0.data[i].figure_name[0] = 0;
        ui_g_Assault_0.data[i].figure_name[1] = 0;
        ui_g_Assault_0.data[i].figure_name[2] = i + 0;
        ui_g_Assault_0.data[i].operate_type = 1;
    }
    for (int i = 7; i < 7; i++) {
        ui_g_Assault_0.data[i].operate_type = 0;
    }

    ui_g_Assault_line6->figure_type = 0;
    ui_g_Assault_line6->operate_type = 1;
    ui_g_Assault_line6->layer = 1;
    ui_g_Assault_line6->color = 2;
    ui_g_Assault_line6->start_x = 1040;
    ui_g_Assault_line6->start_y = 380;
    ui_g_Assault_line6->width = 3;
    ui_g_Assault_line6->end_x = 1040;
    ui_g_Assault_line6->end_y = 700;

    ui_g_Assault_Line1->figure_type = 0;
    ui_g_Assault_Line1->operate_type = 1;
    ui_g_Assault_Line1->layer = 1;
    ui_g_Assault_Line1->color = 2;
    ui_g_Assault_Line1->start_x = 800;
    ui_g_Assault_Line1->start_y = 540;
    ui_g_Assault_Line1->width = 3;
    ui_g_Assault_Line1->end_x = 1120;
    ui_g_Assault_Line1->end_y = 540;

    ui_g_Assault_Line2->figure_type = 0;
    ui_g_Assault_Line2->operate_type = 1;
    ui_g_Assault_Line2->layer = 1;
    ui_g_Assault_Line2->color = 2;
    ui_g_Assault_Line2->start_x = 800;
    ui_g_Assault_Line2->start_y = 460;
    ui_g_Assault_Line2->width = 3;
    ui_g_Assault_Line2->end_x = 1120;
    ui_g_Assault_Line2->end_y = 460;

    ui_g_Assault_Line0->figure_type = 0;
    ui_g_Assault_Line0->operate_type = 1;
    ui_g_Assault_Line0->layer = 1;
    ui_g_Assault_Line0->color = 2;
    ui_g_Assault_Line0->start_x = 800;
    ui_g_Assault_Line0->start_y = 640;
    ui_g_Assault_Line0->width = 3;
    ui_g_Assault_Line0->end_x = 1120;
    ui_g_Assault_Line0->end_y = 640;

    ui_g_Assault_Line3->figure_type = 0;
    ui_g_Assault_Line3->operate_type = 1;
    ui_g_Assault_Line3->layer = 1;
    ui_g_Assault_Line3->color = 2;
    ui_g_Assault_Line3->start_x = 800;
    ui_g_Assault_Line3->start_y = 420;
    ui_g_Assault_Line3->width = 3;
    ui_g_Assault_Line3->end_x = 1120;
    ui_g_Assault_Line3->end_y = 420;

    ui_g_Assault_line4->figure_type = 0;
    ui_g_Assault_line4->operate_type = 1;
    ui_g_Assault_line4->layer = 1;
    ui_g_Assault_line4->color = 2;
    ui_g_Assault_line4->start_x = 960;
    ui_g_Assault_line4->start_y = 380;
    ui_g_Assault_line4->width = 3;
    ui_g_Assault_line4->end_x = 960;
    ui_g_Assault_line4->end_y = 700;

    ui_g_Assault_line5->figure_type = 0;
    ui_g_Assault_line5->operate_type = 1;
    ui_g_Assault_line5->layer = 1;
    ui_g_Assault_line5->color = 2;
    ui_g_Assault_line5->start_x = 880;
    ui_g_Assault_line5->start_y = 380;
    ui_g_Assault_line5->width = 3;
    ui_g_Assault_line5->end_x = 880;
    ui_g_Assault_line5->end_y = 700;


    ui_proc_7_frame(&ui_g_Assault_0);
    SEND_MESSAGE((uint8_t *) &ui_g_Assault_0, sizeof(ui_g_Assault_0));
}

void _ui_update_g_Assault_0() {
    for (int i = 0; i < 7; i++) {
        ui_g_Assault_0.data[i].operate_type = 2;
    }

    ui_proc_7_frame(&ui_g_Assault_0);
    SEND_MESSAGE((uint8_t *) &ui_g_Assault_0, sizeof(ui_g_Assault_0));
}

void _ui_remove_g_Assault_0() {
    for (int i = 0; i < 7; i++) {
        ui_g_Assault_0.data[i].operate_type = 3;
    }

    ui_proc_7_frame(&ui_g_Assault_0);
    SEND_MESSAGE((uint8_t *) &ui_g_Assault_0, sizeof(ui_g_Assault_0));
}


void ui_init_g_Assault() {
    _ui_init_g_Assault_0();
}

void ui_update_g_Assault() {
    _ui_update_g_Assault_0();
}

void ui_remove_g_Assault() {
    _ui_remove_g_Assault_0();
}

ui_2_frame_t ui_g_Dynamic_0;

ui_interface_line_t *ui_g_Dynamic_Enegry = (ui_interface_line_t*)&(ui_g_Dynamic_0.data[0]);
ui_interface_round_t *ui_g_Dynamic_AimStatus = (ui_interface_round_t*)&(ui_g_Dynamic_0.data[1]);

void _ui_init_g_Dynamic_0() {
    for (int i = 0; i < 2; i++) {
        ui_g_Dynamic_0.data[i].figure_name[0] = 0;
        ui_g_Dynamic_0.data[i].figure_name[1] = 1;
        ui_g_Dynamic_0.data[i].figure_name[2] = i + 0;
        ui_g_Dynamic_0.data[i].operate_type = 1;
    }
    for (int i = 2; i < 2; i++) {
        ui_g_Dynamic_0.data[i].operate_type = 0;
    }

    ui_g_Dynamic_Enegry->figure_type = 0;
    ui_g_Dynamic_Enegry->operate_type = 1;
    ui_g_Dynamic_Enegry->layer = 9;
    ui_g_Dynamic_Enegry->color = 3;
    ui_g_Dynamic_Enegry->start_x = 760;
    ui_g_Dynamic_Enegry->start_y = 96;
    ui_g_Dynamic_Enegry->width = 10;
    ui_g_Dynamic_Enegry->end_x = 760;
    ui_g_Dynamic_Enegry->end_y = 156;

    ui_g_Dynamic_AimStatus->figure_type = 2;
    ui_g_Dynamic_AimStatus->operate_type = 1;
    ui_g_Dynamic_AimStatus->layer = 9;
    ui_g_Dynamic_AimStatus->color = 7;
    ui_g_Dynamic_AimStatus->start_x = 211;
    ui_g_Dynamic_AimStatus->start_y = 783;
    ui_g_Dynamic_AimStatus->width = 10;
    ui_g_Dynamic_AimStatus->r = 10;


    ui_proc_2_frame(&ui_g_Dynamic_0);
    SEND_MESSAGE((uint8_t *) &ui_g_Dynamic_0, sizeof(ui_g_Dynamic_0));
}

void _ui_update_g_Dynamic_0() {
    for (int i = 0; i < 2; i++) {
        ui_g_Dynamic_0.data[i].operate_type = 2;
    }

    ui_proc_2_frame(&ui_g_Dynamic_0);
    SEND_MESSAGE((uint8_t *) &ui_g_Dynamic_0, sizeof(ui_g_Dynamic_0));
}

void _ui_remove_g_Dynamic_0() {
    for (int i = 0; i < 2; i++) {
        ui_g_Dynamic_0.data[i].operate_type = 3;
    }

    ui_proc_2_frame(&ui_g_Dynamic_0);
    SEND_MESSAGE((uint8_t *) &ui_g_Dynamic_0, sizeof(ui_g_Dynamic_0));
}


void ui_init_g_Dynamic() {
    _ui_init_g_Dynamic_0();
}

void ui_update_g_Dynamic() {
    _ui_update_g_Dynamic_0();
}

void ui_remove_g_Dynamic() {
    _ui_remove_g_Dynamic_0();
}

ui_1_frame_t ui_g_Static_0;

ui_interface_rect_t *ui_g_Static_EnegryFrame = (ui_interface_rect_t*)&(ui_g_Static_0.data[0]);

void _ui_init_g_Static_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_Static_0.data[i].figure_name[0] = 0;
        ui_g_Static_0.data[i].figure_name[1] = 2;
        ui_g_Static_0.data[i].figure_name[2] = i + 0;
        ui_g_Static_0.data[i].operate_type = 1;
    }
    for (int i = 1; i < 1; i++) {
        ui_g_Static_0.data[i].operate_type = 0;
    }

    ui_g_Static_EnegryFrame->figure_type = 1;
    ui_g_Static_EnegryFrame->operate_type = 1;
    ui_g_Static_EnegryFrame->layer = 0;
    ui_g_Static_EnegryFrame->color = 6;
    ui_g_Static_EnegryFrame->start_x = 760;
    ui_g_Static_EnegryFrame->start_y = 96;
    ui_g_Static_EnegryFrame->width = 2;
    ui_g_Static_EnegryFrame->end_x = 1160;
    ui_g_Static_EnegryFrame->end_y = 156;


    ui_proc_1_frame(&ui_g_Static_0);
    SEND_MESSAGE((uint8_t *) &ui_g_Static_0, sizeof(ui_g_Static_0));
}

void _ui_update_g_Static_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_Static_0.data[i].operate_type = 2;
    }

    ui_proc_1_frame(&ui_g_Static_0);
    SEND_MESSAGE((uint8_t *) &ui_g_Static_0, sizeof(ui_g_Static_0));
}

void _ui_remove_g_Static_0() {
    for (int i = 0; i < 1; i++) {
        ui_g_Static_0.data[i].operate_type = 3;
    }

    ui_proc_1_frame(&ui_g_Static_0);
    SEND_MESSAGE((uint8_t *) &ui_g_Static_0, sizeof(ui_g_Static_0));
}

ui_string_frame_t ui_g_Static_1;
ui_interface_string_t* ui_g_Static_AutoAim = &(ui_g_Static_1.option);

void _ui_init_g_Static_1() {
    ui_g_Static_1.option.figure_name[0] = 0;
    ui_g_Static_1.option.figure_name[1] = 2;
    ui_g_Static_1.option.figure_name[2] = 1;
    ui_g_Static_1.option.operate_type = 1;

    ui_g_Static_AutoAim->figure_type = 7;
    ui_g_Static_AutoAim->operate_type = 1;
    ui_g_Static_AutoAim->layer = 9;
    ui_g_Static_AutoAim->color = 1;
    ui_g_Static_AutoAim->start_x = 43;
    ui_g_Static_AutoAim->start_y = 800;
    ui_g_Static_AutoAim->width = 2;
    ui_g_Static_AutoAim->font_size = 20;
    ui_g_Static_AutoAim->str_length = 7;
    strcpy(ui_g_Static_AutoAim->string, "AutoAim");


    ui_proc_string_frame(&ui_g_Static_1);
    SEND_MESSAGE((uint8_t *) &ui_g_Static_1, sizeof(ui_g_Static_1));
}

void _ui_update_g_Static_1() {
    ui_g_Static_1.option.operate_type = 2;

    ui_proc_string_frame(&ui_g_Static_1);
    SEND_MESSAGE((uint8_t *) &ui_g_Static_1, sizeof(ui_g_Static_1));
}

void _ui_remove_g_Static_1() {
    ui_g_Static_1.option.operate_type = 3;

    ui_proc_string_frame(&ui_g_Static_1);
    SEND_MESSAGE((uint8_t *) &ui_g_Static_1, sizeof(ui_g_Static_1));
}

void ui_init_g_Static_0() {
    _ui_init_g_Static_0();
}

void ui_update_g_Static_0() {
    _ui_update_g_Static_0();
}

void ui_remove_g_Static_0() {
    _ui_remove_g_Static_0();
}

void ui_init_g_Static_1() {
    _ui_init_g_Static_1();
}   

void ui_update_g_Static_1() {
    _ui_update_g_Static_1();
}

void ui_remove_g_Static_1() {
    _ui_remove_g_Static_1();
}
