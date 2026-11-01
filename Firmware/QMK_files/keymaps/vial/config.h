#pragma once

/* Vial keyboard identity for the Tanuki PCB. */
#define VIAL_KEYBOARD_UID {0x54, 0x61, 0x6E, 0x75, 0x6B, 0x69, 0x40, 0x01}

/* Hold Tab (row 3, column 0) and Escape (row 3, column 1) to unlock Vial. */
#define VIAL_UNLOCK_COMBO_ROWS { 3, 3 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

/* The stock Tanuki keymap defines five layers. */
#define DYNAMIC_KEYMAP_LAYER_COUNT 5
