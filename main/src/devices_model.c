#include "include/devices_model.h"

#include <string.h>
#include "sdkconfig.h"

static display_device_config_t *_display_config = NULL;
static joystick_device_config_t *_joystick_config = NULL;

static void _display_model_init(void);
static void _joystick_model_init(void);

void devices_model_init(void)
{
    _display_model_init();
    _joystick_model_init();
}

joystick_device_config_t devices_model_get_joystick(void)
{
    return *_joystick_config;
}

display_device_config_t devices_model_get_display(void)
{
    return *_display_config;
}

static void _joystick_model_init(void)
{
    if (!(_joystick_config == NULL))
        return;

    _joystick_config = calloc(1, sizeof(joystick_device_config_t));

    joystick_device_config_t joystick_config_default = {
        .sw_pin = CONFIG_SW_PIN,
        .x_adc_config = {
            .handle = NULL,
            .unit = CONFIG_X_ADC_UNIT,
            .channel = CONFIG_X_ADC_CHANNEL,
        },
        .y_adc_config = {
            .handle = NULL,
            .unit = CONFIG_Y_ADC_UNIT,
            .channel = CONFIG_Y_ADC_CHANNEL,
        }};

    memcpy(_joystick_config, &joystick_config_default, sizeof(joystick_device_config_t));
}

static void _display_model_init(void)
{
    if (!(_display_config == NULL))
        return;

    _display_config = (display_device_config_t *)calloc(1, sizeof(display_device_config_t));

    display_device_config_t display_config_default = {
        .rs = CONFIG_DISPLAY_RS,
        .en = CONFIG_DISPLAY_EN,
        .d4 = CONFIG_DISPLAY_D4,
        .d5 = CONFIG_DISPLAY_D5,
        .d6 = CONFIG_DISPLAY_D6,
        .d7 = CONFIG_DISPLAY_D7,
    };

    memcpy(_display_config, &display_config_default, sizeof(display_device_config_t));
}