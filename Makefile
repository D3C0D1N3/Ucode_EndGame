# A simple Makefile for compiling small SDL projects

# set the compiler
CC := clang

# set the compiler flags
CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 -std=c99 -Wall -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm

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
OBJS := $(SRCS:.c=.o)

# name of executable
EXEC := game

# default recipe
all: $(EXEC)

# recipe for building the final executable
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

# recipe for building object files
#$(OBJS): $(@:.o=.c) $(HDRS) Makefile
#	$(CC) -o $@ $(@:.o=.c) -c $(CFLAGS)

# recipe to clean the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
