/* Copyright 2024 ~ 2025 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"

// clang-format off
#ifdef LED_MATRIX_ENABLE
const snled27351_led_t g_snled27351_leds[LED_MATRIX_LED_COUNT] = {
/* Refer to SNLED27351 manual for these locations
 *   driver
 *   |  LED address
 *   |  | */
    {0, CB1_CA16},
    {0, CB1_CA15},
    {0, CB1_CA14},
    {0, CB1_CA13},
    {0, CB1_CA12},
    {0, CB1_CA11},
    {0, CB1_CA10},
    {0, CB1_CA9},
    {0, CB1_CA8},
    {0, CB1_CA7},
    {0, CB1_CA6},
    {0, CB1_CA5},
    {0, CB1_CA4},
    {0, CB1_CA3},
    {0, CB1_CA2},
    {0, CB1_CA1},

    {0, CB2_CA16},
    {0, CB2_CA15},
    {0, CB2_CA14},
    {0, CB2_CA13},
    {0, CB2_CA12},
    {0, CB2_CA11},
    {0, CB2_CA10},
    {0, CB2_CA9},
    {0, CB2_CA8},
    {0, CB2_CA7},
    {0, CB2_CA6},
    {0, CB2_CA5},
    {0, CB2_CA4},
    {0, CB2_CA3},
    {0, CB2_CA1},

    {0, CB3_CA16},
    {0, CB3_CA15},
    {0, CB3_CA14},
    {0, CB3_CA13},
    {0, CB3_CA12},
    {0, CB3_CA11},
    {0, CB3_CA10},
    {0, CB3_CA9},
    {0, CB3_CA8},
    {0, CB3_CA7},
    {0, CB3_CA6},
    {0, CB3_CA5},
    {0, CB3_CA4},
    {0, CB3_CA3},
    {0, CB3_CA1},

    {0, CB4_CA16},
    {0, CB4_CA15},
    {0, CB4_CA14},
    {0, CB4_CA13},
    {0, CB4_CA12},
    {0, CB4_CA11},
    {0, CB4_CA10},
    {0, CB4_CA9},
    {0, CB4_CA8},
    {0, CB4_CA7},
    {0, CB4_CA6},
    {0, CB4_CA5},
    {0, CB4_CA3},
    {0, CB4_CA1},

    {0, CB5_CA16},
    {0, CB5_CA15},
    {0, CB5_CA14},
    {0, CB5_CA13},
    {0, CB5_CA12},
    {0, CB5_CA11},
    {0, CB5_CA10},
    {0, CB5_CA9},
    {0, CB5_CA8},
    {0, CB5_CA7},
    {0, CB5_CA6},
    {0, CB5_CA5},
    {0, CB5_CA4},
    {0, CB5_CA3},
    {0, CB5_CA1},

    {0, CB6_CA16},
    {0, CB6_CA15},
    {0, CB6_CA14},
    {0, CB6_CA10},
    {0, CB6_CA7},
    {0, CB6_CA6},
    {0, CB6_CA5},
    {0, CB6_CA4},
    {0, CB6_CA3},
    {0, CB6_CA1},
};

#define __ NO_LED

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15 },
        { 16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  __,  30 },
        { 31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  __,  45 },
        { 46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  __,  58,  __,  59 },
        { 60,  61,  62,  63,  64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  __,  74 },
        { 75,  76,  77,  __,  __,  __,  78,  __,  __,  79,  80,  81,  82,  83,  __,  84 }

    },
    {
        // LED Index to Physical Position
        {0, 0}, {14, 0}, {29, 0}, {44, 0}, {59, 0}, {74, 0}, { 89,  0}, {104,  0}, {119,  0}, {134,  0}, {149,  0}, {164,  0}, {179,  0}, {194,  0}, {209,  0}, {223,  0},
        {0,12}, {14,12}, {29,12}, {44,12}, {59,12}, {74,12}, { 89, 12}, {104, 12}, {119, 12}, {134, 12}, {149, 12}, {164, 12}, {179, 12}, {201, 12},            {223, 12},
        {3,25}, {22,25}, {37,25}, {52,25}, {67,25}, {82,25}, { 97, 25}, {112, 25}, {126, 25}, {141, 25}, {156, 25}, {171, 25}, {186, 25}, {205, 31},            {223, 25},
        {5,38}, {26,38}, {41,38}, {55,38}, {70,38}, {85,38}, {100, 38}, {115, 38}, {130, 38}, {145, 38}, {160, 38}, {175, 38},            {190, 38},            {223, 38},
        {1,51}, {18,51}, {33,51}, {48,51}, {63,51}, {78,51}, { 93, 51}, {108, 51}, {123, 51}, {138, 51}, {153, 51}, {168, 51}, {187, 51}, {209, 51},            {223, 51},
        {1,64}, {20,64}, {39,64},                            { 95, 64},                       {149, 64}, {164, 64}, {179, 64}, {194, 64}, {209, 64},            {223, 64}
    },
    {
        // RGB LED Index to Flag
        4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,
        4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,        4,
        4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,        4,
        4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,        4,        4,
        4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,        4,
        4,   4,   4,                  4,             4,   4,   4,   4,   4,        4
    }
};

#endif
