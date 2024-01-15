CC := clang++
CFLAGS := -std=c++17 -Wall -Wextra -g -O2 -Isrc -I. -fsanitize=address,undefined
LDLIBS := -lncurses
SRCDIR := src
BUILDDIR := build
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))
TARGET := $(BUILDDIR)/dungeon_crawler

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)/*

.PHONY: all clean
