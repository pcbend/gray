
#include <cstdio>
//#include <csignal>


#include <TSystem.h>
#include <Gint.h>


Gint *gint = 0;

//void interruptHandler(int signum); 

int main(int argc, char **argv) {

  printf("hello!\n");


  gint = Gint::Get();
  //gSystem->IgnoreInterrupt(false);

  
  //signal(SIGINT,interruptHandler);
  
  gint->Run(true);

  printf("bye, bye\n");

  return 0;
}

/*
 * doesn't work :(
void interruptHandler(int signum) {
  printf("in %s\t%i\n",__PRETTY_FUNCTION__,signum);
  fflush(stdout);
  return;
}
*/



