#ifndef __GINT_H__
#define __GINT_H__

#include <TRint.h>

class GInt : public TRint {
  public:
    GInt();
    ~GInt();

    void Print() const;


  private:
    int data1;
    int data2;

  ClassDef(GInt,0)

};



#endif

