#ifndef _AXIS_H_
#define _AXIS_H_

#include "AReVi/arObject.h"
#include "AReVi/Lib3D/osdSprite.h"
#include "AReVi/Lib3D/renderer3D.h"
using namespace AReVi;

#include "types.h"

class AxisButton;

/**
 * Classe d�crivant les axes de r�glages des contraintes imprim�s en mode OSD
 */
class Axis : public ArObject {
public :
  AR_CLASS(Axis)
  AR_CONSTRUCTOR_1(Axis, AxisType, axisType)

  /**
   * M�thode permettant d'ajouter un rendu pour l'axe
   * @param renderer Le rendu �� ajouter
   */
  virtual void addRenderer(ArRef<Renderer3D> renderer);

  /**
   * M�thode permettant d'enlever un rendu pour l'axe
   * @param renderer Le rendu � enlever
   */
  virtual void removeRenderer(ArRef<Renderer3D> renderer);

  /**
   * M�thode permettant de retourner le nombre de rendu de l'Axis
   * @return Le nombre de rendu de l'Axis
   */
  virtual unsigned int getNbRenderer(void) const;

  /**
   * M�thode permettant de r�cup�rer un rendu en consultation dont l'indice est pass� en param�tre
   * @param index Indice du rendu � retourner
   * @return Le rendu
   */
  virtual ArConstRef<Renderer3D> getRenderer(unsigned int index) const;

  /**
   * M�thode permettant de r�cup�rer un rendu dont l'indice est pass� en param�tre
   * @param index Indice du rendu � retourner
   * @return Le rendu
   */
  virtual ArRef<Renderer3D> accessRenderer(unsigned int index);

  /**
   * M�thode permettant de d�termier si l'Axis est visible ou non
   * @param visible true si l'Axis doit �tre visible, flase sinon
   */
  virtual void setVisible(bool visible);

  /**
   * M�thode permettant de d�finir la taille de l'Axis
   * @param w Largeur de l'Axis
   * @param h Hauteur de l'Axis
   */
  virtual void setSize(unsigned int w, unsigned int h);

  /**
   * M�thode permettant de recup�rer la taille de l'Axis
   * @param w Largeur de l'Axis
   * @param h Hauteur de l'Axis
   */
  virtual void getSize(unsigned int& w, unsigned int& h) const;

  /**
   * M�thode permettant de d�finir la taille des bouttons de l'Axis
   * @param w Largeur des bouttons
   * @param h Hauteur des bouttons
   */
  virtual void setButtonSize(unsigned int w, unsigned int h);

  /**
   * M�thode permettant de r�cup�rer la taille des bouttons de l'Axis
   * @param w Largeur des bouttons
   * @param h Hauteur des bouttons
   */
  virtual void getButtonSize(unsigned int& w, unsigned int& h) const;

  /**
   * M�thode permettant de positionner l'Axis dans la fen�tre AR�Vi
   * @param x Position en X
   * @param y Position en Y
   */
  virtual void setPosition(int x, int y);

  /**
   * M�thode permettant de d�finir les valeur maximum et minimum de l'Axis
   * @param min Valeur minimale de l'Axis
   * @param max Valeur maximale de l'Axis
   */
  virtual void setBounds(double min, double max);

  /**
   * M�thode permettant de r�cup�rer les valeur maximum et minimum de l'Axis
   * @param min Valeur minimale de l'Axis
   * @param max Valeur maximale de l'Axis
   */
  virtual void getBounds(double& min, double& max) const;

  /**
   * M�thode permettant d'affecter des valeurs aux boutons
   * @param in Valeur du bouton inf�rieur
   * @param out Valeur du bouton sup�rieur
   */
  virtual void setButtonValues(double in, double out);

  /**
   * M�thode permettant de r�cup�rer des valeurs aux boutons
   * @param in Valeur du bouton inf�rieur
   * @param out Valeur du bouton sup�rieur
   */
  virtual void getButtonValues(double& in, double& out) const;

  /**
   * M�thode permettant d'attacher l'Axis � une autre
   * @param axis L'Axis � laquelle attacher celle-ci
   */
  virtual void attachTo(ArRef<Axis> axis);
  
  AR_CALLBACK(Axis, Value, _valueCB,
	      double in;
	      double out;
	      )

protected :

  /**
   * M�thode de d�clenchement sur le d�placement de l'Axis
   * @param evt Ev�nement de d�placement
   */
  virtual void _onAxisMotionCB(const OSD::MotionEvent& evt);

  /**
   * M�thode de d�clenchement sur le d�placement d'un boutton
   * @param evt Ev�nement de d�placement d'un boutton
   */
  virtual void _onButtonMotionCB(const OSD::MotionEvent& evt);

  /**
   * M�thode de d�clenchement sur un changement de valeur de l'Axis
   */
  virtual void _onValueChanged(void);

protected :
  /** Vector des rendus */
  StlVector<ArRef<Renderer3D> > _renderers;
 
  /** Repr�sentation de l'Axis en OSD */
  ArRef<OSDSprite> _axis;
  /** Boutton inf�rieur */
  ArRef<AxisButton> _inOsd;
  /** Boutton sup�rieur */
  ArRef<AxisButton> _outOsd;

  /** ... je sais plus du tout */
  unsigned int _sw, _sh, _bw, _bh;
  /** Valeurs maximale et minimale */
  double _rangeMin, _rangeMax;
  /** Valeurs inf�rieure et sup�rieure */
  double _valueIn, _valueOut;
  /** Surement un truc � voir avec le d�placement de l'Axis ou de ses bouttons */
  int _motionMask;

  /** Gestionnaire de d�clencheur sur un changement de valeur */
  CallbackManager<Axis, ValueEvent> _valueCB;
};

#endif // _AXIS_H_
