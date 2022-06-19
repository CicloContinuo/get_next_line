#gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c && ./a.out
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c && ./a.out
