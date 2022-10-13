CC				:= gcc
INCLUDES		:= include
CFLAGS			:= -Wall -Wextra -g -I $(INCLUDES)

BUILD_DIR		:= ../build
SRC				:= ${wildcard src/*.c}
OBJS			:= $(addprefix $(BUILD_DIR)/,$(addsuffix .o,$(notdir $(basename $(SRC)))))

.Phony: all

all: $(OBJS)

$(BUILD_DIR)/%.o: src/%.c include/%.h
	$(CC) -c $(CFLAGS) $< -o $@