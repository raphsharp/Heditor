#ifndef _BODY_CONTROLLER_H_
#define _BODY_CONTROLLER_H_

#include "AReVi/arObject.h"
using namespace AReVi;

namespace hLib {
class Body;
}
using namespace hLib;

/**
 * Classe d�crivant le contr�le du mod�le charg�
 */
class BodyController : public ArObject {
public :
  AR_CLASS(BodyController)
  AR_CONSTRUCTOR(BodyController)

  // Body management

  /**
   * Classe permettant d'affecter un mod�le au BodyController
   * @param body Le mod�le que doit contr�ler le BodyController
   */
  virtual void setBody(ArRef<Body> body);

  /**
   * M�thode permettant de r�cup�rer en consultation le mod�le que contr�le le BodyController
   * @return Le mod�le
   */
  virtual ArConstRef<Body> getBody(void) const;

  /**
   * M�thode permettant de r�cup�rer le mod�le que contr�le le BodyController
   * @return Le mod�le
   */
  virtual ArRef<Body> accessBody(void);

  AR_CALLBACK(BodyController, Body, _bodyCB, ArRef<Body> body; )

protected :

  /**
   * M�thode d�clench�e lors d'un changement du mod�le
   * @param  
   */
  virtual void _onBody(void);

protected :
  /** Le mod�le charg� */
  ArRef<Body> _body;
  /** Gestionnaire des �v�nements sur le mod�le */
  CallbackManager<BodyController, BodyEvent> _bodyCB;

};

#endif // _BODY_CONTROLLER_H_
