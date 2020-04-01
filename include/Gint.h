#ifndef __GINT_H__
#define __GINT_H__

#include <TRint.h>
#include <TSysEvtHandler.h>

class Gint : public TRint {
  public:
    static Gint *Get(int argc=1,const char *argv[]=0);

    virtual void HandleException(Int_t sig);
    virtual void Terminate(Int_t status = 0);
    

  private: 
    static Gint *fGint;
    Gint(int argv,const char *argc[]);
    ~Gint();

  ClassDef(Gint,0)  
};


class GInterruptHandler : public TSignalHandler {
  public:
    GInterruptHandler():TSignalHandler(ESignals::kSigInterrupt,false) { }
    bool Notify();
  ClassDef(GInterruptHandler,0)
};


#endif
