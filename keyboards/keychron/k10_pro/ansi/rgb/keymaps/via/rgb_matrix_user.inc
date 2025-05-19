#include "palettefx.inc"

RGB_MATRIX_EFFECT(REACTIVE_FLOW)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool REACTIVE_FLOW(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  const uint16_t* palette = palettefx_get_palette_data();
  const uint8_t count = g_last_hit_tracker.count;
  const uint16_t time = palettefx_scaled_time(g_rgb_timer, 1 + rgb_matrix_config.speed / 8);

  // Flow effect rotation coefficients
  const int8_t rot_c = cos8(time / 4) - 128;
  const int8_t rot_s = sin8(time / 4) - 128;
  const uint8_t omega = 32 + sin8(time) / 4;

  // Reactive effect amplitude function
  uint8_t amplitude(uint8_t t) {
    if (t <= 55) {
      return (t < 32) ? (4 + 8 * t) : 255;
    } else {
      t = (((uint16_t)(255 - t)) * UINT16_C(164)) >> 7;
      return scale8(t, t);
    }
  }

  // Calculate hit amplitudes for reactive effect
  uint8_t hit_amplitude[LED_HITS_TO_REMEMBER] = {0};
  for (uint8_t j = 0; j < count; ++j) {
    const uint16_t tick = scale16by8(g_last_hit_tracker.tick[j],
        1 + rgb_matrix_config.speed / 4);
    if (tick <= 255) {
      hit_amplitude[j] = amplitude((uint8_t)tick);
    }
  }

  for (uint8_t i = led_min; i < led_max; ++i) {
    RGB_MATRIX_TEST_LED_FLAGS();
    const uint8_t x = g_led_config.point[i].x;
    const uint8_t y = g_led_config.point[i].y;

    // Calculate flow effect value
    const uint8_t x1 = (uint8_t)((((int16_t)rot_c) * ((int16_t)x)) / 128)
        - (uint8_t)((((int16_t)rot_s) * ((int16_t)y)) / 128);
    const uint8_t y1 = (uint8_t)((((int16_t)rot_s) * ((int16_t)x)) / 128)
        + (uint8_t)((((int16_t)rot_c) * ((int16_t)y)) / 128);

    uint8_t flow_value = scale8(sin8(x1 - 2 * time), omega) + y1 + time / 4;
    flow_value = 2 * ((flow_value <= 127) ? flow_value : (255 - flow_value));

    // Calculate reactive effect value
    uint8_t reactive_value = 0;
    for (uint8_t j = 0; j < count; ++j) {
      if (hit_amplitude[j] == 0) { continue; }

      uint8_t dx = abs8((x - g_last_hit_tracker.x[j]) / 2);
      uint8_t dy = abs8((y - g_last_hit_tracker.y[j]) / 2);
      if (dx < 21 && dy < 21) {
        const uint16_t dist_sqr = dx * dx + dy * dy;
        if (dist_sqr < 21 * 21) {
          const uint8_t dist = sqrt16(dist_sqr);
          reactive_value = qadd8(reactive_value, scale8(255 - 12 * dist, hit_amplitude[j]));
          if (reactive_value == 255) { break; }
        }
      }
    }

    // Blend flow and reactive values with complementary colors
    if (reactive_value > 0) {
      // Get the flow color's position in the palette (0-15)
      uint8_t flow_palette_pos = scale8(flow_value, 15);
      
      // Calculate the complementary position based on the current flow color
      uint8_t reactive_palette_pos = (flow_palette_pos + 8) % 16;
      
      // Scale down the reactive value to make the effect less aggressive
      reactive_value = scale8(reactive_value, 128);  // Reduced from 255 to 128
      
      // Get the base color from the flow effect
      hsv_t flow_hsv = palettefx_interp_color(palette, flow_value);
      // Get the complementary color
      hsv_t reactive_hsv = palettefx_interp_color(palette, reactive_palette_pos * 17);  // 17 = 255/15
      
      // Blend the colors based on reactive_value
      hsv_t final_hsv = {
        .h = lerp8by8(flow_hsv.h, reactive_hsv.h, reactive_value),
        .s = lerp8by8(flow_hsv.s, reactive_hsv.s, reactive_value),
        .v = lerp8by8(flow_hsv.v, reactive_hsv.v, reactive_value)
      };
      
      rgb_t rgb = rgb_matrix_hsv_to_rgb(final_hsv);
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
      continue;
    }
    
    // If no reactive effect, just use the flow value
    rgb_t rgb = rgb_matrix_hsv_to_rgb(palettefx_interp_color(palette, flow_value));
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
  }

  return rgb_matrix_check_finished_leds(led_max);
}

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS