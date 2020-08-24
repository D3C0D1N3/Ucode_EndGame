# A simple Makefile for compiling small SDL projects

# set the compiler
CC := clang
INC = inc


# set the compiler flags
FFLAGS = -F ./resource/frameworks -framework SDL2 -rpath ./resource/frameworks \
	 -F ./resource/frameworks -framework SDL2_image -rpath ./resource/frameworks \
	 -F ./resource/frameworks -framework SDL2_ttf -rpath ./resource/frameworks \
	 -F ./resource/frameworks -framework SDL2_mixer -rpath ./resource/frameworks \

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror
# add header files here
HDRS := inc/header.h \
		#inc/get_application.h \
		#inc/hero.h \

# add source files here
SRCS := src/main.c \
		src/menu.c \
		src/print_error.c \
		src/init_game_over.c \
		src/init_stars.c \
		src/load_game.c \
		src/process.c \
		src/collision_detect.c \
		src/process_events.c \
		src/do_render.c \


# generate names of object files
# OBJS := $(SRCS:.c=.o)

# name of executable
EXEC := endgame

# default recipe
all: $(EXEC)

# recipe for building the final executable
$(EXEC): $(SRCS) $(INC) Makefile
	$(CC) $(SRCS) $(CFLAGS) $(FFLAGS) -o $(EXEC) -I $(INC)

# recipe for building object files
#$(OBJS): $(@:.o=.c) $(HDRS) Makefile
#	$(CC) -o $@ $(@:.o=.c) -c $(CFLAGS)

# recipe to clean the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
