// MyGLWidget.h
#include "LL4GLWidget.h"

class MyGLWidget : public LL4GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : LL4GLWidget(parent) {}
    ~MyGLWidget();
    
  public slots:
    void rotateCotxe(int n);
    
  signals:
    void rotation(int n);

  private:
    int printOglError(const char file[], int line, const char func[]);
    virtual void keyPressEvent (QKeyEvent *e);
    virtual void iniEscena();
    virtual void setupLights();
    virtual void initializeGL();
    
    glm::vec3 colFocus1, posFocus1;
    glm::vec3 colFocus2, posFocus2;
    glm::vec3 colFocus3, posFocus3;
    
    GLuint colFocus1Loc, posFocus1Loc;
    GLuint colFocus2Loc, posFocus2Loc;
    GLuint colFocus3Loc, posFocus3Loc;
    
    int focusini;
    GLuint focusiniLoc;
    
    int sliderpos = 0; //guardaremos la posición del slider
};
