dir	=	tests_bin

all:
		@make fpe
		@make segv
		@make print_env

fpe:
		gcc -o fpe $(dir)/fpe.c

segv:
		gcc -o segv $(dir)/segv.c

print_env:
		gcc -o print_env $(dir)/print_env.c
