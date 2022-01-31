// MyGLWidget.h
#include "Bl2GLWidget.h"

class MyGLWidget : public Bl2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : Bl2GLWidget(parent) {}
    ~MyGLWidget();
    
  protected:
    virtual void carregaShaders();
    virtual void paintGL();
    virtual void initializeGL();

  private:
    int printOglError(const char file[], int line, const char func[]);
    
    void projectTransform();
    
    void viewTransform();
    
    void ini_camera();
    
    GLuint projLoc, viewLoc;
    float fov, raw, znear, zfar;
    glm::vec3 obs, vrp, up;
};
