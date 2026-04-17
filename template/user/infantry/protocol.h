#ifndef __PROTOCOL_H
#define __PROTOCOL_H
#include <stdint.h>

#pragma pack(push, 1)
/**
 * @file    protocol.h
 * @note    本文件由 Node_Bridge 生成, 请勿直接修改
 *
 * @note    Node     command_id
 *          裁判系统  0x0000 - 0x03FF
 *          上位机    0x0400 - 0x04FF
 *          板间通讯  0x0500 - 0x05FF
 *          裁判系统  0xF100 - 0xF1FF
 *          车间通讯  0xF200 - 0xF2FF
 * @version judge.yml v1.0
 * @version host.yml v0.1
 * @version user.yml v0.1
 */

/**********************************************************************
 *                              结构体
 **********************************************************************/

typedef struct {
    int32_t debug0;
    int32_t debug1;
    int32_t debug2;
    int32_t debug3;
    int32_t debug4;
    int32_t debug5;
    int32_t debug6;
    int32_t debug7;
} DebugData_Type;

typedef struct 
{
    float debug0;
    float debug1;
    float debug2;
    float debug3;
    float debug4;
    float debug5;
    float debug6;
    uint32_t vofaTail;
}VofaData_type;


/**********************************************************************
 *                              协议列表
 **********************************************************************/

typedef union {
    struct {
        uint8_t  game_type : 4;
        uint8_t  game_progress : 4;
        uint16_t stage_remain_time;
        uint64_t SyncTimeStamp;
    };
    struct {
        uint8_t data[11];
    };
} game_status_t;

typedef union {
    struct {
        uint8_t winner;
    };
    struct {
        uint8_t data[1];
    };
} game_result_t;

typedef union {
    struct {
        uint16_t ally_1_robot_HP;
        uint16_t ally_2_robot_HP;
        uint16_t ally_3_robot_HP;
        uint16_t ally_4_robot_HP;
        uint16_t reserved;
        uint16_t ally_7_robot_HP;
        uint16_t ally_outpost_HP;
        uint16_t ally_base_HP;
    };
    struct {
        uint8_t data[16];
    };
} game_robot_HP_t;


typedef union {
    struct {
        uint32_t event_type;
    };
    struct {
        uint8_t data[4];
    };
} event_data_t;

typedef union {
    struct 
   {
        uint8_t level;
        uint8_t offending_robot_id;
        uint8_t count;
        /* data */
    };
    struct {
        uint8_t data[3];
    };
} referee_warning_t;

typedef union {
    struct {
        uint8_t dart_remaining_time;
        uint16_t dart_info;
    };
    struct {
        uint8_t data[3];
    };
} dart_info_t;

typedef union {
    struct {
        uint8_t  robot_id;
        uint8_t  robot_level;
        uint16_t remain_HP;
        uint16_t max_HP;
        uint16_t shooter_barrel_cooling_value;
        uint16_t shooter_barrel_heat_limit; 
        uint16_t chassis_power_limit;
        uint8_t  mains_power_gimbal_output : 1;
        uint8_t  mains_power_chassis_output : 1;
        uint8_t  mains_power_shooter_output : 1;
    };
    struct {
        uint8_t data[13];
    };
} game_robot_status_t;

typedef union {
    struct {
        uint16_t reserved_0;
        uint16_t reserved_1;
        float    reserved_2;
        uint16_t chassis_power_buffer;
        uint16_t shooter_17mm_barrel_heat;
        uint16_t shooter_42mm_barrel_heat;
    };
    struct {
        uint8_t data[14];
    };
} power_heat_data_t;

typedef union {
    struct {
        float x;
        float y;
        float angle;
    };
    struct {
        uint8_t data[12];
    };
} game_robot_pos_t;

typedef union {
    struct {
        uint8_t recovery_buff;
        uint16_t cooling_buff;
        uint8_t defence_buff;
        uint8_t vulnerability_buff;
        uint16_t attack_buff;
        uint8_t remaining_energy;
    };
    struct {
        uint8_t data[8];
    };
} buff_info_t;

typedef union {
    struct {
        uint8_t attack_time;
    };
    struct {
        uint8_t data[1];
    };
} aerial_robot_energy_t;

typedef union {
    struct {
        uint8_t armor_id : 4;
        uint8_t hurt_type : 4;
    };
    struct {
        uint8_t data[1];
    };
} robot_hurt_t;

typedef union {
    struct {
        uint8_t bullet_type;
        uint8_t shooter_id;
        uint8_t bullet_freq;
        float   bullet_speed;
    };
    struct {
        uint8_t data[7];
    };
} shoot_data_t;

typedef union {
    struct {
        uint16_t bullet_remaining_num_17mm;
        uint16_t bullet_remaining_num_42mm;
        uint16_t coin_remaining_num;
        uint16_t projectile_allowance_fortress;
    };
    struct {
        uint8_t data[8];
    };
} bullet_remaining_t;

typedef union {
    struct {
        uint32_t rfid_status;
        uint8_t rfid_status_2;
    };
    struct {
        uint8_t data[5];
    };
} rfid_status_t;

typedef union {
    struct {
        uint8_t dart_launch_opening_status;
        uint8_t reserved;
        uint16_t target_change_time;
        uint16_t latest_launch_cmd_time;
    };
    struct {
        uint8_t data[6];
    };
} dart_client_cmd_t;

typedef union 
{
    struct 
    {   
        float hero_x;
        float hero_y;
        float engineer_x;
        float engineer_y;
        float standard_3_x;
        float standard_3_y;
        float standard_4_x;
        float standard_4_y;
        float reserved_0;
        float reserved_1;
        /* data */
    };

    struct
    {
        uint8_t data[40];
    };
    
    /* data */
} ground_robot_position_t;

typedef union 
{
    struct 
    {
        uint16_t mark_progress;
        /* data */
    };
    
    struct
    {
        uint8_t data[2];
    };
    /* data */
} radar_mark_data_t;

typedef union 
{
    struct 
    {
        uint32_t sentry_info;
        uint16_t sentry_info_2;
        /* data */
    };
    
    struct 
    {
        uint8_t data[6];
        /* data */
    };
    
    /* data */
} sentry_info_t;

typedef union 
{
    struct {
        uint8_t radar_info;
    };

    struct {
        uint8_t data[1];
    };
    /* data */
} radar_info_t;

typedef union
{
    struct 
    {
        uint16_t data_cmd_id;
        uint16_t sender_id;
        uint16_t receiver_id;
        uint8_t user_data[112];
        /* data */
    };
    
    struct 
    {
        uint8_t data[118];
        /* data */
    };
    
    /* data */
} robot_interaction_data_t;

typedef union 
{
    struct 
    {
        float target_position_x;
        float target_position_y;
        uint8_t cmd_keyboard;
        uint8_t target_robot_id;
        uint16_t cmd_source;
        /* data */
    };
    
    struct 
    {
        uint8_t data[12];
        /* data */
    };
    /* data */
} map_command_t;

typedef union 
{
    struct 
    {
        uint16_t hero_position_x;
        uint16_t hero_position_y;
        uint16_t engineer_position_x;
        uint16_t engineer_position_y;
        uint16_t infantry_3_position_x;
        uint16_t infantry_3_position_y;
        uint16_t infantry_4_position_x;
        uint16_t infantry_4_position_y;
        uint16_t reserved_0;
        uint16_t reserved_1;
        uint16_t sentry_position_x;
        uint16_t sentry_position_y; 
        /* data */
    };
    
    struct 
    {
        uint8_t data[24];
        /* data */
    };
    
    /* data */
}  map_robo_data_t;

typedef union 
{
    struct 
    {
        uint8_t intention;
        uint16_t start_posotion_x;
        uint16_t start_posotion_y;
        int8_t delta_x[49];
        int8_t delta_y[49];
        uint16_t sender_id;
        /* data */
    };
    
    struct 
    {
        uint8_t data[105];
        /* data */
    };
    
    /* data */
} map_data_t;

typedef union 
{
    struct 
    {
        uint16_t sender_id;
        uint16_t receiver_id;
        uint8_t user_data[30];
        /* data */
    };
    
    struct 
    {
        uint8_t data[34];
        /* data */
    };
    /* data */
} custom_info_t;

/**********************************************************************
 *                              图传链路数据
 **********************************************************************/

typedef union 
{
    struct 
    {
        uint8_t data[30];
        /* data */
    };
    
    /* data */
} custom_robot_data_t;

typedef union 
{
    struct 
    {
        uint8_t data[30];
        /* data */
    };
    
    /* data */
} robot_custom_data_t;

typedef union 
{
    struct 
    {
        uint8_t data[300]
        /* data */
    };
    
    /* data */
}robot_custom_client_data_t;

typedef union 
{
    struct 
    {
        uint8_t data[30];
        /* data */
    };
    
    /* data */
} custom_client_robot_data_t;

/**********************************************************************
 *                              机器人交互子内容
 **********************************************************************/

typedef union 
{
    struct 
    {
        uint8_t delete_type;
        uint8_t layer;
        /* data */
    };
    
    struct 
    {
        uint8_t data[2];
        /* data */
    };
    
    /* data */
} interaction_layer_delete_t;

typedef union 
{
    struct 
    {
        uint8_t figure_name[3];
        uint32_t operate_tpye:3;
        uint32_t figure_tpye:3;
        uint32_t layer:4;
        uint32_t color:4;
        uint32_t details_a:9;
        uint32_t details_b:9;
        uint32_t width:10;
        uint32_t start_x:11;
        uint32_t start_y:11;
        uint32_t details_c:10;
        uint32_t details_d:11;
        uint32_t details_e:11;
        /* data */
    };
    
    struct 
    {
        uint8_t data[15];
        /* data */
    };
    
    /* data */
}interaction_figure_t;

typedef union 
{
    struct 
    {
        interaction_figure_t interaction_figure[2];
        /* data */
    };
    
    struct 
    {
        uint8_t data[30];
        /* data */
    };
    
    /* data */
} interaction_figure_2_t;

typedef union 
{
    struct 
    {
        interaction_figure_t interaction_figure[5];
        /* data */
    };
    
    struct 
    {
        uint8_t data[75];
        /* data */
    };
    
    /* data */
} interaction_figure_5_t;

typedef union 
{
    struct 
    {
        interaction_figure_t interaction_figure[7];
        /* data */
    };
    
    struct 
    {
        uint8_t data[105];
        /* data */
    };
    
    /* data */
} interaction_figure_7_t;

typedef union 
{
    struct 
    {
        interaction_figure_t interaction_figure;
        uint8_t char_data[30];
        /* data */
    };
    
    struct 
    {
        uint8_t data[45];
        /* data */
    };
    
    /* data */
} ext_client_custom_character_t;

/**********************************************************************
 *                              自定义
 **********************************************************************/

typedef union {
    struct {
        DebugData_Type debugData;
    };
    struct 
    {
        VofaData_type vofaData;
    };
    struct {
        uint8_t data[32];
    };
} debug_info_t;

typedef union {
    struct {
        uint16_t code;
        char     text[22];
    };
    struct {
        uint8_t data[24];
    };
} error_info_t;

typedef union {
    struct {};
    struct {
        uint8_t data[0];
    };
} heartbeat_t;

typedef union {
    struct {
        float   yaw_angle_diff;
        float   pitch_angle_diff;
        uint8_t fire;
    };
    struct {
        uint8_t data[9];
    };
} autoaim_data_t;

typedef union {
    struct {
        float vx;
        float vy;
        float vw;
    };
    struct {
        uint8_t data[12];
    };
} chassis_data_t;

typedef union {
    struct {
        float yaw;
        float pitch;
        float roll;
    };
    struct {
        uint8_t data[12];
    };
} gyroscope_data_t;

typedef union {
    struct {
        uint8_t dbusBuffer[18];
    };
    struct {
        uint8_t data[18];
    };
} dbus_data_t;

typedef union {
    struct {
        uint16_t data_cmd_id;
        uint16_t send_id;
        uint16_t receiver_id;
        int32_t  data1;
        int32_t  data2;
        int32_t  data3;
        int32_t  data4;
    };
    struct {
        uint8_t data[22];
    };
} robot_interactive_data_t;

typedef union {
    struct {
        int32_t data1;
        int32_t data2;
        int32_t data3;
        int32_t data4;
    };
    struct {
        uint8_t data[16];
    };
} board_interactive_data_t;

typedef union 
{
    struct 
    {
        int16_t basePower;
        int16_t sate;
        int16_t maxDischargePower;
        int16_t energyPercentage;
    };

    struct 
    {
        uint8_t data[8];
    };
}superCapBoard_t;


/**********************************************************************
 *                              协议信息
 **********************************************************************/

#define PROTOCOL_INFO_LIST                                                                                                                                     \
    {                                                                                                                                                          \
        {0X0001, 11, 1}, {0X0002, 1, 1}, {0X0003, 16, 1}, {0X0101, 4, 1}, {0X0104, 3, 1}, {0X0105, 3, 1}, {0X0201, 13, 1},     \
            {0X0202, 14, 1}, {0X0203, 12, 1}, {0X0204, 8, 1}, {0X0206, 1, 1}, {0X0207, 7, 1}, {0X0208, 8, 1}, {0X0209, 5, 1}, {0X020A, 6, 1}, \
            {0x020B, 40, 1}, {0x020D, 6, 1}, {0x0301, 118, 0}, {0X1024, 32, 0}, {0X6666, 24, 0},\
            {0X0120, 0, 1}, {0X0401, 9, 1}, {0X0402, 12, 1}, {0X0403, 12, 0}, {0X0404, 18, 0}, {0XF301, 22, 1}, {0X0501, 16, 1}, {                             \
            0X0502, 16, 1                                                                                                                                      \
        }, {0x500, 8, 1}                                                                                                                                                   \
    }

/**********************************************************************
 *                              协议接口
 **********************************************************************/

typedef union {
    struct {
        game_status_t                  gameStatus;                  // 0X0001 比赛状态数据
        game_result_t                  gameResult;                  // 0X0002 比赛结果的数据
        game_robot_HP_t                healthPoint;                 // 0X0003 机器人血量数据
        event_data_t                   eventData;                   // 0X0101 场地事件数据
        referee_warning_t              refereeWarning;              // 0X0104 裁判警告信息
        dart_info_t                    dartRemainingtime;           // 0X0105 飞镖发射口倒计
        game_robot_status_t            gameRobotstatus;             // 0X0201 比赛机器人状态
        power_heat_data_t              powerHeatData;               // 0X0202 实时功率热量数据
        game_robot_pos_t               gameRobotpos;                // 0X0203 机器人位置
        buff_info_t                    buffInfo;                    // 0X0204 机器人增益
        robot_hurt_t                   robotHurt;                   // 0X0206 伤害状态
        shoot_data_t                   shootData;                   // 0X0207 实时射击信息
        bullet_remaining_t             bulletRemaining;             // 0X0208 子弹剩余发射数
        rfid_status_t                  rfidStatus;                  // 0X0209 机器人RFID状态
        dart_client_cmd_t              dartClientCmds;              // 0X020A 飞镖机器人客户端指令数据
        ground_robot_position_t        groundRobotPosition;         // 0X020B 地面机器人位置
        sentry_info_t                  sentryInfo;                  // 0X020D 哨兵信息
        robot_interaction_data_t       robotInteractionData;        // 0X0301 机器人交互数据
        debug_info_t                   debugInfo;                   // 0X1024 调试信息
        error_info_t                   errorInfo;                   // 0X6666 报错信息
        heartbeat_t                    heartbeat;                   // 0X0120 心跳包
        autoaim_data_t                 autoaimData;                 // 0X0401 云台控制
        chassis_data_t                 chassisData;                 // 0X0402 底盘控制
        gyroscope_data_t               gyroscopeData;               // 0X0403 陀螺仪数据
        dbus_data_t                    dbusData;                    // 0X0404 遥控器及键鼠数据
        robot_interactive_data_t       robotCommunication;          // 0XF301 学生机器人间通信
        board_interactive_data_t       boardAlpha;                  // 0X0501 主控板间通信
        board_interactive_data_t       boardBeta;                   // 0X0502 主控板间通信
        superCapBoard_t                superCapBoard                // 0x0500 超级电容
    };
    struct {
        uint8_t data[753];
    };
} ProtocolData_Type;

#pragma pack(pop)

#endif
