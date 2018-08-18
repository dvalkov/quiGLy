/***********************************************************************************
 *                                                                                 *
 * quiGLy - quick GL prototyping                                                   *
 *                                                                                 *
 * Copyright (C) 2015-2018 University of Muenster, Germany.                        *
 * Visualization and Computer Graphics Group <http://viscg.uni-muenster.de>        *
 * For a list of authors please refer to the file "CREDITS.txt".                   *
 *                                                                                 *
 * This file is part of the quiGLy software package. quiGLy is free software:      *
 * you can redistribute it and/or modify it under the terms of the GNU General     *
 * Public License version 2 as published by the Free Software Foundation.          *
 *                                                                                 *
 * quiGLy is distributed in the hope that it will be useful, but WITHOUT ANY       *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR   *
 * A PARTICULAR PURPOSE. See the GNU General Public License for more details.      *
 *                                                                                 *
 * You should have received a copy of the GNU General Public License in the file   *
 * "LICENSE.txt" along with this file. If not, see <http://www.gnu.org/licenses/>. *
 *                                                                                 *
 * For non-commercial academic use see the license exception specified in the file *
 * "LICENSE-academic.txt". To get information about commercial licensing please    *
 * contact the authors.                                                            *
 *                                                                                 *
 ***********************************************************************************/

#ifndef WIZARDITEMSPAGE_H
#define WIZARDITEMSPAGE_H

#include "collections/wizarditemcollection.h"
#include "delegates/wizardenumerationdelegate.h"
#include "delegates/wizardpagedelegate.h"
#include "wizarddependencyobject.h"

#include <QWizardPage>
#include <QListWidget>

namespace ysm
{
	class WizardItemDialog;

	//! \brief Provides a multi-item configuration page to the wizard.
	//! All evaluation of the page's configuration must be done in the wizard's project file.
	class WizardItemsPage : public WizardPageDelegate, public WizardDependencyObject
	{
		Q_OBJECT

	public:

		/*!
		 * \brief Initialize new instance.
		 * \param rootElement The XML configuration.
		 * \param parent The parent.
		 */
		WizardItemsPage(QDomElement rootElement, WizardWindow* parent);

		//! \brief Destruct instance.
		virtual ~WizardItemsPage();

	public:

		/*!
		 * \brief Returns the prefixed name.
		 * \param name The name.
		 * \return The prefixed name.
		 */
		QString dynamicName(const QString& name) const Q_DECL_OVERRIDE;

		/*!
		 * \brief Checks wether the widget is complete.
		 * \return True, if widget is complete.
		 */
		bool isComplete() const Q_DECL_OVERRIDE;

	public slots:

		//! \brief Initialize the dynamic items.
		void initializePage() Q_DECL_OVERRIDE;

	public slots:

		//! \brief Add a new item.
		virtual void add();

		//! \brief Edit an item.
		virtual void edit();

		//! \brief Delete an item.
		virtual void remove();

	protected:

		//! \brief The parent window.
		WizardWindow* _parent;

	private:

		//! \brief The prefix used for the fields.
		QString _prefix;

		//! \brief List that contains created items.
		QListWidget* _itemList;

		//! \brief Dialogs and delegates for the items.
		using ItemDialog = QPair<WizardItemDialog*, WizardEnumerationDelegate*>;
		QMap<QString, ItemDialog> _dialogs;

		//! \brief The items that can be added.
		QDomElement _items;

		//! \brief The editing buttons.
		QPushButton* _addButton;
		QPushButton* _editButton;
		QPushButton* _removeButton;

		//! \brief The next item index.
		int _nextIndex;
	};

}

#endif // WIZARDITEMSPAGE_H
