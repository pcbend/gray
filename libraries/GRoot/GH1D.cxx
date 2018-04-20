

#include <GH1D.h>

#include <TClass.h>
#include <TBuffer.h>

ClassImp(GH1D) 

GH1D::GH1D(): TH1D(),GHist() { }

GH1D::GH1D(const char *name,const char *title,int nbins,double xlow,double xhigh) :
      TH1D(name,title,nbins,xlow,xhigh),GHist() { } 

GH1D::GH1D(const char *name,const char *title,int nbins,const double *bins) :
      TH1D(name,title,nbins,bins), GHist() { } 

GH1D::GH1D(const char *name,const char *title,int nbins,const float *bins) :
      TH1D(name,title,nbins,bins) { } 

GH1D::GH1D(const TVectorD &v): TH1D(v), GHist() { }  

GH1D::GH1D(const GH1D &h1d) : TH1D(h1d),GHist(h1d) { }

//GH1D::GH1D(const TH1 &h1d) : TH1D(h1d),GHist() { }

void GH1D::Copy(TObject &obj) const {
  TH1D::Copy(obj);
  GHist::Copy(obj);
}

void GH1D::Reset(Option_t *opt) {
  TH1D::Reset(opt);
  GHist::Reset();
}

void GH1D::Print(Option_t *opt) const {
  TH1D::Print();
  GHist::Print();
}


GH1D &GH1D::operator=(const GH1D &h1) {
  if(this!=&h1) ((TH1D&)h1).Copy(*this);
  return *this;
}

GH1D operator*(double c1,const GH1D &h1) {
  GH1D hnew = h1;
  hnew.Scale(c1);
  hnew.SetDirectory(0);
  return hnew;
}

GH1D operator*(const GH1D &h1,const GH1D &h2) {
  GH1D hnew = h1;
  hnew.Multiply(&h2);
  hnew.SetDirectory(0);
  return hnew;
}

GH1D operator/(const GH1D &h1,const GH1D &h2) {
  GH1D hnew = h1;
  hnew.Divide(&h2);
  hnew.SetDirectory(0);
  return hnew;
}
  
GH1D operator+(const GH1D &h1,const GH1D &h2) {
  GH1D hnew = h1;
  hnew.Add(&h2);
  hnew.SetDirectory(0);
  return hnew;
}

GH1D operator-(const GH1D &h1,const GH1D &h2) {
  GH1D hnew = h1;
  hnew.Add(&h2,-1);
  hnew.SetDirectory(0);
  return hnew;
}


Int_t GH1D::Write(const char *name,int option,int bufsize) const {
  TH1D hist;
  hist.Copy(*((TH1D*)this));
  //this->Copy(hist);
  hist.SetNameTitle(this->GetName(),this->GetTitle());
  return hist.Write();
}




































