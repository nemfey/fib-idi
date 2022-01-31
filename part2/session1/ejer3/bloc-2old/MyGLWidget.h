// MyGLWidget.h
#include "Bl2GLWidget.h"

class MyGLWidget : public Bl2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : Bl2GLWidget(parent) {}
    ~MyGLWidget();
  
  protected:
    virtual void projectTransform();
    
    virtual void carregaShaders();
    
    virtual void paintGL();
    
    virtual void viewTransform();
 
  private:
    int printOglError(const char file[], int line, const char func[]);
    
    GLuint projLoc;
    GLuint viewLoc;
};
