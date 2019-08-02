CC              = gcc
DLIB_DIR_H      = /media/borges/data/cloud/Mega/programming/c/share
DLIB_DIR        = $(DLIB_DIR_H)/dlibs
DLIB_NAME       = 
CFLAGS          = -Wall -Werror -g -O3 -DNDEBUG -Wno-variadic-macros -fPIC  # Werror transforms warning in error
DLIB_STD        = -lm -lpthread -lfcgi -lgc
DLIB            = $(DLIB_STD) $(DLIB_NAME)
COMPILER_FLAGS  = $(CFLAGS) -L$(DLIB_DIR) -I$(DLIB_DIR_H)
LINK_FLAGS      = $(COMPILER_FLAGS) -Wl,-rpath=$(DLIB_DIR) # use -Wl,-rpath= when the library is not in global environment
LINK_DLIB       = $(LINK_FLAGS) -shared -Wl,-soname,$(LIB)
C_SRC_LIB       = memoryManager.c
C_SRC           = $(C_SRC_LIB)
C_OBJ_ORI       = $(C_SRC:.c=.o)
C_SRC_NAME_ONLY = $(notdir $(C_SRC))
C_OBJ_NAME_ONLY = $(C_SRC_NAME_ONLY:.c=.o)
C_OBJ_DIR       = objs/
C_OBJ           = $(addprefix $(C_OBJ_DIR), $(C_OBJ_NAME_ONLY))
C_LIB_H         = $(C_SRC_LIB:.c=.h)
LIB             = lib$(C_SRC_LIB:.c=.so)
EXE             = exe


ARG1       = #-q input.dat
ARG2       = #-o output.dat
ARG3       = #-i list_log_files.dat
ARG4       = #-d date.dat
ARG5       = #-e str_end_block.dat

run: compile
	./$(EXE) $(ARG1) $(ARG2) $(ARG3) $(ARG4) $(ARG5)

lib: compile_lib export_lib export_lib_header
	$(info Dynamic Library created with success: $(LIB) $nDynamic Library Header exported with success: $(C_LIB_H)$nTo use: #include <headers/$(C_LIB_H)>)
# can use to print: $(info your_text) $(warning your_text) or $(error your_text) # for new/break line use: $nYour_text - ex: my_text_line1 $nmy_text_line2

compile_lib: cscrean clean_lib $(C_OBJ_ORI) mv_c_obj
	$(CC) $(LINK_DLIB) $(C_OBJ) -o $(LIB) $(DLIB)

compile: cscrean clean $(C_OBJ_ORI) mv_c_obj
	$(CC) $(LINK_FLAGS) $(C_OBJ) -o $(EXE) $(DLIB)

$(C_OBJ_ORI): %.o : %.c
	$(CC) $(COMPILER_FLAGS) -c $< -o $@ $(DLIB)

export_lib:
	cp $(LIB) $(DLIB_DIR)/

export_lib_header:
	cp $(C_LIB_H) $(DLIB_DIR_H)/headers/

mv_c_obj: 
	mv $(C_OBJ_ORI) $(C_OBJ_DIR)

clean_lib: clean
	rm -rf $(LIB) $(DLIB_DIR)/$(LIB) $(DLIB_DIR_H)/headers/$(C_LIB_H)

clean:
	rm -rf $(C_OBJ_DIR)*.o *~ *.out *.key out.txt

cscrean:
	clear

valg: compile
	valgrind ./$(EXE) $(ARG1) $(ARG2)
	
define n # define a break line - new line to user's message


endef

























	
