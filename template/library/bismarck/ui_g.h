//
// Created by RM UI Designer
// Static Edition
//

#ifndef UI_g_H
#define UI_g_H

#include "ui_interface.h"

extern ui_interface_line_t *ui_g_Assault_line6;
extern ui_interface_line_t *ui_g_Assault_Line1;
extern ui_interface_line_t *ui_g_Assault_Line2;
extern ui_interface_line_t *ui_g_Assault_Line0;
extern ui_interface_line_t *ui_g_Assault_Line3;
extern ui_interface_line_t *ui_g_Assault_line4;
extern ui_interface_line_t *ui_g_Assault_line5;

void ui_init_g_Assault();
void ui_update_g_Assault();
void ui_remove_g_Assault();

extern ui_interface_line_t *ui_g_Dynamic_Enegry;
extern ui_interface_round_t *ui_g_Dynamic_AimStatus;

void ui_init_g_Dynamic();
void ui_update_g_Dynamic();
void ui_remove_g_Dynamic();

extern ui_interface_rect_t *ui_g_Static_EnegryFrame;
extern ui_interface_string_t *ui_g_Static_AutoAim;

void ui_init_g_Static_0();
void ui_update_g_Static_0();
void ui_remove_g_Static_0();

void ui_init_g_Static_1();
void ui_update_g_Static_1();
void ui_remove_g_Static_1();


#endif // UI_g_H
