#ifndef __GH1D_H__
#define __GH1D_H__

#include <TH1D.h>

#include <GHist.h>

class GH1D : public TH1D, public GHist {

  public:
    GH1D();
    GH1D(const char *name,const char *title,int nbinsx,double xlow,double xhigh);
    GH1D(const char *name,const char *title,int nbinsx,const double *xbins);
    GH1D(const char *name,const char *title,int nbinsx,const float  *xbins);
    explicit GH1D(const TVectorD &v);
    GH1D(const GH1D &h1d);
    //GH1D(const TH1  &h1d);
    GH1D& operator=(const GH1D &h1);
    virtual ~GH1D() { }

    virtual void Print(Option_t *opt="") const;
    virtual void Copy(TObject &hnew) const;
    virtual void Reset(Option_t *opt="");

    virtual int Write(const char *name=0,int option=0,int bufsize=0) const;

  ClassDef(GH1D,1)

  public:
    friend GH1D  operator*(double c1, const GH1D &h1);
    friend GH1D  operator*(const GH1D &h1,double c1);
    friend GH1D  operator*(const GH1D &h1,const GH1D &h2);
    friend GH1D  operator/(const GH1D &h1,const GH1D &h2);
    friend GH1D  operator+(const GH1D &h1,const GH1D &h2);
    friend GH1D  operator-(const GH1D &h1,const GH1D &h2);


};

GH1D operator*(double c1,const GH1D &h1);
inline GH1D operator*(const GH1D &h1,double c1) { return operator*(c1,h1); }
GH1D operator*(const GH1D &h1,const GH1D &h2);
GH1D operator/(const GH1D &h1,const GH1D &h2);
GH1D operator+(const GH1D &h1,const GH1D &h2);
GH1D operator-(const GH1D &h1,const GH1D &h2);


  

#endif

