# ncursesProjects
Random little games to learn ncurses and vi.
These are personnal project that I put public because I don't have any reasons to make them private. If you want to report bugs or make changes regarding bugfixes or general code quality, feel free to do it, but I won't accept new features as I want to do them myself.
Also, expect the possibility of regression on works I am currently working on. Commits don't only happen when something works, simply when I want to save it between my multiple PCs.
The main development will be on Arch Linux x86_64, but should be compatible with most linux distributions and Mac if using gcc. I'll try to port Windows support as well using preprocessor directives when I can.
The general goal is using the least library as possible and recode the most I can myself. I won't get rid of ncurses, but I might try to make assembler system call myself to remove some libraries(mostly unistd.h). That may break compatibility for other platforms, but I'll try to patch it afterwards.
