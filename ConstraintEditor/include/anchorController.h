#ifndef _ANCHOR_CONTROLLER_H_
#define _ANCHOR_CONTROLLER_H_

#include "AReVi/arObject.h"
#include "AReVi/Lib3D/material3D.h"
#include "AReVi/Shapes/sphere3D.h"
using namespace AReVi;

namespace hLib {
class Anchor;
}
using namespace hLib;

/**
 * Classe permettant la gestion des ancres sur la vue AR�Vi
 */
class AnchorController : public ArObject {
public :
  AR_CLASS(AnchorController)
  AR_CONSTRUCTOR(AnchorController)

  /**
   * 
   */
  virtual void postChanges(void);

  /**
   * M�thode permettant de retourner le nombre d'ancres du mod�le charg�
   * @return Le nombre d'ancres du mod�le charg�
   */
  virtual size_t getNbAnchors(void) const;

  /**
   * M�thode permettant d'ajouter une ancre au mod�le charg�
   * @param anchor L'ancre � ajouter
   */
  virtual void addAnchor(ArRef<Anchor> anchor);

  /**
   * M�thode permettant d'enlever une ancre au mod�le charg�
   * @param anchor L'ancre � enlever
   */
  virtual void removeAnchor(ArRef<Anchor> anchor);
  
  /**
   * M�thode permettant de supprimer toutes les ancres du mod�le charg�
   */
  virtual void clearAnchors(void);

  /**
   * M�thode permettant de r�cup�rer en consultation une ancre dont l'indice est pass� en param�tre
   * @param id L'indice de l'ancre
   * @return L'ancre
   */
  virtual ArConstRef<Anchor> getAnchor(size_t id) const;

  /**
   * M�thode permettant de r�cup�rer en une ancre dont l'indice est pass� en param�tre
   * @param id L'indice de l'ancre
   * @return L'ancre
   */
  virtual ArRef<Anchor> accessAnchor(size_t id);

  AR_CALLBACK(AnchorController, Anchor, _anchorCB, StlVector<ArRef<Anchor> > anchors; )

  /**
   * M�thode permettant de surlign� une ancre dans la vue AR�Vi
   * @param anchor L'ancre � surligner
   */
  virtual void highLightAnchor(ArRef<Anchor> anchor);

  /**
   * M�thode permettant de r�cup�rer l'ancre surlign�e en consultation 
   * @return L'ancre surlign�e
   */
  virtual ArConstRef<Anchor> getHighLightedAnchor(void) const;

  /**
   * M�thode permettant de r�cup�rer l'ancre surlign�e
   * @return L'ancre surlign�e
   */
  virtual ArRef<Anchor> accessHighLightedAnchor(void);

  AR_CALLBACK(AnchorController, HighLight, _highLightCB,
	      ArRef<Anchor> anchor;
	      )

protected :

  /**
   * M�thode d�crivant l'action r�sultante de la manipulation d'une ancre
   */
  virtual void _onAnchor(void);

  /**
   * M�thode d�crivant l'action r�sultante du surlignage d'une ancre
   * @param  
   */
  virtual void _onHighLight(void);

protected :
  /** Vector des ancres du mod�le */
  StlVector<ArRef<Anchor> > _anchors;
  /** Ancre surlign�e */
  ArRef<Anchor> _highLighted;

  /** Sph�re repr�sentative des ancres */
  ArRef<Sphere3D> _sphere;
  /** Texture de la sph�re */
  ArRef<Material3D> _material;

  /** Gestionnaire de Callback pour les actions sur les ancres */
  CallbackManager<AnchorController, AnchorEvent> _anchorCB;
  /** Gestionnaire de Callback pour le surlignage des ancres */
  CallbackManager<AnchorController, HighLightEvent> _highLightCB;

};

#endif // _ANCHOR_CONTROLLER_H_
