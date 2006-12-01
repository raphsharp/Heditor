#ifndef _C3DOF_H_
#define _C3DOF_H_

#include "AReVi/Lib3D/object3D.h"
using namespace AReVi;

#include "hLib/core/jointConstraint.h"
using namespace hLib;

class C3DOFSh;
class KeyOrientation;

/**
 * Classe permettant de controller graphiquement les articulations � trois degr�s de libert�
 */
class C3DOF : public Object3D {
public :
  AR_CLASS(C3DOF)
  AR_CONSTRUCTOR(C3DOF)
  AR_CONSTRUCTOR_1(C3DOF, ArRef<JointConstraint3DOF>, constraint)

  /**
   * M�thode permettant de d�finir le rayon de la sph�re principale
   * @param radius Le rayon
   */
  virtual void setRadius(double radius);

  /**
   * M�thode permettant de r�cup�rer le rayon de la sph�re principale
   * @return Le rayon
   */
  virtual double getRadius(void) const;

  /**
   * M�thode permettant de cr�er une nouvelle KeyOrientation entre celle s�lectionn�e et la suivante
   */
  virtual void addKeyOrientation(void);

  /**
   * M�thode permettant de supprimer la KeyOrientation s�lectionn�e
   */
  virtual void removeKeyOrientation(void);

  /**
   * M�thode retournant la liste des positions des KeyOrientation
   * @return La liste des positions des KeyOrientation
   */
  virtual StlList<Util3D::Dbl3>& getKeyOrientation(void);

  /**
   * M�thode retournant la liste des KeyOrientation
   * @return La liste des KeyOrientation
   */
  virtual StlList<ArRef<KeyOrientation> > accessKeyOrientation(void);

  AR_CALLBACK(C3DOF, Change, _changeCB, StlVector<Util3D::Dbl3> keyOrientation;)
    
  /**
   * M�thode permettant de s�lectionn�e une KeyOrientation
   * @param keyOrientation La KeyOrientation � s�lectionner
   */
  virtual void select(ArRef<KeyOrientation> keyOrientation);

  /**
   * M�thode permettant de des�lectionner la KeyOrientation actuellement s�lectionn�e
   */
  virtual void unselect(void);

  /**
   * M�thode permettant de r�cup�rer en consultation la KeyOrientation s�lectionn�e
   * @return La KeyOrientation s�lectionn�e
   */
  virtual ArConstRef<KeyOrientation> getSelected(void) const;

  /**
   * M�thode permettant de r�cup�rer la KeyOrientation s�lectionn�e
   * @return La KeyOrientation s�lectionn�e
   */
  virtual ArRef<KeyOrientation> accessSelected(void);

  /**
   * M�thode permettant de rafraichir la repr�sentation graphique de la contrainte de l'articulation
   */
  virtual void updateShape(void);

protected :

  /**
   * M�thode d�clench�e lors d'un mouvement d'une KeyOrientation
   * @param evt L'�v�nement de mouvement d'une KeyOrientation
   */
  virtual void _keyOrientationMotionCB(const Base3D::MotionEvent& evt);

  /**
   * M�thode d�clench�e lors d'un rafraichissment de la repr�sentation graphique de la contrainte de l'articulation
   */
  virtual void _updateShape(void);

protected :
  /** Rayon de la sph�re principale */
  double _radius;
  /** Indice de la KeyOrientation s�lectionn�e */
  int _selected;
  /** Liste des KeyOrientation */
  StlList<ArRef<KeyOrientation> > _keyOrientation;
  /** Liste des positions des KeyOrientation */
  StlList<Util3D::Dbl3> _localKO;
  /** Gestionnaire des �v�nements sur les changements */
  CallbackManager<C3DOF, ChangeEvent> _changeCB;

  /** Forme de la repr�sentation graphique de la contrainte de l'articulation */
  ArRef<C3DOFSh> _sh;
};

#endif // _C3DOF_H_
