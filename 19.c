/*
============================================================================
Name : 19.c
Author : Chirag Date 
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void main(){

  char *fifoName = "./mkFifo";
  char *nodName = "./mknod-fifo";
  
  int fifoStatus, nodStatus;
  
  fifoStatus = mkfifo(fifoName,S_IRWXU);
  
  if(fifoStatus == -1){
    perror("Error while creating FIFO file\n");
  }
  else{
    printf("Successfully created fifo file using mkfifo\n");
  }
  
  nodStatus = mknod(nodName,__S_IFIFO | S_IRWXU,0);
  
  if(nodStatus == -1){
    perror("Error while creating FIFO file\n");
  }
  else{
    printf("Successfully created fifo file using mknod\n");
  }
  
  
}


/*
============================================================================

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ mkfifo fifo
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ strace mkfifo newfifo
execve("/usr/bin/mkfifo", ["mkfifo", "newfifo"], 0x7ffcf99b0678 /* 47 vars */) = 0
brk(NULL)                               = 0x55ee7ff38000
arch_prctl(0x3001 /* ARCH_??? */, 0x7fff1f17acc0) = -1 EINVAL (Invalid argument)
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7efc08441000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=61235, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 61235, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7efc08432000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libselinux.so.1", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=174472, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 181928, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7efc08405000
mmap(0x7efc0840b000, 114688, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6000) = 0x7efc0840b000
mmap(0x7efc08427000, 28672, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x22000) = 0x7efc08427000
mmap(0x7efc0842e000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x29000) = 0x7efc0842e000
mmap(0x7efc08430000, 5800, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7efc08430000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P<\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=2072888, ...}, AT_EMPTY_PATH) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2117488, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7efc08000000
mmap(0x7efc08022000, 1540096, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x22000) = 0x7efc08022000
mmap(0x7efc0819a000, 360448, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x19a000) = 0x7efc0819a000
mmap(0x7efc081f2000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1f1000) = 0x7efc081f2000
mmap(0x7efc081f8000, 53104, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7efc081f8000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpcre2-8.so.0", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=625344, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 627472, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7efc0836b000
mmap(0x7efc0836d000, 438272, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000) = 0x7efc0836d000
mmap(0x7efc083d8000, 176128, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6d000) = 0x7efc083d8000
mmap(0x7efc08403000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x97000) = 0x7efc08403000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7efc08368000
arch_prctl(ARCH_SET_FS, 0x7efc08368800) = 0
set_tid_address(0x7efc08368ad0)         = 23838
set_robust_list(0x7efc08368ae0, 24)     = 0
rseq(0x7efc08369120, 0x20, 0, 0x53053053) = 0
mprotect(0x7efc081f2000, 16384, PROT_READ) = 0
mprotect(0x7efc08403000, 4096, PROT_READ) = 0
mprotect(0x7efc0842e000, 4096, PROT_READ) = 0
mprotect(0x55ee7e063000, 4096, PROT_READ) = 0
mprotect(0x7efc08476000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7efc08432000, 61235)           = 0
statfs("/sys/fs/selinux", 0x7fff1f17ac90) = -1 ENOENT (No such file or directory)
statfs("/selinux", 0x7fff1f17ac90)      = -1 ENOENT (No such file or directory)
getrandom("\x12\xab\x6e\xbc\x16\x6a\xc5\xbe", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0x55ee7ff38000
brk(0x55ee7ff59000)                     = 0x55ee7ff59000
openat(AT_FDCWD, "/proc/filesystems", O_RDONLY|O_CLOEXEC) = 3
newfstatat(3, "", {st_mode=S_IFREG|0444, st_size=0, ...}, AT_EMPTY_PATH) = 0
read(3, "nodev\tsysfs\nnodev\ttmpfs\nnodev\tbd"..., 1024) = 414
read(3, "", 1024)                       = 0
close(3)                                = 0
access("/etc/selinux/config", F_OK)     = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/lib/locale/locale-archive", O_RDONLY|O_CLOEXEC) = 3
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=5716304, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 5716304, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7efc07a00000
close(3)                                = 0
mknodat(AT_FDCWD, "newfifo", S_IFIFO|0666) = 0
close(1)                                = 0
close(2)                                = 0
exit_group(0)                           = ?
+++ exited with 0 +++

chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ gcc 19.c
chirag-date@chirag-date-HP-Laptop-15s-du3xxx:/media/chirag-date/Windows/Users/cdate/Documents/Chirag/IIIT B/SEM1 doc/System Software/List2$ ./a.out
Successfully created fifo file using mkfifo
Successfully created fifo file using mknod

============================================================================
*/

