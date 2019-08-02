CC              = gcc
LIB_D_DIR       = #-L/home/borges/Dropbox/libs_and_make/logBacktrace/LogBacktrace_version_0_0_0_1/dist/Debug/GNU-Linux-x86 # shared dynamic library directory
LIB_D           = #-lLogBacktrace_version_0_0_0_1 # shared dynamic library name
CFLAGS          = -Wall -g -fPIC -static -lpthread -I. -O3 -DNDEBUG -Wno-variadic-macros $(LIB_D_DIR) $(LIB_D)
LINK_FLAGS      = -Wall -g -lm -lpthread -lfcgi -lgc -I. -O3 -DNDEBUG -Wno-variadic-macros -Wl,--export-dynamic -ldl $(LIB_D_DIR) $(LIB_D)
C_SRC           = main.c ../interface/interface.c ../error/error.c ../memoryManager/memoryManager.c ../arrayList/arrayList_noSync/arrayList_noSync.c
C_OBJ_ORI       = $(C_SRC:.c=.o)
C_SRC_NAME_ONLY = $(notdir $(C_SRC))
C_OBJ_NAME_ONLY = $(C_SRC_NAME_ONLY:.c=.o)
C_OBJ_DIR       = objs/
C_OBJ           = $(addprefix $(C_OBJ_DIR), $(C_OBJ_NAME_ONLY))
EXE             = exe


ARG1       = #-q input.dat
ARG2       = #-o output.dat
ARG3       = #-i list_log_files.dat
ARG4       = #-d date.dat
ARG5       = #-e str_end_block.dat

run: compile
	./$(EXE) $(ARG1) $(ARG2) $(ARG3) $(ARG4) $(ARG5)

compile : cscrean clean $(C_OBJ_ORI) mv_c_obj
	$(CC) $(C_OBJ) $(LINK_FLAGS) -o $(EXE)


$(C_OBJ_ORI): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

mv_c_obj: 
	mv $(C_OBJ_ORI) $(C_OBJ_DIR)

clean:
	rm -rf $(C_OBJ_DIR)*.o *~ *.out *.key

cscrean:
	clear

valg: compile
	valgrind ./$(EXE) $(ARG1) $(ARG2)
	
