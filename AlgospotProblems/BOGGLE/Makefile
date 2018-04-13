COMPILER = g++
COMPILE_OPTION = -o

################################
# ALL COMPILE
################################
PROGRAM : boggle 
all : $(PROGRAM)
clean: 
	@rm -f $(PROGRAM) *.o

$(PROGRAM)   : $(PROGRAM).cpp
	$(COMPILER) $(COMPILE_OPTION) $(PROGRAM) $(PROGRAM).cpp

