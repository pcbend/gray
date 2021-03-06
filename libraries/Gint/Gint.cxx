
#include <pwd.h>

#include <TSystem.h>

#include <Gint.h>
#include <GTypes.h>


ClassImp(Gint)


Gint *Gint::fGint = 0;

Gint *Gint::Get(int argc,const char *argv[]) {
  if(!fGint) 
    fGint = new Gint(argc,argv);
  return fGint;
}

Gint::Gint(int argc,const char *argv[]) : TRint("g-ray",0,0,0,0,true) { 

  GetSignalHandler()->Remove();
  GInterruptHandler *ih = new GInterruptHandler();
  ih->Add();
  SetPrompt("g-ray[%d]");

}

Gint::~Gint() { } 



void Gint::Terminate(Int_t status){

  //Be polite when you leave.
  printf(DMAGENTA "\nbye,bye\t" DCYAN "%s" RESET_COLOR  "\n",
         getpwuid(getuid())->pw_name);

  if((clock()%60) == 0){
    printf("DING!");
    fflush(stdout);
    gSystem->Sleep(500);
    printf("\r              \r");
    fflush(stdout);
  }
  TRint::Terminate(status);
}





//******************************//
//******************************//
//******************************//
//******************************//


bool GInterruptHandler::Notify() {
  static int timespressed  = 0;
  timespressed++;
  if(timespressed>3) {
    printf("\n" DRED BG_WHITE  "   No you shutup! " RESET_COLOR "\n"); fflush(stdout);
    exit(1);
  }
  printf("\n" DRED BG_WHITE  "   Control-c was pressed.   " RESET_COLOR "\n"); fflush(stdout);
  Gint::Get()->Terminate();
  return true;
}


