#ifndef _EDIT_ANCHOR_H_
#define _EDIT_ANCHOR_H_

#include "hLib/core/anchor.h"
#include "hLib/core/body.h"
using namespace hLib;

#include "gtkAReViWidget.h"
using namespace GtkTools;

#include "undoRedo.h"

/**
 * Enum�ration des colonnes
 */
enum LinkColumnID {
  COLUMN_LINK_NAME = 0, /**< enum value COLUMN_LINK_NAME. */ 
  COLUMN_LINK_DATA = 1 /**< enum value COLUMN_LINK_DATA. */
};

/**
 * Gestion de l'IHM permettant l'edition des ancres
 */
class EditAnchor : public GtkAReViWidget {
 public :
 
  /**
   * Constructeur de la classe EditAnchor
   * @param arCW R�f�rence sp�cifique � AR�Vi
   */
   AR_CLASS(EditAnchor)
   AR_CONSTRUCTOR(EditAnchor)
   
  /**
   * Destructeur de EditAnchor
   */

  /**
   * Remplissage de la boite de dialogue
   * @param anchor R�f�rence sur une ancre
   * @param body R�f�rence sur un squelette
   */
  virtual void fill(ArRef<Anchor> anchor, ArRef<Body> body);

 protected :
};

#endif // _EDIT_ANCHOR_H_
