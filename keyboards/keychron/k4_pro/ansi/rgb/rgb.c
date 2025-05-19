/* Copyright 2021 ~ 2025 @ Keychron (https://www.keychron.com)
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
#ifdef RGB_MATRIX_ENABLE
const snled27351_led_t g_snled27351_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to SNLED27351 manual for these locations
 *   driver
 *   |  R location
 *   |  |           G location
 *   |  |           |           B location
 *   |  |           |           | */
    {0, CB9_CA1,    CB7_CA1,    CB8_CA1},
    {0, CB9_CA2,    CB7_CA2,    CB8_CA2},
    {0, CB9_CA3,    CB7_CA3,    CB8_CA3},
    {0, CB9_CA4,    CB7_CA4,    CB8_CA4},
    {0, CB9_CA5,    CB7_CA5,    CB8_CA5},
    {0, CB9_CA6,    CB7_CA6,    CB8_CA6},
    {0, CB9_CA7,    CB7_CA7,    CB8_CA7},
    {0, CB9_CA8,    CB7_CA8,    CB8_CA8},
    {0, CB9_CA9,    CB7_CA9,    CB8_CA9},
    {0, CB9_CA10,   CB7_CA10,   CB8_CA10},
    {0, CB9_CA11,   CB7_CA11,   CB8_CA11},
    {0, CB9_CA12,   CB7_CA12,   CB8_CA12},
    {0, CB9_CA13,   CB7_CA13,   CB8_CA13},
    {0, CB9_CA14,   CB7_CA14,   CB8_CA14},
    {0, CB9_CA15,   CB7_CA15,   CB8_CA15},
    {0, CB9_CA16,   CB7_CA16,   CB8_CA16},
    {1, CB6_CA1,    CB4_CA1,    CB5_CA1},
    {1, CB6_CA2,    CB4_CA2,    CB5_CA2},
    {1, CB6_CA3,    CB4_CA3,    CB5_CA3},

    {0, CB3_CA1,    CB1_CA1,    CB2_CA1},
    {0, CB3_CA2,    CB1_CA2,    CB2_CA2},
    {0, CB3_CA3,    CB1_CA3,    CB2_CA3},
    {0, CB3_CA4,    CB1_CA4,    CB2_CA4},
    {0, CB3_CA5,    CB1_CA5,    CB2_CA5},
    {0, CB3_CA6,    CB1_CA6,    CB2_CA6},
    {0, CB3_CA7,    CB1_CA7,    CB2_CA7},
    {0, CB3_CA8,    CB1_CA8,    CB2_CA8},
    {0, CB3_CA9,    CB1_CA9,    CB2_CA9},
    {0, CB3_CA10,   CB1_CA10,   CB2_CA10},
    {0, CB3_CA11,   CB1_CA11,   CB2_CA11},
    {0, CB3_CA12,   CB1_CA12,   CB2_CA12},
    {0, CB3_CA13,   CB1_CA13,   CB2_CA13},
    {0, CB3_CA14,   CB1_CA14,   CB2_CA14},
    {0, CB3_CA15,   CB1_CA15,   CB2_CA15},
    {0, CB3_CA16,   CB1_CA16,   CB2_CA16},
    {1, CB6_CA4,    CB4_CA4,    CB5_CA4},
    {1, CB6_CA5,    CB4_CA5,    CB5_CA5},

    {0, CB6_CA1,    CB4_CA1,    CB5_CA1},
    {0, CB6_CA2,    CB4_CA2,    CB5_CA2},
    {0, CB6_CA3,    CB4_CA3,    CB5_CA3},
    {0, CB6_CA4,    CB4_CA4,    CB5_CA4},
    {0, CB6_CA5,    CB4_CA5,    CB5_CA5},
    {0, CB6_CA6,    CB4_CA6,    CB5_CA6},
    {0, CB6_CA7,    CB4_CA7,    CB5_CA7},
    {0, CB6_CA8,    CB4_CA8,    CB5_CA8},
    {0, CB6_CA9,    CB4_CA9,    CB5_CA9},
    {0, CB6_CA10,   CB4_CA10,   CB5_CA10},
    {0, CB6_CA11,   CB4_CA11,   CB5_CA11},
    {0, CB6_CA12,   CB4_CA12,   CB5_CA12},
    {0, CB6_CA13,   CB4_CA13,   CB5_CA13},
    {0, CB6_CA14,   CB4_CA14,   CB5_CA14},
    {0, CB6_CA15,   CB4_CA15,   CB5_CA15},
    {0, CB6_CA16,   CB4_CA16,   CB5_CA16},
    {1, CB6_CA6,    CB4_CA6,    CB5_CA6},
    {1, CB6_CA7,    CB4_CA7,    CB5_CA7},

    {1, CB3_CA16,   CB1_CA16,   CB2_CA16},
    {1, CB3_CA15,   CB1_CA15,   CB2_CA15},
    {1, CB3_CA14,   CB1_CA14,   CB2_CA14},
    {1, CB3_CA13,   CB1_CA13,   CB2_CA13},
    {1, CB3_CA12,   CB1_CA12,   CB2_CA12},
    {1, CB3_CA11,   CB1_CA11,   CB2_CA11},
    {1, CB3_CA10,   CB1_CA10,   CB2_CA10},
    {1, CB3_CA9,    CB1_CA9,    CB2_CA9},
    {1, CB3_CA8,    CB1_CA8,    CB2_CA8},
    {1, CB3_CA7,    CB1_CA7,    CB2_CA7},
    {1, CB3_CA6,    CB1_CA6,    CB2_CA6},
    {1, CB3_CA5,    CB1_CA5,    CB2_CA5},
    {1, CB3_CA3,    CB1_CA3,    CB2_CA3},
    {1, CB3_CA2,    CB1_CA2,    CB2_CA2},
    {1, CB3_CA1,    CB1_CA1,    CB2_CA1},
    {1, CB6_CA8,    CB4_CA8,    CB5_CA8},

    {1, CB9_CA16,   CB7_CA16,   CB8_CA16},
    {1, CB9_CA14,   CB7_CA14,   CB8_CA14},
    {1, CB9_CA13,   CB7_CA13,   CB8_CA13},
    {1, CB9_CA12,   CB7_CA12,   CB8_CA12},
    {1, CB9_CA11,   CB7_CA11,   CB8_CA11},
    {1, CB9_CA10,   CB7_CA10,   CB8_CA10},
    {1, CB9_CA9,    CB7_CA9,    CB8_CA9},
    {1, CB9_CA8,    CB7_CA8,    CB8_CA8},
    {1, CB9_CA7,    CB7_CA7,    CB8_CA7},
    {1, CB9_CA6,    CB7_CA6,    CB8_CA6},
    {1, CB9_CA5,    CB7_CA5,    CB8_CA5},
    {1, CB9_CA4,    CB7_CA4,    CB8_CA4},
    {1, CB9_CA3,    CB7_CA3,    CB8_CA3},
    {1, CB9_CA2,    CB7_CA2,    CB8_CA2},
    {1, CB9_CA1,    CB7_CA1,    CB8_CA1},
    {1, CB6_CA9,    CB4_CA9,    CB5_CA9},
    {1, CB6_CA10,   CB4_CA10,   CB5_CA10},

    {1, CB12_CA16,  CB10_CA16,  CB11_CA16},
    {1, CB12_CA15,  CB10_CA15,  CB11_CA15},
    {1, CB12_CA14,  CB10_CA14,  CB11_CA14},
    {1, CB12_CA10,  CB10_CA10,  CB11_CA10},
    {1, CB12_CA6,   CB10_CA6,   CB11_CA6},
    {1, CB12_CA5,   CB10_CA5,   CB11_CA5},
    {1, CB12_CA4,   CB10_CA4,   CB11_CA4},
    {1, CB12_CA3,   CB10_CA3,   CB11_CA3},
    {1, CB12_CA2,   CB10_CA2,   CB11_CA2},
    {1, CB12_CA1,   CB10_CA1,   CB11_CA1},
    {1, CB6_CA11,   CB4_CA11,   CB5_CA11},
    {1, CB6_CA12,   CB4_CA12,   CB5_CA12},
};


led_config_t g_led_config = {
    {
        { 0,      1,      2,      3,      4,      5,      6,      7,      8,      9,      10,     11,     12,     13,     14,     15,     16,     17 },
        { 19,     20,     21,     22,     23,     24,     25,     26,     27,     28,     29,     30,     31,     32,     33,     34,     35,     36 },
        { 37,     38,     39,     40,     41,     42,     43,     44,     45,     46,     47,     48,     49,     50,     51,     52,     53,     54 },
        { 55,     56,     57,     58,     59,     60,     61,     62,     63,     64,     65,     66,     NO_LED, 67,     68,     69,     70,     18 },
        { 71,     NO_LED, 72,     73,     74,     75,     76,     77,     78,     79,     80,     81,     82,     83,     84,     85,     86,     87 },
        { 88,     89,     90,     NO_LED, NO_LED, NO_LED, 91,     NO_LED, NO_LED, NO_LED, 92,     93,     94,     95,     96,     97,     98,     99 }
    },
    {
        {0, 0}, {12, 0}, {24, 0}, {36, 0}, {48, 0}, {60, 0}, {72, 0}, {84, 0}, { 96,  0}, {108,  0}, {120,  0}, {132,  0}, {144,  0}, {156,  0}, {169,  0}, {187,  0}, {199,  0}, {211,  0}, {223,0},
        {0,14}, {12,14}, {24,14}, {36,14}, {48,14}, {60,14}, {72,14}, {84,14}, { 96, 14}, {108, 14}, {120, 14}, {132, 14}, {144, 14}, {162, 14}, {187, 14}, {199, 14}, {211, 14}, {223, 14},
        {3,27}, {18,27}, {30,27}, {42,27}, {54,27}, {66,27}, {78,27}, {90,27}, {102, 27}, {114, 27}, {126, 27}, {138, 27}, {150, 27}, {165, 27}, {187, 27}, {199, 27}, {211, 27}, {223, 27},
        {4,37}, {21,37}, {33,37}, {45,37}, {57,37}, {69,37}, {81,37}, {93,37}, {105, 37}, {117, 37}, {129, 37}, {141, 37},            {161, 37}, {187, 37}, {199, 37}, {211, 37},
        {7,50},          {27,50}, {39,50}, {51,50}, {63,50}, {75,50}, {87,50}, { 99, 50}, {111, 50}, {123, 50}, {135, 50}, {152, 50}, {172, 50}, {187, 50}, {199, 50}, {211, 50}, {223, 50},
        {1,61}, {16,61}, {31,61},                            {76,61},                                {120, 61}, {132, 61}, {144, 61}, {160, 61}, {172, 61}, {184, 61}, {199, 61}, {211, 61},
    },
    {
        4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,  4,
        4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,
        4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,
        4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,        4,   4,   4,   4,
        4,        4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,
        4,   4,   4,                  4,                  4,   4,   4,   4,   4,   4,   4,   4,

    }
};
#endif
