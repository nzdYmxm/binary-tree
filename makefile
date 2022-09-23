Q1_TARGET = ../build/Quest_1
Q2_TARGET = ../build/Quest_2
Q3_TARGET = ../build/Quest_3
Q4_TARGET = ../build/Quest_4
Q5_TARGET = ../build/Quest_5

run: clear_screen ${Q5_TARGET}
	./${Q5_TARGET}

all: ${Q1_TARGET} ${Q2_TARGET} ${Q3_TARGET} ${Q4_TARGET} ${Q5_TARGET}
	@echo "All quests are compiled"

bst_traverse_test: ${Q5_TARGET}
	@echo "Binary search tree insert test complete"

${Q5_TARGET}: bst.c bst.h bst_traverse_test.c
	gcc -Wall -Wextra -Werror bst_traverse_test.c bst.c -o ${Q5_TARGET}

bst_insert_test: ${Q4_TARGET}
	@echo "Binary search tree insert test complete"

${Q4_TARGET}: bst.c bst.h bst_insert_test.c
	gcc -Wall -Wextra -Werror bst_insert_test.c bst.c -o ${Q4_TARGET}

bst_create_test: ${Q3_TARGET}
	@echo "Binary search tree test complete"

${Q3_TARGET}: bst.c bst.h bst_create_test.c
	gcc -Wall -Wextra -Werror bst_create_test.c bst.c -o ${Q3_TARGET}

documentation_module: ${Q2_TARGET}
	@echo "Documentation module complete"

${Q2_TARGET}: main_module_entry_point.c print_module.c print_module.h documentation_module.c documentation_module.h
	gcc -Wall -Wextra -Werror main_module_entry_point.c print_module.c documentation_module.c -o ${Q2_TARGET}

print_module: ${Q1_TARGET}
	@echo "Print module complete"

${Q1_TARGET}: main_module_entry_point.c print_module.c print_module.h documentation_module.c documentation_module.h
	gcc -Wall -Wextra -Werror main_module_entry_point.c print_module.c documentation_module.c -o ${Q1_TARGET}

clean:
	rm ../build/*

clear_screen:
	clear
