#ifndef DRACARYS_H
#define DRACARYS_H

#ifdef DRACARYS_USE_OPENGL
#include "dracarys_gfx/dracarys_glr.h"
#endif

#include "dracarys_utility.h"

#define DRACARYS_DEFAULT_RGB_U_COLOR 203, 95, 78
#define DRACARYS_DEFAULT_RGB_F_COLOR 203.0/255.0, 95.0/255.0, 78.0/255.0
#define DRACARYS_DEFAULT_RGBA_U_COLOR 203, 95, 78, 1.0
#define DRACARYS_DEFAULT_RGBA_F_COLOR 203.0/255.0, 95.0/255.0, 78.0/255.0, 1.0

#define DRACARYS_INIT_SUCCESSFUL 1
#define DRACARYS_INIT_FAILURE 0

#define DRACARYS_WINDOW_RUNNING 1
#define DRACARYS_WINDOW_CLOSED 0

enum dracarys_keys {
    DRACARYS_KEY_SPACE          =   32,
    DRACARYS_KEY_APOSTROPHE     =   39, 
    DRACARYS_KEY_COMMA          =   44, 
    DRACARYS_KEY_MINUS          =   45, 
    DRACARYS_KEY_PERIOD         =   46, 
    DRACARYS_KEY_SLASH          =   47, 
    DRACARYS_KEY_0              =   48,
    DRACARYS_KEY_1              =   49,
    DRACARYS_KEY_2              =   50,
    DRACARYS_KEY_3              =   51,
    DRACARYS_KEY_4              =   52,
    DRACARYS_KEY_5              =   53,
    DRACARYS_KEY_6              =   54,
    DRACARYS_KEY_7              =   55,
    DRACARYS_KEY_8              =   56,
    DRACARYS_KEY_9              =   57,
    DRACARYS_KEY_SEMICOLON      =   59,  
    DRACARYS_KEY_EQUAL          =   61,  
    DRACARYS_KEY_A              =   65,
    DRACARYS_KEY_B              =   66,
    DRACARYS_KEY_C              =   67,
    DRACARYS_KEY_D              =   68,
    DRACARYS_KEY_E              =   69,
    DRACARYS_KEY_F              =   70,
    DRACARYS_KEY_G              =   71,
    DRACARYS_KEY_H              =   72,
    DRACARYS_KEY_I              =   73,
    DRACARYS_KEY_J              =   74,
    DRACARYS_KEY_K              =   75,
    DRACARYS_KEY_L              =   76,
    DRACARYS_KEY_M              =   77,
    DRACARYS_KEY_N              =   78,
    DRACARYS_KEY_O              =   79,
    DRACARYS_KEY_P              =   80,
    DRACARYS_KEY_Q              =   81,
    DRACARYS_KEY_R              =   82,
    DRACARYS_KEY_S              =   83,
    DRACARYS_KEY_T              =   84,
    DRACARYS_KEY_U              =   85,
    DRACARYS_KEY_V              =   86,
    DRACARYS_KEY_W              =   87,
    DRACARYS_KEY_X              =   88,
    DRACARYS_KEY_Y              =   89,
    DRACARYS_KEY_Z              =   90,
    DRACARYS_KEY_LEFT_BRACKET   =   91,  
    DRACARYS_KEY_BACKSLASH      =   92,  
    DRACARYS_KEY_RIGHT_BRACKET  =   93,  
    DRACARYS_KEY_GRAVE_ACCENT   =   96,  
    DRACARYS_KEY_WORLD_1        =   161, 
    DRACARYS_KEY_WORLD_2        =   162, 
    DRACARYS_KEY_ESCAPE         =   256,
    DRACARYS_KEY_ENTER          =   257,
    DRACARYS_KEY_TAB            =   258,
    DRACARYS_KEY_BACKSPACE      =   259,
    DRACARYS_KEY_INSERT         =   260,
    DRACARYS_KEY_DELETE         =   261,
    DRACARYS_KEY_RIGHT          =   262,
    DRACARYS_KEY_LEFT           =   263,
    DRACARYS_KEY_DOWN           =   264,
    DRACARYS_KEY_UP             =   265,
    DRACARYS_KEY_PAGE_UP        =   266,
    DRACARYS_KEY_PAGE_DOWN      =   267,
    DRACARYS_KEY_HOME           =   268,
    DRACARYS_KEY_END            =   269,
    DRACARYS_KEY_CAPS_LOCK      =   280,
    DRACARYS_KEY_SCROLL_LOCK    =   281,
    DRACARYS_KEY_NUM_LOCK       =   282,
    DRACARYS_KEY_PRINT_SCREEN   =   283,
    DRACARYS_KEY_PAUSE          =   284,
    DRACARYS_KEY_F1             =   290,
    DRACARYS_KEY_F2             =   291,
    DRACARYS_KEY_F3             =   292,
    DRACARYS_KEY_F4             =   293,
    DRACARYS_KEY_F5             =   294,
    DRACARYS_KEY_F6             =   295,
    DRACARYS_KEY_F7             =   296,
    DRACARYS_KEY_F8             =   297,
    DRACARYS_KEY_F9             =   298,
    DRACARYS_KEY_F10            =   299,
    DRACARYS_KEY_F11            =   300,
    DRACARYS_KEY_F12            =   301,
    DRACARYS_KEY_F13            =   302,
    DRACARYS_KEY_F14            =   303,
    DRACARYS_KEY_F15            =   304,
    DRACARYS_KEY_F16            =   305,
    DRACARYS_KEY_F17            =   306,
    DRACARYS_KEY_F18            =   307,
    DRACARYS_KEY_F19            =   308,
    DRACARYS_KEY_F20            =   309,
    DRACARYS_KEY_F21            =   310,
    DRACARYS_KEY_F22            =   311,
    DRACARYS_KEY_F23            =   312,
    DRACARYS_KEY_F24            =   313,
    DRACARYS_KEY_F25            =   314,
    DRACARYS_KEY_KP_0           =   320,
    DRACARYS_KEY_KP_1           =   321,
    DRACARYS_KEY_KP_2           =   322,
    DRACARYS_KEY_KP_3           =   323,
    DRACARYS_KEY_KP_4           =   324,
    DRACARYS_KEY_KP_5           =   325,
    DRACARYS_KEY_KP_6           =   326,
    DRACARYS_KEY_KP_7           =   327,
    DRACARYS_KEY_KP_8           =   328,
    DRACARYS_KEY_KP_9           =   329,
    DRACARYS_KEY_KP_DECIMAL     =   330,
    DRACARYS_KEY_KP_DIVIDE      =   331,
    DRACARYS_KEY_KP_MULTIPLY    =   332,
    DRACARYS_KEY_KP_SUBTRACT    =   333,
    DRACARYS_KEY_KP_ADD         =   334,
    DRACARYS_KEY_KP_ENTER       =   335,
    DRACARYS_KEY_KP_EQUAL       =   336,
    DRACARYS_KEY_LEFT_SHIFT     =   340,
    DRACARYS_KEY_LEFT_CONTROL   =   341,
    DRACARYS_KEY_LEFT_ALT       =   342,
    DRACARYS_KEY_LEFT_SUPER     =   343,
    DRACARYS_KEY_RIGHT_SHIFT    =   344,
    DRACARYS_KEY_RIGHT_CONTROL  =   345,
    DRACARYS_KEY_RIGHT_ALT      =   346,
    DRACARYS_KEY_RIGHT_SUPER    =   347,
    DRACARYS_KEY_MENU           =   348,
    DRACARYS_KEY_LAST           =   DRACARYS_KEY_MENU
};

int dracarys_platform_initialize(const char* title, int width, int height);
int dracarys_platform_update(void);
void dracarys_platform_end_update(void);
void dracarys_platform_poll_events(void);
void dracarys_platform_swap_buffers(void);
void dracarys_platform_terminate(void);


int dracarys_platform_is_key_pressed(enum dracarys_keys key);
int dracarys_platform_is_key_down(enum dracarys_keys key);
int dracarys_platform_is_key_up(enum dracarys_keys key);

int dracarys_platform_get_window_width(void);
int dracarys_platform_get_window_height(void);
int dracarys_platform_get_window_status(void);

#ifndef DRACARYS_NO_CUSTOM_MAIN

#ifdef DRACARYS_PLATFORM_WINDOWS
#define DRACARYS_GAME(start, update, destroy, container, title, width, height)               \
int main(void) {                                                                             \
    container c;                                                                             \
    if (dracarys_platform_initialize(title, width, height) == DRACARYS_INIT_FAILURE) {       \
        return -1;                                                                           \
    }                                                                                        \
    start(&c);                                                                               \
    while (dracarys_platform_update()) {                                                     \
        update(&c);                                                                          \
        dracarys_platform_swap_buffers();                                                    \
    }                                                                                        \
    destroy(&c);                                                                             \
    dracarys_platform_terminate();                                                           \
    return 0;                                                                                \
}                                                                               
#elif defined(DRACARYS_PLATFORM_WEB) && defined(DRACARYS_USE_OPENGL) 
#include <emscripten/emscripten.h>

#define DRACARYS_GAME(start, update, destroy, container, title, width, height)                \
container c;                                                                                  \
void loop(void) {                                                                             \
    dracarys_platform_poll_events();                                                          \
    if (dracarys_platform_get_window_status() == DRACARYS_WINDOW_CLOSED) {                    \
        destroy(&c);                                                                          \
        dracarys_platform_terminate();                                                        \
        emscripten_cancel_main_loop();                                                        \
    }                                                                                         \
    update(&c);                                                                               \
    dracarys_platform_swap_buffers();                                                         \
}                                                                                             \
int main(void) {                                                                              \
    if (dracarys_platform_initialize(title, width, height) == DRACARYS_INIT_FAILURE) {        \
        return -1;                                                                            \
    }                                                                                         \
    start(&c);                                                                                \
    emscripten_set_main_loop(loop, 0, 1);                                                     \
    return 0;                                                                                 \
}        

#endif

#endif

#endif