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
    virtual void keyPressEvent (QKeyEvent *event);
    virtual void creaBuffers();
    virtual void carregaShaders();
    //virtual void modelTransform ();

  private:
    int printOglError(const char file[], int line, const char func[]);
    
    void projectTransform();
    
    void viewTransform();
    
    void modelTransformHomer();

    void modelTransformTerra();
    
    void ini_camera();
    
    void CapsaModel();
    
    void CapsaEscena();

    void CentreEscena();
    
    void RadiEscena();
    
    GLuint projLoc, viewLoc;
    GLuint VAO_HomerProves, VAO_Terra;
    
    float rotate, fov, raw, znear, zfar;
    float radi, distancia;
    
    glm::vec3 obs, vrp, up, centreEscena;
    glm::vec3 escenaMinima, escenaMaxima;
    
    Model HomerProves;
};
