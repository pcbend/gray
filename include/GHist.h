#ifndef __GHIST_H__
#define __GHIST_H__

#include <TObject.h>

class GHist {
  public:
    GHist() { } 
    virtual ~GHist() { } 

    void Print(Option_t *opt="") const {  }
    void Copy(TObject &obj)      const {  }
    void Reset()                       {  }


  ClassDef(GHist,0) 
};

#endif
