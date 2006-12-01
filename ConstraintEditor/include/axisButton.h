#ifndef _AXIS_BUTTON_H_
#define _AXIS_BUTTON_H_

#include "AReVi/Lib3D/texture.h"
#include "AReVi/Lib3D/abstractInteractor.h"
#include "AReVi/Lib3D/osdText.h"
#include "AReVi/Lib3D/osdSprite.h"
using namespace AReVi;

#include "types.h"

/**
 * Classe d�crivant les buttons OSD repr�sentant les axes dans la fen�tre AR�Vi
 */
class AxisButton : public OSDSprite {
public :
  AR_CLASS(AxisButton)
  AR_CONSTRUCTOR_2(AxisButton, ArRef<Texture>, texture, bool, textUp)

  /**
   * M�thode permettant d'affecter une valeur pour l'axe
   * @param value 
   */
  virtual void setValue(double value);

  /**
   * Gestion de l'interaction sur un �v�nement boutton de souris
   * @param source Source de l'�v�nement
   * @param button Le bouton de la souris qui a �t� actionn�
   * @param pressed Si le bouton a �t� press�
   */
  virtual void onMouseButtonInteraction(ArRef<AbstractInteractor> source, int button, bool pressed);

  /**
   * Gestion de l'interaction de mouvement de la souris
   * @param source Source de l'�v�nement
   * @param newX Nouvelle valeur en X
   * @param newY Nouvelle valeur en Y
   * @param begin true si l'action commence, false sinon
   * @param end true si l'action termine, false sinon
   */
  virtual void onMotionInteraction(ArRef<AbstractInteractor> source, int newX, int newY, bool begin, bool end);

protected :

  /**
   * M�thode de d�clenchement de l'action set de la valeur de AxisButton
   * @param evt L'�v�nement d�clencheur
   */
  virtual void _onSetupCB(const OSD::SetupEvent& evt);

protected :
  /** Valeur de l'axe */
  double _value;

  /** Texte � afficher en mode OSD */
  ArRef<OSDText> _text; 
  /** Flag d'affichage du texte */
  bool _textUp;
};

#endif // _AXIS_BUTTON_H_
