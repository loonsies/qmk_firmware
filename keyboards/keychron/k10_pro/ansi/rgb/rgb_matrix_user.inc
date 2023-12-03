RGB_MATRIX_EFFECT(BREATHING_SPLASH)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

HSV BREATHING_SPLASH_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick - dist;
    if (effect > 255) effect = 255;
    effect = 255 - effect; // Reverse the effect to make it more roundish
    hsv.h += effect;
    hsv.v = qadd8(hsv.v, effect);
    return hsv;
}

bool BREATHING_SPLASH(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    // Breathing effect
    HSV hsv = rgb_matrix_config.hsv;
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    hsv.v = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);

    // Splash reactive effect
    uint8_t count = g_last_hit_tracker.count;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv_splash = hsv; // Initialize splash HSV with breathing effect HSV
        hsv_splash.v = 0;     // Set initial brightness to 0 for splash effect

        for (uint8_t j = 0; j < count; j++) {
            int16_t dx = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t dy = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1)) * 4;
            hsv_splash = BREATHING_SPLASH_math(hsv_splash, dx, dy, dist, tick);
        }

        // Combine breathing and splash effects
        hsv_splash.v = scale8(hsv_splash.v, rgb_matrix_config.hsv.v);
        hsv_splash.v = qadd8(hsv_splash.v, rgb.v); // Combine brightness from breathing and splash
        RGB rgb_splash = rgb_matrix_hsv_to_rgb(hsv_splash);
        rgb_matrix_set_color(i, rgb_splash.r, rgb_splash.g, rgb_splash.b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
