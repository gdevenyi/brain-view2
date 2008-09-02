#include "ResourceForm.h"
#include <QtGui>
#include "GeometryScene.h"

#include <iostream>

ResourceForm::ResourceForm(QWidget *parentWindow, BrainQuarter *viewer) : QWidget(parentWindow){
	ui.setupUi(this);
	sampleTreeSetup(viewer);
	//this->parentWindow = (ResourceForm *) parentWindow; //static_cast<QMainWindow *>(parent);
	connect(ui.treeView, SIGNAL(clicked(const QModelIndex&)),
			this, SLOT(setPropertyForm(const QModelIndex&)));
	haveProps = false;
}

ResourceForm::~ResourceForm() {
}

void ResourceForm::setPropertyForm(const QModelIndex & index) {
	// get a pointer to the selected item
	currentPropItem = static_cast<TreeItem*>(index.internalPointer());

	// only set up form if item has property form
	if (currentPropItem->havePropForm()) {

		// remove the current layout in the property box
		delete ui.propertiesBox->layout();

		// destroy the currently in use form
		if (haveProps) {
			currentPropItem->destroyForm();
		}

		// have the item create its property form
		propWidget = currentPropItem->createForm();
		// create a layout and add the new form to it.
		propLayout = new QVBoxLayout();
		propLayout->addWidget(propWidget);
		ui.propertiesBox->setLayout(propLayout);
		haveProps = true;
	}
}

void ResourceForm::sampleTreeSetup(BrainQuarter *viewer) {
	QStringList headers;
	headers << tr("Title") << tr("Description");

	TreeModel *model = new TreeModel(headers, "", this);

	TreeItem *parent = model->getRootItem();
	parent->setViewer(viewer);
	//parent->insertCone();
	QFile f1("mni_icbm_00101_gray_surface_left_81920.obj");
	QFile f2("mni_icbm_00101_white_surface_right_81920.obj");
	parent->insertGeometry(f1);
	parent->insertGeometry(f2);
	//parent->insertChildren(parent->childCount(), 1, parent->columnCount() );
	//parent->child(parent->childCount() - 1)->setData(0, "testing");

	ui.treeView->setModel(model);
	viewer->viewAll();
}
