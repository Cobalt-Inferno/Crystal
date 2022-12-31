CFLAGS = -march=native -O3 -Wall -Wextra -std=c89 -Wimplicit-function-declaration -Wunused-parameter -Wshadow -Wdouble-promotion -Wundef -fno-common -fstack-usage -Wconversion -ffunction-sections -Wpadded -fshort-enums -ffast-math
CXXFLAGS = -march=native -O3 -Wall -Wextra -std=c++17 -Wno-unused-parameter -Wshadow -Wdouble-promotion -Wundef -fno-common -fstack-usage -Wconversion -ffunction-sections -Wpadded -fshort-enums -ffast-math

# File to install dependencies
INSTALL_DEPS := install-deps.sh

PREFIX = /usr/local
INSTALLDIR = $(PREFIX)/bin
TARGET = crystal
CC = clang
CXX = clang++
RM = rm -rf
SRCDIR = src
INCDIR = include
OBJDIR = obj
SRC := $(shell find $(SRCDIR) -name *.c)
CXXSRC := $(shell find $(SRCDIR) -name *.cpp)
INC := $(wildcard $(INCDIR)/*.h)
OBJS := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
CXXOBJS += $(CXXSRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(TARGET): ${OBJS} ${CXXOBJS}
	$(CXX) $(CXXFLAGS) $(CXXOBJS) $(OBJS) -o $@ 

all: ${OBJS} ${CXXOBJS} 

.PHONY: configure
configure:
	sh $(INSTALL_DEPS)
	@$(RM) $(OBJDIR)
	@cp -rf $(SRCDIR) $(OBJDIR)
	@find $(OBJDIR) -type f -delete

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@
	@echo "Compiliation complete."

$(CXXOBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	mkdir -p $(INCDIR) $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I $(INCDIR) -c $< -o $@
	@echo "Compiliation complete."

.PHONY: install
install:
	mkdir -p ${DESTDIR}/${PREFIX}/bin
	cp -f $(TARGET) ${DESTDIR}${PREFIX}/bin
	@echo "Installation complete."

.PHONY: clean
clean:
	$(RM) $(OBJS) $(CXXOBJS)
	@echo "Clean complete."

.PHONY: fc
fc:
	$(RM) $(OBJDIR)
	$(RM) $(TARGET)
	@echo "Clean complete."

.PHONY: uninstall
uninstall:
	$(RM) ${DESTDIR}${PREFIX}/bin/$(TARGET)
	@echo "Uninstallation complete."
