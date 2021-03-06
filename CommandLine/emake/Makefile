BINARY := ../../emake
SRC_DIR := .
OBJ_DIR := .eobjs

SHARED_SRC_DIR := ../../shared
include $(SHARED_SRC_DIR)/Makefile
include $(SHARED_SRC_DIR)/eyaml/Makefile
include $(SHARED_SRC_DIR)/event_reader/Makefile

OS := $(shell uname -s)
ifeq ($(OS), Linux)
	OS_LIBS=-lboost_system -Wl,--no-as-needed -Wl,-rpath=./ -lboost_program_options -lboost_iostreams -lboost_filesystem -lboost_system -lpthread -ldl
else ifeq ($(OS), Darwin)
	OS_LIBS=-lboost_system -lboost_program_options -lboost_iostreams -lboost_filesystem -lboost_system -lpthread -ldl
else
	OS_LIBS=-lboost_system-mt -Wl,--no-as-needed -Wl,-rpath=./ -lboost_program_options-mt -lboost_iostreams-mt -lboost_filesystem-mt -lboost_system-mt -lpthread
endif

# As a "temporary hack," allow including from CompilerSource to give access to backend/ folder.
CXXFLAGS  := -I$(SRC_DIR) -I../../CompilerSource -std=c++11 -Wall -Wextra -Wpedantic -g
LDFLAGS   := $(OS_LIBS)

rwildcard=$(wildcard $1/$2) $(foreach d,$(wildcard $1/*),$(call rwildcard,$d,$2))
SOURCES := $(call rwildcard,$(SRC_DIR),*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(patsubst %.cpp, %.o, $(SOURCES)))
DEPENDS := $(OBJECTS:.o=.d)

CXXFLAGS += -I$(SHARED_SRC_DIR) $(addprefix -I$(SHARED_SRC_DIR)/, $(SHARED_INCLUDES))
SOURCES += $(addprefix $(SHARED_SRC_DIR),$(SHARED_SOURCES))
OBJECTS += $(addprefix $(OBJ_DIR)/shared/,$(SHARED_SOURCES:.cpp=.o))
DEPENDS += $(addprefix $(OBJ_DIR)/shared/,$(SHARED_SOURCES:.cpp=.d))

OBJDIRS := $(sort $(OBJ_DIR) $(dir $(OBJECTS)))

$(BINARY): $(OBJECTS)
	g++ $^ $(LDFLAGS) -o $@

.PHONY: all clean obj_dirs

all: $(BINARY)
clean:
	rm -rf $(BINARY) $(OBJ_DIR)

# Create the object directories
$(OBJDIRS):
	mkdir -p $@
# Old make has a bug which requires this nonsense...
obj_dirs: $(OBJDIRS)

# Generate rules for new (unbuilt) files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | obj_dirs
	$(CXX) $(CXXFLAGS) -MMD -c -o $@ $<
$(OBJ_DIR)/shared/%.o: $(SHARED_SRC_DIR)/%.cpp | obj_dirs
	$(CXX) $(CXXFLAGS) -MMD -c -o $@ $<

# Include rules for known (previously-built) files
-include $(DEPENDS)
.SUFFIXES:
