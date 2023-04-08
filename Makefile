#graphics api = DRACARYS_USE_OPENGL

CC = gcc
graphics_api = DRACARYS_USE_OPENGL
platform = DRACARYS_PLATFORM_WINDOWS
BUILD_PATH = build
OPT = -O0

FLAGS = -Wall -Wextra \
$(OPT) -pedantic \
-std=c99 -g \

HEADERS = -Iheader/Dracarys -Iheader/Dracarys/extern

OBJ := $(BUILD_PATH)/main.o \
$(BUILD_PATH)/dracarys_utility.o \
$(BUILD_PATH)/glad.o \
$(BUILD_PATH)/dracarys_platform.o \
$(BUILD_PATH)/dracarys_gl_draw.o \
$(BUILD_PATH)/dracarys_gl_buffer.o \
$(BUILD_PATH)/dracarys_gl_clear.o \
$(BUILD_PATH)/dracarys_gl_shader.o \
$(BUILD_PATH)/dracarys_gl_vertex_array.o \

APP_NAME = Dracarys
APP = $(BUILD_PATH)/$(APP_NAME).exe


vpath %.c src src/extern src/dracarys_gfx/dracarys_gl_backend
vpath %.h header/Dracarys

.PHONY: clean run

ifeq ($(platform), DRACARYS_PLATFORM_WINDOWS)

LIBS = -Lsrc/extern \
-lglfw3 -lgdi32 -lmingw32 \

BUILD = $(OBJ) $(APP)

all: $(APP)

$(APP): $(OBJ)
	echo --Successfully built objects--
	$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $@ 

$(BUILD_PATH)/%.o: %.c
	echo --Compiling: $< to $@--
	gcc -c $< -D $(platform) -D $(graphics_api) $(HEADERS) -o $@

endif

ifeq ($(platform), DRACARYS_PLATFORM_WEB)

SHADER_PATH = shaders/QuadWeb.txt

LIBS = -Lsrc/extern \
-lglfw3 \

WEB_FLAGS = -s USE_WEBGL2=1 \
-sMAX_WEBGL_VERSION=2 \
-s FULL_ES3=1 \
-s USE_GLFW=3 \

all: $(APP_NAME).html
	echo "Finished"


$(APP_NAME).html: $(OBJ)
	echo --FINALIZING WEB BUILD--
	emcc -o $(BUILD_PATH)/$(APP_NAME).html --preload-file $(SHADER_PATH) $(OBJ) $(FLAGS) $(WEB_FLAGS) $(LIBS) 

$(BUILD_PATH)/%.o: %.c
	echo --COMPILING SRC--
	emcc -c $< -D $(platform) -D $(graphics_api) $(HEADERS) 
	mv *.o $(BUILD_PATH)

endif

run:
ifeq ($(platform), DRACARYS_PLATFORM_WINDOWS)
	$(APP)
endif
ifeq ($(platform), DRACARYS_PLATFORM_WEB)
	npx serve .
	echo --OPEN BROWSER AND COPY/PASTE URL--
endif

clean:
	echo --Cleaning-- 
ifeq ($(platform), DRACARYS_PLATFORM_WINDOWS)
	rm -f $(OBJ) $(APP)
endif
ifeq ($(platform), DRACARYS_PLATFORM_WEB)
	rm -f $(OBJ) $(BUILD_PATH)/*.data $(BUILD_PATH)/*.wasm $(BUILD_PATH)/*.js $(BUILD_PATH)/*.html 
endif