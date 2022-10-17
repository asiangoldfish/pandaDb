CC				:= gcc
CFLAGS			:= -Wall -Wextra -g

BUILD_DIR		:= build
TARGET			:= $(BUILD_DIR)/pandadb_app
# Adds all .c files in db_* directories to OBJS
OBJS			= $(addprefix $(BUILD_DIR)/,$(addsuffix .o,$(notdir $(basename $(wildcard db_*/src/*.c)))))

# Appends all .c files in core directory to OBJS
OBJS			+= $(addprefix $(BUILD_DIR)/,$(addsuffix .o,$(notdir $(basename $(wildcard core*/src/*.c)))))

SUBDIRS			:= ${wildcard db_*} core

.Phony: clean all subdirs

# Build all subdirectories/libraries first before building core
all: subdirs $(TARGET)

# Build the final executable
$(TARGET): $(OBJS)
	$(eval OBJS = $(wildcard $(BUILD_DIR)/*.o))
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Builds all libraries
subdirs: $(SUBDIRS)
	mkdir -p $(BUILD_DIR)

	@ for dir in $^; do \
		echo "Building $$dir..."; \
		$(MAKE) -C $$dir; \
	done

clean:
	$(RM) -r $(BUILD_DIR)
