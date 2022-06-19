#gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c && ./a.out
#gcc -Wall -Werror -Wextra  example0.c
cc -Wall -Werror -Wextra -D BUFFER_SIZE=10 example0.c && ./a.out
