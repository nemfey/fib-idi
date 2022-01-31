#include "LL2GLWidget.h"

#include "model.h"

class MyGLWidget : public LL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : LL2GLWidget(parent) {}
    ~MyGLWidget();
    
  protected:
    virtual void initializeGL();
    virtual void paintGL();
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void ini_Camera();
    virtual void viewTransform();
    virtual void projectTransform();
    

  private:
    int printOglError(const char file[], int line, const char func[]);
    void RadiEscena();
    
    bool camn; //true->Camara 'normal'; false->Camara Perspectiva en Planta
    float distancia;
};
