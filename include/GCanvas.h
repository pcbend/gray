#ifndef __GCANVAS_H__
#define __GCANVAS_H__

#include <TCanvas.h>

class GCanvas : public TCanvas { 
  public:
    GCanvas(bool build=true) : TCanvas(build) { } 
    GCanvas(const char *name,const char *title="", int form=1) : TCanvas(name,title,form)  { } 
    GCanvas(const char *name,const char *title, int ww,int wh) : TCanvas(name,title,ww,wh) { } 
    GCanvas(const char *name,const char *title, int wtopx,int wtopy, int ww, int wh) : TCanvas(name,title,wtopx,wtopy,ww,wh) { } 
    GCanvas(const char *name,int ww, int wh, int winid) {  } 
    virtual ~GCanvas() { }

    void HandleInput(EEventType event,int px,int py);
    void ProcessedEvent(int event, int x,int y,TObject *selected);

  private:
     

  ClassDef(GCanvas,0)
};

#endif
