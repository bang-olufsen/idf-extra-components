/**
 * @file tusb_audio.h
 * @author Kasper Nyhus (kank@bang-olufsen.dk)
 * @brief
 * @version 0.1
 * @date 2022-10-23
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "sdkconfig.h"
#include "tusb.h"
#include <stdint.h>
#include "esp_err.h"

#if (CONFIG_TINYUSB_AUDIO_ENABLED != 1)
#error "TinyUSB AUDIO driver must be enabled in menuconfig"
#endif

/**
 * @brief On callback type
 */
typedef esp_err_t (*tusb_audio_cb_t)(void);

/**
 * @brief ESP TinyUSB Audio driver configuration structure
 */
typedef struct {
    tusb_audio_cb_t on_pre_callback;
    tusb_audio_cb_t on_post_callback;
    tusb_audio_cb_t on_get_sample_freq;
} tinyusb_audio_config_t;

/**
 * @brief Initialize USB Audio with audio callbacks
 *
 * @param cfg
 * @return esp_err_t
 */
esp_err_t tusb_audio_init(tinyusb_audio_config_t* cfg);

/**
 * @brief De-initialize USB audio driver
 *
 * @return esp_err_t
 */
esp_err_t tusb_audio_deinit(void);

#ifdef __cplusplus
}
#endif
