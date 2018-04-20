
#include <TEnv.h>

#include <Gint.h>
#include <GUtil.h>


void LoadGRAYEnv() {
  // Set the GRAYSYS variable based on the executable path.
  // If GRAYSYS has already been defined, don't overwrite.
  setenv("GRAYSYS", (program_path()+"/..").c_str(), 0);

  // Load $GRAYSYS/.grayrc
  std::string gray_path = Form("%s/.grayrc",getenv("GRAYSYS"));
  gEnv->ReadFile(gray_path.c_str(),kEnvChange);

  // Load $HOME/.grayrc
  gray_path = Form("%s/.grayrc",getenv("HOME"));
  if(file_exists(gray_path.c_str())){
    gEnv->ReadFile(gray_path.c_str(),kEnvChange);
  }
  
  gray_path = Form("%s/.grayrc",getenv("PWD"));
  if(file_exists(gray_path.c_str())){
    gEnv->ReadFile(gray_path.c_str(),kEnvChange);
  }
}


int main(int argc, const char **argv) {

  LoadGRAYEnv();

  Gint::Get()->Run(true);


  return 0;
}

