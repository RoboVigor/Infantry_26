#include "Driver_Remote.h"
#include "handle.h"

void Remote_Init(Remote_Type *remote, Keyboard_Type *kb, Mouse_Type *mouse) {
    remote->state = RemoteIdle;
    kb->state     = RemoteIdle;
    kb->seq       = 0;

    remote->ch1 = 0;
    remote->ch2 = 0;
    remote->ch3 = 0;
    remote->ch4 = 0;

    mouse->x = 0;
    mouse->y = 0;
    mouse->z = 0;

    kb->keyCode = 0;

#ifndef CONTROLLED_BY_DBUS
    remote->buttonPause.state     = OFF;
    remote->buttonPause.laststate = OFF;
    remote->buttonPause.isPressed = OFF;
    remote->buttonLeft.state      = OFF;
    remote->buttonLeft.laststate  = OFF;
    remote->buttonLeft.isPressed  = OFF;
    remote->buttonRight.state     = OFF;
    remote->buttonRight.laststate = OFF;
    remote->buttonRight.isPressed = OFF;
#endif
}

void Remote_Update(Remote_Type *remote, Keyboard_Type *kb, Mouse_Type *mouse, uint8_t RemoteBuffer[]) {
#ifdef CONTROLLED_BY_DBUS
    int i;
    remote->state = RemoteWorking;

    remote->ch1 = (RemoteBuffer[0] | RemoteBuffer[1] << 8) & 0x07FF;
    remote->ch1 -= 1024;
    remote->ch2 = (RemoteBuffer[1] >> 3 | RemoteBuffer[2] << 5) & 0x07FF;
    remote->ch2 -= 1024;
    remote->ch3 = (RemoteBuffer[2] >> 6 | RemoteBuffer[3] << 2 | RemoteBuffer[4] << 10) & 0x07FF;
    remote->ch3 -= 1024;
    remote->ch4 = (RemoteBuffer[4] >> 1 | RemoteBuffer[5] << 7) & 0x07FF;
    remote->ch4 -= 1024;

    remote->switchLeft  = ((RemoteBuffer[5] >> 4) & 0x000C) >> 2;
    remote->switchRight = (RemoteBuffer[5] >> 4) & 0x0003;

    mouse->x = RemoteBuffer[6] | (RemoteBuffer[7] << 8);
    mouse->y = RemoteBuffer[8] | (RemoteBuffer[9] << 8);
    mouse->z = RemoteBuffer[10] | (RemoteBuffer[11] << 8);

    mouse->pressLeft  = RemoteBuffer[12];
    mouse->pressRight = RemoteBuffer[13];

    // 按键禁用
    kb->seq             = (kb->seq++) % 1024;
    kb->keyDisabledCode = 0;
    for (i = 0; i < 15; i++) {
        if (kb->keyDisabledCounter[i] > 0) {
            kb->keyDisabledCounter[i]--;
            kb->keyDisabledCode += 1 << i;
        }
    }

    // kb->keyCode = (RemoteBuffer[14] | RemoteBuffer[15] << 8);
    // kb->keyCode = kb->keyCode & (~kb->keyDisabledCode);
    // kb->keyCode = kb->keyCode;

    kb->keyCode = (RemoteBuffer[14] | RemoteBuffer[15] << 8) & (~kb->keyDisabledCode);

    if (kb->keyCode != 0 || mouse->x != 0) {
        kb->state = RemoteWorking;
    }

#else
    remote->state = RemoteWorking;

    remote->ch1 = (RemoteBuffer[2] | RemoteBuffer[3] << 8) & 0x07FF;
    remote->ch1 -= 1024;
    remote->ch2 = (RemoteBuffer[3] >> 3 | RemoteBuffer[4] << 5) & 0x07FF;
    remote->ch2 -= 1024;
    remote->ch3 = (RemoteBuffer[4] >> 6 | RemoteBuffer[5] << 2 | RemoteBuffer[6] << 10) & 0x07FF;
    remote->ch3 -= 1024;
    remote->ch4 = (RemoteBuffer[6] >> 1 | RemoteBuffer[7] << 7) & 0x07FF;
    remote->ch4 -= 1024;

    remote->gearSwitch = (RemoteBuffer[7] & 0x30) >> 4;

    {
        ButtonState pauseRaw  = ((RemoteBuffer[7] & 0x40) >> 6) ? ON : OFF;
        ButtonState leftRaw   = ((RemoteBuffer[7] & 0x80) >> 7) ? ON : OFF;
        ButtonState rightRaw  = (RemoteBuffer[8] & 0x01) ? ON : OFF;

        remote->buttonPause.isPressed = pauseRaw;
        remote->buttonLeft.isPressed  = leftRaw;
        remote->buttonRight.isPressed = rightRaw;

        if (pauseRaw == ON && remote->buttonPause.laststate == OFF) {
            remote->buttonPause.state = (remote->buttonPause.state == ON) ? OFF : ON;
        }
        if (leftRaw == ON && remote->buttonLeft.laststate == OFF) {
            remote->buttonLeft.state = (remote->buttonLeft.state == ON) ? OFF : ON;
        }
        if (rightRaw == ON && remote->buttonRight.laststate == OFF) {
            remote->buttonRight.state = (remote->buttonRight.state == ON) ? OFF : ON;
        }

        remote->buttonPause.laststate = pauseRaw;
        remote->buttonLeft.laststate  = leftRaw;
        remote->buttonRight.laststate = rightRaw;
    }
    remote->dial                     = ((RemoteBuffer[8] >> 1 | RemoteBuffer[9] << 7) & 0x7ff) - 1024;
    remote->trigger                  = (RemoteBuffer[9] & 0x10) >> 4;

    mouse->x = RemoteBuffer[10] | (RemoteBuffer[11] << 8);
    mouse->y = RemoteBuffer[12] | (RemoteBuffer[13] << 8);
    mouse->z = RemoteBuffer[14] | (RemoteBuffer[15] << 8);

    mouse->pressLeft  = RemoteBuffer[16] & 0x03;
    mouse->pressRight = RemoteBuffer[16] & 0x0C;

    kb->keyCode = (RemoteBuffer[17] | RemoteBuffer[18] << 8);
#endif
}

void Key_Disable(Keyboard_Type *kb, uint16_t key, uint16_t duration) {
    kb->keyDisabledCounter[FastLog2(key)] = duration;
}
