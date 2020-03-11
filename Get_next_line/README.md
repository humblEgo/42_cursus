# Get next line
 - Write a function which returns a line read from a file descriptor, without the newline

----
As `libft` is not allowed for this project, I added a `get_next_line_utils.c` file which contains the functions that are needed for my `get_next_line` to work.

This program must compile with the flag **-D BUFFER_SIZE=xx** which will be used as the buffer size for the read calls in `get_next_line`.

So, please compile like this way: **gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c**.

This program is able to manage multiple file descriptor. 

*For example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors.*

 - Leak check : ✅
 - Norm check : ❌
 - Tested by [GNL_lover](https://github.com/charMstr/GNL_lover) ✅
