# Loadable Kernel Modules Project Writeup
While working on the project, we wrote our modules on my (Fox) bare metal machine (more exciting)

---
## Part 1
For part 1 of the project, we went through the instructions in the book for simple.c and hello.c, adding the extra wanted information. To have a little fun, we set jiffies equal to various different things to see what would happen. Setting it to zero made everything freeze and my computer fans instantly jumped to max speed. Next we tried the maximum value jiffies could take and nothing really happened, which somewhat makes sense given that there's a wrap around macro that kernel modules use I'm pretty sure.

For second_count and jiffies, it was pretty simple. We duplicated the hello.c file and modified the important bits (copying a formatted string with the wanted data to the buffer instead of "Hello world"). Using snprintf because it's memory safe. To make sure the both modules worked right I used `watch -n 0.1 cat /proc/[proc name]` and the counts went up consistently (consistently enough at least)

---
## Part 2
