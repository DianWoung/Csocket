void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

void read_childproc(int sig)
{
    int status;
    pid_t id = waitpid(-1, &status, WNOHANG);
    if (WIFEXITED(status)){
        printf("Remove proc id: %d \n", id);
        printf("Child send: %d \n", WEXITSTATUS(status));
    }
}