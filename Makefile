OUTPUT_A = libj.a
OUTPUT_SO = libj.so
SRCDIR = src/
OBJDIR = obj/

CC = gcc
CSTD = c99
CFLAGS = --std=$(CSTD) -O2 -g0 -Wall -Wextra -ffunction-sections -fdata-sections
LD = $(CC)
LDFLAGS = -shared -fPIC -lc
AR = ar
ARFLAGS = rcs

OBJS := $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(wildcard $(SRCDIR)*.c))
OBJS_A := $(patsubst %.o, %_a.o, $(OBJS))
OBJS_SO := $(patsubst %.o, %_so.o, $(OBJS))

DEPS := $(patsubst %.o, %.d, $(OBJS))
DEPFLAGS = -MM -MF $@

.PHONY: all clean install uninstall

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

install: all
	@echo
	@echo Installing
	cp include/jlib.h /usr/local/include
	cp $(OUTPUT_A) /usr/local/lib
	cp $(OUTPUT_SO) /usr/local/lib

uninstall:
	rm -f /usr/local/include/jlib.h
	rm -f /usr/local/lib/$(OUTPUT_A)
	rm -f /usr/local/lib/$(OUTPUT_SO)

