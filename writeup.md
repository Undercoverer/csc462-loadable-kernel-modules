# Loadable Kernel Modules Project Writeup
While working on the project, we wrote our modules on my (Fox) bare metal machine (more exciting)

---
## Part 1
For part 1 of the project, we went through the instructions in the book for simple.c and hello.c, adding the extra wanted information. To have a little fun, we set jiffies equal to various different things to see what would happen. Setting it to zero made everything freeze and my computer fans instantly jumped to max speed. Next we tried the maximum value jiffies could take and nothing really happened, which somewhat makes sense given that there's a wrap around macro that kernel modules use I'm pretty sure.

For second_count and jiffies, it was pretty simple. We duplicated the hello.c file and modified the important bits (copying a formatted string with the wanted data to the buffer instead of "Hello world"). Using snprintf because it's memory safe. To make sure the both modules worked right I used `watch -n 0.1 cat /proc/[proc name]` and the counts went up consistently (consistently enough at least)

---
## Part 2
Part 2 was a painless process with few hiccups along the way. The only new material, the write portion, just needed 1 line of code, the sscanf statement which took the user inputted pid from k_mem and copied it to the current_pid variable (which is what we renamed l_pid for clarity). We decided to also print the inserted pid to the kernel as well so that we'd be able to tell if the write was successful.

For the read portion, we first checked against null value for the tsk struct, to make sure the user input pid was a valid pid within the system and printed an error message to the kernel and returned if null was found. Finally, we wrote the snprintf statement to copy the formatted output to the buffer using comm, pid, and __state from the tsk struct to fill in the data. This, however, is where we ran into a snag. No matter what we tried the string seemed to refuse to write to the user terminal. We even added a print to the kernel to see if the buffer contained the correct info, which it always did. Thankfully we had the hello.c file to compare to from the first part, where we realized that we had forgotten to assign the return value of snprintf to rv. Without this the copy_to_user function didn't know how many char to copy so was copying 0 chars. After getting that fixed the output printed perfectly whenever \proc\pid was read.

