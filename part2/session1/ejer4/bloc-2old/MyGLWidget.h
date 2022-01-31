// MyGLWidget.h
#include "Bl2GLWidget.h"
#include "../../Model/model.h"

class MyGLWidget : public Bl2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : Bl2GLWidget(parent) {}
    ~MyGLWidget();
  
  protected:
    virtual void initializeGL();
    
    virtual void carregaShaders();
 
  private:
    void projectTransform(float FOV, float ra, float znear, float zfar);
    void viewTransform(glm::vec3 OBS, glm::vec3 VRP, glm::vec3 UP);
    void ini_camera();
    
    int printOglError(const char file[], int line, const char func[]);
    
    GLuint projLoc, viewLoc;
    
    GLuint VAO_HomerProves;
    
    Model HomerProves;
};
