These are some instrucion for run some test programs using the MinilibX

compilation command:
cc -I /usr/local/include <youfile.c> -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit

inside "/usr/local/include", you have to include the mlx.h (the library of the MinilibX)
inside "/usr/local/lib", you have to include the libmlx.a (all the function of MinilibX)
