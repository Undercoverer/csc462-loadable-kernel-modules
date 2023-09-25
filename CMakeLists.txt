cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project("Linux Kernel Module with CLion IDE support / CMake" VERSION 0.1.0 LANGUAGES C)
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find kernel headers
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(KernelHeaders REQUIRED)


# find MODULE_LICENSE("GPL"), MODULE_AUTHOR() etc.
# thanks to "merseyviking" from stack overflow
add_definitions(-D__KERNEL__ -DMODULE)

# this is needed in order for CLion IDE to provide syntax highlightning
# this is independent from the actual kernel object that is built
add_executable(dummy
        # add all *.h and *.c files here that # CLion should cover
        ./ch13/producer.c
        ./ch13/consumer.c
        ./ch2/hello.c
        ./ch2/simple.c
        ./ch2/second_count.c
        ./ch2/jiffies.c
        ./ch3/fig3-33.c
        ./ch3/pid.c
        ./ch3/win32-pipe-child.c
        ./ch3/fig3-32.c
        ./ch3/fig3-30.c
        ./ch3/newproc-win32.c
        ./ch3/fig3-31.c
        ./ch3/multi-fork.c
        ./ch3/fig3-34.c
        ./ch3/unix_pipe.c
        ./ch3/newproc-posix.c
        ./ch3/simple-shell.c
        ./ch3/win32-pipe-parent.c
        ./ch3/shm-posix-consumer.c
        ./ch3/shm-posix-producer.c
        ./ch3/fig3-35.c
        ./ch4/thrd-win32.c
        ./ch4/openmp.c
        ./ch4/thrd-posix.c
        ./ch4/fig4-23.c
        ./ch5/posix-sched.c
        ./ch5/project/posix/list.c
        ./ch5/project/posix/CPU.c
        ./ch5/project/posix/driver.c
        ./ch5/posix-rt.c
        ./ch7/project-1/posix/client.c
        ./ch7/project-1/posix/threadpool.c
        ./CMakeFiles/3.27.6/CompilerIdC/CMakeCCompilerId.c


)

# CLion IDE will find symbols from <linux/*>
target_include_directories("dummy" PRIVATE ${KERNELHEADERS_INCLUDE_DIRS})