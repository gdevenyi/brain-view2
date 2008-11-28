#ifndef GEOMETRYSCENE_H_
#define GEOMETRYSCENE_H_

#include "TreeItem.h"
#include "GeometryNode.h"
#include "textureFileItem.h"
#include "Inventor/nodes/SoSeparator.h"

class GeometryScene : public TreeItem {
public:
	GeometryScene(const QVector<QVariant> &data,
			ResourceForm *rf, TreeItem *parent = 0);
	virtual ~GeometryScene();
	bool loadGeometry(QFile &file);
	bool loadVertstats(QFile &file);
	void wasSelected();
private:
	
	ResourceForm *rf;
	// the root separator from the viewer
	SoSeparator *root;
	// the separator which will hold all the geometry bits
	SoSeparator *scene;
	// the actual geometry bits
	GeometryNode *geometry;
};

#endif /*GEOMETRYSCENE_H_*/
