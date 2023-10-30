#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>


struct command
{
  const char **argv;
};

int
spawn_proc (int in, int out, struct command *cmd)
{
  pid_t pid;

  if ((pid = fork ()) == 0)
    {
      if (in != 0)
        {
          dup2 (in, 0);
          close (in);
        }

      if (out != 1)
        {
          dup2 (out, 1);
          close (out);
        }

      return execvp (cmd->argv [0], (char * const *)cmd->argv);
    }

  return pid;
}

int
fork_pipes (int n, struct command *cmd)
{
  int i;
  pid_t pid;
  int status;
  int in, fd [2];

  /* The first process should get its input from the original file descriptor 0.  */
  in = open("some.txt",O_RDONLY);

  /* Note the loop bound, we spawn here all, but the last stage of the pipeline.  */
  //pipe(fd);
  for (i = 0; i < n - 1; ++i)
    {
      pipe (fd);

      /* f [1] is the write end of the pipe, we carry `in` from the prev iteration.  */
      pid = spawn_proc (in, fd [1], cmd + i);
	  //waitpid(pid,&status,-1);
	  wait(&status);
      /* No need for the write end of the pipe, the child will write here.  */
      close (fd [1]);

      /* Keep the read end of the pipe, the next child will read from there.  */
      in = fd [0];
    }

  /* Last stage of the pipeline - set stdin be the read end of the previous pipe
     and output to the original file descriptor 1. */
  //if (in != 0)
    //dup2 (in, 0);
  //dup2(open("output.txt",O_WRONLY | O_TRUNC | O_CREAT, 0777),1);
  /* Execute the last stage with the current process. */
  //return execvp (cmd [i].argv [0], (char * const *)cmd [i].argv);
  pipe(fd);
  int fdout = open("output.txt",O_WRONLY | O_TRUNC | O_CREAT, 0777);
  spawn_proc(in,fdout, cmd+ i);
  wait(&status);
  close(fd[1]);
  close(fdout);
}


int
main ()
{
  const char *ls[] = { "ls", "-la", 0 };
  const char *awk[] = { "awk", "{print $1}", 0 };
  const char *sort[] = { "sort", 0 };
  const char *uniq[] = { "wc","-l", 0 };

  struct command cmd [] = { {ls}, {awk}, {sort}, {uniq} };
  fork_pipes (4, cmd);
  printf("done");
  return 0;
}
