
#include <cstdio>

#include <GInt.h>

GInt::GInt() : TRint("gray",0,0,0,0,true)   { }

GInt::~GInt() { }



void GInt::Print() const {
  printf("%s\n",__PRETTY_FUNCTION__);
  printf("\tdata1 = %i\n",data1);
  printf("\tdata2 = %i\n",data2);
}

