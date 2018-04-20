
#include<cstdio>
#include<cstdint>
#include<cinttypes>

#include<GCanvas.h>


void GCanvas::HandleInput(EEventType event,int px,int py) {
  bool used = false;
  printf("%s\n",__PRETTY_FUNCTION__);

  
  if(!used) TCanvas::HandleInput(event,px,py);
}

void GCanvas::ProcessedEvent(int event,int x,int y,TObject *selected)    {
  //printf("%s:  e[%i]   x[%i]  y[%i]  %" PRIxPTR  "\n",__PRETTY_FUNCTION__,event,x,y,reinterpret_cast<std::uintptr_t>(selected)); 
  //printf("%s:  e[%i]   x[%i]  y[%i]  %s\n",__PRETTY_FUNCTION__,event,x,y,selected?selected->GetName():"");
}





