// MyGLWidget.h
#include "Bl2GLWidget.h"
#include "../../../Model/model.h"

class MyGLWidget : public Bl2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : Bl2GLWidget(parent) {}
    ~MyGLWidget();
    
  protected:
    virtual void initializeGL();
    virtual void paintGL();
    virtual void creaBuffers();
    virtual void carregaShaders();

  private:
    int printOglError(const char file[], int line, const char func[]);
    
    void projectTransform();
    
    void viewTransform();
    
    GLuint projLoc, viewLoc;
    GLuint VAO_HomerProves;
    
    Model HomerProves;
};
