#pragma once
#include <cstdint>
#include <string>

using namespace System;

template <typename T> T CLAMP(const T& value, const T& low, const T& high)
{
    return value < low ? low : (value > high ? high : value);
}

#ifndef JCTOOL_TYPEDEFS_DEFINED
#define JCTOOL_TYPEDEFS_DEFINED
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
#endif // JCTOOL_TYPEDEFS_DEFINED

#pragma pack(push, 1)

struct brcm_hdr {
    u8 cmd;
    u8 timer;
    u8 rumble_l[4];
    u8 rumble_r[4];
};

struct brcm_cmd_01 {
    u8 subcmd;
    union {
        struct {
            u32 offset;
            u8 size;
        } spi_data;

        struct {
            u8 arg1;
            u8 arg2;
        } subcmd_arg;

        struct {
            u8  mcu_cmd;
            u8  mcu_subcmd;
            u8  mcu_mode;
        } subcmd_21_21;

        struct {
            u8  mcu_cmd;
            u8  mcu_subcmd;
            u8  no_of_reg;
            u16 reg1_addr;
            u8  reg1_val;
            u16 reg2_addr;
            u8  reg2_val;
            u16 reg3_addr;
            u8  reg3_val;
            u16 reg4_addr;
            u8  reg4_val;
            u16 reg5_addr;
            u8  reg5_val;
            u16 reg6_addr;
            u8  reg6_val;
            u16 reg7_addr;
            u8  reg7_val;
            u16 reg8_addr;
            u8  reg8_val;
            u16 reg9_addr;
            u8  reg9_val;
        } subcmd_21_23_04;

        struct {
            u8  mcu_cmd;
            u8  mcu_subcmd;
            u8  mcu_ir_mode;
            u8  no_of_frags;
            u16 mcu_major_v;
            u16 mcu_minor_v;
        } subcmd_21_23_01;
    };
};

struct ir_image_config {
    u8  ir_res_reg;
    u16 ir_exposure;
    u8  ir_leds; // Leds to enable, Strobe/Flashlight modes
    u16 ir_leds_intensity; // MSByte: Leds 1/2, LSB: Leds 3/4
    u8  ir_digital_gain;
    u8  ir_ex_light_filter;
    u32 ir_custom_register; // MSByte: Enable/Disable, Middle Byte: Edge smoothing, LSB: Color interpolation
    u16 ir_buffer_update_time;
    u8  ir_hand_analysis_mode;
    u8  ir_hand_analysis_threshold;
    u32 ir_denoise; // MSByte: Enable/Disable, Middle Byte: Edge smoothing, LSB: Color interpolation
    u8  ir_flip;
};

#pragma pack(pop)

extern s16 uint16_to_int16(u16 a);
extern void decode_stick_params(u16 *decoded_stick_params, u8 *encoded_stick_params);
extern void encode_stick_params(u8 *encoded_stick_params, u16 *decoded_stick_params);

extern std::string get_sn(u32 offset, const u16 read_len);
extern int get_spi_data(u32 offset, const u16 read_len, u8 *test_buf);
extern int write_spi_data(u32 offset, const u16 write_len, u8* test_buf);
extern int get_device_info(u8* test_buf);
extern int get_battery(u8* test_buf);
extern int get_temperature(u8* test_buf);
extern int dump_spi(const char *dev_name);
extern int send_rumble();
extern int play_tune(int tune_no);
extern int play_hd_rumble_file(int file_type, u16 sample_rate, int samples, int loop_start, int loop_end, int loop_wait, int loop_times);
extern int send_custom_command(u8* arg);
extern int device_connection();
extern int set_led_busy();
extern int button_test();
extern int ir_sensor(ir_image_config &ir_cfg);
extern int ir_sensor_config_live(ir_image_config &ir_cfg);
extern int nfc_tag_info();
extern int silence_input_report();
int  handle_ok;
bool enable_button_test;
bool enable_IRVideoPhoto;
bool enable_IRAutoExposure;
bool enable_NFCScanning;
bool cancel_spi_dump;
bool check_connection_ok;

u8 timming_byte;
u8 ir_max_frag_no;

namespace CppWinFormJoy {
    class images
    {
        //For annoying designer..
        //Todo.
    };
}