CC				:= gcc

# Directories with included header files should be listed below
INCLUDES		= include ${wildcard ../*/include}
IFLAGS			= $(foreach flag, $(INCLUDES), -I $(flag))
CFLAGS			:= -Wall -Wextra -g $(IFLAGS)

BUILD_DIR		:= ../build
SRC				:= ${wildcard src/*.c}
OBJS			:= $(addprefix $(BUILD_DIR)/,$(addsuffix .o,$(notdir $(basename $(SRC)))))

.Phony: all

all: $(OBJS)

$(BUILD_DIR)/%.o: src/%.c
	echo $(IFLAGS)
	$(CC) -c $(CFLAGS) $< -o $@