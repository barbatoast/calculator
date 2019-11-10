CC      := gcc
CCFLAGS := \
	-std=c89 						\
	-Wall							\
	-Wextra							\
	-Wpointer-arith					\
	-Wcast-align					\
	-Wwrite-strings					\
	-Wswitch-default				\
	-Wunreachable-code				\
	-Winit-self						\
	-Wmissing-field-initializers	\
	-Wno-unknown-pragmas			\
	-Wstrict-prototypes				\
	-Wundef							\
	-Wold-style-definition			\
	-Wno-misleading-indentation
LDFLAGS :=

SRCDIR := src/
TSTDIR := test/
UNITYDIR := unity/src/
CMOCKDIR := cmock/src/
CMOCKLIB := cmock/lib/
MOCKDIR := mocks/
MOCKPREFIX := $(MOCKDIR)Mock
INC_DIR := -I$(SRCDIR)
TST_INC_DIR := -I$(UNITYDIR) -I$(CMOCKDIR) -I$(MOCKDIR)

TARGET:= calc
MAIN_BASE := $(addsuffix .o, $(TARGET))
MAIN := $(addprefix $(SRCDIR), $(MAIN_BASE))
OBJ_BASE := add.o div.o sub.o mul.o
OBJ := $(addprefix $(SRCDIR), $(OBJ_BASE))
MOCK_OBJ := $(addprefix $(MOCKPREFIX), $(OBJ_BASE))
MOCK_SRC := $(patsubst %.o, %.c, $(MOCK_OBJ))
OBJ += $(MAIN)
DEP_BASE := add.h div.h sub.h mul.h
DEP := $(addprefix $(SRCDIR), $(DEP_BASE))
MOCK_DEP := $(addprefix $(MOCKPREFIX), $(DEP_BASE))

TST_TARGET := test_add test_div test_sub test_mul
TST_MAIN_BASE := $(addsuffix .o, $(TST_TARGET))
TST_MAIN := $(addprefix $(TSTDIR), $(TST_MAIN_BASE))
TST_OBJ_BASE := unity.o
TST_OBJ := $(addprefix $(UNITYDIR), $(TST_OBJ_BASE))
TST_OBJ += $(addprefix $(CMOCKDIR), cmock.o)
TST_OBJ += $(TST_MAIN)
TST_DEP_BASE := unity.h unity_internals.h
TST_DEP := $(addprefix $(UNITYDIR), $(TST_DEP_BASE))

.PHONY : all clean test

all : $(TARGET)

clean :
	rm -f $(TARGET) $(OBJ) $(TST_TARGET) $(TST_OBJ) $(MOCK_OBJ) $(MOCK_DEP) $(MOCK_SRC)

setup :
	ruby $(CMOCKLIB)cmock.rb $(DEP)

test : setup $(TST_TARGET)

$(OBJ) : %.o : %.c $(DEP)
	$(CC) $(INC_DIR) -c -o $@ $< $(CCFLAGS)

$(TARGET): % : $(filter-out $(MAIN), $(OBJ)) $(SRCDIR)%.o
	$(CC) -o $@ $(LIBS) $^ $(CCFLAGS) $(LDFLAGS)

$(MOCK_OBJ) : %.o : %.c $(TST_DEP)
	$(CC) $(TST_INC_DIR) $(INC_DIR) -c -o $@ $< $(CCFLAGS)

$(TST_OBJ) : %.o : %.c $(TST_DEP)
	$(CC) $(TST_INC_DIR) $(INC_DIR) -c -o $@ $< $(CCFLAGS)

#$(TST_TARGET) : test_% : $(filter-out $(TST_MAIN), $(TST_OBJ)) $(MOCK_OBJ) $(TSTDIR)test_%.o	\
#	$(SRCDIR)%.o
#	$(CC) -o $@ $(LIBS) $^ $(CCFLAGS) $(LDFLAGS)

test_add : test_% : $(filter-out $(TST_MAIN), $(TST_OBJ)) $(TSTDIR)test_%.o $(SRCDIR)%.o
	$(CC) -o $@ $(LIBS) $^ $(CCFLAGS) $(LDFLAGS)

test_div : test_% : $(filter-out $(TST_MAIN), $(TST_OBJ)) $(TSTDIR)test_%.o $(SRCDIR)%.o	\
	$(MOCKPREFIX)add.o $(MOCKPREFIX)sub.o
	$(CC) -o $@ $(LIBS) $^ $(CCFLAGS) $(LDFLAGS)

test_sub : test_% : $(filter-out $(TST_MAIN), $(TST_OBJ)) $(TSTDIR)test_%.o $(SRCDIR)%.o
	$(CC) -o $@ $(LIBS) $^ $(CCFLAGS) $(LDFLAGS)

test_mul : test_% : $(filter-out $(TST_MAIN), $(TST_OBJ)) $(TSTDIR)test_%.o $(SRCDIR)%.o	\
	$(MOCKPREFIX)add.o $(MOCKPREFIX)sub.o
	$(CC) -o $@ $(LIBS) $^ $(CCFLAGS) $(LDFLAGS)
