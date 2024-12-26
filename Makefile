CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lcunit

SRC_DIR = .
BUILD_DIR = build
TEST_DIR = tests

SRC_FILES = $(SRC_DIR)/main.c
TEST_FILES = $(SRC_DIR)/test_main.c
EXEC = $(BUILD_DIR)/app
TEST_EXEC = $(BUILD_DIR)/test_app

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(EXEC): $(SRC_FILES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_EXEC): $(TEST_FILES) $(SRC_FILES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

.PHONY: test

test: $(TEST_EXEC)
	$(TEST_EXEC)

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
