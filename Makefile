OUTPUT_A = libj.a
OUTPUT_SO = libj.so
SRCDIR = src/
OBJDIR = obj/

CC = gcc
CSTD = c99
CFLAGS = --std=$(CSTD) -O2 -g0 -Wall -Wextra
LD = $(CC)
LDFLAGS = -shared
AR = ar
ARFLAGS = rcs

OBJS := $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(wildcard $(SRCDIR)*.c))
OBJS_A := $(patsubst %.o, %_a.o, $(OBJS))
OBJS_SO := $(patsubst %.o, %_so.o, $(OBJS))

DEPS := $(patsubst %.o, %.d, $(OBJS))
DEPFLAGS = -MM -MF $@

.PHONY: all clean

all: $(DEPS) $(OUTPUT_A) $(OUTPUT_SO)

$(OUTPUT_A): $(OBJS_A)
	@echo
	@echo Linking static library
	$(AR) $(ARFLAGS) $@ $^

$(OUTPUT_SO): $(OBJS_SO)
	@echo
	@echo Linking shared library
	$(LD) $(LDFLAGS) $^ -o $@

$(OBJDIR)%_a.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)%_so.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -fPIC -w -c $< -o $@

$(OBJDIR)%.d: $(SRCDIR)%.c
	$(CC) $< $(DEPFLAGS)

-include $(DEPS)

clean:
	rm -f $(OBJDIR)* $(OUTPUT_A) $(OUTPUT_SO)

