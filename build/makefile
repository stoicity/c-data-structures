CC = gcc
CCFLAGS = -g

SRCDIR = ../src
INCLUDES = -I../include
OBJDIR = ./obj
LIBDIR = ./lib

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

TARGET = $(LIBDIR)/libdata.a

all: $(TARGET)

clean:
	rm -rf $(OBJECTS) $(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBDIR):
	mkdir -p $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET): $(OBJDIR) $(LIBDIR) $(OBJECTS)
	ar rcs $(TARGET) $(OBJECTS)