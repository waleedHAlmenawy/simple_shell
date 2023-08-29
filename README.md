## Simple Shell
# Authores: Mohamed Elafandy, Waleed Almenawy

These procedures are used to operate the "hsh" shell:

1. The user runs the built program to start the shell.

2. The shell indicates that it is prepared to accept a command by displaying a prompt, such as '$'.

3. The user types a command, which the shell reads.

4. Based on whitespace characters, the shell tokenizes the command into distinct words.

5. The shell determines whether the command is one that is pre-built. If so, the associated built-in function is called.

6. In the event that the command is not a built-in, the shell looks for it in the directories listed by the 'PATH' environment variable. The order is carried out if it is located.

7. If the command cannot be located in the directories listed by

8. The shell waits for the command to finish running.

9. To signal that it is prepared to accept the next command, the shell prints the prompt once more.

10. Until the user departs the shell, the aforementioned actions are repeated.

11. 11. 11. 11. 11. 11. 11. 11. 11. 11. 11. The shell also responds to signals like 'Ctrl+C' (SIGINT) to disregard the keyboard interrupt and 'Ctrl+D' (EOF) to leave the shell.
